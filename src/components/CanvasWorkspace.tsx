import { TemplateTabs } from './TemplateTabs';

export function CanvasWorkspace() {
  return (
    <section className="canvasWrap surface-card">
      <TemplateTabs />
      <div className="canvasViewport" id="canvasViewport">
        <div className="rulerCorner" aria-hidden="true"></div>
        <canvas className="rulerCanvas rulerCanvas--top" id="rulerTop" aria-hidden="true"></canvas>
        <canvas className="rulerCanvas rulerCanvas--left" id="rulerLeft" aria-hidden="true"></canvas>
        <div className="canvasHost" id="canvasHost"></div>
        <div className="precisionMovePanel" id="precisionMovePanel" aria-label="Precise object movement" aria-hidden="true">
          <button
            className="precisionMoveButton precisionMoveButton--up"
            id="precisionMoveUp"
            type="button"
            data-precision-move="up"
            data-move-dx="0"
            data-move-dy="-0.1"
            title="Move up 0.1 mm"
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
            data-move-dx="-0.1"
            data-move-dy="0"
            title="Move left 0.1 mm"
            aria-label="Move selected object left 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_upward_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <button
            className="precisionMoveButton precisionMoveButton--right"
            id="precisionMoveRight"
            type="button"
            data-precision-move="right"
            data-move-dx="0.1"
            data-move-dy="0"
            title="Move right 0.1 mm"
            aria-label="Move selected object right 0.1 mm"
            disabled
          >
            <img src="/resourses/Icons/arrow_upward_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <button
            className="precisionMoveButton precisionMoveButton--down"
            id="precisionMoveDown"
            type="button"
            data-precision-move="down"
            data-move-dx="0"
            data-move-dy="0.1"
            title="Move down 0.1 mm"
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
