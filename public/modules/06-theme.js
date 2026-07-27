const UI_THEME_STORAGE_KEY = "willowXml.uiTheme";
const UI_THEME_OPTIONS = ["system", "light", "dark"];
const uiThemeChangeListeners = new Set();
const systemDarkThemeQuery = globalThis.matchMedia?.("(prefers-color-scheme: dark)") ?? null;

function normalizeUiTheme(theme) {
  const value = String(theme ?? "").toLowerCase();
  return UI_THEME_OPTIONS.includes(value) ? value : "system";
}

function getSavedUiTheme() {
  try {
    return normalizeUiTheme(globalThis.localStorage?.getItem(UI_THEME_STORAGE_KEY));
  } catch {
    return "system";
  }
}

function saveUiTheme(theme) {
  const nextTheme = normalizeUiTheme(theme);
  try {
    globalThis.localStorage?.setItem(UI_THEME_STORAGE_KEY, nextTheme);
  } catch {
    // localStorage can be unavailable in restricted contexts.
  }
  return nextTheme;
}

function resolveUiTheme(theme = currentUiTheme) {
  const preference = normalizeUiTheme(theme);
  if (preference !== "system") return preference;
  return systemDarkThemeQuery?.matches ? "dark" : "light";
}

let currentUiTheme = getSavedUiTheme();
let resolvedUiTheme = resolveUiTheme(currentUiTheme);

function getCurrentUiTheme() {
  return currentUiTheme;
}

function getResolvedUiTheme() {
  return resolvedUiTheme;
}

function onUiThemeChange(listener) {
  if (typeof listener !== "function") return () => {};
  uiThemeChangeListeners.add(listener);
  return () => uiThemeChangeListeners.delete(listener);
}

function applyUiTheme(theme = currentUiTheme, opts = {}) {
  const nextTheme = normalizeUiTheme(theme);
  const nextResolvedTheme = resolveUiTheme(nextTheme);
  const changed = nextTheme !== currentUiTheme || nextResolvedTheme !== resolvedUiTheme;

  currentUiTheme = opts.save === false ? nextTheme : saveUiTheme(nextTheme);
  resolvedUiTheme = nextResolvedTheme;
  document.documentElement.dataset.themePreference = currentUiTheme;
  document.documentElement.dataset.theme = resolvedUiTheme;
  document.documentElement.style.colorScheme = resolvedUiTheme;

  if ((changed || opts.force) && opts.notify !== false) {
    uiThemeChangeListeners.forEach((listener) => listener(currentUiTheme, resolvedUiTheme));
  }
  return resolvedUiTheme;
}

function updateUiThemeControls(language = getCurrentUiLanguage?.() ?? UI_DEFAULT_LANGUAGE) {
  document.querySelectorAll("[data-ui-theme-select]").forEach((select) => {
    select.innerHTML = "";
    UI_THEME_OPTIONS.forEach((theme) => {
      const option = document.createElement("option");
      option.value = theme;
      option.textContent = t(`theme.${theme}`, {}, language);
      select.appendChild(option);
    });
    select.value = currentUiTheme;
    if (typeof enhanceSelectControl === "function") enhanceSelectControl(select);
  });
}

function setUiTheme(theme, opts = {}) {
  const result = applyUiTheme(theme, opts);
  updateUiThemeControls();
  return result;
}

function initUiThemeControls() {
  document.querySelectorAll("[data-ui-theme-select]").forEach((select) => {
    if (select.dataset.uiThemeBound === "1") return;
    select.dataset.uiThemeBound = "1";
    select.addEventListener("change", () => setUiTheme(select.value));
  });
  applyUiTheme(currentUiTheme, { force: true, save: false, notify: false });
  updateUiThemeControls();
}

systemDarkThemeQuery?.addEventListener?.("change", () => {
  if (currentUiTheme !== "system") return;
  applyUiTheme("system", { save: false });
  updateUiThemeControls();
});

if (typeof onUiLanguageChange === "function") {
  onUiLanguageChange((language) => updateUiThemeControls(language));
}

applyUiTheme(currentUiTheme, { force: true, save: false, notify: false });

globalThis.UI_THEME_STORAGE_KEY = UI_THEME_STORAGE_KEY;
globalThis.UI_THEME_OPTIONS = UI_THEME_OPTIONS;
globalThis.normalizeUiTheme = normalizeUiTheme;
globalThis.getSavedUiTheme = getSavedUiTheme;
globalThis.saveUiTheme = saveUiTheme;
globalThis.resolveUiTheme = resolveUiTheme;
globalThis.getCurrentUiTheme = getCurrentUiTheme;
globalThis.getResolvedUiTheme = getResolvedUiTheme;
globalThis.onUiThemeChange = onUiThemeChange;
globalThis.applyUiTheme = applyUiTheme;
globalThis.setUiTheme = setUiTheme;
globalThis.updateUiThemeControls = updateUiThemeControls;
globalThis.initUiThemeControls = initUiThemeControls;
