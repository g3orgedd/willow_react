import { AppLayout } from './components/AppLayout';
import { useCiffEditorRuntime } from './hooks/useCiffEditorRuntime';

export function App() {
  const runtime = useCiffEditorRuntime();

  return (
    <>
      <AppLayout />
      {runtime.status === 'error' ? (
        <div className="modal" aria-live="assertive">
          <div className="modal__backdrop" />
          <div className="modal__card surface-card" role="alert">
            <div className="modal__header">
              <div className="modal__title">Runtime loading error</div>
              <div className="modal__subtitle">{runtime.error?.message ?? 'Unknown error'}</div>
            </div>
          </div>
        </div>
      ) : null}
    </>
  );
}
