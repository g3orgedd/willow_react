# Willow CIFF Editor

Редактор XML/CIFF-шаблонов на React, TypeScript и Vite. Проект также можно запускать и собирать как настольное приложение Electron для Windows.

## Возможности

- создание и редактирование CIFF-шаблонов;
- загрузка и сохранение XML/CIFF-файлов;
- визуальное редактирование элементов на рабочем холсте;
- история изменений, панели свойств и проверка данных;
- запуск в браузере и в виде настольного приложения.

## Требования

- Node.js 18 или новее;
- npm;
- Windows — для создания Windows-сборки Electron.

## Установка

Клонируйте репозиторий и установите зависимости:

```bash
git clone https://github.com/USERNAME/willow-ciff-editor.git
cd willow-ciff-editor
npm install
```

Замените `USERNAME` на имя владельца репозитория GitHub.

## Запуск

### Веб-версия

```bash
npm run dev
```

После запуска откройте адрес, указанный Vite. По умолчанию это `http://localhost:5173`.

### Настольная версия Electron

```bash
npm run desktop:dev
```

## Проверка проекта

```bash
npm test
npm run typecheck
npm run build
```

Для локального просмотра production-сборки:

```bash
npm run preview
```

## Сборка приложения для Windows

```bash
npm run desktop:build
```

Готовые установочные файлы создаются в каталоге `desktop-release-local`. Каталог является результатом сборки и не добавляется в Git.

## Структура проекта

```text
electron/          Главный процесс Electron
public/            Статические ресурсы и legacy-модули редактора
scripts/           Сценарии сборки настольного приложения
src/
  components/      React-компоненты интерфейса
  domain/          Описание модулей и предметной области
  hooks/           React-хуки и инициализация runtime
  legacy/          Типы для существующих JavaScript-модулей
  utils/           Вспомогательные функции
tests/             Автоматические тесты
```

Основная бизнес-логика редактора находится в `public/modules`. React отвечает за интерфейс и подключает существующий runtime через `useCiffEditorRuntime`.

## Основные команды

| Команда | Назначение |
| --- | --- |
| `npm run dev` | Запустить веб-версию в режиме разработки |
| `npm run desktop:dev` | Запустить Vite и Electron |
| `npm test` | Выполнить автоматические тесты |
| `npm run typecheck` | Проверить типы TypeScript |
| `npm run build` | Создать production-сборку веб-версии |
| `npm run desktop:build` | Собрать настольное приложение |
| `npm run preview` | Просмотреть production-сборку |

## Примечание для PowerShell

Если выполнение `npm.ps1` запрещено политикой PowerShell, используйте `npm.cmd`:

```powershell
npm.cmd install
npm.cmd run dev
```

## Лицензия

Лицензия для проекта пока не указана.
