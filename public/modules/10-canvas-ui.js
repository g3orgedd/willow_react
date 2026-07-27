const Konva = window.Konva;

const PRECISION_MOVE_REPEAT_DELAY_MS = 320;
const PRECISION_MOVE_REPEAT_INTERVAL_MS = 72;
let notificationModalCloseHandler = null;
let confirmationModalConfirmHandler = null;
let confirmationModalCancelHandler = null;

function isEditableEventTarget(target) {
  const element = target instanceof Element ? target : null;
  if (!element) return false;
  return !!element.closest("input, textarea, select, [contenteditable='true']");
}

function initCanvas() {
  const rect = elCanvasHost.getBoundingClientRect();

  stage = new Konva.Stage({
    container: "canvasHost",
    width: rect.width,
    height: rect.height,
    draggable: false
  });

  gridLayer = new Konva.Layer({ listening: false });
  objLayer = new Konva.Layer();
  uiLayer = new Konva.Layer();

  stage.add(gridLayer);
  stage.add(objLayer);
  stage.add(uiLayer);

  transformer = new Konva.Transformer({
    rotateEnabled: false,
    ignoreStroke: true,
    boundBoxFunc: (oldBox, newBox) => {
      if (newBox.width < 5 || newBox.height < 5) return oldBox;
      return newBox;
    }
  });
  selectionRect = new Konva.Rect({
    visible: false,
    listening: false,
    fill: "rgba(106,168,255,0.18)",
    stroke: "rgba(106,168,255,0.75)",
    strokeWidth: 1,
    dash: [4, 4]
  });
  alignmentGuideGroup = new Konva.Group({
    name: "AlignmentGuides",
    visible: false,
    listening: false
  });
  uiLayer.add(alignmentGuideGroup);
  uiLayer.add(selectionRect);
  uiLayer.add(transformer);

  stage.on("mousedown", (e) => {
    if ((e.evt?.button ?? 0) !== 0) return;
    if (tryCommitPendingCanvasPlacement(e, "mouse")) return;
    if (isSpaceDown || isMobilePanMode) {
      startStagePan(e, { cancelBubble: isMobilePanMode, preventDefault: isMobilePanMode });
      return;
    }
    if (e.target === stage) {
      const p = getStageLocalPointerPosition();
      if (!p) return;
      isSelectionBoxActive = true;
      selectionBoxAdditive = !!e.evt.shiftKey;
      selectionStart = p;
      selectionRect.setAttrs({ x: p.x, y: p.y, width: 0, height: 0, visible: true });
      uiLayer.batchDraw();
    }
  });

  stage.on("mousemove", () => {
    const p = stage.getPointerPosition();
    if (!p) return;

    if (isPanning && panStart) {
      updateStagePan();
      return;
    }

    if (isSelectionBoxActive && selectionStart) {
      const local = getStageLocalPointerPosition();
      if (!local) return;
      selectionRect.setAttrs({
        x: Math.min(selectionStart.x, local.x),
        y: Math.min(selectionStart.y, local.y),
        width: Math.abs(local.x - selectionStart.x),
        height: Math.abs(local.y - selectionStart.y),
        visible: true
      });
      uiLayer.batchDraw();
      return;
    }

    const mm = pxToMmWorld(p.x, p.y);
    elStatusRight.textContent = `Cursor: X = ${mm.x.toFixed(2)} mm  Y = ${mm.y.toFixed(2)} mm`;
  });

  stage.on("mouseup", () => {
    if (isSelectionBoxActive) {
      const box = selectionRect.getClientRect({ relativeTo: uiLayer });
      const hasArea = box.width > 3 && box.height > 3;
      selectionRect.visible(false);

      if (hasArea) {
        const nextNames = selectionBoxAdditive ? getSelectedNames().slice() : [];
        state.fields.forEach((field) => {
          if (!field._konva) return;
          const fieldRect = field._konva.getClientRect({ relativeTo: objLayer });
          if (!rectsIntersect(box, fieldRect)) return;
          if (!nextNames.includes(field.name)) nextNames.push(field.name);
        });
        setSelectedNames(nextNames, nextNames[nextNames.length - 1] ?? null);
        renderSelectionPanels();
        renderFieldLists();
        renderUI();
      } else if (!selectionBoxAdditive) {
        setSelectedNames([]);
        renderSelectionPanels();
        renderFieldLists();
        renderUI();
      }

      isSelectionBoxActive = false;
      selectionStart = null;
      selectionBoxAdditive = false;
      uiLayer.batchDraw();
    }

    stopStagePan();
  });

  stage.on("touchstart", (e) => {
    if (tryCommitPendingCanvasPlacement(e, "touch")) return;
    if (!isMobilePanMode) return;
    const touches = e.evt?.touches;
    if (touches && touches.length !== 1) return;
    startStagePan(e, { cancelBubble: true, preventDefault: true });
  });

  stage.on("touchmove", (e) => {
    if (!isMobilePanMode || !isPanning) return;
    updateStagePan(e, { cancelBubble: true, preventDefault: true });
  });

  stage.on("touchend touchcancel", (e) => {
    if (!isMobilePanMode || !isPanning) return;
    cancelStagePanEvent(e, { cancelBubble: true, preventDefault: true });
    stopStagePan();
  });

  elCanvasHost.addEventListener("wheel", (ev) => {
    if (!ev.ctrlKey) return;
    ev.preventDefault();
    const delta = -ev.deltaY;
    const step = delta > 0 ? 10 : -10;
    setZoom(clamp(25, 400, zoomPct + step));
  }, { passive: false });

  window.addEventListener("resize", () => {
    const r = elCanvasHost.getBoundingClientRect();
    stage.size({ width: r.width, height: r.height });
    stage.batchDraw();
    renderRulers();
  });

  window.addEventListener("keydown", (e) => {
    if (e.key === "Escape" && pendingCanvasPlacement) {
      e.preventDefault();
      clearPendingCanvasPlacement();
      return;
    }
    if (isEditableEventTarget(e.target)) {
      if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === "s") {
        e.preventDefault();
        if (elSaveTemplateModal && !elSaveTemplateModal.classList.contains("hidden")) {
          saveTemplateFromDialog();
        } else {
          openSaveTemplateModal();
        }
      }
      return;
    }
    if (e.code === "Space") isSpaceDown = true;
    if (e.key === "Delete") deleteSelected();
    if (matchesPrimaryShortcut(e, "KeyZ", "z")) { e.preventDefault(); undo(); }
    if (matchesPrimaryShortcut(e, "KeyY", "y")) { e.preventDefault(); redo(); }
    if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === "s") {
      e.preventDefault();
      if (elSaveTemplateModal && !elSaveTemplateModal.classList.contains("hidden")) {
        saveTemplateFromDialog();
      } else {
        openSaveTemplateModal();
      }
    }
  });
  window.addEventListener("keyup", (e) => { if (e.code === "Space") { isSpaceDown = false; stopStagePan(); } });
  window.addEventListener("blur", () => { isSpaceDown = false; stopStagePan(); });

  // Transformer transformend => apply resize to internal geometry
  transformer.on("transformend", () => {
    const selectedFields = getSelectedFields().filter((field) => field._konva);
    if (!selectedFields.length) return;
    const before = selectedFields.map((field) => ({
      name: field.name,
      geometry: { ...field.geom }
    }));

    pushHistory();

    selectedFields.forEach((field) => {
      const group = field._konva;
      const rect = group.findOne("Rect");
      if (!rect) return;

      const scaleX = group.scaleX();
      const scaleY = group.scaleY();

      let newW = Math.max(5, rect.width() * scaleX);
      let newH = Math.max(5, rect.height() * scaleY);

      group.scaleX(1);
      group.scaleY(1);

      if (field.fldType === "Barcode" && field.barcode?.dataMatrix) {
        const nextModuleSize = getNearestDataMatrixModuleSizeForGeom(field, newW, newH);
        field.barcode.dataMatrix.moduleSize = nextModuleSize;
        const syncedSize = getDataMatrixFieldSizeMm(field, nextModuleSize);
        if (syncedSize) {
          newW = mmToPx(syncedSize.w);
          newH = mmToPx(syncedSize.h);
        }
      }

      rect.width(newW);
      rect.height(newH);

      const label = group.findOne("Text");
      if (label) {
        label.width(Math.max(0, newW - 12));
        label.height(Math.max(0, newH - 8));
      }

      const geomNew = pxGeomToInternal(group.x(), group.y(), newW, newH);
      field.geom.x = geomNew.x;
      field.geom.y = geomNew.y;
      field.geom.w = geomNew.w;
      field.geom.h = geomNew.h;
      if (field.fldType === "Barcode" && field.barcode) field.barcode.bcH = geomNew.h;
    });

    renderAll();
    appLogger.action("FIELDS_RESIZED", "Пользователь изменил размер выбранных объектов.", {
      before,
      after: selectedFields.map((field) => ({
        name: field.name,
        geometry: { ...field.geom }
      }))
    });
    appLogger.state("APPLICATION_STATE_AFTER_RESIZE", "Состояние после изменения размеров объектов.");
  });
}

