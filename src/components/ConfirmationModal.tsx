export function ConfirmationModal() {
  return (
    <div id="confirmationModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-confirmation-cancel="1"></div>
      <div
        className="modal__card surface-card"
        role="alertdialog"
        aria-modal="true"
        aria-labelledby="confirmationModalTitle"
        aria-describedby="confirmationModalMessage"
      >
        <div className="modal__header">
          <div>
            <div className="modal__title" id="confirmationModalTitle">Confirm action</div>
            <div className="modal__subtitle" id="confirmationModalMessage"></div>
          </div>
        </div>

        <div className="modal__actions">
          <button id="btnCancelConfirmation" className="btn btn--text" type="button">Cancel</button>
          <button id="btnConfirmConfirmation" className="btn btn--primary" type="button">Continue</button>
        </div>
      </div>
    </div>
  );
}
