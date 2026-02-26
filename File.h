#pragma once
#include <iostream>
using namespace std;
template <typename TYPE>
class List {
protected:
    TYPE* data;
    int size;
    int capacity;
    double multiplier;

public:
    List(int capacity, double multiplier) 
    {
        this->size = 0;
        this->capacity = capacity;
        this->multiplier = multiplier;
        this->data = new TYPE[this->capacity];
    }
    List(int capacity) : List(capacity, 10) {}

    List(double multiplier) : List(10, multiplier) {}

    List() : List(10, 10) {}

    ~List() 
    {
        delete[] this->data;
    }

    // Get Size
    int length() 
    {
        return this->size;
    }
    int len() 
    {
        return this->size;
    }
    // Resize Method
    void resize() 
    {
        TYPE* ogData = this->data;
        this->capacity *= this->multiplier;
        this->data = new TYPE[this->capacity];
        for (int i = 0; i < this->size; i++) 
        {
            this->data[i] = ogData[i];
        }
        delete[] ogData;
    }
    List<TYPE>& operator+(TYPE right)
    {
        this->insert(right);
        return this;
    }
    TYPE read(int index) 
    {
        return this->data[index];
    }
    virtual void insert(TYPE value)
    {
        if (this->capacity == this->size)
        {
            this->resize();
        }
        this->data[this->size] = value;
        this->size++;
    }
    void insert(TYPE value, int index)
    {
        if (this->size == this->capacity)
        {
            this->resize();
        }
        for (int i = this->size; i > index; i--)
        {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        this->size++;
    }
    void remove()
    {
        this->size--;
    }
    void remove(int index)
    {
        for (int i = index; i < this->size; i++)
        {
            this->data[i] = this->data[i + 1];
        }
        this->size--;
    }
    friend ostream& operator<<(ostream& left, List<TYPE>& right)
    {
        left << "[ ";
        for (int i = 0; i < right.size; i++)
        {
            left << right.data[i] << " ";
        }
        left << "]";
        return left;
    }
    List<TYPE> operator+(List<TYPE> right)
    {
        List<TYPE> noob;
        for (int i = 0; i < this->size; i++)
        {
            noob.insert(this->data[i]);
        }
        return noob;
    }
};
