const { app, BrowserWindow, ipcMain, nativeTheme, net, protocol, shell } = require("electron");
const fs = require("node:fs");
const os = require("node:os");
const path = require("node:path");
const { pathToFileURL } = require("node:url");
const { createFileLogger, createSessionId } = require("./logger.cjs");
const { createFontCatalogService, createFontRendererService } = require("./fonts.cjs");

const APP_PROTOCOL = "glyph";
const APP_HOST = "app";
let fileLogger = null;
let quitAfterLogFlush = false;
let logFlushInProgress = false;

protocol.registerSchemesAsPrivileged([
  {
    scheme: APP_PROTOCOL,
    privileges: {
      standard: true,
      secure: true,
      supportFetchAPI: true,
      corsEnabled: true,
      stream: true
    }
  }
]);

function getDevServerUrl() {
  const arg = process.argv.find((value) => value.startsWith("--dev-url="));
  return arg ? arg.slice("--dev-url=".length) : process.env.VITE_DEV_SERVER_URL || null;
}

function getDistDir() {
  return path.resolve(__dirname, "..", "dist");
}

function getWindowIconPath() {
  const distIconPath = path.join(getDistDir(), "resourses", "Icons", "icon.ico");
  if (fs.existsSync(distIconPath)) return distIconPath;
  return path.join(__dirname, "..", "public", "resourses", "Icons", "icon.ico");
}

function resolveAppProtocolPath(requestUrl) {
  const url = new URL(requestUrl);
  const distDir = getDistDir();
  const rawPathname = decodeURIComponent(url.pathname || "/");
  const relativePath = rawPathname === "/"
    ? "index.html"
    : rawPathname.replace(/^\/+/, "");
  const filePath = path.resolve(distDir, relativePath);

  const normalizedDist = distDir.toLowerCase();
  const normalizedFile = filePath.toLowerCase();
  if (normalizedFile !== normalizedDist && !normalizedFile.startsWith(`${normalizedDist}${path.sep}`)) {
    throw new Error(`Blocked path outside app bundle: ${requestUrl}`);
  }

  return filePath;
}

function registerAppProtocol() {
  protocol.handle(APP_PROTOCOL, (request) => {
    const filePath = resolveAppProtocolPath(request.url);
    return net.fetch(pathToFileURL(filePath).toString());
  });
}

function isAllowedNavigation(url, devServerUrl) {
  if (devServerUrl && url.startsWith(devServerUrl)) return true;
  return url.startsWith(`${APP_PROTOCOL}://${APP_HOST}/`);
}

function logMain(category, event, message, details = null, level = "INFO") {
  if (!fileLogger) {
    if (level === "ERROR" || level === "FATAL") console.error(`[${event}] ${message}`, details);
    return Promise.resolve();
  }
  return fileLogger.log({
    category,
    event,
    message,
    details,
    level,
    source: "electron-main"
  });
}

function initializeFileLogging() {
  const logsDirectory = path.join(app.getPath("userData"), "logs");
  fileLogger = createFileLogger({
    baseDir: logsDirectory,
    sessionId: createSessionId(),
    appVersion: app.getVersion()
  });

  ipcMain.on("glyph:log", (event, payload) => {
    const rendererDetails = {
      ...(payload?.details && typeof payload.details === "object" ? payload.details : { value: payload?.details }),
      renderer: {
        webContentsId: event.sender.id,
        url: event.sender.getURL()
      }
    };
    fileLogger.log({
      category: payload?.category,
      event: payload?.event,
      message: payload?.message,
      details: rendererDetails,
      level: payload?.level,
      timestamp: payload?.timestamp,
      source: payload?.source || "renderer"
    });
  });

  ipcMain.handle("glyph:get-log-info", () => fileLogger.getInfo());
  ipcMain.handle("glyph:flush-logs", () => fileLogger.flush().then(() => fileLogger.getInfo()));

  return logMain(
    "application",
    "APPLICATION_SESSION_STARTED",
    "Glyph Studio logging session started.",
    {
      application: {
        name: app.getName(),
        version: app.getVersion(),
        packaged: app.isPackaged,
        appPath: app.getAppPath(),
        userDataPath: app.getPath("userData"),
        logsDirectory
      },
      runtime: {
        electron: process.versions.electron,
        chrome: process.versions.chrome,
        node: process.versions.node,
        v8: process.versions.v8
      },
      operatingSystem: {
        platform: process.platform,
        release: os.release(),
        architecture: process.arch,
        hostname: os.hostname(),
        locale: app.getLocale(),
        timezone: Intl.DateTimeFormat().resolvedOptions().timeZone
      },
      process: {
        pid: process.pid,
        arguments: process.argv
      }
    }
  );
}

