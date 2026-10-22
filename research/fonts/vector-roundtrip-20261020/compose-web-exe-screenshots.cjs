// Two genuine Glyph screenshots only. This is not a ClariSoft comparison.
const { app, BrowserWindow, nativeImage } = require('electron');
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const { pathToFileURL } = require('node:url');
const directory = __dirname;
const output = path.join(directory, 'web-exe-screenshots');
const inputs = [
  { id: 'web', title: 'WEB · Веб-версия Glyph', file: 'web-vector-editor-full.png', metadata: 'web-vector-editor-full.json', output: 'web-original.png' },
  { id: 'exe', title: 'EXE · Glyph Studio.exe', file: 'exe-vector-editor-full.png', metadata: 'exe-vector-editor-full.json', output: 'exe-original.png' },
];
fs.mkdirSync(output, { recursive: true });
for (const input of inputs) {
  input.source = path.join(directory, input.file);
  const bytes = fs.readFileSync(input.source);
  const image = nativeImage.createFromBuffer(bytes);
  if (image.isEmpty()) throw new Error('Invalid actual screenshot: ' + input.source);
  input.dimensions = image.getSize();
  const metadata = JSON.parse(fs.readFileSync(path.join(directory, input.metadata), 'utf8'));
  input.capturedAt = metadata.capturedAt;
  input.zoom = metadata.zoom;
  input.sha256 = crypto.createHash('sha256').update(bytes).digest('hex');
  fs.writeFileSync(path.join(output, input.output), bytes);
}
const manifest = { scope: 'Actual Glyph WEB and EXE editor screenshots only. Genuine ClariSoft GUI screenshots were not obtained and are not represented here.',
  method: 'Original screenshot pixels are unchanged. The side-by-side PNG proportionally resizes the full screenshots to fit; original PNG files are included.',
  inputs };
fs.writeFileSync(path.join(output, 'sources.json'), JSON.stringify(manifest, null, 2));
const cards = inputs.map(input => `<article><header><div><h2>${input.title}</h2><p>${input.dimensions.width} × ${input.dimensions.height} · масштаб редактора ${input.zoom}%</p></div><a href="${input.output}" target="_blank">Оригинал ↗</a></header><figure><img src="${input.output}" alt="${input.title}"></figure></article>`).join('');
const html = `<!doctype html><html lang="ru"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>Glyph: веб-версия и EXE — настоящие снимки интерфейсов</title><style>
*{box-sizing:border-box}body{margin:0;background:#eef1f5;color:#1b2432;font:16px "Segoe UI",Arial,sans-serif}main{width:100%;max-width:2460px;margin:auto;padding:24px}.intro{display:flex;align-items:center;justify-content:space-between;gap:20px;margin-bottom:20px}h1{margin:0 0 8px;font-size:28px}.intro p{margin:0;line-height:1.5;color:#526174}button{font:inherit;background:white;border:1px solid #bbc8d9;border-radius:8px;padding:9px 15px;cursor:pointer;white-space:nowrap}.screens{display:grid;grid-template-columns:minmax(0,1fr) minmax(0,1fr);gap:20px}article{border:1px solid #d1d9e4;border-radius:12px;overflow:hidden;background:white}article header{height:80px;display:flex;align-items:center;justify-content:space-between;padding:16px 20px;gap:12px}h2{font-size:21px;margin:0 0 5px}article p{font-size:14px;margin:0;color:#65758a}a{color:#2c5fa8;text-decoration:none;font-size:14px;white-space:nowrap}figure{margin:0;padding:10px;background:#e0e6ed;overflow:auto;line-height:0}img{display:block;width:100%;height:auto}.actual figure{height:920px}.actual img{width:auto;max-width:none}footer{font-size:15px;line-height:1.5;color:#526174;margin-top:16px}@media(max-width:1000px){main{padding:12px}.intro{display:block}.intro button{margin-top:10px}h1{font-size:22px}h2{font-size:16px}article header{padding:12px;height:90px}article p{font-size:12px}}
</style></head><body><main><section class="intro"><div><h1>Glyph: веб-версия и приложение EXE</h1><p>Подлинные снимки одного шаблона в двух версиях. Здесь показаны только интерфейсы Glyph.</p></div><button id="size">Показать пиксели 1:1</button></section><section class="screens">${cards}</section><footer>Оба редактора показывают сохранённые CIFF без повторного сохранения. Поле времени отображает текущее время снимка.<br>Для этой пары нет скриншота ClariSoft: изображение его интерфейса здесь не представлено. <a href="sources.json">Источники и SHA-256</a></footer></main><script>document.getElementById('size').onclick=()=>{const actual=document.body.classList.toggle('actual');document.getElementById('size').textContent=actual?'Вписать снимки':'Показать пиксели 1:1';};</script></body></html>`;
fs.writeFileSync(path.join(output, 'index.html'), html);
app.setPath('userData', path.join(output, 'isolated-composition-profile'));
app.disableHardwareAcceleration();
app.whenReady().then(async () => {
  const window = new BrowserWindow({ show:false,width:2460,height:1500,useContentSize:true,
    webPreferences:{sandbox:true,contextIsolation:true,nodeIntegration:false,offscreen:true} });
  await window.loadURL(pathToFileURL(path.join(output, 'index.html')).toString());
  // Offscreen windows can be capped to the monitor size; CDP fixes the viewport
  // before measuring the document so both full screenshots and footer fit.
  window.webContents.debugger.attach('1.3');
  const layout = async height => {
    await window.webContents.debugger.sendCommand('Emulation.setDeviceMetricsOverride', {
      width:2460,height,deviceScaleFactor:1,mobile:false,
    });
    return window.webContents.executeJavaScript(`(async()=>{await Promise.all(Array.from(document.images).map(image=>image.decode()));await new Promise(requestAnimationFrame);await new Promise(requestAnimationFrame);return{width:innerWidth,height:innerHeight,contentHeight:Math.ceil(document.querySelector('main').getBoundingClientRect().bottom),scrollHeight:document.documentElement.scrollHeight,clientHeight:document.documentElement.clientHeight,images:Array.from(document.images).map(image=>({src:image.getAttribute('src'),width:image.naturalWidth,height:image.naturalHeight,displayWidth:image.width,displayHeight:image.height}))};})()`);
  };
  let measured = await layout(1800);
  measured = await layout(measured.contentHeight);
  if (measured.scrollHeight > measured.clientHeight) measured = await layout(measured.scrollHeight);
  if(measured.width!==2460 || measured.scrollHeight>measured.clientHeight) throw new Error('Screenshot layout has unresolved clipping: '+JSON.stringify(measured));
  const filename=path.join(output,'web-exe-side-by-side.png');
  const screenshot=await window.webContents.debugger.sendCommand('Page.captureScreenshot', {format:'png',captureBeyondViewport:true,fromSurface:true});
  fs.writeFileSync(filename,Buffer.from(screenshot.data,'base64'));
  fs.writeFileSync(path.join(output,'composition.json'),JSON.stringify(measured,null,2));
  console.log(JSON.stringify({png:filename,html:path.join(output,'index.html'),width:2460,height:measured.height}));
  window.destroy();app.exit(0);
}).catch(error=>{console.error(error.stack||error);app.exit(1);});
