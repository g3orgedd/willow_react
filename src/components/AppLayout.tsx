import { CanvasWorkspace } from './CanvasWorkspace';
import { AdvancedEditorModals } from './AdvancedEditorModals';
import { CloseTabModal } from './CloseTabModal';
import { ConfirmationModal } from './ConfirmationModal';
import { DataMatrixModal } from './DataMatrixModal';
import { DocumentationModal } from './DocumentationModal';
import { LeftPanel } from './LeftPanel';
import { MobilePanels } from './MobilePanels';
import { NewTemplateModal } from './NewTemplateModal';
import { NotificationModal } from './NotificationModal';
import { RightPanel } from './RightPanel';
import { SaveTemplateModal } from './SaveTemplateModal';
import { TopBar } from './TopBar';
import { TextFieldModal } from './TextFieldModal';

export function AppLayout() {
  return (
    <>
      <TopBar />
      <main className="app">
        <LeftPanel />
        <CanvasWorkspace />
        <RightPanel />
      </main>
      <MobilePanels />
      <AdvancedEditorModals />
      <NewTemplateModal />
      <DataMatrixModal />
      <SaveTemplateModal />
      <TextFieldModal />
      <CloseTabModal />
      <ConfirmationModal />
      <NotificationModal />
      <DocumentationModal />
    </>
  );
}
