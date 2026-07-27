import { Fragment } from 'react';

type TextPresetCard = {
  id: string;
  name: string;
  value?: string;
  values?: string[];
  mode: 'fixed' | 'user';
  maxCharacters: string;
  printed: boolean;
};

const TEXT_PRESET_CARDS: TextPresetCard[] = [
  { id: 'gtin', name: 'GTIN', value: '00000000000000', mode: 'user', maxCharacters: '14', printed: false },
  { id: 'kripto', name: 'KRIPTO', value: '0000', mode: 'user', maxCharacters: '4', printed: false },
  { id: 'kripto2', name: 'KRIPTO2', value: '00000000000000000000000000000000000000000000', mode: 'user', maxCharacters: '44', printed: false },
  { id: 'sn', name: 'SN', values: ['000000', '0000000000000'], mode: 'user', maxCharacters: '6 / 13', printed: false },
  { id: 'c1', name: 'С1', value: '~101', mode: 'fixed', maxCharacters: '4', printed: false },
  { id: 'c2', name: 'С2', value: '21', mode: 'fixed', maxCharacters: '2', printed: false },
  { id: 'c3', name: 'С3', values: ['~d02991', '~d02993'], mode: 'fixed', maxCharacters: '7', printed: false },
  { id: 'c4', name: 'C4', value: '~d02992', mode: 'fixed', maxCharacters: '7', printed: false },
  { id: 'product_date', name: 'PRODUCT_DATE', value: '0000000000', mode: 'user', maxCharacters: '—', printed: true },
  { id: 'packing_date', name: 'PACKING_DATE', value: '0000000000', mode: 'user', maxCharacters: '—', printed: true },
  { id: 'expiration_date', name: 'EXPIRATION_DATE', value: '0000000000', mode: 'user', maxCharacters: '—', printed: true },
  { id: 'party', name: 'PARTY', value: '00000', mode: 'user', maxCharacters: '—', printed: true },
  { id: 'r_num', name: 'R_NUM', value: '00000', mode: 'user', maxCharacters: '—', printed: true },
  { id: 'team', name: 'TEAM', value: '00', mode: 'user', maxCharacters: '—', printed: true },
];

export function TextFieldModal() {
  return (
    <div id="textFieldModal" className="modal modal--text-field hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div
        className="modal__card modal__card--text-field surface-card"
        role="dialog"
        aria-modal="true"
        aria-labelledby="textFieldModalTitle"
        aria-describedby="textFieldModalSubtitle"
      >
        <div className="modal__header textFieldModal__header">
          <div>
            <div className="modal__title" id="textFieldModalTitle">Add text field</div>
            <div className="modal__subtitle" id="textFieldModalSubtitle">
              Add a regular fixed text field or select one or more ready-made fields.
            </div>
          </div>
        </div>

        <div className="textFieldModal__content">
          <label className="textFieldModeCard" htmlFor="textFieldModeFixed">
            <input id="textFieldModeFixed" name="textFieldMode" type="radio" value="fixed" defaultChecked />
            <span>
              <strong id="textFieldModeFixedTitle">Fixed text</strong>
              <small id="textFieldModeFixedDescription">Create the same editable fixed text field as before.</small>
            </span>
          </label>

          <label className="textFieldModeCard" htmlFor="textFieldModePresets">
            <input id="textFieldModePresets" name="textFieldMode" type="radio" value="presets" />
            <span>
              <strong id="textFieldModePresetsTitle">Ready-made fields</strong>
              <small id="textFieldModePresetsDescription">Select several fields to add them in one vertical stack.</small>
            </span>
          </label>

          <div id="textFieldPresetList" className="textPresetList">
            {TEXT_PRESET_CARDS.map((preset) => (
              <Fragment key={preset.id}>
                {preset.id === 'product_date' ? (
                  <div className="textPresetList__divider" aria-hidden="true"></div>
                ) : null}
                <div className="textPresetCard" data-text-preset-row={preset.id}>
                <label className="textPresetCard__main" htmlFor={`textPreset-${preset.id}`}>
                  <input
                    id={`textPreset-${preset.id}`}
                    className="textPresetCard__checkbox"
                    type="checkbox"
                    data-text-preset={preset.id}
                  />
                  <span className="textPresetCard__copy">
                    <strong>{preset.name}</strong>
                    {preset.value ? <code>{preset.value}</code> : null}
                  </span>
                </label>

                {preset.values ? (
                  <select
                    className="select textPresetCard__variant"
                    data-text-preset-value={preset.id}
                    defaultValue=""
                    disabled
                    aria-label={`${preset.name} value`}
                  >
                    <option value="">Select value</option>
                    {preset.values.map((value) => <option value={value} key={value}>{value}</option>)}
                  </select>
                ) : null}

                <div className="textPresetCard__meta">
                  <span className={preset.mode === 'user' ? 'textPresetTypeUser' : 'textPresetTypeFixed'}>
                    {preset.mode === 'user' ? 'User entered' : 'Fixed'}
                  </span>
                  <span className={preset.printed ? 'textPresetPrintPrinted' : 'textPresetPrintHidden'}>
                    {preset.printed ? 'Printed' : 'Not printed'}
                  </span>
                  <span><span className="textPresetMaxLabel">Max</span>: {preset.maxCharacters}</span>
                </div>
                <div className="textPresetCard__status" data-text-preset-status={preset.id}></div>
                </div>
              </Fragment>
            ))}
          </div>

          <div id="textFieldPresetError" className="note textFieldModal__error" aria-live="polite"></div>
        </div>

        <div className="modal__actions textFieldModal__actions">
          <button id="btnCancelTextField" className="btn btn--text" type="button">Cancel</button>
          <button id="btnConfirmTextField" className="btn btn--primary" type="button">Add</button>
        </div>
      </div>
    </div>
  );
}
