const TEMPLATE_TABS_STORAGE_KEY = "willowXml.templateTabs.v1";
const TEMPLATE_TABS_STORAGE_VERSION = 1;
const TEMPLATE_TAB_PERSIST_DELAY_MS = 40;

let tabsState = { tabs: [], activeTabId: null };
let emptyTemplateState = null;
let templateTabRestoreInProgress = false;
let templateTabPersistTimer = null;
let templateTabsResizeObserver = null;
let templateTabsDragState = null;
let templateTabsSuppressClick = false;
let pendingCloseTemplateTabId = null;
let closeTemplateTabAfterSaveId = null;

function cloneTemplateTabValue(value) {
  if (typeof structuredClone === "function") return structuredClone(value);
  return JSON.parse(JSON.stringify(value));
}

function createTemplateTabId() {
  if (globalThis.crypto?.randomUUID) return globalThis.crypto.randomUUID();
  return `template-${Date.now().toString(36)}-${Math.random().toString(36).slice(2, 11)}`;
}

function normalizeTemplateTabTitle(value, fallback = t("tabs.untitled")) {
  const raw = String(value ?? "").trim().replace(/^.*[\\/]/, "");
  const withoutExtension = raw.replace(/\.(ciff|xml)$/i, "").trim();
  return withoutExtension || fallback;
}

function getNextUntitledTemplateTitle() {
  const base = t("tabs.untitled");
  const used = new Set(tabsState.tabs.map((tab) => tab.title));
  if (!used.has(base)) return base;
  let index = 2;
  while (used.has(`${base} ${index}`)) index += 1;
  return `${base} ${index}`;
}

function getActiveTemplateTab() {
  return tabsState.tabs.find((tab) => tab.id === tabsState.activeTabId) ?? null;
}

function createCurrentTemplateContentFingerprint() {
  if (!state.xmlDoc || !state.line1 || !state.line2) return "__empty_template__";
  const editorState = JSON.parse(snapshotState());
  delete editorState.selectedName;
  delete editorState.selectedNames;
  delete editorState.showHiddenOnCanvas;
  delete editorState.validation;
  return JSON.stringify({
    line1: state.line1,
    line2: state.line2,
    editorState
  });
}

function captureCurrentTemplateView() {
  return {
    zoomPct: Number.isFinite(Number(zoomPct)) ? Number(zoomPct) : 100,
    stageX: stage ? Number(stage.x()) : 20,
    stageY: stage ? Number(stage.y()) : 20,
    gridMm: GRID_SIZE_OPTIONS.includes(Number(state.gridMm)) ? Number(state.gridMm) : GRID_MM,
    gridEnabled: !!elToggleGrid?.checked,
    snapEnabled: !!elToggleSnap?.checked,
    alignEnabled: !!elToggleAlign?.checked,
    mobilePanMode: !!isMobilePanMode
  };
}

function captureCurrentTemplateState() {
  return {
    raw: {
      xmlText: state.xmlText ?? "",
      line1: state.line1 ?? "",
      line2: state.line2 ?? "",
      lineEnding: state.lineEnding ?? "\r\n"
    },
    editorSnapshot: snapshotState(),
    history: {
      undo: Array.isArray(history.undo) ? history.undo.slice() : [],
      redo: Array.isArray(history.redo) ? history.redo.slice() : []
    },
    view: captureCurrentTemplateView()
  };
}

function captureActiveTemplateTab() {
  if (templateTabRestoreInProgress) return null;
  const tab = getActiveTemplateTab();
  if (!tab) return null;

  tab.templateState = captureCurrentTemplateState();
  const fingerprint = createCurrentTemplateContentFingerprint();
  tab.isDirty = tab.savedFingerprint == null
    ? fingerprint !== "__empty_template__"
    : fingerprint !== tab.savedFingerprint;
  return tab;
}

function parseTemplateTabXmlDocument(raw) {
  const line1 = String(raw?.line1 ?? "");
  const line2 = String(raw?.line2 ?? "");
  if (!line1 || !line2) return null;
  const doc = new DOMParser().parseFromString(`${line1}\n${line2}`, "text/xml");
  return doc.querySelector("parsererror") ? null : doc;
}

