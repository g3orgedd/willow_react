const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const root = path.join(__dirname, '..');
const modal = fs.readFileSync(path.join(root, 'src', 'components', 'NewTemplateModal.tsx'), 'utf8');
const styles = fs.readFileSync(path.join(root, 'public', 'styles.css'), 'utf8');
const builder = fs.readFileSync(path.join(root, 'public', 'modules', '45-template-preset.js'), 'utf8');

function between(source, startMarker, endMarker) {
  const start = source.indexOf(startMarker);
  const end = source.indexOf(endMarker, start + startMarker.length);
  assert.ok(start >= 0 && end > start, `${startMarker} must remain extractable`);
  return source.slice(start, end);
}

test('template wizard keeps its existing hooks on one semantic modal surface', () => {
  assert.match(modal, /className="modal__card modal__card--builder templateWizard surface-card"/);
  assert.match(modal, /<header className="modal__header templateWizard__header">/);
  assert.match(modal, /className="dialogContent builderDialogContent templateWizard__content"/);
  assert.match(modal, /className="modal__actions templateWizard__footer"/);

  for (let step = 0; step <= 5; step += 1) {
    assert.match(modal, new RegExp(`data-builder-step="${step}"`));
  }
  for (const id of [
    'newTemplatePrinterModel', 'newTemplatePrintMode', 'newTemplateWidth', 'newTemplateHeight',
    'builderSymbolSize', 'builderSnValue', 'builderModuleSize', 'builderSummary', 'builderValidation',
    'btnCancelNewTemplate', 'btnBuilderBack', 'btnBuilderNext', 'btnCreateNewTemplate'
  ]) {
    assert.match(modal, new RegExp(`id="${id}"`));
  }

  assert.match(modal, /className="note builderSizeHint"/);
  assert.match(modal, /className="fieldFilter snLengthSelector"/);
});

test('creation method and data source options expose radio semantics', () => {
  assert.equal((modal.match(/role="radiogroup"/g) || []).length, 2);
  assert.equal((modal.match(/role="radio" aria-checked="false"/g) || []).length, 5);

  const renderStep = between(builder, 'function renderTemplateBuilderStep()', 'function resetTemplateBuilder()');
  assert.match(renderStep, /element\.setAttribute\("aria-checked", String\(isSelected\)\)/);
  assert.match(renderStep, /templateBuilderStep \? `\$\{templateBuilderStep\} \/ \$\{/);
});

test('wizard layout is flat, scrollable, and responsive', () => {
  assert.match(styles, /#newTemplateModal \.modal__card\.modal__card--builder\s*\{[^}]*width:\s*min\(620px,[^}]*max-height:\s*min\(760px,[^}]*border-radius:\s*var\(--app-radius-md\);/s);
  assert.match(styles, /#newTemplateModal \.templateWizard__content\s*\{[^}]*overflow-y:\s*auto;/s);
  assert.match(styles, /#newTemplateModal > \.modal__backdrop\s*\{[^}]*backdrop-filter:\s*blur\(2\.5px\);/s);
  assert.match(styles, /\.canvasWrap\.is-file-dragging::before\s*\{[^}]*backdrop-filter:\s*blur\(2\.5px\);/s);
  assert.match(styles, /\.builderFieldChoice\s*\{[^}]*border:\s*0;[^}]*background:\s*transparent;/s);
  assert.doesNotMatch(styles, /\.builderFieldChoice:focus-within\s*\{/);
  assert.match(styles, /\.builderFieldChoice input\s*\{[^}]*appearance:\s*none;[^}]*check_box_outline_blank_24dp\.svg/s);
  assert.match(styles, /\.builderFieldChoice input:checked\s*\{[^}]*check_box_24dp\.svg/s);
  assert.match(styles, /\.builderFieldChoice input:focus-visible\s*\{[^}]*outline:\s*2px solid var\(--md-sys-color-primary\);/s);
  assert.match(styles, /\.builderFieldSettings\s*\{[^}]*border:\s*0;[^}]*border-radius:\s*0;[^}]*background:\s*transparent;/s);
  assert.match(styles, /\.builderFieldSettings\.is-open\s*\{[^}]*border-top:\s*1px solid/s);
  assert.match(styles, /@media \(max-width: 560px\)[\s\S]*?#newTemplateModal \.fieldRow\s*\{[^}]*grid-template-columns:\s*minmax\(0, 1fr\);/);
});

test('review step uses structured sections without summary cards or chips', () => {
  const summary = between(builder, 'function renderTemplateBuilderSummary()', 'function getTemplateBuilderStepValidity()');
  assert.match(summary, /<section class="builderSummary__section">/);
  assert.match(summary, /<dl class="builderSummary__rows">/);
  assert.match(summary, /builderCopy\("summaryDataSource"\)/);
  assert.match(summary, /selected\.length \? `[^`]*builderSummary__section/s);
  assert.doesNotMatch(summary, /DataMatrix only/);
  assert.match(styles, /\.builderSummary__row\s*\{[^}]*border:\s*0;[^}]*border-radius:\s*0;[^}]*background:\s*transparent;/s);
  assert.match(styles, /\.builderSummary__fields span\s*\{[^}]*border:\s*0;[^}]*border-radius:\s*0;[^}]*background:\s*transparent;/s);
});

test('wizard navigation and creation paths remain connected to the existing state machine', () => {
  const init = between(builder, 'function initTemplatePresetBuilder()', 'function createTemplateFromBuilderDialog()');
  const create = between(builder, 'function createTemplateFromBuilderDialog()', 'globalThis.createDefaultTemplatePresetDraft');

  assert.match(init, /templateBuilderStep \+= 1/);
  assert.match(init, /templateBuilderStep = Math\.max\(0, templateBuilderStep - 1\)/);
  assert.match(create, /if \(draft\.creationKind === "empty"\)\s*\{\s*createNewTemplateFromDialog\(\)/s);
  assert.match(create, /const result = generateTemplatePreset\(draft\)/);
  assert.match(create, /const committed = commitGeneratedTemplatePreset\(result\)/);
});
