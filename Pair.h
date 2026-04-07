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
	bool operator==(Pair<KEY, VALUE> right)
	{
		return this->key == right.key;
	}
};
template <typename KEY, typename VALUE>
class Map
{
public:
	List < Pair<KEY, VALUE>>** store;
	int size;
	int capacity;
	int startingCapacity;

	Map(int startCap)
	{
		this->store = new List<Pair<KEY, VALUE>>* [startCap];
		this->size = 0;
		this->capacity = startCap;
		this->startingCapacity = startCap;
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
			if (store[i] != nullptr)
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
	int hash(char key)
	{
		return int(key) % this->capacity;
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

	void resize()
	{
		List<Pair<KEY, VALUE>>** ogStore = this->store;
		store = new List< Pair<KEY, VALUE> >* [this->capacity + this->startingCapacity];
		int ogCap = this->capacity;
		this->capacity = this->capacity + this->startingCapacity;
		for (int i = 0; i < this->capacity; i++)
		{
			this->store[i] = nullptr;
		}
		int index = 0;
		Pair<KEY, VALUE> pair;
		for (int i = 0; i < ogCap; i++)
		{
			if (ogStore[i] != nullptr)
			{
				for (int j = 0; j < ogStore[i]->len(); j++)
				{
					index = hash(ogStore[i]->read(j).key);
					if (this->store[index] == nullptr)
					{
						this->store[index] = new List<Pair<KEY, VALUE>>();
					}
					pair = Pair<KEY, VALUE>(ogStore[i]->read(j).key, ogStore[i]->read(j).value);
					this->store[index]->insert(pair);
				}
			}
		}
		for (int i = 0; i < ogCap; i++)
		{
			if (ogStore[i] != nullptr)
			{
				delete ogStore[i];
			}
		}
		delete[] ogStore;
	}

	VALUE get(KEY key)
	{
		int index = hash(key);
		if (this->store[index] != nullptr)
		{
			for (int i = 0; i < this->store[index]->len(); i++)
			{
				if (this->store[index]->read(i).key == key)
				{
					return this->store[index]->read(i).value;
				}
			}
		}
		return (VALUE)NULL;
	}

	void add(KEY key, VALUE value)
	{
		if (this->size > this->capacity * 0.7)
		{
			this->resize();
		}
		int index = hash(key);
		if (this->store[index] == nullptr)
		{
			this->store[index] = new List<Pair<KEY, VALUE>>();
		}
		Pair<KEY, VALUE> pair(key, value);
		this->store[index]->insert(pair);
		this->size++;
	}

	void display()
	{
		for (int i = 0; i < this->capacity; i++)
		{
			cout << i << " : ";
			if (this->store[i] != nullptr)
			{
				for (int j = 0; j < this->store[i]->len(); j++)
				{
					cout << "(" << this->store[i]->read(j).key << "," << this->store[i]->read(j).value << ") ";
				}
			}
			cout << endl;
		}
	}

	bool isKey(KEY key)
	{
		int index = hash(key);
		int result = this->store[index]->search(key);
		return result != -1;
	}
};