function matchesPrimaryShortcut(e, code, key) {
  if (!(e.ctrlKey || e.metaKey) || e.shiftKey || e.altKey) return false;

  // KeyboardEvent.code is based on the physical key and does not depend on
  // the active keyboard layout. Keep event.key as a fallback for older paths.
  return e.code === code || String(e.key || "").toLowerCase() === key;
}

function cancelStagePanEvent(e, options = {}) {
  if (options.cancelBubble && e) e.cancelBubble = true;
  if (options.preventDefault && e?.evt?.cancelable) e.evt.preventDefault();
}

function startStagePan(e, options = {}) {
  cancelStagePanEvent(e, options);
  const p = stage.getPointerPosition();
  if (!p) return;

  if (isSelectionBoxActive) {
    isSelectionBoxActive = false;
    selectionStart = null;
    selectionBoxAdditive = false;
    selectionRect.visible(false);
    uiLayer.batchDraw();
  }

  clearAlignmentGuides();
  isPanning = true;
  panStart = { x: stage.x(), y: stage.y(), px: p.x, py: p.y };
  elCanvasHost?.classList.add("canvasHost--panning");
}

function updateStagePan(e, options = {}) {
  cancelStagePanEvent(e, options);
  const p = stage.getPointerPosition();
  if (!p || !panStart) return;

  const dx = p.x - panStart.px;
  const dy = p.y - panStart.py;
  stage.position({ x: panStart.x + dx, y: panStart.y + dy });
  stage.batchDraw();
  renderRulers();
}