function describeWindow(mainWindow) {
  if (!mainWindow || mainWindow.isDestroyed()) return null;
  return {
    id: mainWindow.id,
    bounds: mainWindow.getBounds(),
    contentBounds: mainWindow.getContentBounds(),
    maximized: mainWindow.isMaximized(),
    minimized: mainWindow.isMinimized(),
    fullScreen: mainWindow.isFullScreen(),
    focused: mainWindow.isFocused(),
    visible: mainWindow.isVisible()
  };
}

function createMainWindow() {
  const devServerUrl = getDevServerUrl();
  const mainWindow = new BrowserWindow({
    width: 1280,
    height: 800,
    minWidth: 960,
    minHeight: 640,
    show: false,
    autoHideMenuBar: true,
    backgroundColor: nativeTheme.shouldUseDarkColors ? "#121318" : "#e5e7eb",
    icon: getWindowIconPath(),
    webPreferences: {
      preload: path.join(__dirname, "preload.cjs"),
      contextIsolation: true,
      nodeIntegration: false,
      sandbox: true
    }
  });

  mainWindow.once("ready-to-show", () => {
    logMain("application", "MAIN_WINDOW_READY", "Main window is ready and will be shown.", describeWindow(mainWindow));
    mainWindow.show();
  });

  mainWindow.webContents.setWindowOpenHandler(({ url }) => {
    if (/^https?:\/\//i.test(url)) {
      logMain("actions", "EXTERNAL_LINK_OPEN_REQUESTED", "User requested opening an external link.", { url });
      shell.openExternal(url).catch((error) => {
        logMain("errors", "EXTERNAL_LINK_OPEN_FAILED", "Failed to open an external link.", { url, error }, "ERROR");
      });
    }
    return { action: "deny" };
  });

  mainWindow.webContents.on("will-navigate", (event, url) => {
    if (isAllowedNavigation(url, devServerUrl)) return;
    event.preventDefault();
    logMain("application", "NAVIGATION_BLOCKED", "Navigation outside the application was blocked.", { url }, "WARN");
    if (/^https?:\/\//i.test(url)) {
      shell.openExternal(url).catch((error) => {
        logMain("errors", "EXTERNAL_NAVIGATION_OPEN_FAILED", "Failed to open blocked navigation externally.", { url, error }, "ERROR");
      });
    }
  });

  mainWindow.webContents.on("did-finish-load", () => {
    logMain("application", "RENDERER_LOADED", "Renderer finished loading.", {
      windowId: mainWindow.id,
      url: mainWindow.webContents.getURL()
    });
  });

  mainWindow.webContents.on("did-fail-load", (_event, errorCode, errorDescription, validatedURL, isMainFrame) => {
    logMain("errors", "RENDERER_LOAD_FAILED", "Renderer failed to load.", {
      errorCode,
      errorDescription,
      validatedURL,
      isMainFrame
    }, "ERROR");
  });

  mainWindow.webContents.on("render-process-gone", (_event, details) => {
    logMain("errors", "RENDER_PROCESS_GONE", "Renderer process terminated unexpectedly.", details, "FATAL");
  });

  mainWindow.on("unresponsive", () => {
    logMain("errors", "MAIN_WINDOW_UNRESPONSIVE", "Main window became unresponsive.", describeWindow(mainWindow), "ERROR");
  });

  mainWindow.on("responsive", () => {
    logMain("application", "MAIN_WINDOW_RESPONSIVE", "Main window became responsive again.", describeWindow(mainWindow), "WARN");
  });

  mainWindow.on("focus", () => {
    logMain("application", "MAIN_WINDOW_FOCUSED", "Main window received focus.", describeWindow(mainWindow), "DEBUG");
  });

  mainWindow.on("blur", () => {
    logMain("application", "MAIN_WINDOW_BLURRED", "Main window lost focus.", describeWindow(mainWindow), "DEBUG");
  });

  mainWindow.on("maximize", () => {
    logMain("state", "WINDOW_STATE_CHANGED", "Main window was maximized.", describeWindow(mainWindow));
  });

  mainWindow.on("unmaximize", () => {
    logMain("state", "WINDOW_STATE_CHANGED", "Main window left maximized state.", describeWindow(mainWindow));
  });

  let boundsLogTimer = null;
  const scheduleBoundsLog = () => {
    if (boundsLogTimer) clearTimeout(boundsLogTimer);
    boundsLogTimer = setTimeout(() => {
      boundsLogTimer = null;
      logMain("state", "WINDOW_BOUNDS_CHANGED", "Main window position or size changed.", describeWindow(mainWindow), "DEBUG");
    }, 500);
  };
  mainWindow.on("move", scheduleBoundsLog);
  mainWindow.on("resize", scheduleBoundsLog);
  mainWindow.on("close", () => {
    if (boundsLogTimer) clearTimeout(boundsLogTimer);
    logMain("application", "MAIN_WINDOW_CLOSING", "Main window is closing.", describeWindow(mainWindow));
  });

  logMain("application", "MAIN_WINDOW_CREATED", "Main application window was created.", {
    ...describeWindow(mainWindow),
    developmentServer: devServerUrl || null
  });

  if (devServerUrl) {
    mainWindow.loadURL(devServerUrl);
  } else {
    mainWindow.loadURL(`${APP_PROTOCOL}://${APP_HOST}/index.html`);
  }
}

