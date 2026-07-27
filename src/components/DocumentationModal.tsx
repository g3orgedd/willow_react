import type { ReactNode } from 'react';
import functionalityMarkdown from '../../FUNCTIONALITY.md?raw';
import changelogMarkdown from '../../CHANGELOG.md?raw';

function renderInline(text: string): ReactNode[] {
  const parts = text.split(/(\*\*[^*]+\*\*|`[^`]+`)/g).filter(Boolean);
  return parts.map((part, index) => {
    if (part.startsWith('**') && part.endsWith('**')) {
      return <strong key={index}>{part.slice(2, -2)}</strong>;
    }
    if (part.startsWith('`') && part.endsWith('`')) {
      return <code key={index}>{part.slice(1, -1)}</code>;
    }
    return part;
  });
}

function splitTableRow(line: string): string[] {
  return line.trim().replace(/^\||\|$/g, '').split('|').map((cell) => cell.trim());
}

function MarkdownDocument({ source }: { source: string }) {
  const lines = source.replace(/\r\n/g, '\n').split('\n');
  const blocks: ReactNode[] = [];
  let index = 0;

  while (index < lines.length) {
    const line = lines[index];
    if (!line.trim()) {
      index += 1;
      continue;
    }

    const heading = line.match(/^(#{1,6})\s+(.+)$/);
    if (heading) {
      const level = Math.min(heading[1].length, 4);
      const content = renderInline(heading[2]);
      if (level === 1) blocks.push(<h2 key={index}>{content}</h2>);
      else if (level === 2) blocks.push(<h3 key={index}>{content}</h3>);
      else blocks.push(<h4 key={index}>{content}</h4>);
      index += 1;
      continue;
    }

    if (/^\s*-\s+/.test(line)) {
      const items: ReactNode[] = [];
      const listKey = index;
      while (index < lines.length && /^\s*-\s+/.test(lines[index])) {
        items.push(<li key={index}>{renderInline(lines[index].replace(/^\s*-\s+/, ''))}</li>);
        index += 1;
      }
      blocks.push(<ul key={listKey}>{items}</ul>);
      continue;
    }

    if (line.trim().startsWith('|') && index + 1 < lines.length && lines[index + 1].trim().startsWith('|')) {
      const tableKey = index;
      const header = splitTableRow(line);
      index += 2;
      const rows: string[][] = [];
      while (index < lines.length && lines[index].trim().startsWith('|')) {
        rows.push(splitTableRow(lines[index]));
        index += 1;
      }
      blocks.push(
        <div className="documentationTableWrap" key={tableKey}>
          <table>
            <thead><tr>{header.map((cell, cellIndex) => <th key={cellIndex}>{renderInline(cell)}</th>)}</tr></thead>
            <tbody>
              {rows.map((row, rowIndex) => (
                <tr key={rowIndex}>{row.map((cell, cellIndex) => <td key={cellIndex}>{renderInline(cell)}</td>)}</tr>
              ))}
            </tbody>
          </table>
        </div>
      );
      continue;
    }

    const paragraphKey = index;
    const paragraph: string[] = [];
    while (
      index < lines.length &&
      lines[index].trim() &&
      !/^(#{1,6})\s+/.test(lines[index]) &&
      !/^\s*-\s+/.test(lines[index]) &&
      !lines[index].trim().startsWith('|')
    ) {
      paragraph.push(lines[index].trim());
      index += 1;
    }
    blocks.push(<p key={paragraphKey}>{renderInline(paragraph.join(' '))}</p>);
  }

  return <div className="documentationMarkdown">{blocks}</div>;
}

export function DocumentationModal() {
  return (
    <div id="documentationModal" className="modal modal--documentation hidden" aria-hidden="true">
      <div className="modal__backdrop" data-modal-close="1"></div>
      <div
        className="modal__card modal__card--documentation surface-card"
        role="dialog"
        aria-modal="true"
        aria-labelledby="documentationModalTitle"
      >
        <div className="modal__header documentationModal__header">
          <div className="modal__title" id="documentationModalTitle">Functionality</div>
        </div>

        <div className="documentationModal__content">
          <div id="functionalityDocument"><MarkdownDocument source={functionalityMarkdown} /></div>
          <div id="changelogDocument" className="hidden"><MarkdownDocument source={changelogMarkdown} /></div>
        </div>

        <div className="modal__actions documentationModal__actions">
          <button id="btnCloseDocumentation" className="btn btn--primary" type="button">Close</button>
        </div>
      </div>
    </div>
  );
}
