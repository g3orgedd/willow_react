export type CiffModuleKey =
  | 'core'
  | 'ciffCompatibility'
  | 'fonts'
  | 'fontCatalog'
  | 'nativeTextPreview'
  | 'clstEncryption'
  | 'clstTagData'
  | 'clstCalculatedData'
  | 'clstVersionInfo'
  | 'i18n'
  | 'theme'
  | 'logging'
  | 'canvasUi'
  | 'xmlLoad'
  | 'rendering'
  | 'editor'
  | 'templatePreset'
  | 'inputs'
  | 'historySave'
  | 'templateTabs'
  | 'bootstrap';

export interface CiffEditorModule {
  readonly key: CiffModuleKey;
  readonly src: string;
  readonly checks: readonly string[];
}

export const CIFF_EDITOR_MODULES: readonly CiffEditorModule[] = [
  { key: 'core', src: '/modules/00-core.js', checks: ['CIFF_EDITOR_CORE_READY'] },
  { key: 'ciffCompatibility', src: '/modules/01-ciff-compatibility.js', checks: ['CIFF_COMPATIBILITY_READY'] },
  { key: 'fonts', src: '/modules/02-fonts.js', checks: ['getEffectiveTextFontFamily', 'getTextCanvasFontFamily'] },
  { key: 'fontCatalog', src: '/modules/03-font-catalog.js', checks: ['initTextFontCatalog', 'getAvailableTextFontFamilies'] },
  { key: 'nativeTextPreview', src: '/modules/04-native-text-preview.js', checks: ['makeNativeTextPreviewNode'] },
  { key: 'clstEncryption', src: '/modules/clst/encryption.js', checks: ['CEncryption', 'CLST_ENCRYPTION_READY'] },
  { key: 'clstTagData', src: '/modules/clst/tag-data.js', checks: ['resolveClstTagData', 'CLST_TAG_DATA_READY'] },
  { key: 'clstCalculatedData', src: '/modules/clst/calculated-data.js', checks: ['prepareCiffCalculatedData'] },
  { key: 'clstVersionInfo', src: '/modules/clst/version-info.js', checks: ['generateClStVersionInfo', 'CLST_VERSION_INFO_READY'] },
  { key: 'i18n', src: '/modules/05-i18n.js', checks: ['t', 'initUiLanguageControls'] },
  { key: 'theme', src: '/modules/06-theme.js', checks: ['setUiTheme', 'initUiThemeControls'] },
  { key: 'logging', src: '/modules/07-logging.js', checks: ['appLogger', 'initAppLogging'] },
  { key: 'canvasUi', src: '/modules/10-canvas-ui.js', checks: ['initCanvas', 'initUI'] },
  { key: 'xmlLoad', src: '/modules/20-xml-load.js', checks: ['loadXml', 'parseFields'] },
  { key: 'rendering', src: '/modules/30-rendering.js', checks: ['renderAll', 'startDynamicFieldValueTicker'] },
  { key: 'editor', src: '/modules/40-editor.js', checks: ['renderSelectionPanels', 'addField'] },
  { key: 'templatePreset', src: '/modules/45-template-preset.js', checks: ['generateTemplatePreset', 'initTemplatePresetBuilder'] },
  { key: 'inputs', src: '/modules/50-inputs.js', checks: ['inputText', 'snapPoint'] },
  { key: 'historySave', src: '/modules/60-history-save.js', checks: ['pushHistory', 'patchXmlLosslessV2'] },
  { key: 'templateTabs', src: '/modules/70-template-tabs.js', checks: ['initTemplateTabs', 'switchTemplateTab'] },
  { key: 'bootstrap', src: '/modules/90-bootstrap.js', checks: [] },
] as const;

export const CIFF_EDITOR_MODULE_FLAGS: Record<CiffModuleKey, boolean> = {
  core: true,
  ciffCompatibility: true,
  fonts: true,
  fontCatalog: true,
  nativeTextPreview: true,
  clstEncryption: true,
  clstTagData: true,
  clstCalculatedData: true,
  clstVersionInfo: true,
  i18n: true,
  theme: true,
  logging: true,
  canvasUi: true,
  xmlLoad: true,
  rendering: true,
  editor: true,
  templatePreset: true,
  inputs: true,
  historySave: true,
  templateTabs: true,
  bootstrap: true,
};
