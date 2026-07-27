# Willow XML CIFF Editor — React + TypeScript + Vite

Проект перенесён на стек React + TypeScript + Vite с сохранением текущей разметки, CSS-классов, `id` элементов и legacy-модулей логики.

## Запуск

```bash
npm install
npm run dev
```

После запуска открой адрес, который покажет Vite, обычно:

```text
http://localhost:5173
```

## Проверка

```bash
npm run typecheck
npm run build
npm run preview
```

## Структура

```text
src/
  components/       React-компоненты интерфейса без изменения визуальной структуры
  hooks/            Хуки для инициализации runtime приложения
  domain/           Типизированное описание CIFF runtime-модулей
  legacy/           Глобальные декларации для старых модулей
  utils/            Вспомогательные функции загрузки скриптов
public/
  modules/          Перенесённая существующая бизнес-логика JS без изменения поведения
  libs/             Konva runtime
  resourses/        SVG-иконки, используемые текущей версткой
  styles.css        Оригинальные стили приложения
```

## Важная деталь переноса

Существующая логика редактора сохранена как последовательность legacy-модулей в `public/modules`. React отвечает за структуру интерфейса и инициализацию runtime через `useCiffEditorRuntime`, но сами обработчики, расчёты, загрузка/сохранение XML/CIFF, рендеринг Konva, история, инспекторы и валидация остаются теми же модулями, чтобы не изменить текущее поведение.

Проверено:

```text
npm run typecheck
npm run build
```

## Установка на Windows

Если PowerShell блокирует `npm`, используйте `npm.cmd`:

```powershell
npm.cmd install
npm.cmd run typecheck
npm.cmd run build
npm.cmd run dev
```

В архиве намеренно нет `package-lock.json`: зависимости должны подтягиваться из публичного npm registry.

Если установка всё равно падает, выполните:

```powershell
npm.cmd cache clean --force
npm.cmd config set registry https://registry.npmjs.org/
npm.cmd install --no-audit --no-fund
```
