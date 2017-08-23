#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "DynamicList.h"

using namespace std;

class HashTable
{
private:
	DynamicList *table;
	int size;

	int hash(string key) const;
public:
	HashTable(int);
	~HashTable();
	void clear();
	int insert(string);
	int remove(string);
	int find(string) const;
	bool isFull() const;
	bool isEmpty() const;
	void print() const;
};
int HashTable::hash(string s) const
{
	int sum = 0, index = 0;
	for (string::size_type i = 0; i < s.length(); i++)
	{
		sum += s[i];
	}
	index = sum % (this->size);
	return index;
}

HashTable::HashTable(int n)
{
	table = new DynamicList[n];
	this->size = n;
}

HashTable::~HashTable()
{
	clear();
}

void HashTable::clear()
{
	for (int i = 0; i<size; i++) {
		table[i].clear();
	}
	delete[] table;
}

int HashTable::insert(string i)
{
	int index = hash(i);
	table[index].append(i);
	return 0;
}

int HashTable::remove(string i)
{
	int index = hash(i);
	return table[index].remove(i);
}

int HashTable::find(string i) const
{
	int index = this->hash(i);
	return table[index].find(i);
}

bool HashTable::isFull() const
{
	for (int i = 0; i<size; i++) {
		if (table[i].isFull()) {
			return true;
		}
	}
	return false;
}

bool HashTable::isEmpty() const
{
	bool status = true;
	for (int i = 0; i<size; i++) {
		if (!table[i].isFull()) {
			status = false;
		}
	}
	return status;
}

void HashTable::print() const
{
	for (int i = 0; i<size; i++) {
		cout << "Bucket " << i << ": ";
		table[i].print();
	}
}

#endif
