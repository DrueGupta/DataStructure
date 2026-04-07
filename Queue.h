#pragma once
#include "List.h"
using namespace std;

template<typename TYPE>
class Queue : public List<TYPE>
{
public:
	void enqueue(TYPE value)
	{
		this->insert(value);
	}

	void dequeue()
	{
		this->remove(0);
	}

	TYPE read()
	{
		return List<TYPE>::read(0);
	}
};
