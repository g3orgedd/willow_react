export function RightPanel() {
  return (
    <>
      <aside id="inspectorPanel" className="panel panel--right inspector surface-card" aria-label="Inspector">
        <button id="btnInspectorExpand" className="inspectorCollapsedRail" type="button" aria-label="Open inspector" aria-expanded="false">
          <span className="inspectorCollapsedRail__chevron" aria-hidden="true">
            <img className="inspectorControlIcon" src="/resourses/Icons/chevron_backward.svg" alt="" />
          </span>
          <span id="inspectorCollapsedLabel" className="inspectorCollapsedRail__label">Properties</span>
        </button>

        <div id="inspectorExpanded" className="inspectorExpanded">
          <header className="inspectorHeader">
            <div className="inspectorHeader__copy">
              <div className="inspectorHeader__title" id="inspectorTitle">Properties</div>
              <div className="inspectorHeader__subtitle" id="inspectorSubtitle">No template open</div>
            </div>
            <div className="inspectorHeader__actions">
              <button id="btnInspectorAppSettings" className="inspectorIconButton" type="button" aria-label="Application settings" aria-expanded="false">
                <img className="inspectorControlIcon" src="/resourses/Icons/settings_24dp.svg" alt="" aria-hidden="true" />
              </button>
              <button id="btnInspectorObjectMenu" className="inspectorIconButton hidden" type="button" aria-label="Object actions" aria-haspopup="menu" aria-expanded="false">
                <img className="inspectorControlIcon" src="/resourses/Icons/more_vert_24dp.svg" alt="" aria-hidden="true" />
              </button>
              <button id="btnInspectorCollapse" className="inspectorIconButton inspectorCollapseButton" type="button" aria-label="Collapse inspector" aria-expanded="true">
                <img className="inspectorControlIcon" src="/resourses/Icons/chevron_forward.svg" alt="" aria-hidden="true" />
              </button>
            </div>
          </header>

          <div id="inspectorBody" className="inspectorBody">
            <div id="inspectorNoTemplate" className="inspectorEmptyState">
              <div className="inspectorEmptyState__title">No template open</div>
            </div>

            <section id="inspectorObjectContext" className="inspectorContext hidden" aria-hidden="true">
              <div id="propsEmpty" className="muted hidden">No object selected</div>
              <div id="propsPanel" className="inspectorFieldPanel hidden"></div>

              <details id="objectAdvancedSection" className="inspectorDisclosure hidden">
                <summary className="inspectorDisclosure__summary">Advanced</summary>
                <div className="inspectorDisclosure__body inspectorActionList">
                  <button id="btnOpenDataMatrixEditor" className="btn btn--ghost btn--wide inspectorAction__button" type="button">
                    <img className="buttonIcon" src="/resourses/Icons/datamatrix_24dp.svg" alt="" aria-hidden="true" />
                    <span>DataMatrix profile</span>
                  </button>
                </div>
              </details>
            </section>

            <section id="inspectorTemplateContext" className="inspectorContext" aria-hidden="false">
              <div id="inspectorTemplateSections" className="inspectorSectionList hidden">
                <section className="inspectorSection" id="templateSizeSection">
                  <div className="inspectorSection__title" id="templateSizeSectionTitle">Size</div>
                  <div id="templateSizePanel" className="inspectorSection__content"></div>
                </section>

                <section className="inspectorSection" id="templatePrinterSection">
                  <div className="inspectorSection__title" id="templatePrinterSectionTitle">Printer</div>
                  <div id="templateTargetPanel" className="inspectorSection__content"></div>
                </section>

                <section className="inspectorSection" id="templateWorkspaceSection">
                  <div className="inspectorSection__title" id="templateWorkspaceSectionTitle">Workspace</div>
                  <div className="inspectorSection__grid">
                    <div className="fieldRow fieldRow--fullWidth">
                      <label htmlFor="gridSizeSelect">Grid size (mm)</label>
                      <select id="gridSizeSelect" className="select" defaultValue="1">
                        <option value="1">1 mm</option>
                        <option value="3">3 mm</option>
                        <option value="5">5 mm</option>
                        <option value="10">10 mm</option>
                      </select>
                    </div>
                    <div className="fieldRow fieldRow--fullWidth">
                      <label htmlFor="moveStepSelect">Move step (mm)</label>
                      <select id="moveStepSelect" className="select" defaultValue="0.1">
                        <option value="0.1">0.1 mm</option>
                        <option value="0.3">0.3 mm</option>
                        <option value="0.5">0.5 mm</option>
                        <option value="0.7">0.7 mm</option>
                        <option value="1">1 mm</option>
                        <option value="1.2">1.2 mm</option>
                        <option value="1.5">1.5 mm</option>
                        <option value="2">2 mm</option>
                        <option value="2.5">2.5 mm</option>
                        <option value="3">3 mm</option>
                        <option value="5">5 mm</option>
                        <option value="7">7 mm</option>
                        <option value="10">10 mm</option>
                      </select>
                    </div>
                  </div>
                </section>

                <details id="templateAdvancedSection" className="inspectorDisclosure">
                  <summary className="inspectorDisclosure__summary">Advanced</summary>
                  <div className="inspectorDisclosure__body inspectorActionList">
                    <button id="btnOpenOffsetsEditor" className="btn btn--ghost btn--wide inspectorAction__button" type="button">
                      <img className="buttonIcon" src="/resourses/Icons/move_up_24dp.svg" alt="" aria-hidden="true" />
                      <span>Date offset editor</span>
                    </button>
                    <button id="btnOpenHiddenFieldsEditor" className="btn btn--ghost btn--wide inspectorAction__button" type="button">
                      <img className="buttonIcon" src="/resourses/Icons/visibility_off_24dp.svg" alt="" aria-hidden="true" />
                      <span>Hidden field editor</span>
                    </button>
                  </div>
                </details>
              </div>
            </section>
          </div>
        </div>
      </aside>

      <div id="inspectorObjectMenu" className="inspectorPopover inspectorObjectMenu surface-card hidden" role="menu" aria-label="Object actions">
        <button id="btnInspectorTogglePrint" className="inspectorMenuItem" type="button" role="menuitemcheckbox" aria-checked="false">
          <span className="inspectorMenuItem__icon inspectorMenuItem__icon--printState" aria-hidden="true"></span>
          <span id="inspectorPrintLabel">Print output</span>
        </button>
        <div className="inspectorMenuDivider" role="separator"></div>
        <button id="btnDelete" className="inspectorMenuItem inspectorMenuItem--danger" type="button" role="menuitem" disabled>
          <span className="inspectorMenuItem__icon inspectorMenuItem__icon--delete" aria-hidden="true"></span>
          <span id="inspectorDeleteLabel">Delete selected</span>
        </button>
      </div>

      <div id="inspectorAppSettings" className="inspectorPopover inspectorAppSettings surface-card hidden" role="dialog" aria-labelledby="inspectorAppSettingsTitle">
        <div className="inspectorPopover__title" id="inspectorAppSettingsTitle">Application settings</div>
        <div className="inspectorSettingsGrid">
          <div className="fieldRow">
            <label htmlFor="uiLanguageSelect">Language</label>
            <select id="uiLanguageSelect" className="select" data-ui-language-select></select>
          </div>
          <div className="fieldRow">
            <label htmlFor="uiThemeSelect">Theme</label>
            <select id="uiThemeSelect" className="select" data-ui-theme-select></select>
          </div>
        </div>
        <div className="settingsDocumentationActions">
          <button id="btnOpenFunctionality" className="btn btn--tonal btn--wide" type="button">Functionality</button>
          <button id="btnOpenChangelog" className="btn btn--ghost btn--wide" type="button">Changes</button>
        </div>
      </div>
    </>
  );
}
