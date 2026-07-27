export function MobilePanels() {
  return (
    <>
  <div id="mobilePanelMenuOverlay" className="mobilePanelMenuOverlay" hidden></div>
  <aside id="mobilePanelMenu" className="mobilePanelMenu" aria-hidden="true" aria-label="Panels menu" hidden>
    <div className="mobilePanelMenu__header">
      <div>
        <div className="panel__title">Panels</div>
        <div className="muted">Tools and settings</div>
      </div>
      <button id="mobilePanelMenuClose" className="btn btn--ghost btn--icon" type="button" aria-label="Close panels menu" title="Close">
        <img className="iconButton__icon" src="/resourses/Icons/close_24dp.svg" alt="" aria-hidden="true" />
      </button>
    </div>

    <div className="mobilePanelMenu__content">
      <div id="mobileRightPanelSlot" className="mobilePanelMenu__slot"></div>
      <div id="mobileLeftPanelSlot" className="mobilePanelMenu__slot"></div>
    </div>
  </aside>
    </>
  );
}
