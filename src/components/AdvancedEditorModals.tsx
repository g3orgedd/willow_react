export function AdvancedEditorModals() {
  return (
    <>
      <div id="dataMatrixEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="datamatrix"></div>
        <div
          className="modal__card modal__card--editor surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="dataMatrixEditorModalTitle"
          aria-describedby="dataMatrixEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header">
            <div>
              <div className="modal__title" id="dataMatrixEditorModalTitle">DataMatrix</div>
              <div className="modal__subtitle" id="dataMatrixEditorModalSubtitle">Edit the selected DataMatrix profile and segments.</div>
            </div>
          </div>
          <div className="editorModal__content">
            <div id="dmEmpty" className="muted">No DataMatrix object found.<br />Create a new DataMatrix or select an existing one.</div>
            <div id="dmPanel" className="form hidden"></div>
          </div>
          <div className="modal__actions editorModal__actions">
            <button id="btnCloseDataMatrixEditor" className="btn btn--primary" type="button">Close</button>
          </div>
        </div>
      </div>

      <div id="offsetsEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="offsets"></div>
        <div
          className="modal__card modal__card--editor surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="offsetsEditorModalTitle"
          aria-describedby="offsetsEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header editorModal__header--actions">
            <div>
              <div className="modal__title" id="offsetsEditorModalTitle">Date offsets</div>
              <div className="modal__subtitle" id="offsetsEditorModalSubtitle">Manage reusable calculated dates.</div>
            </div>
            <button id="addOffset" className="btn btn--tonal btn--icon" type="button" aria-label="Add offset" title="Add offset">
              <img className="iconButton__icon" src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
            </button>
          </div>
          <div className="editorModal__content">
            <div id="offsetsEditor" className="hiddenEditor"></div>
          </div>
          <div className="modal__actions editorModal__actions">
            <button id="btnCloseOffsetsEditor" className="btn btn--primary" type="button">Close</button>
          </div>
        </div>
      </div>

      <div id="hiddenFieldsEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="hidden"></div>
        <div
          className="modal__card modal__card--editor surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="hiddenFieldsEditorModalTitle"
          aria-describedby="hiddenFieldsEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header">
            <div>
              <div className="modal__title" id="hiddenFieldsEditorModalTitle">Hidden fields</div>
              <div className="modal__subtitle" id="hiddenFieldsEditorModalSubtitle">Edit values for non-printed fields.</div>
            </div>
          </div>
          <div className="editorModal__content">
            <div id="hiddenEditor" className="hiddenEditor"></div>
          </div>
          <div className="modal__actions editorModal__actions">
            <button id="btnCloseHiddenFieldsEditor" className="btn btn--primary" type="button">Close</button>
          </div>
        </div>
      </div>
    </>
  );
}