function restoreTemplateTabState(tab) {
  if (!tab?.templateState) return false;
  if (typeof clearPendingCanvasPlacement === "function") {
    clearPendingCanvasPlacement({ restoreStatus: false });
  }
  templateTabRestoreInProgress = true;

  try {
    const templateState = cloneTemplateTabValue(tab.templateState);
    const raw = templateState.raw ?? {};
    state.xmlText = String(raw.xmlText ?? "");
    state.line1 = String(raw.line1 ?? "");
    state.line2 = String(raw.line2 ?? "");
    state.lineEnding = String(raw.lineEnding ?? "\r\n");
    state.xmlDoc = parseTemplateTabXmlDocument(raw);

    restoreFromSnapshot(templateState.editorSnapshot, { render: false });
    history = {
      undo: Array.isArray(templateState.history?.undo) ? templateState.history.undo.slice() : [snapshotState()],
      redo: Array.isArray(templateState.history?.redo) ? templateState.history.redo.slice() : []
    };
    if (!history.undo.length) history.undo = [snapshotState()];

    const view = templateState.view ?? {};
    state.gridMm = GRID_SIZE_OPTIONS.includes(Number(view.gridMm)) ? Number(view.gridMm) : GRID_MM;
    if (elGridSizeSelect) {
      elGridSizeSelect.value = String(state.gridMm);
      if (typeof syncCustomSelectControl === "function") syncCustomSelectControl(elGridSizeSelect);
    }
    if (elToggleGrid) elToggleGrid.checked = view.gridEnabled !== false;
    if (elToggleSnap) elToggleSnap.checked = view.snapEnabled !== false;
    if (elToggleAlign) elToggleAlign.checked = !!view.alignEnabled;

    zoomPct = clamp(25, 400, Number(view.zoomPct) || 100);
    if (elZoomRange) elZoomRange.value = String(zoomPct);
    if (elZoomLabel) elZoomLabel.textContent = `${zoomPct}%`;
    if (stage) {
      stage.position({
        x: Number.isFinite(Number(view.stageX)) ? Number(view.stageX) : 20,
        y: Number.isFinite(Number(view.stageY)) ? Number(view.stageY) : 20
      });
    }
    setMobilePanMode(!!view.mobilePanMode);

    renderAll();
    updateUndoRedoButtons();
    if (!state.xmlDoc && elStatusLeft) elStatusLeft.textContent = t("status.noTemplate");
    return true;
  } catch (error) {
    console.error("Failed to restore template tab:", error);
    appLogger.error("TEMPLATE_TAB_RESTORE_FAILED", "Не удалось восстановить состояние вкладки шаблона.", error, {
      tabId: tab?.id || null,
      title: tab?.title || null
    });
    return false;
  } finally {
    templateTabRestoreInProgress = false;
  }
}

function createEmptyTemplateTabState() {
  return cloneTemplateTabValue(emptyTemplateState ?? captureCurrentTemplateState());
}

function createTemplateTabRecord(title = getNextUntitledTemplateTitle()) {
  const id = createTemplateTabId();
  return {
    id,
    templateId: id,
    title: normalizeTemplateTabTitle(title),
    templateState: createEmptyTemplateTabState(),
    isDirty: false,
    savedFingerprint: "__empty_template__"
  };
}

function ensureActiveTemplateTabVisible() {
  if (!elTemplateTabsList) return;
  const activeElement = elTemplateTabsList.querySelector(".templateTab.is-active");
  if (!activeElement) return;

  const listRect = elTemplateTabsList.getBoundingClientRect();
  const activeRect = activeElement.getBoundingClientRect();

  if (activeRect.left < listRect.left) {
    elTemplateTabsList.scrollLeft = Math.max(
      0,
      elTemplateTabsList.scrollLeft - (listRect.left - activeRect.left)
    );
  } else if (activeRect.right > listRect.right) {
    elTemplateTabsList.scrollLeft += activeRect.right - listRect.right;
  }
}

