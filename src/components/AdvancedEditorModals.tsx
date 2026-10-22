export function AdvancedEditorModals() {
  return (
    <>
      <div id="dataMatrixEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="datamatrix"></div>
        <div
          className="modal__card modal__card--editor dmEditorModal surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="dataMatrixEditorModalTitle"
          aria-describedby="dataMatrixEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header dmEditorModal__header">
            <div>
              <div className="modal__title" id="dataMatrixEditorModalTitle">DataMatrix</div>
              <div className="modal__subtitle" id="dataMatrixEditorModalSubtitle">Edit the selected DataMatrix profile and segments.</div>
            </div>
            <button id="btnCloseDataMatrixEditor" className="btn btn--text dmEditorModal__close" type="button" aria-label="Close">
              <img className="iconButton__icon" src="/resourses/Icons/close_24dp.svg" alt="" aria-hidden="true" />
            </button>
          </div>
          <div className="editorModal__content">
            <div id="dmEmpty" className="muted">No DataMatrix object found.<br />Create a new DataMatrix or select an existing one.</div>
            <div id="dmPanel" className="form hidden"></div>
          </div>
        </div>
      </div>

      <div id="offsetsEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="offsets"></div>
        <div
          className="modal__card modal__card--editor dateOffsetsModal surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="offsetsEditorModalTitle"
          aria-describedby="offsetsEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header dateOffsetsModal__header">
            <div>
              <div className="modal__title" id="offsetsEditorModalTitle">Date offsets</div>
              <div className="modal__subtitle" id="offsetsEditorModalSubtitle">Manage reusable calculated dates.</div>
            </div>
            <button id="btnCloseOffsetsEditor" className="btn btn--text dateOffsetsModal__close" type="button" aria-label="Close">
              <img className="iconButton__icon" src="/resourses/Icons/close_24dp.svg" alt="" aria-hidden="true" />
            </button>
          </div>
          <section className="dateOffsetsEditor" aria-labelledby="dateOffsetsSectionTitle">
            <div className="dateOffsetsEditor__sectionHeader">
              <h3 id="dateOffsetsSectionTitle" className="dateOffsetsEditor__sectionTitle">Offsets</h3>
              <span id="dateOffsetsCount" className="dateOffsetsEditor__count">0</span>
              <button id="addOffset" className="btn btn--tonal btn--small dateOffsetsEditor__addButton" type="button" aria-label="Add offset">
                <img className="iconButton__icon" src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
                <span>Add offset</span>
              </button>
            </div>
            <div className="editorModal__content">
              <div id="offsetsEditor" className="dateOffsetsList"></div>
            </div>
          </section>
        </div>
      </div>

      <div id="hiddenFieldsEditorModal" className="modal modal--editor hidden" aria-hidden="true">
        <div className="modal__backdrop" data-editor-modal-close="hidden"></div>
        <div
          className="modal__card modal__card--editor hiddenFieldsModal surface-card"
          role="dialog"
          aria-modal="true"
          aria-labelledby="hiddenFieldsEditorModalTitle"
          aria-describedby="hiddenFieldsEditorModalSubtitle"
        >
          <div className="modal__header editorModal__header hiddenFieldsModal__header">
            <div>
              <div className="modal__title" id="hiddenFieldsEditorModalTitle">Hidden fields</div>
              <div className="modal__subtitle" id="hiddenFieldsEditorModalSubtitle">Edit values for non-printed fields.</div>
            </div>
            <button id="btnCloseHiddenFieldsEditor" className="btn btn--text hiddenFieldsModal__close" type="button" aria-label="Close">
              <img className="iconButton__icon" src="/resourses/Icons/close_24dp.svg" alt="" aria-hidden="true" />
            </button>
          </div>
          <section className="hiddenFieldsEditor" aria-labelledby="hiddenFieldsSectionTitle">
            <div className="hiddenFieldsEditor__sectionHeader">
              <h3 id="hiddenFieldsSectionTitle" className="hiddenFieldsEditor__sectionTitle">Fields</h3>
              <span id="hiddenFieldsCount" className="hiddenFieldsEditor__count">0</span>
            </div>
            <div className="editorModal__content">
              <div id="hiddenEditor" className="hiddenFieldsList"></div>
            </div>
          </section>
        </div>
      </div>
    </>
  );
}
