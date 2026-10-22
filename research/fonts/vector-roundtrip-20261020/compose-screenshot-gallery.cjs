// Compose four existing, genuine editor screenshots. Missing screenshots are
// an error; this script never substitutes a generated layout for a GUI capture.
// electron.exe compose-screenshot-gallery.cjs --clarisoft-web=C:\...\web.png --clarisoft-exe=C:\...\exe.png
const { app, BrowserWindow, nativeImage } = require('electron');
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const { pathToFileURL } = require('node:url');
const argument = (name) => process.argv.find(value => value.startsWith('--' + name + '='))?.slice(name.length + 3);
const directory = __dirname;
const output = argument('output') ? path.resolve(argument('output')) : path.join(directory, 'screenshots-side-by-side');
const inputs = [
  { id: 'web', label: 'Веб-версия Glyph', file: argument('web') || path.join(directory, fs.existsSync(path.join(directory, 'web-vector-editor-full.png')) ? 'web-vector-editor-full.png' : 'web-vector-editor.png'), output: 'web-preview.png', ciff: 'web-vector.ciff' },
  { id: 'clarisoft-web', label: 'ClariSoft · файл из веб-версии', file: argument('clarisoft-web'), output: 'clarisoft-web.png', ciff: 'web-vector.ciff' },
  { id: 'exe', label: 'Glyph Studio.exe', file: argument('exe') || path.join(directory, fs.existsSync(path.join(directory, 'exe-vector-editor-full.png')) ? 'exe-vector-editor-full.png' : 'exe-vector-editor.png'), output: 'exe-preview.png', ciff: 'exe-vector.ciff' },
  { id: 'clarisoft-exe', label: 'ClariSoft · файл из EXE', file: argument('clarisoft-exe'), output: 'clarisoft-exe.png', ciff: 'exe-vector.ciff' },
];
for (const input of inputs) {
  if (!input.file || !fs.existsSync(input.file)) throw new Error('A genuine GUI screenshot is required for ' + input.id + ': ' + input.file);
  input.file = path.resolve(input.file);
  const image = nativeImage.createFromPath(input.file);
  if (image.isEmpty()) throw new Error('Invalid screenshot: ' + input.file);
  input.dimensions = image.getSize();
  input.sha256 = crypto.createHash('sha256').update(fs.readFileSync(input.file)).digest('hex');
}
fs.mkdirSync(output, { recursive: true });
for (const input of inputs) fs.copyFileSync(input.file, path.join(output, input.output));
const manifest = { createdAt: new Date().toISOString(), method: 'Unmodified genuine GUI captures, arranged side by side. The composite scales each whole image to fit; the originals retain their pixels.', inputs };
fs.writeFileSync(path.join(output, 'screenshot-sources.json'), JSON.stringify(manifest, null, 2));
const card = input => `<article class="card"><header><div><h2>${input.label}</h2><p>${input.ciff} · исходник ${input.dimensions.width}×${input.dimensions.height}</p></div><a href="${input.output}" target="_blank">Оригинал ↗</a></header><figure><img src="${input.output}" alt="${input.label}" decoding="sync"></figure></article>`;
const html = `<!doctype html><html lang="ru"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>Glyph и ClariSoft — настоящие снимки интерфейсов</title><style>
*{box-sizing:border-box}body{margin:0;background:#f0f2f5;color:#19202b;font-family:Segoe UI,Arial,sans-serif}main{max-width:2448px;margin:auto;padding:24px}.intro{display:flex;justify-content:space-between;gap:20px;align-items:center;margin-bottom:22px}.intro h1{font-size:27px;margin:0 0 6px}.intro p{font-size:16px;color:#526071;margin:0;line-height:1.5}button{font:inherit;border:1px solid #bdc7d5;background:white;padding:9px 15px;border-radius:8px;cursor:pointer;white-space:nowrap}button[aria-pressed=true]{background:#dce8ff;border-color:#7b9bd3}.row{display:grid;grid-template-columns:minmax(0,1fr) minmax(0,1fr);gap:20px;margin-bottom:24px}.card{background:white;border:1px solid #d5dce6;border-radius:12px;overflow:hidden}.card header{height:82px;display:flex;justify-content:space-between;gap:12px;align-items:center;padding:15px 20px;border-bottom:1px solid #e2e6ec}.card h2{font-size:20px;margin:0 0 5px}.card p{font-size:13px;color:#657386;margin:0}.card a{font-size:14px;color:#295aa9;text-decoration:none;white-space:nowrap}figure{margin:0;height:820px;display:flex;align-items:flex-start;justify-content:center;overflow:auto;background:#e6e9ed;padding:12px}img{display:block;max-width:100%;max-height:100%;object-fit:contain}.actual figure{display:block}.actual img{max-width:none;max-height:none;object-fit:initial}footer{font-size:14px;line-height:1.5;color:#526071}footer a{color:#295aa9}@media(max-width:1000px){main{padding:12px}.intro{align-items:flex-start}.intro h1{font-size:22px}.card header{padding:12px;height:96px}.card h2{font-size:16px}.card a{font-size:12px}figure{height:550px;padding:6px}}@media print{.controls{display:none}body{background:white}main{padding:0}}
</style></head><body><main><div class="intro"><div><h1>Предпросмотр Glyph и те же CIFF в ClariSoft</h1><p>Настоящие снимки интерфейсов. Оригиналы доступны отдельно; поле времени изменяется по часам компьютера.</p></div><div class="controls"><button id="fit" aria-pressed="true">Вписать</button> <button id="actual" aria-pressed="false">Пиксели 1:1</button></div></div><section class="row" aria-label="Веб и ClariSoft">${card(inputs[0])}${card(inputs[1])}</section><section class="row" aria-label="EXE и ClariSoft">${card(inputs[2])}${card(inputs[3])}</section><footer>Снимки не перерисованы. В режиме «Вписать» целые изображения пропорционально уменьшены для сравнения.<br><a href="screenshot-sources.json">Происхождение файлов и SHA-256</a></footer></main><script>for(const id of ['fit','actual'])document.getElementById(id).onclick=()=>{document.body.classList.toggle('actual',id==='actual');document.getElementById('fit').setAttribute('aria-pressed',String(id==='fit'));document.getElementById('actual').setAttribute('aria-pressed',String(id==='actual'));};</script></body></html>`;
fs.writeFileSync(path.join(output, 'index.html'), html);
app.setPath('userData', path.join(output, 'isolated-composition-profile'));
app.disableHardwareAcceleration();
app.whenReady().then(async () => {
  const window = new BrowserWindow({ show: false, width: 2448, height: 2080,
    webPreferences: { sandbox: true, contextIsolation: true, nodeIntegration: false, offscreen: true } });
  await window.loadURL(pathToFileURL(path.join(output, 'index.html')).toString());
  const measurement = await window.webContents.executeJavaScript(`(async()=>{await Promise.all(Array.from(document.images).map(image=>image.decode()));await new Promise(requestAnimationFrame);return{width:document.documentElement.scrollWidth,height:document.documentElement.scrollHeight,images:Array.from(document.images).map(image=>({src:image.getAttribute('src'),width:image.naturalWidth,height:image.naturalHeight}))};})()`);
  window.setContentSize(measurement.width, measurement.height);
  await new Promise(resolve => setTimeout(resolve, 100));
  fs.writeFileSync(path.join(output, 'glyph-clarisoft-side-by-side.png'), (await window.webContents.capturePage()).toPNG());
  fs.writeFileSync(path.join(output, 'composition.json'), JSON.stringify(measurement, null, 2));
  console.log(JSON.stringify({ html:path.join(output,'index.html'),png:path.join(output,'glyph-clarisoft-side-by-side.png') }));
  window.destroy();app.exit(0);
}).catch(error=>{console.error(error.stack||error);app.exit(1);});
