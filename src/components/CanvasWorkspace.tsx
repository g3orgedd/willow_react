import { TemplateTabs } from './TemplateTabs';

export function CanvasWorkspace() {
  return (
    <section className="canvasWrap editorWorkspace">
      <div className="templateDropPrompt" aria-hidden="true">
        <span className="templateDropPrompt__icon" aria-hidden="true">
          <img src="/resourses/Icons/upload_file_24dp.svg" alt="" />
        </span>
        <span className="templateDropPrompt__text">Drop the file to open the template</span>
      </div>
      <TemplateTabs />
      <div className="canvasViewport" id="canvasViewport">
        <div className="rulerCorner" aria-hidden="true"></div>
        <canvas className="rulerCanvas rulerCanvas--top" id="rulerTop" aria-hidden="true"></canvas>
        <canvas className="rulerCanvas rulerCanvas--left" id="rulerLeft" aria-hidden="true"></canvas>
        <div className="canvasHost" id="canvasHost"></div>
        <div className="precisionMovePanel" id="precisionMovePanel" role="group" aria-label="Precise object movement" aria-hidden="true">
          <button
            className="precisionMoveButton precisionMoveButton--up"
            id="precisionMoveUp"
            type="button"
            data-precision-move="up"
            aria-label="Move selected object up 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_upward_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <button
            className="precisionMoveButton precisionMoveButton--left"
            id="precisionMoveLeft"
            type="button"
            data-precision-move="left"
            aria-label="Move selected object left 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_back_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <div className="precisionMoveStep">
            <select id="precisionMoveStep" className="select" aria-label="Move step (mm)" />
          </div>
          <button
            className="precisionMoveButton precisionMoveButton--right"
            id="precisionMoveRight"
            type="button"
            data-precision-move="right"
            aria-label="Move selected object right 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_forward_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <button
            className="precisionMoveButton precisionMoveButton--down"
            id="precisionMoveDown"
            type="button"
            data-precision-move="down"
            aria-label="Move selected object down 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_downward_24dp.svg" alt="" aria-hidden="true" />
          </button>
        </div>
      </div>

      <div className="statusbar">
        <div id="statusLeft" className="statusbar__item">Open a CIFF file (.ciff/.xml).</div>
        <div id="statusRight" className="statusbar__item">-</div>
      </div>
    </section>
  );
}
