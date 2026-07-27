const fs = require("node:fs");
const path = require("node:path");
const util = require("node:util");

const LOG_FILE_NAMES = Object.freeze({
  application: "application.txt",
  actions: "user-actions.txt",
  files: "file-operations.txt",
  state: "application-state.txt",
  errors: "errors.txt"
});

const SENSITIVE_KEY_PATTERN = /(password|passwd|token|secret|authorization|cookie|xmltext|line1|line2|content|calcdata|defaultvalue|userenterdata)/i;
const MAX_STRING_LENGTH = 4000;
const MAX_ARRAY_LENGTH = 250;
const MAX_OBJECT_DEPTH = 8;

function pad(value, length = 2) {
  return String(value).padStart(length, "0");
}

function formatLocalDate(date) {
  return `${date.getFullYear()}-${pad(date.getMonth() + 1)}-${pad(date.getDate())}`;
}

function formatLocalTimestamp(date) {
  const offsetMinutes = -date.getTimezoneOffset();
  const offsetSign = offsetMinutes >= 0 ? "+" : "-";
  const offsetHours = pad(Math.floor(Math.abs(offsetMinutes) / 60));
  const offsetRemainder = pad(Math.abs(offsetMinutes) % 60);
  return (
    `${formatLocalDate(date)} ${pad(date.getHours())}:${pad(date.getMinutes())}:${pad(date.getSeconds())}.` +
    `${pad(date.getMilliseconds(), 3)} ${offsetSign}${offsetHours}:${offsetRemainder}`
  );
}

function createSessionId(date = new Date()) {
  return (
    `${formatLocalDate(date).replaceAll("-", "")}-` +
    `${pad(date.getHours())}${pad(date.getMinutes())}${pad(date.getSeconds())}-` +
    `pid${process.pid}`
  );
}

function sanitizeValue(value, key = "", depth = 0, seen = new WeakSet()) {
  if (SENSITIVE_KEY_PATTERN.test(key)) return "[REDACTED]";
  if (value == null || typeof value === "number" || typeof value === "boolean") return value;
  if (typeof value === "bigint") return `${value}n`;
  if (typeof value === "string") {
    return value.length > MAX_STRING_LENGTH
      ? `${value.slice(0, MAX_STRING_LENGTH)}… [truncated ${value.length - MAX_STRING_LENGTH} chars]`
      : value;
  }
  if (typeof value === "function") return `[Function ${value.name || "anonymous"}]`;
  if (value instanceof Error) {
    return {
      name: value.name,
      message: value.message,
      stack: value.stack,
      cause: value.cause ? sanitizeValue(value.cause, "cause", depth + 1, seen) : undefined
    };
  }
  if (depth >= MAX_OBJECT_DEPTH) return "[Max depth reached]";
  if (typeof value !== "object") return String(value);
  if (seen.has(value)) return "[Circular reference]";
  seen.add(value);

  if (Array.isArray(value)) {
    const limited = value.slice(0, MAX_ARRAY_LENGTH).map((item) => sanitizeValue(item, "", depth + 1, seen));
    if (value.length > MAX_ARRAY_LENGTH) {
      limited.push(`[${value.length - MAX_ARRAY_LENGTH} more items omitted]`);
    }
    return limited;
  }

  const output = {};
  Object.entries(value).forEach(([entryKey, entryValue]) => {
    output[entryKey] = sanitizeValue(entryValue, entryKey, depth + 1, seen);
  });
  return output;
}

function formatDetails(details) {
  if (details == null) return "  (none)";
  const sanitized = sanitizeValue(details);
  const inspected = util.inspect(sanitized, {
    colors: false,
    compact: false,
    depth: MAX_OBJECT_DEPTH,
    maxArrayLength: MAX_ARRAY_LENGTH,
    maxStringLength: MAX_STRING_LENGTH,
    sorted: true,
    breakLength: 120
  });
  return inspected.split(/\r?\n/).map((line) => `  ${line}`).join("\n");
}

function formatEntry(entry, context) {
  const separator = "=".repeat(100);
  return [
    separator,
    `[${formatLocalTimestamp(entry.timestamp)}] [${entry.level}] [session: ${context.sessionId}]`,
    `Event: ${entry.event}`,
    `Message: ${entry.message || "(no message)"}`,
    `Source: ${entry.source || "unknown"}`,
    "Details:",
    formatDetails(entry.details),
    ""
  ].join("\n");
}

function normalizeCategory(category) {
  return Object.hasOwn(LOG_FILE_NAMES, category) ? category : "application";
}

function normalizeLevel(level) {
  const normalized = String(level || "INFO").toUpperCase();
  return ["TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"].includes(normalized)
    ? normalized
    : "INFO";
}

function createFileLogger(options) {
  const baseDir = path.resolve(options.baseDir);
  const sessionId = options.sessionId || createSessionId();
  const appVersion = String(options.appVersion || "unknown");
  let writeQueue = Promise.resolve();
  let lastWriteError = null;

  async function append(entry) {
    const dateDirectory = path.join(baseDir, formatLocalDate(entry.timestamp));
    const filePath = path.join(dateDirectory, LOG_FILE_NAMES[entry.category]);
    await fs.promises.mkdir(dateDirectory, { recursive: true });
    await fs.promises.appendFile(
      filePath,
      formatEntry(entry, { sessionId, appVersion }),
      { encoding: "utf8" }
    );
    return filePath;
  }

  function log(payload = {}) {
    const entry = {
      timestamp: payload.timestamp ? new Date(payload.timestamp) : new Date(),
      category: normalizeCategory(payload.category),
      level: normalizeLevel(payload.level),
      event: String(payload.event || "UNSPECIFIED_EVENT").slice(0, 160),
      message: String(payload.message || "").slice(0, 2000),
      source: String(payload.source || "main").slice(0, 160),
      details: payload.details ?? null
    };
    if (Number.isNaN(entry.timestamp.getTime())) entry.timestamp = new Date();

    writeQueue = writeQueue
      .then(() => append(entry))
      .catch((error) => {
        lastWriteError = error;
        console.error("Failed to write Willow log entry:", error);
      });
    return writeQueue;
  }

  function flush() {
    return writeQueue;
  }

  function getInfo() {
    return {
      baseDir,
      sessionId,
      appVersion,
      files: { ...LOG_FILE_NAMES },
      lastWriteError: lastWriteError
        ? { name: lastWriteError.name, message: lastWriteError.message }
        : null
    };
  }

  return { log, flush, getInfo };
}

module.exports = {
  LOG_FILE_NAMES,
  createFileLogger,
  createSessionId,
  formatLocalDate,
  sanitizeValue
};
