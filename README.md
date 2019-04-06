# Prog.Tech-Lab-2
Лабораторная работа №2

• Задание 1. Унарная операция
Создать класс целых чисел (long). Определить операторы - - (префиксная форма,
метод) для вычитания пользовательского значения, - - (постфиксная форма, метод) для
вычитания 1, ++ (префиксная форма, дружественная функция) для прибавления
пользовательского значения, ++(постфиксная форма, дружественная функция) для
прибавления 1. Оператор ! возвращает отрицательное значение.
• Задание 2. Бинарная операция
Создать объект "стек", размеры стека задаются пользователем с клавиатуры,
значения также вводятся с клавиатуры. Перегрузить операции половину как
дружественные функции, половину как методы +, +=, -, -=, *, *=, /, /= для работы с
числами.

Важно учитывать при реализации:

● Необходимо выполнить разделение на h и cpp файлы для каждого класса. h файлы
содержат определение, cpp файлы содержат реализацию. функция main обязана
располагаться в отдельном cpp файле.

● Элемент очереди/стека/списка содержит данные и ссылку на
предыдущий/следующий/предыдущий и следующий элемент. Элемент реализовать
с помощью класса или структуры. В классе или структуре, реализующей элемент,
необходимо поместить функции для установки и извлечения данных. То есть
напрямую обращения к данным и ссылке(-ам) быть не должно.

● Необходимо работать с динамическим выделением памяти. Важно выделять и
всегда очищать выделенную память.

● Необходимо написать для каждого класса: конструктор с параметрами и без
параметров, конструктор копирования, деструктор, необходимо
продемонстрировать применение спецификатора explicit.

● Требуется реализовать методы/функции с аргументами по умолчанию.

● Реализовать пользовательское меню согласно заданию.В пользовательском меню
обязательно предоставить пользователю возможность взаимодействовать со всеми
настраиваемыми параметрами. То есть не должно существовать в программе
числовых или буквенных констант, которые могут быть введены пользователем.