function updateTemplateTabsScrollTail() {
  if (!elTemplateTabsList) return;
  const tail = elTemplateTabsList.querySelector(".templateTabs__scrollTail");
  const tabElements = [...elTemplateTabsList.querySelectorAll(".templateTab")];
  if (!tail || !tabElements.length) return;

  const styles = getComputedStyle(elTemplateTabsList);
  const gap = Number.parseFloat(styles.columnGap || styles.gap) || 0;
  const tabsWidth = tabElements.reduce((total, tab) => total + tab.getBoundingClientRect().width, 0)
    + gap * Math.max(0, tabElements.length - 1);

  if (tabsWidth <= elTemplateTabsList.clientWidth) {
    tail.hidden = true;
    tail.style.flexBasis = "0px";
    return;
  }

  const lastTabWidth = tabElements.at(-1)?.getBoundingClientRect().width ?? 0;
  tail.hidden = false;
  tail.style.flexBasis = `${Math.max(0, elTemplateTabsList.clientWidth - lastTabWidth - gap)}px`;
}

function snapTemplateTabsToNearestBoundary() {
  if (!elTemplateTabsList) return;
  const listRect = elTemplateTabsList.getBoundingClientRect();
  const currentScrollLeft = elTemplateTabsList.scrollLeft;
  const targets = [...elTemplateTabsList.querySelectorAll(".templateTab")].map((tab) => (
    currentScrollLeft + tab.getBoundingClientRect().left - listRect.left
  ));
  if (!targets.length) return;

  const nearestTarget = targets.reduce((nearest, target) => (
    Math.abs(target - currentScrollLeft) < Math.abs(nearest - currentScrollLeft) ? target : nearest
  ));
  elTemplateTabsList.scrollLeft = clamp(
    0,
    Math.max(0, elTemplateTabsList.scrollWidth - elTemplateTabsList.clientWidth),
    nearestTarget
  );
}

function finishTemplateTabsDrag({ snap = true } = {}) {
  if (!templateTabsDragState) return;
  const wasDragging = templateTabsDragState.isDragging;
  templateTabsDragState = null;
  elTemplateTabsList?.classList.remove("is-dragging");

  if (wasDragging) {
    if (snap) snapTemplateTabsToNearestBoundary();
    templateTabsSuppressClick = true;
    window.setTimeout(() => {
      templateTabsSuppressClick = false;
    }, 0);
  }
}

function initTemplateTabsMouseDrag() {
  if (!elTemplateTabsList) return;

  elTemplateTabsList.addEventListener("pointerdown", (event) => {
    if (event.pointerType !== "mouse" || event.button !== 0) return;
    if (!event.target.closest(".templateTab")) return;
    templateTabsDragState = {
      pointerId: event.pointerId,
      startX: event.clientX,
      startScrollLeft: elTemplateTabsList.scrollLeft,
      isDragging: false
    };
  });

  window.addEventListener("pointermove", (event) => {
    const drag = templateTabsDragState;
    if (!drag || event.pointerId !== drag.pointerId) return;
    const deltaX = event.clientX - drag.startX;
    if (!drag.isDragging && Math.abs(deltaX) < 5) return;

    if (!drag.isDragging) {
      drag.isDragging = true;
      elTemplateTabsList.classList.add("is-dragging");
    }
    event.preventDefault();
    elTemplateTabsList.scrollLeft = drag.startScrollLeft - deltaX;
  }, { passive: false });

  window.addEventListener("pointerup", (event) => {
    if (templateTabsDragState?.pointerId !== event.pointerId) return;
    finishTemplateTabsDrag();
  });
  window.addEventListener("pointercancel", (event) => {
    if (templateTabsDragState?.pointerId !== event.pointerId) return;
    finishTemplateTabsDrag();
  });
  window.addEventListener("blur", () => finishTemplateTabsDrag());

  elTemplateTabsList.addEventListener("click", (event) => {
    if (!templateTabsSuppressClick) return;
    event.preventDefault();
    event.stopImmediatePropagation();
    templateTabsSuppressClick = false;
  }, true);
  elTemplateTabsList.addEventListener("dragstart", (event) => {
    if (event.target.closest(".templateTab")) event.preventDefault();
  });
}

function updateCloseTemplateTabModalContent() {
  if (!pendingCloseTemplateTabId) return;
  const tab = tabsState.tabs.find((item) => item.id === pendingCloseTemplateTabId);
  if (!tab) return;
  if (elCloseTabModalTitle) {
    elCloseTabModalTitle.textContent = t("dialog.closeTab.title", { title: tab.title });
  }
  if (elCloseTabModalMessage) {
    elCloseTabModalMessage.textContent = t("dialog.closeTab.message");
  }
}

