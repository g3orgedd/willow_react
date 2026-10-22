export function TemplateTabs() {
  return (
    <div className="templateTabs" id="templateTabs" aria-label="Open templates">
      <div className="templateTabs__list" id="templateTabsList" role="tablist"></div>
      <button
        className="templateTabs__add templateTabs__menuButton"
        id="btnTemplateTabsMenu"
        type="button"
        aria-label="Manage tabs"
        aria-haspopup="menu"
        aria-expanded="false"
        aria-controls="templateTabMenu"
      >
        <svg className="templateTabs__actionIcon" viewBox="0 0 18 18" aria-hidden="true" focusable="false">
          <circle cx="9" cy="4.5" r="1.4" />
          <circle cx="9" cy="9" r="1.4" />
          <circle cx="9" cy="13.5" r="1.4" />
        </svg>
      </button>
      <button
        className="templateTabs__add"
        id="btnAddTemplateTab"
        type="button"
        aria-label="Create template in new tab"
      >
        <img src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
      </button>
    </div>
  );
}
