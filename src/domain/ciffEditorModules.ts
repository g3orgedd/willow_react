export type CiffModuleKey =
  | 'core'
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
