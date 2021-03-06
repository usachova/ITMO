- [x] 1. [Передача значения по ссылке](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/1)
> Объявите (в отельном заголовочном файле) и реализуйте (в другом файле) данные процедуры (они не возвращают значений!):
> 1. Меняет значения двух входных переменных друг на друга. 
> 2. Отбрасывает от вещественного числа его дробную часть. 
> 3. Умножает комплексную переменную на второй аргумент процедуры – вещественное число. 
> 4. Сдвигает окружность на заданный вектор. 
>
> Все процедуры должны быть написаны в двух вариантах – один вариант использует указатели, второй вариант – ссылки. Напишите программу, проверяющую и демонстрирующую правильность работы процедур
- [x] 2. [Классы](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/2)
> Описать указанные класс "Комплексное число". Написать программу, использующую описанный класс: инициализация переменных (ввод пользователя), выполнение действий с экземплярами класса (в зависимости от дальнейшего ввода пользователя).
- [x] 3. [Перегрузка операторов](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/3)
> Описать типы данных "Комплексное число" и "Стек целых чисел" и поместить их в отдельный заголовочный файл, в нем же описать операторы, указанные в варианте. Реализацию функций поместить с отдельный cpp файл. Написать программу, проверяющую правильность работы – для наглядности и лучшего усвоения материала использовать как явный, так и не явный метод вызова функций операторов. 
- [x] 4. [Виртуальные функции](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/4)
> Реализовать все указанные интерфейсы (абстрактные базовые классы) для классов: 
> 1. Круг 
> 2. Равносторонний треугольник 
> 
> Функционал системы: 
> - Хранение множества фигур 
> - Динамическое добавление фигур пользователем. (через консоль) 
> - Отобразить все фигуры. 
> - Суммарная площадь всех фигур. 
> - Суммарный периметр всех фигур. 
> - Центр масс всей системы. 
> - Память, занимаемая всеми экземплярами классов. 
> - Сортировка фигур между собой по массе. 
- [x] 5. [Шаблоны, исключения](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/5)
> Написать шаблонную функцию "поиска максимального элемента массива" и класса "стек из максимум N элементов типа T". Описать класс-исключение или иерархию классов-исключений. Генерировать исключения в соответствующих исключительных ситуациях.
- [x] 6. [Обобщённые алгоритмы](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/6)
> Требуется реализовать следующие обобщенные алгоритмы: 
> 1. all_of - возвращает true, если все элементы диапазона удовлетворяют некоторому предикату. Иначе false 
> 2. is_sorted - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия 
> 3. find_backward - находит первый элемент, равный заданному, с конца. 
>
> Каждый алгоритм должен быть выполнен в виде шаблонной функции, позволяющей взаимодействовать со стандартными контейнерами STL с помощью итераторов. Предикаты, условия, операторы сравнения должны быть параметризованы. 
- [x] 7. [Кольцевой буфер](https://github.com/usachova/ITMO-Programming-2-sem/tree/master/7)
> Реализовать кольцевой буфер в виде stl-совместимого контейнера (например, может быть использован с стандартными алгоритмами), обеспеченного итератором произвольного доступа. Реализация не должна использовать ни одни из контейнеров STL. 
> 
> Буфер должен обладать следующими возможностями: 
> 1. Вставка и удаление в конец 
> 2. Вставка и удаление в начало 
> 3. Вставка и удаление в произвольное место по итератору 
> 4. Доступ в конец, начало 
> 5. Доступ по индексу 
> 6. Изменение капасити 
- [ ] 8. [Кубик Рубика]
> Спроектировать и реализовать программу, имитирующую сборку Кубика Рубика 3x3.
> 
> К программе предъявляются следующие функциональные требования:
> - Сохранение и чтение состояния кубика рубика из файла
> - Проверка корректности текущего состояния (инвариант состояний кубика)
> - Вывод в консоль текущего состояния
> - Вращение граней кубика рубика с помощью вводимых команд
> - Генерация случайного состояния Кубика Рубика, корректного с точки зрения инварианта состояний
> - Нахождения “решения” для текущего состояния в виде последовательности поворотов граней
> 
> Нефункциональные требования:
> - Программа должны быть спроектирована, с использованием ОПП
> - Логические сущности должны быть выделены в отдельный классы
> 
> Дополнительно:
> Реализовать графический интерфейс приложения, с использование OpenGL Utility Toolkit
