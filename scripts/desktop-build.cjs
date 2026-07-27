const { spawnSync } = require("node:child_process");
const fs = require("node:fs");
const path = require("node:path");

const workspace = path.resolve(__dirname, "..");
const packageJson = require(path.join(workspace, "package.json"));
const configuredOutput = packageJson.build?.directories?.output || "desktop-release-local";

function timestamp() {
  const now = new Date();
  const pad = (value) => String(value).padStart(2, "0");
  return [
    now.getFullYear(),
    pad(now.getMonth() + 1),
    pad(now.getDate()),
    "-",
    pad(now.getHours()),
    pad(now.getMinutes()),
    pad(now.getSeconds())
  ].join("");
}

function assertInsideWorkspace(targetPath) {
  const resolved = path.resolve(workspace, targetPath);
  const relative = path.relative(workspace, resolved);
  if (relative.startsWith("..") || path.isAbsolute(relative)) {
    throw new Error(`Refusing to use output outside workspace: ${resolved}`);
  }
  return resolved;
}

function removeOutputIfPossible(outputDir) {
  const resolved = assertInsideWorkspace(outputDir);
  if (!fs.existsSync(resolved)) return true;

  try {
    fs.rmSync(resolved, { recursive: true, force: true });
    return true;
  } catch (error) {
    const code = error && typeof error === "object" ? error.code : null;
    if (code === "EBUSY" || code === "EPERM" || code === "ENOTEMPTY") {
      console.warn(
        `[desktop:build] Cannot clean "${outputDir}" because Windows still has a file locked. ` +
        "A fresh output folder will be used for this build."
      );
      return false;
    }
    throw error;
  }
}

const canUseConfiguredOutput = removeOutputIfPossible(configuredOutput);
const outputDir = canUseConfiguredOutput
  ? configuredOutput
  : `${configuredOutput}-${timestamp()}`;

const builderCli = path.join(workspace, "node_modules", "electron-builder", "cli.js");

const result = spawnSync(
  process.execPath,
  [builderCli, "--win", `--config.directories.output=${outputDir}`],
  {
    cwd: workspace,
    env: process.env,
    stdio: "inherit",
    shell: false
  }
);

if (result.error) throw result.error;
if (result.status !== 0) process.exit(result.status ?? 1);

console.log(`[desktop:build] Desktop artifacts written to ${outputDir}`);
