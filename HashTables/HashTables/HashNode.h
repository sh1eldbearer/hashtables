#ifndef HASHNODE_H
#define HASHNODE_H

template <typename ValueType> class HashNode
{
private:
	std::string key;
	ValueType value;
public:
	// Default constructor.
	HashNode(std::string newKey, ValueType newValue) : key(newKey), value(newValue) { }

	// Default destructor.
	~HashNode() { }

	std::string GetKey()
	{
		return key;
	}

	void SetKey(std::string newKey)
	{
		key = newKey;
	}

	ValueType GetValue()
	{
		return value;
	}

	void SetValue(ValueType newValue)
	{
		value = newValue;
	}
};

#endif // !HASHNODE_H
