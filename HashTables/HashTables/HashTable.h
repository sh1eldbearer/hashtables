#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

#include "HashNode.h"

template <typename T> class HashTable
{
private:
	int tableSize = 0;

	// Hashing function.
	int Hash(std::string key)
	{
		long long intKey = 0;
		for (int charIndex = 0; charIndex < key.size(); charIndex++)
		{
			intKey += key.at(charIndex);
		}
		return intKey % tableSize;
	}
public:
	std::vector<std::vector<HashNode<T>*>> table;

	// Default constructor.
	HashTable(int size) : tableSize(size)
	{
		for (int count = 0; count < size; count++)
		{
			std::vector<HashNode<T>*> newBucket;
			table.push_back(newBucket);
		}
	}

	// Default destructor.
	~HashTable() { }

	int Insert(std::string key, T value)
	{
		int hashedValue = Hash(key);
		table[hashedValue].push_back(new HashNode<T>(key, value));
		return hashedValue;
	}

	T Retrieve(std::string keyToFind)
	{

	}
};

#endif // !HASHTABLE_H