declare global {
  interface WillowLogPayload {
    category?: 'application' | 'actions' | 'files' | 'state' | 'errors';
    level?: 'TRACE' | 'DEBUG' | 'INFO' | 'WARN' | 'ERROR' | 'FATAL';
    event?: string;
    message?: string;
    source?: string;
    timestamp?: string;
    details?: unknown;
  }

  interface WillowLoggerBridge {
    log(payload: WillowLogPayload): void;
    getInfo(): Promise<{
      baseDir: string;
      sessionId: string;
      appVersion: string;
      files: Record<string, string>;
      lastWriteError: { name: string; message: string } | null;
    }>;
    flush(): Promise<unknown>;
  }

  interface Window {
    CIFF_EDITOR_MODULE_FLAGS?: Record<string, boolean>;
    CIFF_EDITOR_MODULE_LIST?: readonly unknown[];
    __WILLOW_CIFF_RUNTIME_PROMISE__?: Promise<void>;
    __WILLOW_CIFF_RUNTIME_READY__?: boolean;
    Konva?: unknown;
    willowLogger?: WillowLoggerBridge;
  }
}

export {};