process.on("uncaughtExceptionMonitor", (error, origin) => {
  logMain("errors", "MAIN_PROCESS_UNCAUGHT_EXCEPTION", "An uncaught exception reached the main process.", {
    origin,
    error
  }, "FATAL");
});

process.on("unhandledRejection", (reason) => {
  logMain("errors", "MAIN_PROCESS_UNHANDLED_REJECTION", "An unhandled promise rejection occurred in the main process.", {
    reason
  }, "ERROR");
});

app.whenReady().then(async () => {
  await initializeFileLogging();
  ipcMain.on("glyph:get-system-tick-count", (event) => {
    const sourceUrl = event.senderFrame?.url || event.sender.getURL();
    event.returnValue = isAllowedNavigation(sourceUrl, getDevServerUrl())
      ? Math.floor(os.uptime() * 1000) >>> 0
      : null;
  });
  const fontCatalog = createFontCatalogService();
  const fontRenderer = createFontRendererService();
  ipcMain.handle("glyph:list-fonts", (event) => {
    const sourceUrl = event.senderFrame?.url || event.sender.getURL();
    if (!isAllowedNavigation(sourceUrl, getDevServerUrl())) throw new Error("Untrusted font catalog request.");
    return fontCatalog.list();
  });
  ipcMain.handle("glyph:render-font", (event, request) => {
    const sourceUrl = event.senderFrame?.url || event.sender.getURL();
    if (!isAllowedNavigation(sourceUrl, getDevServerUrl())) throw new Error("Untrusted font rendering request.");
    return fontRenderer.render(request);
  });
  app.on("will-quit", () => fontRenderer.dispose());
  registerAppProtocol();
  createMainWindow();

  app.on("activate", () => {
    if (BrowserWindow.getAllWindows().length === 0) createMainWindow();
  });
});

app.on("window-all-closed", () => {
  if (process.platform !== "darwin") app.quit();
});

app.on("before-quit", (event) => {
  if (!fileLogger || quitAfterLogFlush) return;
  event.preventDefault();
  if (logFlushInProgress) return;
  logFlushInProgress = true;
  logMain("application", "APPLICATION_SESSION_ENDING", "Application is shutting down.", {
    openWindowCount: BrowserWindow.getAllWindows().length,
    processUptimeSeconds: Number(process.uptime().toFixed(3))
  }).finally(() => fileLogger.flush()).finally(() => {
    quitAfterLogFlush = true;
    app.quit();
  });
});

app.on("web-contents-created", (_event, contents) => {
  contents.on("will-attach-webview", (event) => {
    event.preventDefault();
  });
});
