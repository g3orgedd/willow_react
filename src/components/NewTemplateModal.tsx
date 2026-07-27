const extraFields = [
  ['party', 'PARTY'],
  ['team', 'TEAM'],
  ['productDate', 'PRODUCT_DATE'],
  ['expirationDate', 'EXPIRATION_DATE'],
  ['rNum', 'R_NUM'],
  ['packingDate', 'PACKING_DATE'],
  ['time', 'TIME'],
] as const;

function DateSettings({ field, title }: { field: string; title: string }) {
  return (
    <div className="builderFieldSettings" data-builder-settings={field} hidden>
      <div className="builderFieldSettings__inner">
        <div className="builderFieldSettings__title" data-builder-settings-title={field}>{title}</div>
        <div className="builderSettingsGrid">
          <label className="fieldRow" data-builder-date-mode-row={field}>
            <span data-builder-i18n="builder.field.dateMode">Date mode</span>
            <select className="select" data-builder-date-generation={field} defaultValue={field === 'expirationDate' ? 'printer-offset' : 'printer-current'}>
              <option value="printer-current" data-builder-i18n-option="builder.date.current">Current date</option>
              <option value="printer-offset" data-builder-i18n-option="builder.date.calculated">Calculated date</option>
            </select>
          </label>
          <label className="fieldRow">
            <span data-builder-i18n="builder.field.format">Format</span>
            <select className="select" data-builder-date-format={field}>
              <option value="dd/MM/yy::en">dd/MM/yy</option>
              <option value="dd/MM/yyyy::en">dd/MM/yyyy</option>
              <option value="dd/MMM/yyyy::en">dd/MMM/yyyy (EN)</option>
              <option value="dd/MMM/yyyy::ru">dd/MMM/yyyy (RU)</option>
            </select>
          </label>
          <label className="fieldRow">
            <span data-builder-i18n="builder.field.separator">Separator</span>
            <select className="select" data-builder-date-separator={field}>
              <option value=".">.</option>
              <option value="/">/</option>
              <option value="-">-</option>
              <option value="">None</option>
            </select>
          </label>
        </div>
        <div className="builderOffsetGrid" data-builder-offset={field} hidden>
          <label><span data-builder-i18n="builder.offset.years">Years</span><input className="input" type="number" defaultValue="0" data-builder-offset-years={field} /></label>
          <label><span data-builder-i18n="builder.offset.months">Months</span><input className="input" type="number" defaultValue="0" data-builder-offset-months={field} /></label>
          <label><span data-builder-i18n="builder.offset.days">Days</span><input className="input" type="number" defaultValue={field === 'expirationDate' ? '30' : '0'} data-builder-offset-days={field} /></label>
        </div>
      </div>
    </div>
  );
}

