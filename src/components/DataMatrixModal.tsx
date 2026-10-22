const DATA_MATRIX_SYMBOL_SIZES = [
  '14X14',
  '16X16',
  '18X18',
  '20X20',
  '22X22',
  '24X24',
  '26X26',
  '32X32',
  '36X36',
  'Auto',
];

export function DataMatrixModal() {
  return (
    <div id="dataMatrixModal" className="modal hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div
        className="modal__card surface-card"
        role="dialog"
        aria-modal="true"
        aria-labelledby="dataMatrixModalTitle"
        aria-describedby="dataMatrixModalSubtitle"
      >
        <div className="modal__header">
          <div>
            <div className="modal__title" id="dataMatrixModalTitle">Add DataMatrix</div>
            <div className="modal__subtitle" id="dataMatrixModalSubtitle">
              Select the code format and serial number length.
            </div>
          </div>
        </div>

        <div className="dialogContent">
          <div className="form form--dialog">
            <div className="fieldRow">
              <label htmlFor="newDataMatrixSymbolSize">Code format</label>
              <select id="newDataMatrixSymbolSize" className="select" defaultValue="">
                <option value="">Select code format</option>
                {DATA_MATRIX_SYMBOL_SIZES.map((size) => (
                  <option value={size} key={size}>{size}</option>
                ))}
              </select>
            </div>

            <div className="fieldRow">
              <label id="newDataMatrixSnValueLabel" htmlFor="newDataMatrixSnValue">SN value</label>
              <input id="newDataMatrixSnValue" type="hidden" defaultValue="000000" />
              <div className="fieldFilter snLengthSelector" role="group" aria-labelledby="newDataMatrixSnValueLabel">
                <button className="fieldFilter__button fieldFilter__button--active" type="button" data-dm-sn-length="6" aria-pressed="true">6</button>
                <button className="fieldFilter__button" type="button" data-dm-sn-length="13" aria-pressed="false">13</button>
              </div>
            </div>

            <div id="dataMatrixModalError" className="note dataMatrixModal__error" aria-live="polite"></div>
          </div>
        </div>

        <div className="modal__actions">
          <button id="btnCancelDataMatrix" className="btn btn--text" type="button">Cancel</button>
          <button id="btnConfirmDataMatrix" className="btn btn--primary" type="button">Add</button>
        </div>
      </div>
    </div>
  );
}
