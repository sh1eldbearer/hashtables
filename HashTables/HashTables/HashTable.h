#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

#include "HashNode.h"

template <typename T> class HashTable
{
private:
	int tableSize = 0;
	std::vector<std::vector<HashNode<std::string, T>*>> table;
public:
	// Default constructor.
	HashTable(int size) : tableSize(size)
	{
		for (int count = 0; count < size; count++)
		{
			std::vector<HashNode<std::string, T>*> newBucket;
			table.push_back(newBucket);
		}
	}

	// Default destructor.
	~HashTable() { }


};

#endif // !HASHTABLE_H