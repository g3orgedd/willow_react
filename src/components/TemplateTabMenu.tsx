export function TemplateTabMenu() {
  return (
    <div
      className="templateTabMenu hidden"
      id="templateTabMenu"
      role="menu"
      aria-label="Tab actions"
      aria-hidden="true"
    >
      <button className="templateTabMenu__item" type="button" role="menuitem" data-template-tab-action="close">
        <svg viewBox="0 -960 960 960" aria-hidden="true" focusable="false">
          <path d="m256-200-56-56 224-224-224-224 56-56 224 224 224-224 56 56-224 224 224 224-56 56-224-224-224 224Z" />
        </svg>
        <span data-template-tab-menu-label="close">Close current</span>
      </button>
      <button className="templateTabMenu__item" type="button" role="menuitem" data-template-tab-action="close-others">
        <svg viewBox="0 -960 960 960" aria-hidden="true" focusable="false">
          <path d="M120-200v-560h560v240h160v320H120Zm80-80h400v-400H200v400Zm480 0h80v-160h-80v160ZM280-360h240v-80H280v80Zm0-160h240v-80H280v80Z" />
        </svg>
        <span data-template-tab-menu-label="close-others">Close others</span>
      </button>
      <button className="templateTabMenu__item" type="button" role="menuitem" data-template-tab-action="close-right">
        <svg viewBox="0 -960 960 960" aria-hidden="true" focusable="false">
          <path d="m376-240-56-56 184-184-184-184 56-56 240 240-240 240Zm240 0-56-56 184-184-184-184 56-56 240 240-240 240Z" />
        </svg>
        <span data-template-tab-menu-label="close-right">Close tabs to the right</span>
      </button>
      <button className="templateTabMenu__item" type="button" role="menuitem" data-template-tab-action="close-all">
        <svg viewBox="0 -960 960 960" aria-hidden="true" focusable="false">
          <path d="M200-120q-33 0-56.5-23.5T120-200v-440h80v440h440v80H200Zm160-160q-33 0-56.5-23.5T280-360v-440q0-33 23.5-56.5T360-880h440q33 0 56.5 23.5T880-800v440q0 33-23.5 56.5T800-280H360Zm112-112 108-108 108 108 56-56-108-108 108-108-56-56-108 108-108-108-56 56 108 108-108 108 56 56Z" />
        </svg>
        <span data-template-tab-menu-label="close-all">Close all</span>
      </button>
    </div>
  );
}
