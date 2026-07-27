export function CloseTabModal() {
  return (
    <div id="closeTabModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-close-tab-cancel="1"></div>
      <div
        className="modal__card surface-card"
        role="alertdialog"
        aria-modal="true"
        aria-labelledby="closeTabModalTitle"
        aria-describedby="closeTabModalMessage"
      >
        <div className="modal__header">
          <div>
            <div className="modal__title" id="closeTabModalTitle">Close template?</div>
            <div className="modal__subtitle" id="closeTabModalMessage">
              This template has unsaved changes. If you close it without saving, the information will be lost.
            </div>
          </div>
        </div>

        <div className="modal__actions closeTabModal__actions">
          <button id="btnCancelCloseTab" className="btn btn--text" type="button">Cancel</button>
          <button id="btnCloseTabWithoutSaving" className="btn btn--danger" type="button">
            Close without saving
          </button>
          <button id="btnSaveAndCloseTab" className="btn btn--primary" type="button">Save</button>
        </div>
      </div>
    </div>
  );
}
