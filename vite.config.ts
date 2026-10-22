import { createRequire } from 'node:module';
import { defineConfig, type Plugin } from 'vite';
import react from '@vitejs/plugin-react';

const require = createRequire(import.meta.url);
// Vite reloads this config in the same process. Its native helpers use CJS,
// whose separate Node cache must also be refreshed after a watched update.
for (const helper of ['./scripts/vite-fonts.cjs', './electron/fonts.cjs']) {
  delete require.cache[require.resolve(helper)];
}
const { createViteFontPlugin } = require('./scripts/vite-fonts.cjs') as {
  createViteFontPlugin: () => Plugin;
};

export default defineConfig({
  plugins: [react(), createViteFontPlugin()],
  server: {
    host: '0.0.0.0',
    port: 5173,
  },
});
