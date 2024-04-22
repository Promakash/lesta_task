//Задание 2
#pragma once
#include "PCH.h"

template <typename T>
class CircularBuffer_array{
private:
    T* buffer = nullptr;
    size_t cur_size = 0;
    size_t write = 0;
    size_t read = 0;
    size_t size = 0;
public:
    CircularBuffer_array(const size_t &size_){
        if (size_ == 0){
            throw std::invalid_argument("Can't be 0");
        }
        size = size_;
        buffer = new T[size];
    }

    ~CircularBuffer_array(){
        delete[] buffer;
    }

    void write_data(const T &value){
        if (cur_size == size){
            std::cout << "Buffer is full - can't add more" << '\n';
            return;
        }
        buffer[write] = value;
        write = (write + 1) % size;
        size++;
    }

    T get_data(){
        if (cur_size == 0){
            throw std::out_of_range("Called on empty buffer!");
        }
        T data = buffer[read];
        read = (read+1) % size;
        size--;
        return data;
    }

    const size_t getSize(){
        return size;
    }

    const size_t getCurSize(){
        return cur_size;
    }

    const bool isFull(){
        return cur_size == size;
    }
};

//Плюсы реализации
//За счет того, что это массив, доступ к элементам происходит крайне быстро
//Память выделена заранее и поэтому не будут тратиться ресурсы на выделение нового блока (запрос к ОС на выделение памяти довольно медленная операция)
//Минусы
//Неэффективное использование памяти - буфер может быть не заполнен до конца, но при этом занимает больше памяти, чем ему следовало бы

//Подводя итог, стоит сказать, что данная реализация хороша тем, что все операции происходят в ней быстро, но при этом в ней не самый лучший менеджмент памяти