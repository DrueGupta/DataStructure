#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template <typename TYPE>
class Deck : public List<TYPE>
{
	void addFront(TYPE value)
	{
		this->insert(value, 0);
	}
	void addBack(TYPE value)
	{
		this->insert(value);
	}
	void removeFront()
	{
		this->remove(0);
	}
	void removeBack()
	{
		this->remove();
	}
	TYPE readFront()
	{
		return this->read(0);
	}
	TYPE readBack()
	{
		return this->read(this->size - 1);
	}
};
