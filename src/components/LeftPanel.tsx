export function LeftPanel() {
  return (
    <aside className="panel panel--left surface-card">
      <div className="panel__section panel__section--dense">
        <div className="toolgrid" aria-label="Add object">
          <button className="btn btn--ghost toolButton" id="addDataMatrix" type="button">
            <img className="buttonIcon" src="/resourses/Icons/datamatrix_24dp.svg" alt="" aria-hidden="true" />
            <span>DataMatrix</span>
          </button>

          <button className="btn btn--ghost toolButton" id="addFixedText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/text_fields_24dp.svg" alt="" aria-hidden="true" />
            <span>Text</span>
          </button>

          <button className="btn btn--ghost toolButton" id="addDateText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/calendar_month_24dp.svg" alt="" aria-hidden="true" />
            <span>Date</span>
          </button>

          <button className="btn btn--ghost toolButton" id="addTimeText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/clock_loader_24dp.svg" alt="" aria-hidden="true" />
            <span>Time</span>
          </button>

          <button className="btn btn--ghost toolButton" id="addOffsetDateText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/move_up_24dp.svg" alt="" aria-hidden="true" />
            <span>Offset</span>
          </button>

          <button className="btn btn--ghost toolButton" id="addCounterText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/decimal_increase_24dp.svg" alt="" aria-hidden="true" />
            <span>Counter</span>
          </button>
        </div>
      </div>

      <div className="panel__section panel__section--fill fieldBrowser">
        <div className="srOnly" id="fieldBrowserTitle">Fields</div>
        <div className="fieldBrowser__controls">
          <label className="srOnly" id="searchField" htmlFor="fieldSearch">Search fields</label>
          <div className="panelSearchSlot fieldBrowser__search">
            <img className="panelSearchIcon" src="/resourses/Icons/search_24dp.svg" alt="" aria-hidden="true" />
            <input id="fieldSearch" className="input panelSearch" type="search" placeholder="Search fields" />
          </div>
          <button id="btnShowHiddenOnCanvas" className="btn btn--ghost btn--icon" type="button" aria-label="Show hidden fields" title="Show hidden fields">
            <img className="btnIcon" src="/resourses/Icons/visibility_24dp.svg" alt="" aria-hidden="true" />
          </button>
        </div>

        <div className="fieldFilter" role="group" aria-label="Filter fields">
          <button className="fieldFilter__button fieldFilter__button--active" type="button" data-field-filter="printed" aria-pressed="true">
            <span data-field-filter-label="printed">Printed</span>
            <span className="fieldFilter__count" data-field-filter-count="printed">0</span>
          </button>
          <button className="fieldFilter__button" type="button" data-field-filter="hidden" aria-pressed="false">
            <span data-field-filter-label="hidden">Hidden</span>
            <span className="fieldFilter__count" data-field-filter-count="hidden">0</span>
          </button>
        </div>

        <div id="fieldsList" className="list" aria-labelledby="fieldBrowserTitle"></div>
      </div>
    </aside>
  );
}
