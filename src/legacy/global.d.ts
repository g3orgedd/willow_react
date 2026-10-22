declare global {
  interface GlyphLogPayload {
    category?: 'application' | 'actions' | 'files' | 'state' | 'errors';
    level?: 'TRACE' | 'DEBUG' | 'INFO' | 'WARN' | 'ERROR' | 'FATAL';
    event?: string;
    message?: string;
    source?: string;
    timestamp?: string;
    details?: unknown;
  }

  interface GlyphLoggerBridge {
    log(payload: GlyphLogPayload): void;
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
    glyphSystemTickCount?: () => number;
    CIFF_EDITOR_MODULE_FLAGS?: Record<string, boolean>;
    CIFF_EDITOR_MODULE_LIST?: readonly unknown[];
    __GLYPH_CIFF_RUNTIME_PROMISE__?: Promise<void>;
    __GLYPH_CIFF_RUNTIME_READY__?: boolean;
    Konva?: unknown;
    glyphLogger?: GlyphLoggerBridge;
    glyphFonts?: {
      list(): Promise<{ families: string[] }>;
      render(request: {
        text: string; face: string; pitch: number; pitchResolution?: number;
        bold?: boolean; italic?: boolean; xMag?: number; yMag?: number;
        charSpace?: number; xRes?: number; yRes?: number;
      }): Promise<{
        dataUrl: string; outlinePath?: string | null; width: number; height: number; advanceWidth: number;
        fontHeight: number; baseline: number; offsetX: number; offsetY: number;
        fontFamily: number; trueType: boolean;
      }>;
    };
  }
}

export {};
