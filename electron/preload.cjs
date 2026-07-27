const { contextBridge, ipcRenderer } = require("electron");

const ALLOWED_LOG_CATEGORIES = new Set(["application", "actions", "files", "state", "errors"]);
const ALLOWED_LOG_LEVELS = new Set(["TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"]);

function normalizeLogPayload(payload = {}) {
  const category = ALLOWED_LOG_CATEGORIES.has(payload.category) ? payload.category : "application";
  const normalizedLevel = String(payload.level || "INFO").toUpperCase();
  return {
    category,
    level: ALLOWED_LOG_LEVELS.has(normalizedLevel) ? normalizedLevel : "INFO",
    event: String(payload.event || "UNSPECIFIED_RENDERER_EVENT").slice(0, 160),
    message: String(payload.message || "").slice(0, 2000),
    source: String(payload.source || "renderer").slice(0, 160),
    timestamp: payload.timestamp || new Date().toISOString(),
    details: payload.details ?? null
  };
}

contextBridge.exposeInMainWorld("willowLogger", Object.freeze({
  log(payload) {
    ipcRenderer.send("willow:log", normalizeLogPayload(payload));
  },
  getInfo() {
    return ipcRenderer.invoke("willow:get-log-info");
  },
  flush() {
    return ipcRenderer.invoke("willow:flush-logs");
  }
}));
