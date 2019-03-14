#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>

#include "HashNode.h"

template <typename T> class HashTable
{
private:
	int tableSize = 0;
	std::vector<std::list<HashNode<T>*>> table;

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
	// Default constructor.
	HashTable(int size) : tableSize(size)
	{
		for (int count = 0; count < size; count++)
		{
			std::list<HashNode<T>*> newBucket;
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
		int hashedValue = Hash(keyToFind);
		std::list<HashNode<T>*> bucket = table[hashedValue];
		typename std::list<HashNode<T>*>::iterator myIter = bucket.begin();

		for (myIter = bucket.begin(); myIter != bucket.end(); myIter++)
		{
			if ((*myIter)->GetKey() == keyToFind)
			{
				return (*myIter)->GetValue();
			}
		}

		return -1;
	}

	void PrintTable()
	{
		for (int bucketNumber = 0; bucketNumber < tableSize; bucketNumber++)
		{
			std::cout << "Hash " << bucketNumber<< ": ";

			std::list<HashNode<T>*> bucket = table[bucketNumber];
			typename std::list<HashNode<T>*>::iterator myIter = bucket.begin();

			for (myIter = bucket.begin(); myIter != bucket.end(); myIter++)
			{
				std::cout << (*myIter)->GetValue();
				std::cout << " -> ";
			}
			std::cout << "\n";
		}
	}
};

#endif // !HASHTABLE_H