function stopStagePan() {
  const didPan = !!isPanning;
  isPanning = false;
  panStart = null;
  elCanvasHost?.classList.remove("canvasHost--panning");
  if (didPan && typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
}

function isMobilePanControlAvailable() {
  return !window.matchMedia || window.matchMedia("(max-width: 960px)").matches;
}

function syncMobilePanModeUI() {
  elBtnPanMode?.classList.toggle("is-active", isMobilePanMode);
  elBtnPanMode?.setAttribute("aria-pressed", String(isMobilePanMode));
  elCanvasHost?.classList.toggle("canvasHost--panMode", isMobilePanMode);
}

function updateFieldDraggingForPanMode() {
  state.fields.forEach((field) => field._konva?.draggable(!isMobilePanMode));
  transformer?.listening(!isMobilePanMode);
  transformer?.visible(!isMobilePanMode);
  if (isMobilePanMode) {
    selectionRect?.visible(false);
    isSelectionBoxActive = false;
    selectionStart = null;
    selectionBoxAdditive = false;
    clearAlignmentGuides();
  }
  objLayer?.batchDraw();
  uiLayer?.batchDraw();
}

function setMobilePanMode(enabled) {
  if (enabled && pendingCanvasPlacement) clearPendingCanvasPlacement();
  isMobilePanMode = !!enabled && isMobilePanControlAvailable();
  if (!isMobilePanMode) stopStagePan();
  updateFieldDraggingForPanMode();
  syncMobilePanModeUI();
}

function refreshCanvasSizeAfterPanelMove() {
  if (!stage || !elCanvasHost) return;

  const applySize = () => {
    const r = elCanvasHost.getBoundingClientRect();
    if (!r.width || !r.height) return;
    stage.size({ width: r.width, height: r.height });
    stage.batchDraw();
    renderRulers();
  };

  requestAnimationFrame(applySize);
  setTimeout(applySize, 240);
}

function initMobilePanelMenu() {
  const mobileQuery = window.matchMedia?.("(max-width: 960px)");
  const menu = $("mobilePanelMenu");
  const overlay = $("mobilePanelMenuOverlay");
  const toggle = $("mobilePanelMenuToggle");
  const closeBtn = $("mobilePanelMenuClose");
  if (!mobileQuery || !menu || !overlay || !toggle || !closeBtn) return;

  const entries = [
    { el: document.querySelector(".panel--right"), slot: $("mobileRightPanelSlot") },
    { el: document.querySelector(".panel--left"), slot: $("mobileLeftPanelSlot") }
  ].filter((entry) => entry.el && entry.slot)
    .map((entry) => ({
      ...entry,
      parent: entry.el.parentNode,
      next: entry.el.nextSibling
    }));

  let isOpen = false;
  let touchStartX = null;

  const setMenuOpen = (nextOpen) => {
    isOpen = !!nextOpen && mobileQuery.matches;
    menu.hidden = !mobileQuery.matches;
    overlay.hidden = !isOpen;
    menu.classList.toggle("is-open", isOpen);
    overlay.classList.toggle("is-open", isOpen);
    menu.setAttribute("aria-hidden", String(!isOpen));
    toggle.setAttribute("aria-expanded", String(isOpen));
  };

  const moveEntry = (entry, toMenu) => {
    if (toMenu) {
      if (entry.el.parentNode !== entry.slot) entry.slot.appendChild(entry.el);
      return;
    }

    if (entry.el.parentNode !== entry.parent) {
      entry.parent.insertBefore(entry.el, entry.next);
    }
  };

  const syncMenuMode = () => {
    const mobile = mobileQuery.matches;
    entries.forEach((entry) => moveEntry(entry, mobile));
    if (!mobile) setMenuOpen(false);
    else {
      menu.hidden = false;
      menu.setAttribute("aria-hidden", String(!isOpen));
    }
    refreshCanvasSizeAfterPanelMove();
  };

  toggle.addEventListener("click", () => setMenuOpen(!isOpen));
  closeBtn.addEventListener("click", () => setMenuOpen(false));
  overlay.addEventListener("click", () => setMenuOpen(false));
  document.addEventListener("ciff:canvas-placement-started", () => setMenuOpen(false));
  window.addEventListener("keydown", (e) => {
    if (e.key === "Escape" && isOpen) setMenuOpen(false);
  });

  menu.addEventListener("touchstart", (e) => {
    touchStartX = e.touches?.[0]?.clientX ?? null;
  }, { passive: true });
  menu.addEventListener("touchend", (e) => {
    const endX = e.changedTouches?.[0]?.clientX;
    if (touchStartX !== null && Number.isFinite(endX) && touchStartX - endX > 64) {
      setMenuOpen(false);
    }
    touchStartX = null;
  }, { passive: true });

  if (mobileQuery.addEventListener) mobileQuery.addEventListener("change", syncMenuMode);
  else mobileQuery.addListener?.(syncMenuMode);

  syncMenuMode();
}

// ---------- UI init ----------
function initUI() {
  if (typeof initUiLanguageControls === "function") initUiLanguageControls();
  if (typeof onUiLanguageChange === "function") {
    onUiLanguageChange(() => {
      renderAll();
      if (typeof syncTextFieldModalControls === "function") syncTextFieldModalControls();
    });
  }
  if (typeof initUiThemeControls === "function") initUiThemeControls();
  if (typeof onUiThemeChange === "function") {
    onUiThemeChange(() => {
      renderAll();
      requestAnimationFrame(() => {
        renderRulers();
        renderGrid();
      });
    });
  }

  // Tabs
  document.querySelectorAll(".tab").forEach(btn => {
    btn.addEventListener("click", () => {
      document.querySelectorAll(".tab").forEach((b) => {
        b.classList.remove("tab--active");
        b.active = false;
        b.setAttribute("aria-selected", "false");
      });
      btn.classList.add("tab--active");
      btn.active = true;
      btn.setAttribute("aria-selected", "true");
      const tab = btn.dataset.tab;

      document.querySelectorAll(".tabview").forEach(v => v.classList.remove("tabview--active"));
      $(`tab-${tab}`).classList.add("tabview--active");
    });
  });

  $("fileInput").addEventListener("change", async (e) => {
    const file = e.target.files?.[0];
    if (!file) return;
    appLogger.file("FILE_OPEN_SELECTED", "Пользователь выбрал файл для открытия.", {
      name: file.name,
      sizeBytes: file.size,
      mimeType: file.type || null,
      lastModified: file.lastModified ? new Date(file.lastModified).toISOString() : null
    });
    try {
      const text = await readFileSmart(file);
      const result = typeof openXmlInNewTemplateTab === "function"
        ? openXmlInNewTemplateTab(text, file.name)
        : loadXml(text, { title: file.name, markDirty: false, source: "file" });
      appLogger.file("FILE_OPEN_COMPLETED", "Открытие выбранного файла завершено.", {
        name: file.name,
        sizeBytes: file.size,
        success: !!result
      }, result ? "INFO" : "WARN");
    } catch (error) {
      console.error("Failed to open CIFF file:", error);
      appLogger.error("FILE_OPEN_FAILED", "Ошибка чтения или открытия выбранного файла.", error, {
        name: file.name,
        sizeBytes: file.size,
        mimeType: file.type || null
      });
      openNotificationModal(
        t("dialog.fileOpenError.message"),
        t("dialog.fileOpenError.title")
      );
    } finally {
      e.target.value = "";
    }
  });
  $("btnOpenFile")?.addEventListener("click", () => $("fileInput").click());

  $("btnSave").addEventListener("click", () => openSaveTemplateModal());

  populateNewTemplateOptions();
  $("btnNewTemplate").addEventListener("click", () => openNewTemplateModal());
  $("btnCancelNewTemplate").addEventListener("click", () => closeNewTemplateModal());
  $("btnCreateNewTemplate").addEventListener("click", () => (
    typeof createTemplateFromBuilderDialog === "function"
      ? createTemplateFromBuilderDialog()
      : createNewTemplateFromDialog()
  ));
  elNewTemplateModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeNewTemplateModal();
  });
  $("btnCancelDataMatrix")?.addEventListener("click", () => closeDataMatrixModal());
  elBtnConfirmDataMatrix?.addEventListener("click", () => confirmDataMatrixModal());
  elDataMatrixModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeDataMatrixModal();
  });
  elNewDataMatrixSymbolSize?.addEventListener("change", () => syncDataMatrixModalControls());
  elNewDataMatrixSnValue?.addEventListener("change", () => syncDataMatrixModalControls());
  $("btnCancelSaveTemplate")?.addEventListener("click", () => closeSaveTemplateModal());
  $("btnConfirmSaveTemplate")?.addEventListener("click", () => saveTemplateFromDialog());
  elSaveTemplateName?.addEventListener("keydown", (e) => {
    if (e.key !== "Enter") return;
    e.preventDefault();
    saveTemplateFromDialog();
  });
  elSaveTemplateModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeSaveTemplateModal();
  });
  $("btnCancelTextField")?.addEventListener("click", () => closeTextFieldModal());
  $("btnConfirmTextField")?.addEventListener("click", () => confirmTextFieldModal());
  elTextFieldModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeTextFieldModal();
  });
  elTextFieldModeFixed?.addEventListener("change", () => syncTextFieldModalControls());
  elTextFieldModePresets?.addEventListener("change", () => syncTextFieldModalControls());
  elTextFieldModal?.querySelectorAll("[data-text-preset]").forEach((checkbox) => {
    checkbox.addEventListener("change", () => {
      if (checkbox.checked && elTextFieldModePresets) elTextFieldModePresets.checked = true;
      syncTextFieldModalControls();
    });
  });
  elTextFieldModal?.querySelectorAll("[data-text-preset-value]").forEach((select) => {
    select.addEventListener("change", () => syncTextFieldModalControls());
  });
  elBtnCloseNotification?.addEventListener("click", () => closeNotificationModal());
  elNotificationModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeNotificationModal();
  });
  elBtnCancelConfirmation?.addEventListener("click", () => closeConfirmationModal(false));
  elBtnConfirmConfirmation?.addEventListener("click", () => closeConfirmationModal(true));
  elConfirmationModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.confirmationCancel === "1") closeConfirmationModal(false);
  });
  $("btnOpenFunctionality")?.addEventListener("click", () => openDocumentationModal("functionality"));
  $("btnOpenChangelog")?.addEventListener("click", () => openDocumentationModal("changelog"));
  elBtnCloseDocumentation?.addEventListener("click", () => closeDocumentationModal());
  elDocumentationModal?.addEventListener("click", (e) => {
    if (e.target?.dataset?.modalClose === "1") closeDocumentationModal();
  });
  $("btnOpenDataMatrixEditor")?.addEventListener("click", () => openAdvancedEditorModal("datamatrix"));
  $("btnOpenOffsetsEditor")?.addEventListener("click", () => openAdvancedEditorModal("offsets"));
  $("btnOpenHiddenFieldsEditor")?.addEventListener("click", () => openAdvancedEditorModal("hidden"));
  elBtnCloseDataMatrixEditor?.addEventListener("click", () => closeAdvancedEditorModal("datamatrix"));
  elBtnCloseOffsetsEditor?.addEventListener("click", () => closeAdvancedEditorModal("offsets"));
  elBtnCloseHiddenFieldsEditor?.addEventListener("click", () => closeAdvancedEditorModal("hidden"));
  document.querySelectorAll("[data-editor-modal-close]").forEach((backdrop) => {
    backdrop.addEventListener("click", () => closeAdvancedEditorModal(backdrop.dataset.editorModalClose));
  });
  elZoomRange.addEventListener("input", () => setZoom(parseInt(String(elZoomRange.value), 10)));
  $("zoomIn").addEventListener("click", () => setZoom(clamp(25, 400, zoomPct + 10)));
  $("zoomOut").addEventListener("click", () => setZoom(clamp(25, 400, zoomPct - 10)));
  elBtnPanMode?.addEventListener("click", () => setMobilePanMode(!isMobilePanMode));

  const mobilePanQuery = window.matchMedia?.("(max-width: 960px)");
  const syncMobilePanAvailability = () => {
    if (mobilePanQuery && !mobilePanQuery.matches) setMobilePanMode(false);
    else syncMobilePanModeUI();
  };
  if (mobilePanQuery?.addEventListener) mobilePanQuery.addEventListener("change", syncMobilePanAvailability);
  else mobilePanQuery?.addListener?.(syncMobilePanAvailability);
  syncMobilePanAvailability();

  elToggleGrid.addEventListener("change", () => {
    renderGrid();
    if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
  });
  elToggleSnap.addEventListener("change", () => {
    if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
  });
  elToggleAlign?.addEventListener("change", () => {
    clearAlignmentGuides();
    if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
  });
  if (elGridSizeSelect) {
    elGridSizeSelect.value = String(state.gridMm);
    elGridSizeSelect.addEventListener("change", () => {
      const nextGridMm = Number(elGridSizeSelect.value);
      state.gridMm = GRID_SIZE_OPTIONS.includes(nextGridMm) ? nextGridMm : GRID_MM;
      elGridSizeSelect.value = String(state.gridMm);
      renderGrid();
      if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
    });
  }
  if (typeof enhanceSelectControls === "function") enhanceSelectControls(document);
  if (typeof enhanceNumberControls === "function") enhanceNumberControls(document);
  if (typeof syncTextFieldModalControls === "function") syncTextFieldModalControls();
  if (typeof syncDataMatrixModalControls === "function") syncDataMatrixModalControls();

  elSearch.addEventListener("input", () => renderFieldLists());
  elFieldFilterButtons.forEach((button) => {
    button.addEventListener("click", () => {
      activeFieldFilter = button.dataset.fieldFilter || "printed";
      renderFieldLists();
    });
  });
  initPrecisionMoveControls();

  $("addFixedText").addEventListener("click", () => openTextFieldModal());
  $("addDateText").addEventListener("click", () => beginCanvasPlacement({
    kind: "field",
    fldType: "DateText",
    toolButtonId: "addDateText"
  }));
  $("addOffsetDateText").addEventListener("click", () => beginCanvasPlacement({
    kind: "field",
    fldType: "OffsetDateText",
    toolButtonId: "addOffsetDateText"
  }));
  $("addTimeText").addEventListener("click", () => beginCanvasPlacement({
    kind: "field",
    fldType: "TimeText",
    toolButtonId: "addTimeText"
  }));
  $("addCounterText").addEventListener("click", () => beginCanvasPlacement({
    kind: "field",
    fldType: "CounterText",
    toolButtonId: "addCounterText"
  }));
  $("addDataMatrix").addEventListener("click", () => openDataMatrixModal());

  elBtnDelete.addEventListener("click", () => deleteSelected());

  $("btnShowHiddenOnCanvas").addEventListener("click", () => {
    state.showHiddenOnCanvas = !state.showHiddenOnCanvas;
    renderAll();
    if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
  });
  $("addOffset").addEventListener("click", () => {
    if (!state.xmlDoc) return;
    pushHistory();
    createDateOffset();
    renderAll();
  });

  $("btnUndo").addEventListener("click", undo);
  $("btnRedo").addEventListener("click", redo);

  initMobilePanelMenu();

  window.addEventListener("keydown", (e) => {
    if (e.key === "Escape" && elConfirmationModal && !elConfirmationModal.classList.contains("hidden")) {
      closeConfirmationModal(false);
      return;
    }
    if (e.key === "Escape" && elNewTemplateModal && !elNewTemplateModal.classList.contains("hidden")) {
      closeNewTemplateModal();
    }
    if (e.key === "Escape" && elDataMatrixModal && !elDataMatrixModal.classList.contains("hidden")) {
      closeDataMatrixModal();
    }
    if (e.key === "Escape" && elSaveTemplateModal && !elSaveTemplateModal.classList.contains("hidden")) {
      closeSaveTemplateModal();
    }
    if (e.key === "Escape" && elTextFieldModal && !elTextFieldModal.classList.contains("hidden")) {
      closeTextFieldModal();
    }
    if (e.key === "Escape" && elNotificationModal && !elNotificationModal.classList.contains("hidden")) {
      closeNotificationModal();
      return;
    }
    if (e.key === "Escape" && elDocumentationModal && !elDocumentationModal.classList.contains("hidden")) {
      closeDocumentationModal();
      return;
    }
    if (e.key === "Escape" && getOpenAdvancedEditorModal()) {
      closeAdvancedEditorModal();
    }
  });

  updateHiddenCanvasToggleButton();
  elStatusLeft.textContent = t("status.openFile");
  elStatusRight.textContent = "-";
  syncPrecisionMoveControls();
}