function closeTemplateTabWarningModal() {
  if (!elCloseTabModal) return;
  pendingCloseTemplateTabId = null;
  elCloseTabModal.classList.add("hidden");
  elCloseTabModal.setAttribute("aria-hidden", "true");
  document.body.classList.toggle("modal-open", Boolean(document.querySelector(".modal:not(.hidden)")));
}

function openTemplateTabWarningModal(tabId) {
  const tab = tabsState.tabs.find((item) => item.id === tabId);
  if (!tab || !elCloseTabModal) return false;
  pendingCloseTemplateTabId = tab.id;
  updateCloseTemplateTabModalContent();
  elCloseTabModal.classList.remove("hidden");
  elCloseTabModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  window.setTimeout(() => elBtnSaveAndCloseTab?.focus(), 0);
  return true;
}

function requestCloseTemplateTab(tabId) {
  const tab = tabsState.tabs.find((item) => item.id === tabId);
  if (!tab) return false;
  if (tab.id === tabsState.activeTabId) captureActiveTemplateTab();
  if (!tab.isDirty) return closeTemplateTab(tab.id);
  return openTemplateTabWarningModal(tab.id);
}

function closePendingTemplateTabWithoutSaving() {
  const tabId = pendingCloseTemplateTabId;
  closeTemplateTabWarningModal();
  if (tabId) closeTemplateTab(tabId);
}

function saveAndClosePendingTemplateTab() {
  const tabId = pendingCloseTemplateTabId;
  if (!tabId) return;
  closeTemplateTabWarningModal();

  if (tabsState.activeTabId !== tabId && !switchTemplateTab(tabId)) return;
  closeTemplateTabAfterSaveId = tabId;
  if (!openSaveTemplateModal()) closeTemplateTabAfterSaveId = null;
}

function cancelPendingTemplateTabCloseAfterSave() {
  closeTemplateTabAfterSaveId = null;
}

function renderTemplateTabs() {
  if (!elTemplateTabsList) return;
  elTemplateTabsList.innerHTML = "";

  tabsState.tabs.forEach((tab) => {
    const item = document.createElement("div");
    item.className = `templateTab${tab.id === tabsState.activeTabId ? " is-active" : ""}`;
    item.dataset.templateTabId = tab.id;

    const activate = document.createElement("button");
    activate.type = "button";
    activate.className = "templateTab__activate";
    activate.setAttribute("role", "tab");
    activate.setAttribute("aria-selected", String(tab.id === tabsState.activeTabId));
    activate.title = tab.title;

    const title = document.createElement("span");
    title.className = "templateTab__title";
    title.textContent = tab.title;
    activate.appendChild(title);

    if (tab.isDirty) {
      const dirty = document.createElement("span");
      dirty.className = "templateTab__dirty";
      dirty.title = t("tabs.unsaved");
      dirty.setAttribute("aria-label", t("tabs.unsaved"));
      activate.appendChild(dirty);
    }

    activate.addEventListener("click", () => switchTemplateTab(tab.id));

    const close = document.createElement("button");
    close.type = "button";
    close.className = "templateTab__close";
    close.setAttribute("aria-label", t("tabs.close", { title: tab.title }));
    close.title = t("tabs.close", { title: tab.title });
    close.innerHTML = `
      <svg class="templateTab__closeIcon" viewBox="0 -960 960 960" aria-hidden="true" focusable="false">
        <path d="m256-200-56-56 224-224-224-224 56-56 224 224 224-224 56 56-224 224 224 224-56 56-224-224-224 224Z"></path>
      </svg>
    `;
    close.addEventListener("click", (event) => {
      event.stopPropagation();
      requestCloseTemplateTab(tab.id);
    });

    item.appendChild(activate);
    item.appendChild(close);
    elTemplateTabsList.appendChild(item);
  });

  const scrollTail = document.createElement("span");
  scrollTail.className = "templateTabs__scrollTail";
  scrollTail.setAttribute("aria-hidden", "true");
  elTemplateTabsList.appendChild(scrollTail);

  updateTemplateTabsScrollTail();
  ensureActiveTemplateTabVisible();
}

