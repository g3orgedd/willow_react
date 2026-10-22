/* Detailed renderer logging for Glyph Studio. */
(() => {
  const MAX_FALLBACK_ENTRIES = 500;
  const fallbackEntries = [];
  let initialized = false;
  let stateLogTimer = null;
  let pendingStateReasons = [];
  let originalConsoleError = null;
  let originalConsoleWarn = null;

  function serializeError(error) {
    if (error instanceof Error) {
      return {
        name: error.name,
        message: error.message,
        stack: error.stack,
        cause: error.cause ? serializeError(error.cause) : null
      };
    }
    if (error && typeof error === "object") {
      return {
        name: String(error.name || "UnknownError"),
        message: String(error.message || error.reason || "Unknown error"),
        stack: error.stack ? String(error.stack) : null
      };
    }
    return { name: "Error", message: String(error), stack: null };
  }

  function makeSafeDetails(value, depth = 0, seen = new WeakSet()) {
    if (value == null || typeof value === "number" || typeof value === "boolean") return value;
    if (typeof value === "string") return value.length > 2000 ? `${value.slice(0, 2000)}…` : value;
    if (value instanceof Error) return serializeError(value);
    if (typeof value === "function") return `[Function ${value.name || "anonymous"}]`;
    if (typeof value !== "object") return String(value);
    if (depth >= 6) return "[Max depth reached]";
    if (seen.has(value)) return "[Circular reference]";
    seen.add(value);
    if (Array.isArray(value)) {
      return value.slice(0, 200).map((item) => makeSafeDetails(item, depth + 1, seen));
    }
    const output = {};
    Object.entries(value).forEach(([key, item]) => {
      if (/(password|token|secret|xmlText|line1|line2|calcData|defaultValue|userEnterData|content)/i.test(key)) {
        output[key] = "[REDACTED]";
      } else {
        output[key] = makeSafeDetails(item, depth + 1, seen);
      }
    });
    return output;
  }

  function emitLog(category, event, message, details = null, level = "INFO", source = "renderer") {
    const payload = {
      category,
      event,
      message,
      details: makeSafeDetails(details),
      level,
      source,
      timestamp: new Date().toISOString()
    };
    try {
      if (globalThis.glyphLogger?.log) {
        globalThis.glyphLogger.log(payload);
      } else {
        fallbackEntries.push(payload);
        if (fallbackEntries.length > MAX_FALLBACK_ENTRIES) fallbackEntries.shift();
      }
    } catch (error) {
      originalConsoleError?.("Failed to send Glyph Studio log entry:", error);
    }
  }

  function getElementLabel(element) {
    if (!element) return "";
    const ariaLabel = element.getAttribute?.("aria-label");
    const title = element.getAttribute?.("title");
    const text = element.textContent?.replace(/\s+/g, " ").trim();
    return String(ariaLabel || title || text || element.id || element.tagName || "").slice(0, 300);
  }

  function describeElement(element) {
    if (!(element instanceof Element)) return null;
    const closestDialog = element.closest("[role='dialog'], [role='alertdialog']");
    const closestTabView = element.closest(".tabview");
    const closestPanel = element.closest(".panel");
    const dataset = {};
    Object.entries(element.dataset || {}).forEach(([key, value]) => {
      dataset[key] = String(value).slice(0, 300);
    });
    return {
      tagName: element.tagName,
      id: element.id || null,
      type: element.getAttribute("type"),
      role: element.getAttribute("role"),
      label: getElementLabel(element),
      disabled: "disabled" in element ? !!element.disabled : null,
      ariaPressed: element.getAttribute("aria-pressed"),
      ariaSelected: element.getAttribute("aria-selected"),
      dataset,
      context: {
        dialogId: closestDialog?.id || null,
        tabViewId: closestTabView?.id || null,
        panelClass: closestPanel?.className || null
      }
    };
  }

  function describeControlValue(element) {
    if (!(element instanceof HTMLInputElement || element instanceof HTMLSelectElement || element instanceof HTMLTextAreaElement)) {
      return null;
    }
    if (element instanceof HTMLSelectElement) {
      return {
        kind: "select",
        value: element.value,
        selectedLabel: element.selectedOptions?.[0]?.textContent?.trim() || "",
        selectedIndex: element.selectedIndex
      };
    }
    if (element.type === "checkbox" || element.type === "radio") {
      return { kind: element.type, checked: element.checked };
    }
    if (["number", "range", "color", "date", "time"].includes(element.type)) {
      return { kind: element.type, value: element.value };
    }
    return {
      kind: element.type || element.tagName.toLowerCase(),
      value: "[REDACTED]",
      valueLength: String(element.value || "").length
    };
  }

  function summarizeField(field) {
    return {
      name: field.name,
      sourceName: field.sourceName ?? null,
      type: field.fldType,
      printed: !!field.printed,
      orientation: field.orientation,
      lineNumber: field.ln,
      geometryInternal: field.geom ? { ...field.geom } : null,
      geometryMillimeters: field.geom && typeof internalToMm === "function"
        ? {
            x: Number(internalToMm(field.geom.x).toFixed(2)),
            y: Number(internalToMm(field.geom.y).toFixed(2)),
            width: Number(internalToMm(field.geom.w).toFixed(2)),
            height: Number(internalToMm(field.geom.h).toFixed(2))
          }
        : null,
      textSettings: field.text ? {
        pitch: field.text.pitch,
        xMag: field.text.xMag
      } : null,
      barcode: field.barcode?.dataMatrix ? {
        symbolSize: field.barcode.dataMatrix.symbolSize,
        moduleSize: field.barcode.dataMatrix.moduleSize,
        segmentCount: field.barcode.dataMatrix.segments?.length || 0,
        segmentSources: (field.barcode.dataMatrix.segments || []).map((segment) => segment.srcField)
      } : null
    };
  }

  function collectApplicationState() {
    try {
      const fields = Array.isArray(state?.fields) ? state.fields : [];
      const printedFields = fields.filter((field) => field.printed);
      const hiddenFields = fields.filter((field) => !field.printed);
      const activeTab = typeof getActiveTemplateTab === "function" ? getActiveTemplateTab() : null;
      const selectedNames = typeof getSelectedNames === "function" ? getSelectedNames() : [];
      return {
        document: {
          loaded: !!state?.xmlDoc,
          designedFor: state?.docMeta?.designedFor || null,
          printerModel: state?.docMeta?.printerModel || null,
          printMode: state?.docMeta?.printMode || null,
          version: state?.docMeta?.version || null,
          overallSizeMillimeters: typeof internalToMm === "function"
            ? {
                width: Number(internalToMm(getCanvasInternalWidth()).toFixed(2)),
                height: Number(internalToMm(getCanvasInternalHeight()).toFixed(2))
              }
            : null,
          usedSizeMillimeters: typeof internalToMm === "function"
            ? {
                width: Number(internalToMm(getUsedImageInternalWidth()).toFixed(2)),
                height: Number(internalToMm(getUsedImageInternalHeight()).toFixed(2))
              }
            : null
        },
        activeTemplateTab: activeTab ? {
          id: activeTab.id,
          title: activeTab.title,
          dirty: !!activeTab.isDirty
        } : null,
        tabs: typeof tabsState !== "undefined"
          ? {
              activeTabId: tabsState.activeTabId,
              count: tabsState.tabs.length,
              items: tabsState.tabs.map((tab) => ({
                id: tab.id,
                title: tab.title,
                dirty: !!tab.isDirty,
                hasDocument: !!tab.templateState?.raw?.line2
              }))
            }
          : null,
        fields: {
          total: fields.length,
          printed: printedFields.length,
          hidden: hiddenFields.length,
          byType: fields.reduce((result, field) => {
            const type = field.fldType || "Unknown";
            result[type] = (result[type] || 0) + 1;
            return result;
          }, {}),
          items: fields.map(summarizeField)
        },
        selection: {
          primaryName: state?.selectedName || null,
          selectedNames,
          count: selectedNames.length
        },
        offsets: {
          count: state?.dateOffsets?.length || 0,
          loaded: !!state?.dateOffsetsLoaded,
          dirty: !!state?.dateOffsetsDirty,
          names: (state?.dateOffsets || []).map((offset) => offset.name)
        },
        editor: {
          language: document.documentElement.lang || null,
          theme: document.documentElement.dataset.theme || null,
          gridSizeMillimeters: state?.gridMm,
          gridVisible: !!elToggleGrid?.checked,
          snapEnabled: !!elToggleSnap?.checked,
          alignEnabled: !!elToggleAlign?.checked,
          hiddenFieldsVisibleOnCanvas: !!state?.showHiddenOnCanvas,
          activeFieldFilter: typeof activeFieldFilter !== "undefined" ? activeFieldFilter : null,
          zoomPercent: typeof zoomPct !== "undefined" ? zoomPct : null,
          mobilePanMode: typeof isMobilePanMode !== "undefined" ? isMobilePanMode : null,
          pendingPlacement: typeof pendingCanvasPlacement !== "undefined" && pendingCanvasPlacement
            ? {
                kind: pendingCanvasPlacement.kind,
                fieldType: pendingCanvasPlacement.fldType || null,
                toolButtonId: pendingCanvasPlacement.toolButtonId || null
              }
            : null
        },
        history: typeof history !== "undefined"
          ? { undoDepth: history.undo?.length || 0, redoDepth: history.redo?.length || 0 }
          : null,
        validation: state?.validation ? makeSafeDetails(state.validation) : null,
        window: {
          width: window.innerWidth,
          height: window.innerHeight,
          devicePixelRatio: window.devicePixelRatio,
          online: navigator.onLine,
          visibility: document.visibilityState
        }
      };
    } catch (error) {
      return {
        collectionFailed: true,
        error: serializeError(error)
      };
    }
  }

  function logApplicationState(event, reason, extra = null, level = "INFO") {
    emitLog("state", event, reason, {
      state: collectApplicationState(),
      extra
    }, level, "renderer-state");
  }

  function scheduleApplicationStateLog(reason, extra = null, delay = 180) {
    pendingStateReasons.push({ reason, extra });
    if (stateLogTimer) clearTimeout(stateLogTimer);
    stateLogTimer = window.setTimeout(() => {
      stateLogTimer = null;
      const reasons = pendingStateReasons.slice();
      pendingStateReasons = [];
      logApplicationState(
        "APPLICATION_STATE_AFTER_INTERACTION",
        "Состояние приложения после пользовательского взаимодействия.",
        { triggers: reasons }
      );
    }, delay);
  }

  function installInteractionLogging() {
    document.addEventListener("click", (event) => {
      const control = event.target instanceof Element
        ? event.target.closest("button, [role='button'], [role='tab'], a")
        : null;
      if (!control) return;
      const description = describeElement(control);
      emitLog(
        "actions",
        "USER_CONTROL_CLICKED",
        `Пользователь нажал элемент управления «${description?.label || "без подписи"}».`,
        {
          control: description,
          pointer: {
            button: event.button,
            detail: event.detail,
            shiftKey: event.shiftKey,
            ctrlKey: event.ctrlKey,
            altKey: event.altKey,
            metaKey: event.metaKey
          }
        }
      );
      scheduleApplicationStateLog("click", { control: description });
    }, true);

    document.addEventListener("change", (event) => {
      const control = event.target;
      if (!(control instanceof HTMLInputElement || control instanceof HTMLSelectElement || control instanceof HTMLTextAreaElement)) {
        return;
      }
      const description = describeElement(control);
      const value = describeControlValue(control);
      emitLog(
        "actions",
        "USER_CONTROL_CHANGED",
        `Пользователь изменил элемент «${description?.label || control.id || control.name || "без подписи"}».`,
        { control: description, value }
      );
      scheduleApplicationStateLog("change", { control: description, value });
    }, true);

    document.addEventListener("keydown", (event) => {
      const isShortcut = event.ctrlKey || event.metaKey || event.altKey || event.key === "Escape" || event.key === "Delete";
      if (!isShortcut) return;
      const editable = event.target instanceof Element
        ? !!event.target.closest("input, textarea, select, [contenteditable='true']")
        : false;
      emitLog(
        "actions",
        "USER_KEYBOARD_SHORTCUT",
        `Пользователь использовал клавишу или сочетание «${event.key}».`,
        {
          key: event.key,
          code: event.code,
          ctrlKey: event.ctrlKey,
          metaKey: event.metaKey,
          altKey: event.altKey,
          shiftKey: event.shiftKey,
          repeat: event.repeat,
          editableTarget: editable
        },
        "DEBUG"
      );
      scheduleApplicationStateLog("keyboard-shortcut", { key: event.key, code: event.code });
    }, true);
  }

  function installErrorLogging() {
    window.addEventListener("error", (event) => {
      emitLog("errors", "RENDERER_UNCAUGHT_ERROR", "Необработанная ошибка в интерфейсе приложения.", {
        message: event.message,
        filename: event.filename,
        lineNumber: event.lineno,
        columnNumber: event.colno,
        error: serializeError(event.error || event.message)
      }, "ERROR", "renderer-window");
      logApplicationState(
        "APPLICATION_STATE_AT_ERROR",
        "Состояние приложения в момент необработанной ошибки.",
        { error: serializeError(event.error || event.message) },
        "ERROR"
      );
    });

    window.addEventListener("unhandledrejection", (event) => {
      emitLog("errors", "RENDERER_UNHANDLED_REJECTION", "Необработанное отклонение Promise в интерфейсе.", {
        reason: serializeError(event.reason)
      }, "ERROR", "renderer-window");
      logApplicationState(
        "APPLICATION_STATE_AT_ERROR",
        "Состояние приложения в момент необработанного отклонения Promise.",
        { reason: serializeError(event.reason) },
        "ERROR"
      );
    });

    originalConsoleError = console.error.bind(console);
    originalConsoleWarn = console.warn.bind(console);
    console.error = (...args) => {
      emitLog("errors", "CONSOLE_ERROR", "В интерфейсе вызван console.error.", {
        arguments: args.map((arg) => arg instanceof Error ? serializeError(arg) : makeSafeDetails(arg))
      }, "ERROR", "renderer-console");
      originalConsoleError(...args);
    };
    console.warn = (...args) => {
      emitLog("errors", "CONSOLE_WARNING", "В интерфейсе вызван console.warn.", {
        arguments: args.map((arg) => arg instanceof Error ? serializeError(arg) : makeSafeDetails(arg))
      }, "WARN", "renderer-console");
      originalConsoleWarn(...args);
    };
  }

  function installLifecycleLogging() {
    document.addEventListener("visibilitychange", () => {
      emitLog(
        "application",
        "DOCUMENT_VISIBILITY_CHANGED",
        `Видимость интерфейса изменилась: ${document.visibilityState}.`,
        { visibilityState: document.visibilityState },
        "DEBUG"
      );
    });
    window.addEventListener("online", () => {
      emitLog("application", "NETWORK_ONLINE", "Браузерный контекст перешёл в состояние online.", null, "DEBUG");
    });
    window.addEventListener("offline", () => {
      emitLog("application", "NETWORK_OFFLINE", "Браузерный контекст перешёл в состояние offline.", null, "WARN");
    });
    window.addEventListener("beforeunload", () => {
      logApplicationState("FINAL_RENDERER_STATE", "Финальное состояние интерфейса перед выгрузкой.");
      emitLog("application", "RENDERER_UNLOADING", "Интерфейс приложения выгружается.");
    });
  }

  async function initAppLogging() {
    if (initialized) return;
    initialized = true;
    installErrorLogging();
    installInteractionLogging();
    installLifecycleLogging();

    let bridgeInfo = null;
    try {
      bridgeInfo = await globalThis.glyphLogger?.getInfo?.();
      if (globalThis.glyphLogger?.log && fallbackEntries.length) {
        fallbackEntries.splice(0).forEach((entry) => globalThis.glyphLogger.log(entry));
      }
    } catch (error) {
      originalConsoleWarn?.("Glyph Studio file logging bridge is unavailable:", error);
    }

    emitLog("application", "RENDERER_LOGGING_INITIALIZED", "Система логирования интерфейса инициализирована.", {
      loggingBridgeAvailable: !!globalThis.glyphLogger?.log,
      logInfo: bridgeInfo,
      runtime: {
        userAgent: navigator.userAgent,
        language: navigator.language,
        languages: navigator.languages,
        platform: navigator.platform,
        hardwareConcurrency: navigator.hardwareConcurrency,
        deviceMemory: navigator.deviceMemory ?? null,
        touchPoints: navigator.maxTouchPoints,
        screen: {
          width: screen.width,
          height: screen.height,
          availableWidth: screen.availWidth,
          availableHeight: screen.availHeight,
          colorDepth: screen.colorDepth
        }
      }
    });
    logApplicationState("INITIAL_RENDERER_STATE", "Начальное состояние интерфейса после запуска.");
  }

  globalThis.appLogger = Object.freeze({
    log: emitLog,
    action(event, message, details = null, level = "INFO") {
      emitLog("actions", event, message, details, level, "renderer-action");
    },
    file(event, message, details = null, level = "INFO") {
      emitLog("files", event, message, details, level, "renderer-file");
    },
    error(event, message, error, details = null, level = "ERROR") {
      emitLog("errors", event, message, {
        error: serializeError(error),
        details
      }, level, "renderer-error");
    },
    state: logApplicationState,
    scheduleState: scheduleApplicationStateLog,
    collectState: collectApplicationState,
    flush() {
      return globalThis.glyphLogger?.flush?.() ?? Promise.resolve(null);
    }
  });
  globalThis.initAppLogging = initAppLogging;
})();
