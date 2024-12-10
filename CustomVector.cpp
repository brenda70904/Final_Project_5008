#include <stdexcept>
#include <iostream>

#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

/**
 * A template class that mimics some of the functionalities of std::vector.
 * It dynamically resizes itself to hold as many elements as are inserted into it.
 *
 * @tparam T The data type of the elements stored in the vector.
 */
template <typename T>
class CustomVector {
private:
    T* array;       ///< Pointer to the array that holds the elements.
    int capacity;   ///< Total capacity of the vector.
    int current;    ///< Current number of elements in the vector.

public:
    /**
     * Constructor that initializes the vector with an initial capacity of 10 elements.
     */
    CustomVector() : capacity(10), current(0) {
        array = new T[capacity];
    }

    /**
     * Destructor that deallocates the dynamic array to prevent memory leaks.
     */
    ~CustomVector() {
        delete[] array;
    }

    /**
     * Adds a new element to the end of the vector. If the current size reaches
     * the capacity, the capacity is doubled and elements are moved to a new array.
     *
     * @param data The data to be added.
     */
    void push_back(const T& data) {
        if (current == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < current; i++) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        array[current++] = data;
    }

    /**
     * Returns the number of elements in the vector.
     *
     * @return The current size of the vector.
     */
    int size() const {
        return current;
    }

    /**
     * Clears the vector by resetting the element count to zero.
     */
    void clear() {
        current = 0;
    }

    /**
     * Checks if the vector is empty.
     *
     * @return True if the vector is empty, false otherwise.
     */
    bool isEmpty() const {
        return current == 0;
    }

    /**
     * Overloaded subscript operator to access elements in the vector.
     * Throws out_of_range exception if the index is invalid.
     *
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[](int index) {
        if (index < 0 || index >= current) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    /**
     * Const overloaded subscript operator to access elements in the vector.
     * Throws out_of_range exception if the index is invalid.
     *
     * @param index The index of the element to access.
     * @return Const reference to the element at the specified index.
     */
    const T& operator[](int index) const {
        if (index < 0 || index >= current) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    /**
     * Returns a pointer to the first element.
     *
     * @return Pointer to the first element.
     */
    T* begin() { return array; }

    /**
     * Returns a pointer to the element following the last element.
     *
     * @return Pointer to the element following the last element.
     */
    T* end() { return array + current; }

    /**
     * Returns a const pointer to the first element.
     *
     * @return Const pointer to the first element.
     */
    const T* begin() const { return array; }

    /**
     * Returns a const pointer to the element following the last element.
     *
     * @return Const pointer to the element following the last element.
     */
    const T* end() const { return array + current; }
};

#endif // CUSTOMVECTOR_H