function openNotificationModal(message, title = t("dialog.notification.title"), options = {}) {
  notificationModalCloseHandler = typeof options.onClose === "function" ? options.onClose : null;
  if (!elNotificationModal) {
    const onClose = notificationModalCloseHandler;
    notificationModalCloseHandler = null;
    onClose?.();
    return;
  }
  if (elNotificationModalTitle) elNotificationModalTitle.textContent = title;
  if (elNotificationModalMessage) elNotificationModalMessage.textContent = message;
  elNotificationModal.classList.remove("hidden");
  elNotificationModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  setTimeout(() => elBtnCloseNotification?.focus(), 0);
}

function openConfirmationModal(message, title, options = {}) {
  if (!elConfirmationModal) return;

  confirmationModalConfirmHandler = typeof options.onConfirm === "function" ? options.onConfirm : null;
  confirmationModalCancelHandler = typeof options.onCancel === "function" ? options.onCancel : null;
  if (elConfirmationModalTitle) elConfirmationModalTitle.textContent = title;
  if (elConfirmationModalMessage) elConfirmationModalMessage.textContent = message;
  if (elBtnConfirmConfirmation) {
    elBtnConfirmConfirmation.textContent = options.confirmLabel ?? t("dialog.continue");
  }
  if (elBtnCancelConfirmation) {
    elBtnCancelConfirmation.textContent = options.cancelLabel ?? t("dialog.cancel");
  }
  elConfirmationModal.classList.remove("hidden");
  elConfirmationModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  setTimeout(() => elBtnConfirmConfirmation?.focus(), 0);
}

