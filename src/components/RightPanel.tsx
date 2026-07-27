export function RightPanel() {
  return (
    <aside className="panel panel--right surface-card">
      <div className="tabsWrap">
        <div className="tabs" role="tablist" aria-label="Inspector sections">
          <button className="tab tab--active" id="object_tab" data-tab="object" type="button" role="tab" aria-selected="true">Object</button>
          <button className="tab" id="template_tab" data-tab="template" type="button" role="tab" aria-selected="false">Template</button>
          <button className="tab" id="advanced_tab" data-tab="advanced" type="button" role="tab" aria-selected="false">Advanced</button>
          <button className="tab" id="settings_tab" data-tab="settings" type="button" role="tab" aria-selected="false">Settings</button>
        </div>
      </div>

      <div className="panel__section tabview tabview--active" id="tab-object">
        <div className="panel__title">Selected object</div>
        <div id="propsEmpty" className="muted">No object selected<br />Select an object on the canvas or in the field list.</div>
        <div id="propsPanel" className="form hidden"></div>

        <div className="sectionAction">
          <button id="btnDelete" className="btn btn--danger btn--wide" type="button" disabled>Delete selected</button>
        </div>
      </div>

      <div className="panel__section tabview" id="tab-template">
        <div className="sectionBlock">
          <div className="panel__title">Template size</div>
          <div id="templateSizePanel" className="form"></div>
        </div>

        <div className="hr"></div>

        <div className="sectionBlock">
          <div className="panel__title">Printer settings</div>
          <div id="templateTargetPanel" className="form"></div>
        </div>
      </div>

      <div className="panel__section tabview" id="tab-advanced">
        <div className="panel__title advancedSettingsTitle">Advanced settings</div>
        <div className="advancedEditorActions">
          <div className="advancedEditorAction">
            <div className="advancedEditorDescription" id="dataMatrixEditorDescription">Code profile and segments</div>
            <button id="btnOpenDataMatrixEditor" className="btn btn--ghost advancedEditorButton" type="button" aria-describedby="dataMatrixEditorDescription">
              <img className="buttonIcon" src="/resourses/Icons/datamatrix_24dp.svg" alt="" aria-hidden="true" />
              <span>DataMatrix</span>
            </button>
          </div>

          <div className="advancedEditorAction">
            <div className="advancedEditorDescription" id="offsetsEditorDescription">Calculated template dates</div>
            <button id="btnOpenOffsetsEditor" className="btn btn--ghost advancedEditorButton" type="button" aria-describedby="offsetsEditorDescription">
              <img className="buttonIcon" src="/resourses/Icons/move_up_24dp.svg" alt="" aria-hidden="true" />
              <span>Offsets</span>
            </button>
          </div>

          <div className="advancedEditorAction">
            <div className="advancedEditorDescription" id="hiddenFieldsEditorDescription">Values of non-printed fields</div>
            <button id="btnOpenHiddenFieldsEditor" className="btn btn--ghost advancedEditorButton" type="button" aria-describedby="hiddenFieldsEditorDescription">
              <img className="buttonIcon" src="/resourses/Icons/visibility_off_24dp.svg" alt="" aria-hidden="true" />
              <span>Hidden fields</span>
            </button>
          </div>
        </div>
      </div>

      <div className="panel__section tabview" id="tab-settings">
        <div className="panel__title systemSettingsTitle">System settings</div>

        <div className="sectionBlock languageSettings advancedSelectSetting advancedSelectSetting--first">
          <div className="fieldRow">
            <label htmlFor="uiLanguageSelect">Language</label>
            <select id="uiLanguageSelect" className="select" data-ui-language-select></select>
          </div>
        </div>

        <div className="sectionBlock advancedSelectSetting advancedSelectSetting--middle">
          <div className="fieldRow">
            <label htmlFor="uiThemeSelect">Theme</label>
            <select id="uiThemeSelect" className="select" data-ui-theme-select></select>
          </div>
        </div>

        <div className="sectionBlock advancedSelectSetting advancedSelectSetting--last">
          <div className="fieldRow">
            <label htmlFor="gridSizeSelect">Grid size</label>
            <select id="gridSizeSelect" className="select" defaultValue="1">
              <option value="1" >1 mm</option>
              <option value="3">3 mm</option>
              <option value="5">5 mm</option>
              <option value="10">10 mm</option>
            </select>
          </div>
        </div>

        <div className="hr"></div>

        <div className="settingsDocumentationActions">
          <button id="btnOpenFunctionality" className="btn btn--tonal btn--wide" type="button">Функционал</button>
          <button id="btnOpenChangelog" className="btn btn--ghost btn--wide" type="button">Изменения</button>
        </div>

      </div>
    </aside>
  );
}
