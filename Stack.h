#pragma once
#include "List.h"
using namespace std;

template <typename TYPE>
class Stack : public List<TYPE>
{
public:
	void push(TYPE value)
	{
		this -> insert(value);
	}

	void pop()
	{
		this->remove();
	}
	
	TYPE read()
	{
		return List<TYPE>::read(this->size - 1);
	}
};
