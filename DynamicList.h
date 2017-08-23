#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include<iostream>
#include<string>
using namespace std;

class DynamicList
{
private:
	struct Node
	{
		string i;
		Node* next;
	};

	Node* head;

public:
	DynamicList();
	~DynamicList();
	void clear();
	int insert(string);
	int append(string);
	int remove(string);
	int peek(string&) const;
	bool isFull() const;
	bool isEmpty() const;
	int getLength() const;
	int find(string) const;
	void print() const;
};
DynamicList::DynamicList()
{
	head = NULL;
}

DynamicList::~DynamicList()
{
	clear();
}

void DynamicList::clear()
{
	Node* p = NULL;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

int DynamicList::insert(string i)
{
	if (isFull())
		return -1;

	Node* n = new Node;
	n->i = i;

	Node* p = head, *q = NULL;

	while (p != NULL)
	{
		q = p;
		p = p->next;
	}

	if (q == NULL)
	{
		n->next = head;
		head = n;
	}
	else
	{
		q->next = n;
		n->next = p;
	}

	return 0;
}

int DynamicList::append(string i)
{
	if (isFull())
		return -1;

	Node* n = new Node;
	n->i = i;
	n->next = NULL;

	if (isEmpty())
	{
		head = n;
		return 0;
	}

	Node* p = head;

	while (p->next != NULL)
		p = p->next;

	p->next = n;

	return 0;
}

int DynamicList::remove(string i)
{
	if (isEmpty())
		return -1;

	Node* p = head, *q = NULL;

	while (p != NULL && p->i != i)
	{
		q = p;
		p = p->next;
	}

	if (p == NULL)
		return -1;

	if (q == NULL)
		head = head->next;
	else
		q->next = p->next;

	delete p;

	return 0;
}

int DynamicList::peek(string& i) const
{
	if (isEmpty())
		return -1;

	i = head->i;

	return 0;
}

bool DynamicList::isFull() const
{
	Node* dummy = new Node;

	if (dummy)
	{
		delete dummy;
		return false;
	}

	return true;
}

bool DynamicList::isEmpty() const
{
	return head == NULL;
}

int DynamicList::getLength() const
{
	int len = 0;
	Node* p = head;

	while (p)
	{
		len++;
		p = p->next;
	}

	return len;
}

int DynamicList::find(string i) const
{
	int pos = -1;
	Node* p = head;

	while (p)
	{
		pos++;

		if (p->i == i)
			return pos;

		p = p->next;

	}

	return -1;
}

void DynamicList::print() const
{
	Node* p = head;

	cout << "Head->";
	while (p)
	{
		cout << p->i << "->";
		p = p->next;
	}
	cout << "->NULL";

	cout << endl;
}

#endif