export function NewTemplateModal() {
  return (
    <div id="newTemplateModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div className="modal__card modal__card--builder surface-card" role="dialog" aria-modal="true" aria-labelledby="newTemplateTitle">
        <div className="modal__header">
          <div>
            <div className="modal__title" id="newTemplateTitle">Create template</div>
            <div className="modal__subtitle" id="templateBuilderSubtitle">Choose how to create a template.</div>
          </div>
          <div className="builderProgress" id="templateBuilderProgress" aria-live="polite"></div>
        </div>

        <div className="dialogContent builderDialogContent">
          <div className="builderStep" data-builder-step="0">
            <div className="builderChoiceGrid">
              <button type="button" className="builderChoice" data-builder-kind="empty">
                <strong data-builder-i18n="builder.kind.empty">Blank template</strong>
                <span data-builder-i18n="builder.kind.emptyDescription">Create an empty template for manual editing.</span>
              </button>
              <button type="button" className="builderChoice" data-builder-kind="preset-builder">
                <strong data-builder-i18n="builder.kind.preset">Template builder</strong>
                <span data-builder-i18n="builder.kind.presetDescription">Create a template with DataMatrix and fields.</span>
              </button>
            </div>
          </div>

          <div className="builderStep" data-builder-step="1" hidden>
            <div className="form form--dialog builderSettingsGrid">
              <div className="fieldRow">
                <label htmlFor="newTemplatePrinterModel">Printer model</label>
                <select id="newTemplatePrinterModel" className="select"></select>
              </div>
              <div className="fieldRow">
                <label htmlFor="newTemplatePrintMode">Print mode</label>
                <select id="newTemplatePrintMode" className="select"></select>
              </div>
              <div className="fieldRow">
                <label htmlFor="newTemplateWidth">Width (mm)</label>
                <input id="newTemplateWidth" className="input" type="number" min="0.01" max="53.33" step="0.01" />
              </div>
              <div className="fieldRow">
                <label htmlFor="newTemplateHeight">Height (mm)</label>
                <input id="newTemplateHeight" className="input" type="number" min="0.01" max="75.00" step="0.01" />
              </div>
            </div>
            <div className="note">For 53 mm print heads the supported range is 53.33 by 75.00 mm.</div>
          </div>

          <div className="builderStep" data-builder-step="2" hidden>
            <div className="builderChoiceGrid">
              <button type="button" className="builderChoice" data-builder-source="server-full">
                <strong data-builder-i18n="builder.source.serverFull">All data from server</strong>
                <span data-builder-i18n="builder.source.serverFullDescription">DataMatrix and every selected variable field are supplied by the server.</span>
              </button>
              <button type="button" className="builderChoice" data-builder-source="server-dm-printer-rest">
                <strong data-builder-i18n="builder.source.printerRest">Only DataMatrix from server</strong>
                <span data-builder-i18n="builder.source.printerRestDescription">The server supplies DataMatrix; dates, time and operator fields are generated on the printer.</span>
              </button>
            </div>
          </div>

          <div className="builderStep" data-builder-step="3" hidden>
            <div className="builderSettingsGrid">
              <label className="fieldRow">
                <span data-builder-i18n="builder.dm.symbol">Symbol size</span>
                <select id="builderSymbolSize" className="select"></select>
              </label>
              <label className="fieldRow">
                <span data-builder-i18n="builder.dm.sn">SN value</span>
                <select id="builderSnValue" className="select">
                  <option value="000000">000000</option>
                  <option value="0000000000000">0000000000000</option>
                </select>
              </label>
              <label className="fieldRow">
                <span data-builder-i18n="builder.dm.moduleSize">Module size</span>
                <select id="builderModuleSize" className="select" defaultValue="0.50">
                  <option value="0.50">0.50</option>
                </select>
              </label>
            </div>
          </div>

          <div className="builderStep" data-builder-step="4" hidden>
            <div className="builderFieldGrid">
              {extraFields.map(([id, label]) => (
                <label className="builderFieldChoice" key={id}>
                  <input type="checkbox" data-builder-field={id} />
                  <span data-builder-field-label={id}>{label}</span>
                </label>
              ))}
            </div>
            <div className="builderDynamicSettings">
              <DateSettings field="productDate" title="PRODUCT_DATE" />
              <DateSettings field="expirationDate" title="EXPIRATION_DATE" />
              <DateSettings field="packingDate" title="PACKING_DATE" />
              <div className="builderFieldSettings" data-builder-settings="time" hidden>
                <div className="builderFieldSettings__inner">
                  <div className="builderFieldSettings__title">TIME</div>
                  <div className="builderSettingsGrid">
                    <label className="fieldRow"><span>Format</span><select id="builderTimeFormat" className="select"><option>HH:mm</option><option>HH:mm:ss</option><option>hh:mm</option></select></label>
                    <label className="fieldRow"><span>Separator</span><select id="builderTimeSeparator" className="select"><option value=":">:</option><option value=".">.</option><option value="">None</option></select></label>
                  </div>
                </div>
              </div>
            </div>
          </div>

          <div className="builderStep" data-builder-step="5" hidden>
            <div id="builderSummary" className="builderSummary"></div>
            <div id="builderValidation" className="builderValidation" role="alert"></div>
          </div>
        </div>

        <div className="modal__actions">
          <button id="btnCancelNewTemplate" className="btn btn--text" type="button">Cancel</button>
          <button id="btnBuilderBack" className="btn btn--text" type="button" hidden>Back</button>
          <button id="btnBuilderNext" className="btn btn--primary" type="button" disabled>Next</button>
          <button id="btnCreateNewTemplate" className="btn btn--primary" type="button" hidden>Create</button>
        </div>
      </div>
    </div>
  );
}
