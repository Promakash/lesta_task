#pragma once
#include "PCH.h"

template <typename T>
class CircularBuffer_circularlist {
private:
    struct Node {
        T v;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* write = nullptr;
    Node* read = nullptr;
    size_t size = 0;
    size_t cur_size = 0;
    size_t node_count = 0;

private:
    void pushBack(const T& value) {
        cur_size++;
        Node* node = new Node();
        node->v = value;
        if (head == nullptr) {
            head = node;
            write = head;
            read = head;
        }
        else {
            tail->next = node;
        }
        tail = node;
        tail->next = head;
    }
public:
    CircularBuffer_circularlist(const size_t& size_) {
        if (size_ == 0) {
            throw std::invalid_argument("Can't be 0");
        }
        size = size_;
    }

    ~CircularBuffer_circularlist() {
        Node* p = head;
        while (head != tail) {
            head = head->next;
            delete p;
            p = head;
        }
        delete head;
    }

    void write_data(const T& value) {
        if (cur_size == size) {
            std::cout << "Buffer is full - can't add more" << '\n';
            return;
        }
        if (node_count < size){
            this->pushBack(value);
            node_count++;
        }
        else {
            write->v = value;
            write = write->next;
            cur_size++;
        }
    }

    T get_data() {
        if (cur_size == 0) {
            throw std::out_of_range("Called on empty buffer!");
        }
        T data = read->v;
        read = read->next;
        cur_size--;
        return data;
    }

    const size_t getSize() {
        return size;
    }

    const size_t getCurSize() {
        return cur_size;
    }

    const bool isFull(){
        return cur_size == size;
    }
};
