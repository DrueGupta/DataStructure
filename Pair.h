#pragma once
#include "List.h"

template <typename KEY, typename VALUE>
struct Pair
{
	KEY key;
	VALUE value;
	Pair(KEY k, VALUE v)
	{
		this->key = k;
		this->value = v;
	}
	Pair() {}
};
template <typename KEY, typename VALUE>
class Map
{
public:
	List < Pair<KEY, VALUE>** store;
	int size;
	int capacity;

	Map(int startCap)
	{
		this->store = new List<Pair<KEY, VALUE>>* [startCap];
		this->size = 0;
		this->capacity = startCap;
		for (int i = 0; i < startCap; i++)
		{
			store[i] = nullptr;
		}
	}

	Map() : Map(10) {}

	~Map()
	{
		for (int i = 0; i < this->capacity; i++)
		{
			if store[i] != nullptr
			{
				delete store[i];
			}
		}
		delete[] this->store;
	}

	int hash(int key)
	{
		return key % this->capacity;
	}
	int hash(double key)
	{
		return int(key * 1000000) % this->capacity;
	}
	int hash(string key)
	{
		int value = 0;
		for (int i = 0; i < key.size(); i++)
		{
			value += (i + 1) * (int)key[i];
		}
		return value % this->capacity;
	}
 };