function writeTemplateTabsToStorage() {
  if (templateTabRestoreInProgress) return;
  try {
    const payload = {
      version: TEMPLATE_TABS_STORAGE_VERSION,
      activeTabId: tabsState.activeTabId,
      tabs: tabsState.tabs
    };
    globalThis.localStorage?.setItem(TEMPLATE_TABS_STORAGE_KEY, JSON.stringify(payload));
  } catch (error) {
    console.warn("Unable to persist template tabs:", error);
    appLogger.error("TEMPLATE_TABS_PERSIST_FAILED", "Не удалось сохранить состояние вкладок в локальное хранилище.", error, {
      activeTabId: tabsState.activeTabId,
      tabCount: tabsState.tabs.length
    }, "WARN");
  }
}

function persistTemplateTabsNow(options = {}) {
  if (templateTabPersistTimer) {
    clearTimeout(templateTabPersistTimer);
    templateTabPersistTimer = null;
  }
  if (options.capture !== false) captureActiveTemplateTab();
  renderTemplateTabs();
  writeTemplateTabsToStorage();
}

function schedulePersistActiveTemplateTab() {
  if (templateTabRestoreInProgress || !tabsState.activeTabId) return;
  if (templateTabPersistTimer) clearTimeout(templateTabPersistTimer);
  templateTabPersistTimer = window.setTimeout(() => persistTemplateTabsNow(), TEMPLATE_TAB_PERSIST_DELAY_MS);
}

function markActiveTemplateTabDirty() {
  if (templateTabRestoreInProgress) return;
  const tab = getActiveTemplateTab();
  if (!tab) return;
  if (!tab.isDirty) {
    tab.isDirty = true;
    renderTemplateTabs();
  }
  schedulePersistActiveTemplateTab();
}

function switchTemplateTab(tabId) {
  if (!tabId || tabId === tabsState.activeTabId) return true;
  const nextTab = tabsState.tabs.find((tab) => tab.id === tabId);
  if (!nextTab) return false;

  const previousTab = getActiveTemplateTab();
  captureActiveTemplateTab();
  tabsState.activeTabId = nextTab.id;
  if (!restoreTemplateTabState(nextTab)) return false;
  persistTemplateTabsNow({ capture: false });
  appLogger.action("TEMPLATE_TAB_SWITCHED", "Пользователь переключил активную вкладку шаблона.", {
    previous: previousTab ? { id: previousTab.id, title: previousTab.title, dirty: !!previousTab.isDirty } : null,
    next: { id: nextTab.id, title: nextTab.title, dirty: !!nextTab.isDirty },
    tabCount: tabsState.tabs.length
  });
  appLogger.state("APPLICATION_STATE_AFTER_TAB_SWITCH", "Состояние после переключения вкладки.");
  return true;
}

function closeTemplateTab(tabId) {
  const index = tabsState.tabs.findIndex((tab) => tab.id === tabId);
  if (index < 0) return false;
  const closingTab = tabsState.tabs[index];
  const wasActive = tabId === tabsState.activeTabId;
  captureActiveTemplateTab();
  tabsState.tabs.splice(index, 1);

  if (!tabsState.tabs.length) {
    const replacement = createTemplateTabRecord();
    tabsState.tabs.push(replacement);
    tabsState.activeTabId = replacement.id;
    restoreTemplateTabState(replacement);
  } else if (wasActive) {
    const nextTab = tabsState.tabs[Math.min(index, tabsState.tabs.length - 1)];
    tabsState.activeTabId = nextTab.id;
    restoreTemplateTabState(nextTab);
  }

  persistTemplateTabsNow({ capture: false });
  appLogger.action("TEMPLATE_TAB_CLOSED", "Вкладка шаблона закрыта.", {
    closed: {
      id: closingTab.id,
      title: closingTab.title,
      dirty: !!closingTab.isDirty,
      wasActive
    },
    nextActiveTabId: tabsState.activeTabId,
    remainingTabCount: tabsState.tabs.length
  });
  appLogger.state("APPLICATION_STATE_AFTER_TAB_CLOSE", "Состояние после закрытия вкладки.");
  return true;
}

function isReusableEmptyTemplateTab(tab) {
  return !!tab && !state.xmlDoc && !tab.isDirty && tabsState.tabs.length === 1;
}

