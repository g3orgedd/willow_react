export function SaveTemplateModal() {
  return (
    <div id="saveTemplateModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div className="modal__card surface-card" role="dialog" aria-modal="true" aria-labelledby="saveTemplateTitle">
        <div className="modal__header">
          <div>
            <div className="modal__title" id="saveTemplateTitle">Save template</div>
            <div className="modal__subtitle" id="saveTemplateSubtitle">Enter a template name to save it to this device.</div>
          </div>
        </div>

        <div className="dialogContent">
          <div className="form form--dialog">
            <div className="fieldRow">
              <label htmlFor="saveTemplateName">Template name</label>
              <input
                id="saveTemplateName"
                className="input"
                type="text"
                autoComplete="off"
                maxLength={120}
                required
              />
            </div>
          </div>
        </div>

        <div className="modal__actions">
          <button id="btnCancelSaveTemplate" className="btn btn--text" type="button">Cancel</button>
          <button id="btnConfirmSaveTemplate" className="btn btn--primary" type="button">Save</button>
        </div>
      </div>
    </div>
  );
}
