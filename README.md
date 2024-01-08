// 
1.0 Установить Mach3Registry
1. Для компиляции использовать среду visual c++ 2008 express edition.
2. После открытия  и компиляции проекта файл  «Interop.Mach4.1.0.dll» переместить в корневую директорию mach3 C://mach3
3. ПКМ на проекте ->  Ссылки -> Удалить Interop.Mach4.1.0
4. Заново создать ссылку Interop.Mach4.1.0
5. Указать ссылку на mach3.exe
6. Удалить класс GD c формы PluginControlDialog
