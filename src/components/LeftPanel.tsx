import { useId } from 'react';

function HiddenCanvasToggleIcon() {
  const maskId = useId();

  return (
    <svg className="btnIcon hiddenCanvasToggleIcon" viewBox="0 -960 960 960" fill="none" aria-hidden="true" focusable="false">
      <defs>
        <mask id={maskId} maskUnits="userSpaceOnUse" x="0" y="-960" width="960" height="960">
          <rect x="0" y="-960" width="960" height="960" fill="white" />
          <path className="hiddenCanvasToggleIcon__slash" d="M112 -848 L848 -112" pathLength="1" stroke="black" strokeWidth="160" strokeLinecap="round" />
        </mask>
      </defs>
      <path
        fill="currentColor"
        mask={`url(#${maskId})`}
        d="M607.5-372.5Q660-425 660-500t-52.5-127.5Q555-680 480-680t-127.5 52.5Q300-575 300-500t52.5 127.5Q405-320 480-320t127.5-52.5Zm-204-51Q372-455 372-500t31.5-76.5Q435-608 480-608t76.5 31.5Q588-545 588-500t-31.5 76.5Q525-392 480-392t-76.5-31.5ZM214-281.5Q94-363 40-500q54-137 174-218.5T480-800q146 0 266 81.5T920-500q-54 137-174 218.5T480-200q-146 0-266-81.5ZM480-500Zm207.5 160.5Q782-399 832-500q-50-101-144.5-160.5T480-720q-113 0-207.5 59.5T128-500q50 101 144.5 160.5T480-280q113 0 207.5-59.5Z"
      />
      <path className="hiddenCanvasToggleIcon__slash" d="M112 -848 L848 -112" pathLength="1" stroke="currentColor" strokeWidth="80" strokeLinecap="round" />
    </svg>
  );
}

