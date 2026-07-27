export function TemplateTabs() {
  return (
    <div className="templateTabs" id="templateTabs" aria-label="Open templates">
      <div className="templateTabs__list" id="templateTabsList" role="tablist"></div>
      <button
        className="templateTabs__add"
        id="btnAddTemplateTab"
        type="button"
        aria-label="Create template in new tab"
        title="Create template in new tab"
      >
        <img src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
      </button>
    </div>
  );
}
