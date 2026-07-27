export function TopBar() {
  return (
  <header className="topbar">
    <div className="topbar__brandCluster">
      <button id="mobilePanelMenuToggle" className="btn btn--ghost btn--icon mobilePanelMenuToggle surface-card" type="button" aria-label="Open panels menu" aria-controls="mobilePanelMenu" aria-expanded="false" title="Panels menu">
        <img className="iconButton__icon" src="/resourses/Icons/menu_24dp.svg" alt="" aria-hidden="true" />
      </button>

      <div className="brand surface-card">
        <div className="brand__icon">
          <img id="logo" src="/resourses/Icons/azm_24dp.svg" alt="" aria-hidden="true" />
        </div>
        <div className="brand__copy">
          <div className="brand__eyebrow">Willow XML</div>
          <div className="brand__title">CIFF Editor</div>
        </div>
      </div>

      <div className="topbar__actions topbar__actions--primary">
        <button id="btnNewTemplate" className="btn btn--tonal topbarAction" type="button" aria-label="Create template" title="Create template">
          <img className="buttonIcon" src="/resourses/Icons/add_circle_24dp.svg" alt="" aria-hidden="true" />
          <span>Create</span>
        </button>

        <button id="btnOpenFile" className="btn btn--ghost topbarAction" type="button" aria-label="Open file" title="Open file">
          <img className="buttonIcon" src="/resourses/Icons/upload_file_24dp.svg" alt="" aria-hidden="true" />
          <span>Open</span>
        </button>
        <input id="fileInput" type="file" accept=".ciff,.xml,text/xml" hidden />

        <button id="btnSave" className="btn btn--primary topbarAction" type="button" aria-label="Save file" title="Save file">
          <img className="buttonIcon" src="/resourses/Icons/save_24dp.svg" alt="" aria-hidden="true" />
          <span>Save</span>
        </button>
      </div>
    </div>

    <div className="topbar__actions topbar__actions--utility">
      <div className="utilityGroup surface-card">
        <button id="btnUndo" className="btn btn--ghost btn--icon" type="button" aria-label="Undo" title="Undo (Ctrl+Z)">
          <img className="iconButton__icon" src="/resourses/Icons/undo_24dp.svg" alt="" aria-hidden="true" />
        </button>

        <button id="btnRedo" className="btn btn--ghost btn--icon" type="button" aria-label="Redo" title="Redo (Ctrl+Y)">
          <img className="iconButton__icon" src="/resourses/Icons/redo_24dp.svg" alt="" aria-hidden="true" />
        </button>
      </div>

      <button id="btnPanMode" className="btn btn--ghost mobilePanToggle surface-card" type="button" aria-label="Pan canvas" title="Pan mode" aria-pressed="false">
        <img className="buttonIcon" src="/resourses/Icons/pan_tool_24dp.svg" alt="" aria-hidden="true" />
        <span>Pan</span>
      </button>

      <div className="utilityGroup utilityGroup--toggles surface-card">
        <label className="utilityToggle" htmlFor="toggleGrid" id="toggleGrid_ID">
          <input id="toggleGrid" type="checkbox" defaultChecked />
          <span>Grid</span>
        </label>

        <label className="utilityToggle" htmlFor="toggleSnap" id="toggleSnap_ID">
          <input id="toggleSnap" type="checkbox" defaultChecked />
          <span>Snap</span>
        </label>

        <label className="utilityToggle" htmlFor="toggleAlign" id="toggleAlign_ID">
          <input id="toggleAlign" type="checkbox" />
          <span className="utilityToggle__label">
            <span className="utilityToggle__full">Align</span>
            <span className="utilityToggle__short">Align</span>
          </span>
        </label>
      </div>

      <div className="zoom surface-card">
        <button id="zoomOut" className="btn btn--ghost btn--icon" type="button" aria-label="Zoom out">
          <img className="iconButton__icon" src="/resourses/Icons/remove_24dp.svg" alt="" aria-hidden="true" />
        </button>

        <div className="zoom__sliderWrap">
          <label className="srOnly" htmlFor="zoomRange">Zoom</label>
          <input id="zoomRange" className="zoomRange" type="range" min="25" max="400" defaultValue="100" step="1" />
        </div>

        <button id="zoomIn" className="btn btn--ghost btn--icon" type="button" aria-label="Zoom in">
          <img className="iconButton__icon" src="/resourses/Icons/add_24dp.svg" alt="" aria-hidden="true" />
        </button>

        <div id="zoomLabel" className="zoom__label">100%</div>
      </div>
    </div>
  </header>
  );
}
