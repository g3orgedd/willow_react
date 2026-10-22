import { useEffect, useState } from 'react';
import { CIFF_EDITOR_MODULE_FLAGS, CIFF_EDITOR_MODULES } from '../domain/ciffEditorModules';
import { loadScriptOnce } from '../utils/loadScript';

export type RuntimeStatus = 'idle' | 'loading' | 'ready' | 'error';

export interface RuntimeState {
  readonly status: RuntimeStatus;
  readonly error: Error | null;
}

function logRuntime(
  level: GlyphLogPayload['level'],
  event: string,
  message: string,
  details: unknown = null,
): void {
  window.glyphLogger?.log({
    category: level === 'ERROR' || level === 'FATAL' ? 'errors' : 'application',
    level,
    event,
    message,
    details,
    source: 'react-runtime-loader',
    timestamp: new Date().toISOString(),
  });
}

function ensureGlobalSymbols(moduleKey: string, checks: readonly string[]): void {
  const missing = checks.filter((name) => typeof globalThis[name as keyof typeof globalThis] === 'undefined');
  if (missing.length > 0) {
    throw new Error(`Module "${moduleKey}" loaded without required symbols: ${missing.join(', ')}`);
  }
}

async function bootRuntime(): Promise<void> {
  if (window.__GLYPH_CIFF_RUNTIME_READY__) return;
  logRuntime('INFO', 'RUNTIME_BOOT_STARTED', 'Начата загрузка модулей редактора.', {
    moduleCount: CIFF_EDITOR_MODULES.length,
  });

  window.CIFF_EDITOR_MODULE_FLAGS = { ...CIFF_EDITOR_MODULE_FLAGS };
  window.CIFF_EDITOR_MODULE_LIST = CIFF_EDITOR_MODULES;

  await loadScriptOnce('/libs/konva.min.js');
  logRuntime('DEBUG', 'RUNTIME_DEPENDENCY_LOADED', 'Загружена библиотека Konva.', {
    source: '/libs/konva.min.js',
  });

  for (const moduleEntry of CIFF_EDITOR_MODULES) {
    if (window.CIFF_EDITOR_MODULE_FLAGS[moduleEntry.key] === false) {
      logRuntime('WARN', 'RUNTIME_MODULE_SKIPPED', 'Модуль редактора отключён флагом конфигурации.', {
        key: moduleEntry.key,
        source: moduleEntry.src,
      });
      continue;
    }
    await loadScriptOnce(moduleEntry.src);
    ensureGlobalSymbols(moduleEntry.key, moduleEntry.checks);
    logRuntime('DEBUG', 'RUNTIME_MODULE_LOADED', 'Модуль редактора успешно загружен.', {
      key: moduleEntry.key,
      source: moduleEntry.src,
      checkedSymbols: moduleEntry.checks,
    });
  }

  window.__GLYPH_CIFF_RUNTIME_READY__ = true;
  logRuntime('INFO', 'RUNTIME_BOOT_COMPLETED', 'Все модули редактора успешно загружены.');
}

export function useCiffEditorRuntime(): RuntimeState {
  const [state, setState] = useState<RuntimeState>({ status: 'idle', error: null });

  useEffect(() => {
    let cancelled = false;
    setState({ status: 'loading', error: null });

    const runtimePromise = window.__GLYPH_CIFF_RUNTIME_PROMISE__ ?? bootRuntime();
    window.__GLYPH_CIFF_RUNTIME_PROMISE__ = runtimePromise;

    runtimePromise
      .then(() => {
        if (!cancelled) setState({ status: 'ready', error: null });
      })
      .catch((error: unknown) => {
        const normalizedError = error instanceof Error ? error : new Error(String(error));
        console.error('CIFF editor runtime error:', normalizedError);
        logRuntime('FATAL', 'RUNTIME_BOOT_FAILED', 'Не удалось загрузить или инициализировать редактор.', {
          error: {
            name: normalizedError.name,
            message: normalizedError.message,
            stack: normalizedError.stack,
          },
        });
        if (!cancelled) setState({ status: 'error', error: normalizedError });
      });

    return () => {
      cancelled = true;
    };
  }, []);

  return state;
}