function closeConfirmationModal(confirmed) {
  if (!elConfirmationModal || elConfirmationModal.classList.contains("hidden")) return;

  const handler = confirmed ? confirmationModalConfirmHandler : confirmationModalCancelHandler;
  confirmationModalConfirmHandler = null;
  confirmationModalCancelHandler = null;
  elConfirmationModal.classList.add("hidden");
  elConfirmationModal.setAttribute("aria-hidden", "true");
  document.body.classList.toggle("modal-open", Boolean(document.querySelector(".modal:not(.hidden)")));
  if (handler) window.setTimeout(handler, 0);
}

function closeNotificationModal() {
  if (!elNotificationModal) return;
  const onClose = notificationModalCloseHandler;
  notificationModalCloseHandler = null;
  elNotificationModal.classList.add("hidden");
  elNotificationModal.setAttribute("aria-hidden", "true");
  document.body.classList.toggle("modal-open", Boolean(document.querySelector(".modal:not(.hidden)")));
  if (onClose) window.setTimeout(onClose, 0);
}

function openDocumentationModal(documentName) {
  if (!elDocumentationModal) return;
  const showChangelog = documentName === "changelog";
  elFunctionalityDocument?.classList.toggle("hidden", showChangelog);
  elChangelogDocument?.classList.toggle("hidden", !showChangelog);
  if (elDocumentationModalTitle) {
    elDocumentationModalTitle.textContent = t(showChangelog
      ? "dialog.documentation.changelogTitle"
      : "dialog.documentation.functionalityTitle");
  }
  elDocumentationModal.classList.remove("hidden");
  elDocumentationModal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");
  elDocumentationModal.querySelector(".documentationModal__content")?.scrollTo({ top: 0 });
  setTimeout(() => elBtnCloseDocumentation?.focus(), 0);
}

