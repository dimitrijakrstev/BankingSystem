//
//  Vector.h
//  Banking System
//
//  Created by DIMITRIJA KRSTEV on 12.5.25.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>       // For size_t type
#include <stdexcept>     // For std::out_of_range exception
#include "BankAccount.h"

class Vector {
private:
    BankAccount** data;
    size_t capacity;
    size_t size;
    void resize();
    
public:
    Vector();
    ~Vector();
    void push_back(BankAccount* acc); // Adds a new account pointer
    BankAccount* operator[](size_t index); // Access element at index
    size_t getSize() const;          // Get number of elements
    void clear();                    // Delete all pointers and reset vector
    BankAccount** begin();
    BankAccount** end();
    void removeAt(size_t index);
};

#endif
