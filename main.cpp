#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

// Template class definition
template <typename T>
class Myvector {
private:
    T* data;        // Pointer to dynamically allocated array
    size_t size;    // Number of elements in the vector
    size_t capacity; // Capacity of the vector

public:
    // Constructors and destructor
    Myvector();                                // Default constructor
    Myvector(size_t initial_capacity);         // Constructor with initial capacity
    ~Myvector();                               // Destructor
    Myvector(std::initializer_list<T> init);    // Constructor with initializer list

    // Capacity and size methods
    size_t size_() const;                      // Returns the current size
    size_t capacity_() const;                  // Returns the current capacity
    bool empty() const;                        // Checks if the vector is empty
    void reserve(size_t new_capacity);         // Reserves new memory for the vector
    void shrink_to_fit();                      // Shrinks the capacity to fit the size
    void print() const;                        // Prints the vector's elements

    // Element access methods
    T& operator[](size_t index);               // Access elements with []
    T& at(size_t index);                       // Access elements with boundary check
    void erase(size_t index);                  // Erases the element at the given index

    // Modifiers
    void push_back(const T& value);            // Adds an element at the end
    void pop_back();                           // Removes the last element
    void clear();                              // Clears the vector
    void insert(size_t pos, const T& value);   // Inserts an element at the given position
    void resize(size_t new_size);              // Resizes the vector
    void swap(Myvector<T>& other);             // Swaps two vectors
    void sort();          // sắp xếp các phần tử trong vector
};

// Default constructor
template <typename T>
Myvector<T>::Myvector() {
    size = 0;
    capacity = 1;
    data = new T[capacity];
    std::cout << "Empty Myvector is initialized" << std::endl;
}

// Constructor with initial capacity
template <typename T>
Myvector<T>::Myvector(size_t initial_capacity) {
    size = 0;
    capacity = initial_capacity;
    data = new T[capacity];
    std::cout << "The vector is initialized with a capacity of " << capacity << std::endl;
}

// Destructor
template <typename T>
Myvector<T>::~Myvector() {
    delete[] data;
    data = nullptr;
    std::cout << "Memory has been freed" << std::endl;
}

// Constructor with initializer list
template <typename T>
Myvector<T>::Myvector(std::initializer_list<T> init) {
    size = init.size();
    capacity = size;
    data = new T[capacity];

    size_t index = 0;
    for (const T& value : init) {
        data[index++] = value;
    }

    std::cout << "Myvector constructor with initializer list called" << std::endl;
}

// Size and capacity methods
template <typename T>
size_t Myvector<T>::size_() const {
    return size;
}

template <typename T>
size_t Myvector<T>::capacity_() const {
    return capacity;
}

template <typename T>
bool Myvector<T>::empty() const {
    return size == 0;
}

// Reserves memory
template <typename T>
void Myvector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

// Shrinks to fit the size
template <typename T>
void Myvector<T>::shrink_to_fit() {
    if (capacity > size) {
        T* new_data = new T[size];
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = size;
    }
}

// Prints the vector elements
template <typename T>
void Myvector<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Access element with []
template <typename T>
T& Myvector<T>::operator[](size_t index) {
    static T default_value = T(); // Default value to return in case of an error

    if (size == 0) {
        std::cout << "Vector is empty, cannot access element!" << std::endl;
        return default_value;
    }

    if (index >= size) {
        std::cout << "Index out of bounds!" << std::endl;
        return default_value;
    }

    return data[index];
}

// Access element with boundary check
template <typename T>
T& Myvector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds!");
    }
    return data[index];
}

// Erases element at the specified index
template <typename T>
void Myvector<T>::erase(size_t index) {
    if (size == 0) {
        std::cerr << "Error: Cannot erase from an empty vector." << std::endl;
        return;
    }

    if (index >= size) {
        std::cerr << "Error: Index out of range." << std::endl;
        return;
    }

    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size;
}

// Adds element at the end
template <typename T>
void Myvector<T>::push_back(const T& value) {
    if (size >= capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    data[size] = value;
    size++;
}

// Removes the last element
template <typename T>
void Myvector<T>::pop_back() {
    if (size > 0) {
        size--;
    }
}

// Clears the vector
template <typename T>
void Myvector<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Inserts element at specified position
template <typename T>
void Myvector<T>::insert(size_t pos, const T& value) {
    if (pos > size) {
        std::cerr << "Error: Position out of range" << std::endl;
        
    }

    if (size == capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }

    for (size_t i = size; i > pos; --i) {
        data[i] = data[i - 1];
    }

    data[pos] = value;
    size++;
    
}

// Resizes the vector
template <typename T>
void Myvector<T>::resize(size_t new_size) {
    if (new_size > capacity) {
        reserve(new_size);
    }
    size = new_size;
}

// Swaps contents of two vectors
template <typename T>
void Myvector<T>::swap(Myvector<T>& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

#endif // MYVECTOR_H

#include <iostream>
#include "Myvector.h"

using namespace std;

int main() {
    Myvector<int> vec;

    // Add elements for testing
    vec.reserve(5);
    cout<<"size is :"<<vec.size_()<<endl;
    cout<<"capacity is "<<vec.capacity_()<<endl;
    vec.push_back(10) ;
    vec.push_back(20);
    vec.push_back(30) ;

    std::cout << "Before erase:" << std::endl;
    vec.print();

    // Erase element at position 1
    vec.erase(1);

    std::cout << "After erase:" << std::endl;
    vec.print();

    return 0;
}