function closeDocumentationModal() {
  if (!elDocumentationModal) return;
  elDocumentationModal.classList.add("hidden");
  elDocumentationModal.setAttribute("aria-hidden", "true");
  document.body.classList.remove("modal-open");
}

function getAdvancedEditorModal(kind) {
  if (kind === "datamatrix") return elDataMatrixEditorModal;
  if (kind === "offsets") return elOffsetsEditorModal;
  if (kind === "hidden") return elHiddenFieldsEditorModal;
  return null;
}

function getOpenAdvancedEditorModal() {
  return [elDataMatrixEditorModal, elOffsetsEditorModal, elHiddenFieldsEditorModal]
    .find((modal) => modal && !modal.classList.contains("hidden")) ?? null;
}

function openAdvancedEditorModal(kind) {
  if (!state.xmlDoc) {
    openNotificationModal(t("dialog.notification.openFileFirst"));
    return;
  }

  const modal = getAdvancedEditorModal(kind);
  if (!modal) return;

  if (kind === "datamatrix") {
    const selectedDataMatrix = getSelectedFields().find((field) => field.fldType === "Barcode" && field.barcode?.dataMatrix);
    const firstDataMatrix = state.fields.find((field) => field.fldType === "Barcode" && field.barcode?.dataMatrix);
    const dataMatrix = selectedDataMatrix ?? firstDataMatrix;
    if (dataMatrix && !isFieldSelected(dataMatrix.name)) setSelectedNames([dataMatrix.name], dataMatrix.name);
  }

  renderAll();
  modal.classList.remove("hidden");
  modal.setAttribute("aria-hidden", "false");
  document.body.classList.add("modal-open");

  const closeButton = kind === "datamatrix"
    ? elBtnCloseDataMatrixEditor
    : kind === "offsets"
      ? elBtnCloseOffsetsEditor
      : elBtnCloseHiddenFieldsEditor;
  window.setTimeout(() => closeButton?.focus(), 0);
}

