# Завершение шести открытий ClariSoft — 22.10.2026

После предыдущего сбоя пользователь закрыл проверочное окно ClariSoft. Новый экземпляр оригинального приложения снова стал доступен Computer Use. Все шесть ранее не завершённых файлов из `research/xml-fix-20261022/exports-final` открыты в самом ClariSoft:

| Файл | Статус | Save | Ошибки |
|---|---|---|---|
| xml-web-party-gtin2.ciff | Ready | disabled | Нет |
| xml-exe-party-gtin2.ciff | Ready | disabled | Нет |
| xml-web-party-box-gtin.ciff | Ready | disabled | Нет |
| xml-exe-party-box-gtin.ciff | Ready | disabled | Нет |
| xml-web-anisotropic-yres.ciff | Ready | disabled | Нет |
| xml-exe-anisotropic-yres.ciff | Ready | disabled | Нет |

Каждый полный путь подтверждён заголовком живого окна. Исходный файл не сохранялся. Сводка и отдельные AX-тексты: [gui-prior-six/results.json](gui-prior-six/results.json). Объединение с 12 прежними проверками: [all18-summary.json](gui-prior-six/all18-summary.json), 18 уникальных файлов, все Ready/clean.

Для EXE Party первый короткий опрос закончился до появления главного окна. Последующее наблюдение того же запущенного процесса PID23500 подтвердило штатную загрузку; файл повторно не генерировался.

Повторная попытка захвата окна вернула `FrameArrived timed out: timed out waiting on channel`. Свежее AX-чтение после ошибки работало; проверка продолжилась без снимков. Эти записи подтверждают GUI-загрузку, но не являются визуальным сравнением screenshot. Сравнение параметров и native Draw проводится отдельно. Исправленные XRes/YRes-файлы следующей сборки должны иметь отдельные проверки и не подменять эти прежние артефакты.