function createTemplateInNewTab(xmlText, title, options = {}) {
  captureActiveTemplateTab();
  const previousActiveId = tabsState.activeTabId;
  const previousTabsLength = tabsState.tabs.length;
  let tab = getActiveTemplateTab();
  const reuseActive = options.reuseEmpty !== false && isReusableEmptyTemplateTab(tab);

  if (!reuseActive) {
    tab = createTemplateTabRecord(title || getNextUntitledTemplateTitle());
    tabsState.tabs.push(tab);
    tabsState.activeTabId = tab.id;
    restoreTemplateTabState(tab);
  } else if (title) {
    tab.title = normalizeTemplateTabTitle(title);
  }

  const loaded = loadXml(xmlText, {
    title: title || tab.title,
    markDirty: options.markDirty !== false,
    source: options.source || "new-tab"
  });
  if (loaded) {
    appLogger.action("TEMPLATE_TAB_CREATED", reuseActive
      ? "Пустая вкладка использована для нового шаблона."
      : "Для шаблона создана новая вкладка.", {
      tabId: tab.id,
      title: tab.title,
      source: options.source || "new-tab",
      reusedEmptyTab: reuseActive,
      tabCount: tabsState.tabs.length
    });
    return tab;
  }

  if (!reuseActive && tabsState.tabs.length > previousTabsLength) {
    tabsState.tabs = tabsState.tabs.filter((item) => item.id !== tab.id);
    tabsState.activeTabId = previousActiveId;
    const previousTab = getActiveTemplateTab();
    if (previousTab) restoreTemplateTabState(previousTab);
  }
  renderTemplateTabs();
  return null;
}

function openXmlInNewTemplateTab(xmlText, filename) {
  return createTemplateInNewTab(xmlText, normalizeTemplateTabTitle(filename), {
    markDirty: false,
    source: "file"
  });
}

function onTemplateLoadedIntoActiveTab(options = {}) {
  const tab = getActiveTemplateTab();
  if (!tab || templateTabRestoreInProgress) return;
  if (options.title) tab.title = normalizeTemplateTabTitle(options.title, tab.title);
  tab.templateState = captureCurrentTemplateState();
  const fingerprint = createCurrentTemplateContentFingerprint();
  if (options.markDirty) {
    tab.savedFingerprint = null;
    tab.isDirty = true;
  } else {
    tab.savedFingerprint = fingerprint;
    tab.isDirty = false;
  }
  persistTemplateTabsNow({ capture: false });
}

function markActiveTemplateTabSaved(filename) {
  const tab = getActiveTemplateTab();
  if (!tab) return;
  if (filename) tab.title = normalizeTemplateTabTitle(filename, tab.title);
  tab.savedFingerprint = createCurrentTemplateContentFingerprint();
  tab.isDirty = false;
  appLogger.file("TEMPLATE_TAB_MARKED_SAVED", "Активная вкладка отмечена как сохранённая.", {
    tabId: tab.id,
    title: tab.title,
    filename: filename || null
  });
  persistTemplateTabsNow();
  if (closeTemplateTabAfterSaveId === tab.id) {
    closeTemplateTabAfterSaveId = null;
    closeTemplateTab(tab.id);
  }
}

function getActiveTemplateTabSaveName() {
  return getActiveTemplateTab()?.title ?? "";
}

function restoreTemplateTabsFromStorage() {
  try {
    const raw = globalThis.localStorage?.getItem(TEMPLATE_TABS_STORAGE_KEY);
    if (!raw) return false;
    const stored = JSON.parse(raw);
    if (stored?.version !== TEMPLATE_TABS_STORAGE_VERSION || !Array.isArray(stored.tabs)) return false;

    const tabs = stored.tabs.filter((tab) => (
      tab && typeof tab.id === "string" && typeof tab.title === "string" &&
      tab.templateState && typeof tab.templateState.editorSnapshot === "string"
    )).map((tab) => ({
      id: tab.id,
      templateId: typeof tab.templateId === "string" ? tab.templateId : tab.id,
      title: normalizeTemplateTabTitle(tab.title),
      templateState: cloneTemplateTabValue(tab.templateState),
      isDirty: !!tab.isDirty,
      savedFingerprint: typeof tab.savedFingerprint === "string" ? tab.savedFingerprint : null
    }));
    if (!tabs.length) return false;

    tabsState.tabs = tabs;
    tabsState.activeTabId = tabs.some((tab) => tab.id === stored.activeTabId)
      ? stored.activeTabId
      : tabs[0].id;
    const activeTab = getActiveTemplateTab();
    const restored = restoreTemplateTabState(activeTab);
    if (restored) {
      appLogger.log("application", "TEMPLATE_TABS_RESTORED", "Вкладки восстановлены из локального хранилища.", {
        activeTabId: tabsState.activeTabId,
        tabCount: tabsState.tabs.length,
        tabs: tabsState.tabs.map((tab) => ({
          id: tab.id,
          title: tab.title,
          dirty: !!tab.isDirty
        }))
      });
    }
    return restored;
  } catch (error) {
    console.warn("Unable to restore template tabs:", error);
    appLogger.error("TEMPLATE_TABS_RESTORE_FAILED", "Не удалось восстановить вкладки из локального хранилища.", error);
    return false;
  }
}

