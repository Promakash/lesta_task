#pragma once
//Исходный вариант
bool isEven(int value){
    return value % 2 == 0;
}

//Улучшенный вариант
bool isEvenBetter(const long long &value){
    return (value & 1) == 0;
}