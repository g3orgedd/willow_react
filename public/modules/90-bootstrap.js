/* bootstrap.js - initialize CIFF editor after all modules are loaded */
(() => {
  const required = ["initAppLogging", "initCanvas", "initUI", "initTemplateTabs", "initTemplatePresetBuilder", "startDynamicFieldValueTicker", "renderAll"];
  const missing = required.filter((name) => typeof globalThis[name] !== "function");
  if (missing.length) {
    throw new Error(`Missing required CIFF modules: ${missing.join(", ")}`);
  }

  Promise.all([initAppLogging(), initTextFontCatalog()])
    .catch((error) => console.error("Failed to initialize application logging:", error))
    .finally(() => {
      initCanvas();
      initUI();
      initTemplateTabs();
      initTemplatePresetBuilder();
      startDynamicFieldValueTicker();
      renderAll();
      appLogger.state("APPLICATION_READY", "Приложение полностью инициализировано и готово к работе.");
    });
})();
