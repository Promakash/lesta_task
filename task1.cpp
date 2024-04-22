//Задание 1
//На языке С/С++, написать алгоритм (функцию) определения четности целого числа,
// который будет аналогичен нижеприведенному по функциональности, но отличен по своей сути.

//Объяснить плюсы и минусы обеих реализаций.

//Исходный вариант
bool isEven(int value){
    return value % 2 == 0;
}

//Улучшенный вариант
bool isEvenBetter(const long long &value){
    return (value & 1) == 0;
}

//Cравнение
//isEven
//Плюсы:
// интуитивно понятный код
//Минусы:
// при вызове функции происходит ненужное копирование аргумента фукнции(value).
// Если целое число больше 4 байт, то функция может сработать некорректно

//isEvenBetter
//Плюсы:
//Не происходит копирования аргумента функции
//Может обработать число размером до 8 байт
//Операция битового И (&) работает быстрее, по сравнению с %
//Минусы:
//запись (value & 1) может быть не до конца понятна