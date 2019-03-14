#ifndef HASHNODE_H
#define HASHNODE_H

template <typename KeyType, typename ValueType> class HashNode
{
private:
	KeyType key;
	ValueType value;
public:
	// Default constructor.
	HashNode(KeyType newKey, ValueType newValue) : key(newKey), value(newValue) { }

	// Default destructor.
	~HashNode() { }
};

#endif // !HASHNODE_H
