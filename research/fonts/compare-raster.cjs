const fs = require('node:fs');
const path = require('node:path');
const { createFontRendererService } = require('../../electron/fonts.cjs');
const rows = JSON.parse(fs.readFileSync(path.join(__dirname, 'oracle-raster.json'),'utf8').replace(/^\uFEFF/,''));
const service = createFontRendererService();
(async () => {
  try {
    const output = [];
    for (const row of rows) {
      const result = await service.render({ text: row.text, face: row.face, pitch: row.pitch, pitchResolution: 1, xMag: 100, yMag: 100, charSpace: 0, xRes: 1200, yRes: 1200, bold: false, italic: false });
      const file = `worker-raster_${row.face}_${row.pitch}.png`;
      fs.writeFileSync(path.join(__dirname,file),Buffer.from(result.dataUrl.split(',')[1],'base64'));
      output.push({ face: row.face,pitch: row.pitch,oracleWidth: row.widthDots,oracleHeight: row.heightDots,width: result.width,height:result.height,fontFamily:result.fontFamily,ttSize:result.ttSize,file });
    }
    fs.writeFileSync(path.join(__dirname,'worker-raster-metrics.json'),JSON.stringify(output,null,2));
    process.stdout.write(JSON.stringify(output));
  } finally { service.dispose(); }
})().catch(error => {process.stderr.write(String(error.stack));process.exitCode=1;});