export function LeftPanel() {
  return (
    <>
      <aside
        id="leftPanel"
        className="panel panel--left leftPanel surface-card"
        aria-labelledby="fieldBrowserTitle"
        data-collapsed="false"
      >
        <div id="leftPanelExpanded" className="leftPanel__expanded">
          <header className="leftPanel__header">
            <h2 id="fieldBrowserTitle" className="leftPanel__title">Objects</h2>
            <div className="leftPanel__headerActions">
              <button
                id="btnToggleFieldSearch"
                className="btn btn--ghost leftPanelIconButton"
                type="button"
                aria-label="Search objects"
                aria-expanded="false"
                aria-controls="leftPanelSearch"
              >
                <img className="btnIcon" src="/resourses/Icons/search_24dp.svg" alt="" aria-hidden="true" />
              </button>
              <button
                id="btnCollapseLeftPanel"
                className="btn btn--ghost leftPanelIconButton"
                type="button"
                aria-label="Collapse objects panel"
                aria-controls="leftPanel"
                aria-expanded="true"
              >
                <img className="btnIcon" src="/resourses/Icons/chevron_backward.svg" alt="" aria-hidden="true" />
              </button>
            </div>
          </header>

          <div id="leftPanelSearch" className="leftPanelSearch" aria-hidden="true">
            <label className="srOnly" id="searchField" htmlFor="fieldSearch">Search objects</label>
            <div className="panelSearchSlot leftPanelSearch__field">
              <img className="panelSearchIcon" src="/resourses/Icons/search_24dp.svg" alt="" aria-hidden="true" />
              <input id="fieldSearch" className="input panelSearch" type="search" placeholder="Search objects" tabIndex={-1} />
              <button
                id="btnCloseFieldSearch"
                className="btn btn--ghost leftPanelSearch__close"
                type="button"
                aria-label="Clear and close search"
                tabIndex={-1}
              >
                <img className="btnIcon" src="/resourses/Icons/close_24dp.svg" alt="" aria-hidden="true" />
              </button>
            </div>
          </div>

          <div className="leftPanel__filterRow">
            <div className="fieldFilter fieldFilter--fieldBrowser leftPanelTabs" role="tablist" aria-label="Filter objects">
              <button
                className="fieldFilter__button fieldFilter__button--active"
                type="button"
                role="tab"
                data-field-filter="printed"
                aria-controls="fieldsList"
                aria-selected="true"
                aria-pressed="true"
              >
                <span data-field-filter-label="printed">Printed</span>
                <span className="fieldFilter__count" data-field-filter-count="printed">0</span>
              </button>
              <button
                className="fieldFilter__button"
                type="button"
                role="tab"
                data-field-filter="hidden"
                aria-controls="fieldsList"
                aria-selected="false"
                aria-pressed="false"
                tabIndex={-1}
              >
                <span data-field-filter-label="hidden">Hidden</span>
                <span className="fieldFilter__count" data-field-filter-count="hidden">0</span>
              </button>
            </div>
            <button
              id="btnShowHiddenOnCanvas"
              className="btn btn--ghost leftPanelIconButton"
              type="button"
              aria-label="Show hidden fields"
              aria-pressed="false"
            >
              <HiddenCanvasToggleIcon />
            </button>
          </div>
        </div>

        <div id="leftPanelCollapsedActions" className="leftPanel__collapsedActions" aria-hidden="true">
          <button
            id="btnAddObjectCollapsed"
            className="btn btn--ghost leftPanelIconButton"
            type="button"
            aria-label="Add object"
            aria-haspopup="dialog"
            aria-expanded="false"
            aria-controls="leftAddObjectPopover"
            tabIndex={-1}
          >
            <img className="btnIcon" src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
          </button>
          <div className="leftPanel__collapsedTopActions">
            <button
              id="btnToggleFieldSearchCollapsed"
              className="btn btn--ghost leftPanelIconButton"
              type="button"
              aria-label="Search objects"
              aria-controls="leftPanelSearch"
              aria-expanded="false"
              tabIndex={-1}
            >
              <img className="btnIcon" src="/resourses/Icons/search_24dp.svg" alt="" aria-hidden="true" />
            </button>
            <button
              id="btnShowHiddenOnCanvasCollapsed"
              className="btn btn--ghost leftPanelIconButton"
              type="button"
              aria-label="Show hidden fields"
              aria-pressed="false"
              tabIndex={-1}
            >
              <HiddenCanvasToggleIcon />
            </button>
          </div>
        </div>

        <div id="fieldsList" className="list leftPanel__list" role="list" aria-labelledby="fieldBrowserTitle"></div>

        <section className="leftPanel__addSection" aria-labelledby="leftPanelAddSectionTitle">
          <h3 id="leftPanelAddSectionTitle" className="leftPanel__addSectionTitle">Add</h3>
          <div className="toolgrid leftPanelAddGrid" aria-label="Add object">
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
        </section>

        <button
          id="btnExpandLeftPanel"
          className="btn btn--ghost leftPanelIconButton leftPanel__expandButton"
          type="button"
          aria-label="Expand objects panel"
          aria-controls="leftPanel"
          aria-expanded="false"
          tabIndex={-1}
        >
          <img className="btnIcon" src="/resourses/Icons/chevron_forward.svg" alt="" aria-hidden="true" />
        </button>
      </aside>

      <div
        id="leftAddObjectPopover"
        className="leftPanelAddPopover hidden"
        role="dialog"
        aria-modal="false"
        aria-labelledby="leftAddObjectPopoverTitle"
        aria-hidden="true"
      >
        <div id="leftAddObjectPopoverTitle" className="leftPanelAddPopover__header">Add object</div>
        <div className="toolgrid leftPanelAddGrid" aria-label="Add object">
          <button className="btn btn--ghost toolButton" data-add-object-target="addDataMatrix" type="button">
            <img className="buttonIcon" src="/resourses/Icons/datamatrix_24dp.svg" alt="" aria-hidden="true" />
            <span>DataMatrix</span>
          </button>

          <button className="btn btn--ghost toolButton" data-add-object-target="addFixedText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/text_fields_24dp.svg" alt="" aria-hidden="true" />
            <span>Text</span>
          </button>

          <button className="btn btn--ghost toolButton" data-add-object-target="addDateText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/calendar_month_24dp.svg" alt="" aria-hidden="true" />
            <span>Date</span>
          </button>

          <button className="btn btn--ghost toolButton" data-add-object-target="addTimeText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/clock_loader_24dp.svg" alt="" aria-hidden="true" />
            <span>Time</span>
          </button>

          <button className="btn btn--ghost toolButton" data-add-object-target="addOffsetDateText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/move_up_24dp.svg" alt="" aria-hidden="true" />
            <span>Offset</span>
          </button>

          <button className="btn btn--ghost toolButton" data-add-object-target="addCounterText" type="button">
            <img className="buttonIcon" src="/resourses/Icons/decimal_increase_24dp.svg" alt="" aria-hidden="true" />
            <span>Counter</span>
          </button>
        </div>
      </div>
    </>
  );
}