function initTemplateTabs() {
  emptyTemplateState = captureCurrentTemplateState();
  if (!emptyTemplateState.history.undo.length) {
    emptyTemplateState.history.undo = [emptyTemplateState.editorSnapshot];
  }

  elBtnAddTemplateTab?.addEventListener("click", () => openNewTemplateModal());
  initTemplateTabsMouseDrag();
  elBtnCancelCloseTab?.addEventListener("click", () => closeTemplateTabWarningModal());
  elBtnCloseTabWithoutSaving?.addEventListener("click", () => closePendingTemplateTabWithoutSaving());
  elBtnSaveAndCloseTab?.addEventListener("click", () => saveAndClosePendingTemplateTab());
  elCloseTabModal?.addEventListener("click", (event) => {
    if (event.target?.dataset?.closeTabCancel === "1") closeTemplateTabWarningModal();
  });
  window.addEventListener("keydown", (event) => {
    if (event.key === "Escape" && elCloseTabModal && !elCloseTabModal.classList.contains("hidden")) {
      closeTemplateTabWarningModal();
    }
  });
  if (typeof onUiLanguageChange === "function") {
    onUiLanguageChange(() => {
      renderTemplateTabs();
      updateCloseTemplateTabModalContent();
    });
  }

  if (!restoreTemplateTabsFromStorage()) {
    const initialTab = createTemplateTabRecord();
    tabsState.tabs = [initialTab];
    tabsState.activeTabId = initialTab.id;
    restoreTemplateTabState(initialTab);
    appLogger.log("application", "INITIAL_EMPTY_TAB_CREATED", "Создана начальная пустая вкладка шаблона.", {
      tabId: initialTab.id,
      title: initialTab.title
    });
  }

  renderTemplateTabs();
  if (typeof ResizeObserver === "function") {
    templateTabsResizeObserver?.disconnect();
    templateTabsResizeObserver = new ResizeObserver(() => {
      updateTemplateTabsScrollTail();
      ensureActiveTemplateTabVisible();
    });
    templateTabsResizeObserver.observe(elTemplateTabsList);
  }
  writeTemplateTabsToStorage();
  window.addEventListener("beforeunload", () => persistTemplateTabsNow());
}

function getTemplateTabsState() {
  captureActiveTemplateTab();
  return cloneTemplateTabValue(tabsState);
}

globalThis.initTemplateTabs = initTemplateTabs;
globalThis.getTemplateTabsState = getTemplateTabsState;
globalThis.switchTemplateTab = switchTemplateTab;
globalThis.closeTemplateTab = closeTemplateTab;
globalThis.requestCloseTemplateTab = requestCloseTemplateTab;
globalThis.createTemplateInNewTab = createTemplateInNewTab;
globalThis.openXmlInNewTemplateTab = openXmlInNewTemplateTab;
globalThis.schedulePersistActiveTemplateTab = schedulePersistActiveTemplateTab;
globalThis.markActiveTemplateTabDirty = markActiveTemplateTabDirty;
globalThis.onTemplateLoadedIntoActiveTab = onTemplateLoadedIntoActiveTab;
globalThis.markActiveTemplateTabSaved = markActiveTemplateTabSaved;
globalThis.getActiveTemplateTabSaveName = getActiveTemplateTabSaveName;
globalThis.cancelPendingTemplateTabCloseAfterSave = cancelPendingTemplateTabCloseAfterSave;
