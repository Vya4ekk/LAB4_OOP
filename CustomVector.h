#pragma once
#include <iostream>

#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

template <typename T>
class CustomVector {
private:
    T* data;
    int size_;
    int capacity_;

    void moveData(T* source, T* destination, int count);

public:
    CustomVector();
    ~CustomVector();
    explicit CustomVector(int initialCapacity);
    CustomVector(const CustomVector& other);
    CustomVector& operator=(const CustomVector& other);
    //CustomVector(std::initializer_list<T> initList) : size(initList.size()), capacity(initList.size());

    void push_back(const T& value);
    void pop_back();
    void clear();
    int size() const;
    int capacity() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    void reserve(int newCapacity);
    void resize(int newSize, const T& value = T());
    bool empty() const;

    T* begin();
    const T* begin() const;

    T* end();
    const T* end() const;
};

template <typename T>
CustomVector<T>::CustomVector() : data(nullptr), size_(0), capacity_(0) {}

template <typename T>
CustomVector<T>::CustomVector(int initialCapacity) : size_(0), capacity_(initialCapacity) {
    data = new T[capacity];
}

template <typename T>
CustomVector<T>::CustomVector(const CustomVector& other) : size_(other.size), capacity_(other.capacity) {
    data = new T[capacity_];
    moveData(other.data, data, size_);
}

template <typename T>
CustomVector<T>& CustomVector<T>::operator=(const CustomVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        moveData(other.data, data, size);
    }
    return *this;
}

template <typename T>
CustomVector<T>::~CustomVector() {
    delete[] data;
}

template <typename T>
void CustomVector<T>::moveData(T* source, T* destination, int count) {
    for (size_t i = 0; i < count; ++i) {
        destination[i] = source[i];
    }
}

template <typename T>
void CustomVector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        reserve(capacity_ * 2 + 1);
    }
    data[size_++] = value;
}

template <typename T>
void CustomVector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    }
}

template <typename T>
void CustomVector<T>::clear() {
    size = 0;
}

template <typename T>
int CustomVector<T>::size() const {
    return size_;
}

template <typename T>
int CustomVector<T>::capacity() const {
    return capacity_;
}

template <typename T>
T& CustomVector<T>::operator[](int index) {
    if (index < size_) {
        return data[index];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
const T& CustomVector<T>::operator[](int index) const {
    if (index < size_) {
        return data[index];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
void CustomVector<T>::reserve(int newCapacity) {
    if (newCapacity > capacity_) {
        T* newData = new T[newCapacity];
        moveData(data, newData, size_);
        delete[] data;
        data = newData;
        capacity_ = newCapacity;
    }
}

template <typename T>
void CustomVector<T>::resize(int newSize, const T& value) {
    if (newSize > size) {
        reserve(newSize);
        for (size_t i = size; i < newSize; ++i) {
            data[i] = value;
        }
    }
    size = newSize;
}

template <typename T>
bool CustomVector<T>::empty() const {
    return size == 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CustomVector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, CustomVector<T>& vec) {
    T value;
    vec.clear();

    while (is >> value) {
        vec.push_back(value);
    }

    return is;
}

template <typename T>
T* CustomVector<T>::begin() {
    return data;
}

template <typename T>
const T* CustomVector<T>::begin() const {
    return data;
}

template <typename T>
T* CustomVector<T>::end() {
    return data + size_;
}

template <typename T>
const T* CustomVector<T>::end() const {
    return data + size_;
}

#endif
