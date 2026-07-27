export function NotificationModal() {
  return (
    <div id="notificationModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div
        className="modal__card surface-card"
        role="alertdialog"
        aria-modal="true"
        aria-labelledby="notificationModalTitle"
        aria-describedby="notificationModalMessage"
      >
        <div className="modal__header">
          <div>
            <div className="modal__title" id="notificationModalTitle">Notice</div>
            <div className="modal__subtitle" id="notificationModalMessage"></div>
          </div>
        </div>

        <div className="modal__actions">
          <button id="btnCloseNotification" className="btn btn--primary" type="button">Close</button>
        </div>
      </div>
    </div>
  );
}