function closeAdvancedEditorModal(kind = null) {
  const modal = kind ? getAdvancedEditorModal(kind) : getOpenAdvancedEditorModal();
  if (!modal) return;
  modal.classList.add("hidden");
  modal.setAttribute("aria-hidden", "true");
  document.body.classList.toggle("modal-open", Boolean(document.querySelector(".modal:not(.hidden)")));
}

function getPrecisionMoveButtons() {
  return Array.from(document.querySelectorAll("[data-precision-move]"));
}

function getPrecisionMoveButtonDelta(button) {
  return {
    dxMm: Number(button?.dataset?.moveDx ?? 0),
    dyMm: Number(button?.dataset?.moveDy ?? 0)
  };
}

function syncPrecisionMoveControls() {
  const hasSelection = typeof getSelectedFields === "function" && getSelectedFields().length > 0;
  const panel = $("precisionMovePanel");
  panel?.classList.toggle("is-visible", hasSelection);
  panel?.setAttribute("aria-hidden", String(!hasSelection));
  getPrecisionMoveButtons().forEach((button) => {
    button.disabled = !hasSelection;
  });
}

function moveSelectionFromPrecisionButton(button, options = {}) {
  const { dxMm, dyMm } = getPrecisionMoveButtonDelta(button);
  if (!Number.isFinite(dxMm) || !Number.isFinite(dyMm)) return false;
  if (dxMm === 0 && dyMm === 0) return false;
  if (typeof moveSelectedFieldsByMm !== "function") return false;
  return moveSelectedFieldsByMm(dxMm, dyMm, options);
}

function initPrecisionMoveControls() {
  getPrecisionMoveButtons().forEach((button) => {
    let repeatDelayId = null;
    let repeatIntervalId = null;

    const stopRepeat = () => {
      if (repeatDelayId !== null) window.clearTimeout(repeatDelayId);
      if (repeatIntervalId !== null) window.clearInterval(repeatIntervalId);
      repeatDelayId = null;
      repeatIntervalId = null;
      button.classList.remove("is-pressing");
    };

    button.addEventListener("pointerdown", (event) => {
      if (button.disabled || event.button !== 0) return;
      event.preventDefault();
      button.classList.add("is-pressing");
      button.setPointerCapture?.(event.pointerId);

      const moved = moveSelectionFromPrecisionButton(button);
      if (!moved) {
        stopRepeat();
        return;
      }

      repeatDelayId = window.setTimeout(() => {
        repeatDelayId = null;
        repeatIntervalId = window.setInterval(() => {
          moveSelectionFromPrecisionButton(button, { skipHistory: true });
        }, PRECISION_MOVE_REPEAT_INTERVAL_MS);
      }, PRECISION_MOVE_REPEAT_DELAY_MS);
    });

    button.addEventListener("click", (event) => {
      if (event.detail !== 0) return;
      moveSelectionFromPrecisionButton(button);
    });

    button.addEventListener("pointerup", stopRepeat);
    button.addEventListener("pointercancel", stopRepeat);
    button.addEventListener("lostpointercapture", stopRepeat);
    button.addEventListener("mouseleave", (event) => {
      if (event.buttons === 0) stopRepeat();
    });
  });
}

function setZoom(pct) {
  zoomPct = pct;
  elZoomRange.value = String(pct);
  elZoomLabel.textContent = `${pct}%`;

  renderGrid();
  renderObjects();
  renderRulers();
  renderUI();
  if (typeof schedulePersistActiveTemplateTab === "function") schedulePersistActiveTemplateTab();
}

function getPixelsPerMm() { return MM_TO_PX_BASE * (zoomPct / 100); }
function mmToPx(mm) { return mm * getPixelsPerMm(); }
function pxToMm(px) { return px / getPixelsPerMm(); }
function internalToMm(v) { return v / INTERNAL_PER_MM; }
function mmToInternal(mm) { return Math.round(mm * INTERNAL_PER_MM); }

