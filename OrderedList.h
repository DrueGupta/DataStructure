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
		if(this->size == this->capacity)
			this->resize():
	}
	int index = 0;
	for (int i = 0; this->data[i] < value && i < this->sie; i++)
	{
		index = i;
	}
	for (int i = this->size; i > index; i--)
	{
		this->date[i] = this->date[i - 1];
	}
	this->date[index] = value;

	void insert(TYPE value, int index)
	{
		this->insert(value);
	}
};
