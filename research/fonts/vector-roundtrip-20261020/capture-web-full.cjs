// Pure HTTP website screenshot in a hidden, isolated Electron renderer.
// No preload, IPC bridge, Save, native desktop capture, or visible window.
const { app, BrowserWindow } = require('electron');
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const directory = __dirname;
const ciff = path.join(directory, 'web-vector.ciff');
const before = fs.readFileSync(ciff);
app.setPath('userData', path.join(directory, 'isolated-screenshot-web-profile'));
app.disableHardwareAcceleration();
const deadline = setTimeout(() => { console.error('Web read-only screenshot timed out.');app.exit(1); }, 35000);
app.whenReady().then(async () => {
  const window = new BrowserWindow({ show: false, width: 1440, height: 1100, useContentSize: true,
    webPreferences: { sandbox: true, contextIsolation: true, nodeIntegration: false, offscreen: true } });
  await window.loadURL('http://127.0.0.1:5173');
  window.setContentSize(1440, 1100);
  const evidence = await window.webContents.executeJavaScript(`(async()=>{
    const deadline=Date.now()+25000;
    while(!globalThis.__GLYPH_CIFF_RUNTIME_READY__||!textFontCatalog.ready||!stage){
      if(Date.now()>deadline)throw new Error('Web runtime did not initialize.');
      await new Promise(resolve=>setTimeout(resolve,25));
    }
    if(typeof glyphLogger!=='undefined'||!String(glyphFonts.render).includes('/__glyph_fonts/render'))throw new Error('Web renderer unexpectedly uses Electron IPC.');
    if(!loadXml(${JSON.stringify(before.subarray(2).toString('utf16le'))},{source:'readonly-web-screenshot',title:'web-vector.ciff',markDirty:false}))throw new Error('Cannot reopen the saved web CIFF.');
    setZoom(100);setSelectedNames([]);renderAll();
    await Promise.all(Array.from(nativeTextPreviewPending.values()));renderAll();
    await new Promise(resolve=>setTimeout(resolve,150));
    return {url:location.href,width:innerWidth,height:innerHeight,zoom:zoomPct,capturedAt:new Date().toISOString(),
      noPreloadOrIpc:typeof glyphLogger==='undefined',httpNativeService:String(glyphFonts.render).includes('/__glyph_fonts/render'),
      fields:state.fields.map(field=>({name:field.name,type:field.fldType,face:getEffectiveTextFontFamily(field),geom:{...field.geom},
        preview:field._konva?.findOne('.PreviewValue')?.getClassName(),previewText:makePreviewText(field)}))};
  })()`);
  if(evidence.fields.length!==10||!evidence.fields.every(field=>field.preview==='Path'))throw new Error('The actual web preview did not show all ten vector fields.');
  const filename=path.join(directory,'web-vector-editor-full.png');
  fs.writeFileSync(filename,(await window.webContents.capturePage()).toPNG());
  const after=fs.readFileSync(ciff);
  if(!before.equals(after))throw new Error('Read-only web screenshot changed the CIFF.');
  fs.writeFileSync(path.join(directory,'web-vector-editor-full.json'),JSON.stringify({...evidence,filename,ciff,
    ciffSha256:crypto.createHash('sha256').update(after).digest('hex'),
    method:'Actual HTTP website reopened the saved CIFF in a hidden 1440x1100 renderer with an isolated profile, no preload/IPC and no Save.'},null,2));
  console.log(JSON.stringify({filename,width:evidence.width,height:evidence.height,fields:evidence.fields.length,ciffUnchanged:true}));
  clearTimeout(deadline);window.destroy();app.exit(0);
}).catch(error=>{console.error(error.stack||error);clearTimeout(deadline);app.exit(1);});
