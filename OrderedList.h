#pragma once
#include<iostream>
#include"List.h"
using namespace std;

template <typename TYPE>
class OrderedList : public List<TYPE> 
{
public:
	void insert(TYPE value) override 
	{
		if (this->size == this->capacity) 
		{
			this->resize();
		}
		int index = 0;
		for (index = 0; this->data[index] < value && index < this->size; index++) {}
		for (int i = this->size; i > index; i--) 
		{
			this->data[i] = this->data[i - 1];
		}
		this->data[index] = value;
		this->size++;
	}
	void insert(TYPE value, int index) 
	{
		this->insert(value);
	}
	int search(TYPE value) override
	{
		int left = 0;
		int right = this->size - 1;
		int middle = (left + right) / 2;
		while (left < right)
		{
			if (this->data[middle] == value)
				return middle;
			else if (value < this->data[middle])
				right = middle - 1;
			else if (value > this->data[middle])
				left = middle + 1;
			middle = (left + right) / 2;
		}
		return -1;
	}
};