function pxToMmWorld(px, py) {
  const x = pxToMm(px - stage.x());
  const y = pxToMm(py - stage.y());
  return { x, y };
}

function getStageLocalPointerPosition() {
  const p = stage.getPointerPosition();
  if (!p) return null;
  return { x: p.x - stage.x(), y: p.y - stage.y() };
}

function syncPendingCanvasPlacementUI() {
  document.querySelectorAll(".toolButton").forEach((button) => {
    const isPending = button.id === pendingCanvasPlacement?.toolButtonId;
    button.classList.toggle("is-placement-pending", isPending);
    button.setAttribute("aria-pressed", String(isPending));
  });
  elCanvasHost?.classList.toggle("canvasHost--placing", !!pendingCanvasPlacement);
  if (pendingCanvasPlacement && elStatusLeft) {
    elStatusLeft.textContent = t("placement.hint");
  }
}

function clearPendingCanvasPlacement(options = {}) {
  if (!pendingCanvasPlacement) return false;
  const cancelledRequest = pendingCanvasPlacement;
  pendingCanvasPlacement = null;
  syncPendingCanvasPlacementUI();
  if (options.restoreStatus !== false && typeof renderSelectionPanels === "function") {
    renderSelectionPanels();
  }
  appLogger.action(
    options.reason === "committed" ? "PLACEMENT_MODE_COMPLETED" : "PLACEMENT_MODE_CANCELLED",
    options.reason === "committed"
      ? "Режим размещения завершён после создания объекта."
      : "Ожидающее размещение объекта отменено.",
    {
      reason: options.reason || "cancelled",
      request: {
        kind: cancelledRequest.kind,
        fieldType: cancelledRequest.fldType || null,
        toolButtonId: cancelledRequest.toolButtonId || null,
        presetNames: (cancelledRequest.resolved || []).map((item) => item.preset?.name).filter(Boolean)
      }
    },
    options.reason === "committed" ? "DEBUG" : "INFO"
  );
  return true;
}

function beginCanvasPlacement(request) {
  if (!state.xmlDoc) {
    openNotificationModal(t("dialog.notification.openFileFirst"));
    return false;
  }
  if (!request?.kind || !request?.toolButtonId) return false;

  if (isMobilePanMode) setMobilePanMode(false);
  pendingCanvasPlacement = request;
  syncPendingCanvasPlacementUI();
  appLogger.action("PLACEMENT_MODE_STARTED", "Выбран инструмент, приложение ожидает точку размещения на шаблоне.", {
    kind: request.kind,
    fieldType: request.fldType || null,
    toolButtonId: request.toolButtonId,
    presetNames: (request.resolved || []).map((item) => item.preset?.name).filter(Boolean),
    inputMode: isMobilePanControlAvailable() ? "mouse-or-touch" : "mouse"
  });
  document.dispatchEvent(new CustomEvent("ciff:canvas-placement-started"));
  return true;
}

function tryCommitPendingCanvasPlacement(e, inputType) {
  const now = performance.now();
  if (inputType === "mouse" && now < suppressCanvasMouseUntil) {
    cancelStagePanEvent(e, { cancelBubble: true, preventDefault: true });
    return true;
  }
  if (!pendingCanvasPlacement) return false;

  const local = getStageLocalPointerPosition();
  if (!local) return true;

  const canvasWidthPx = mmToPx(internalToMm(getCanvasInternalWidth()));
  const canvasHeightPx = mmToPx(internalToMm(getCanvasInternalHeight()));
  const isInsideTemplate = (
    local.x >= 0 &&
    local.y >= 0 &&
    local.x <= canvasWidthPx &&
    local.y <= canvasHeightPx
  );

  cancelStagePanEvent(e, { cancelBubble: true, preventDefault: inputType === "touch" });
  if (!isInsideTemplate) return true;

  if (inputType === "touch") suppressCanvasMouseUntil = now + 700;
  const request = pendingCanvasPlacement;
  const position = {
    x: mmToInternal(pxToMm(local.x)),
    y: mmToInternal(pxToMm(local.y))
  };

  appLogger.action("PLACEMENT_POINT_SELECTED", "Пользователь выбрал точку размещения объекта.", {
    inputType,
    fieldType: request.fldType || null,
    positionInternal: position,
    positionMillimeters: {
      x: Number(internalToMm(position.x).toFixed(2)),
      y: Number(internalToMm(position.y).toFixed(2))
    },
    snapEnabled: !!elToggleSnap?.checked
  });
  clearPendingCanvasPlacement({ restoreStatus: false, reason: "committed" });
  commitCanvasPlacement(request, position);
  return true;
}

function rectsIntersect(a, b) {
  return !(
    a.x + a.width < b.x ||
    b.x + b.width < a.x ||
    a.y + a.height < b.y ||
    b.y + b.height < a.y
  );
}

function getCanvasInternalWidth() {
  return state.subImage.maxWidth || state.subImage.width || 0;
}

function getCanvasInternalHeight() {
  return state.subImage.maxHeight || state.subImage.height || 0;
}

function getUsedImageInternalWidth() {
  return state.subImage.width || state.subImage.maxWidth || 0;
}

function getUsedImageInternalHeight() {
  return state.subImage.height || state.subImage.maxHeight || 0;
}

