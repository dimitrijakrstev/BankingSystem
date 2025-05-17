//
//  Vector.cpp
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 12.5.25.
//

#include "Vector.h"

Vector::Vector() {
    capacity = 5;
    size = 0;
    data = new BankAccount* [capacity];
}

Vector::~Vector() {
    clear();
    delete[] data;
}

void Vector::resize() {
    capacity = capacity * 2;
    BankAccount** newData = new BankAccount* [capacity];
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
}

void Vector::push_back(BankAccount* acc) {
    if (size == capacity) {
        resize();
    }
    data[size++] = acc;
}

BankAccount* Vector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index is out of bounds!");
    }
    return data[index];
}

size_t Vector::getSize() const {
    return size;
}

void Vector::clear() {
    for (size_t i = 0; i < size; i++) {
        delete data[i];
    }
    size = 0;
}

BankAccount** Vector::begin() {
    return data;
}

BankAccount** Vector::end() {
    return data + size;
}

void Vector::removeAt(size_t index) {
    if (index >= size) return;

    delete data[index];  // Free memory
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}
