#include<iostream>
using namespace std;
#include<assert.h>
#include"slist.h"

LinkNode::LinkNode(const DataType x):data(x),next(nullptr){}

SList::SList(): head(nullptr),tail(nullptr){}

SList::SList(const SList& s):head(nullptr),tail(nullptr)
{
	if (s.head == nullptr)
	{
		return;
	}
	LinkNode* tmp = s.head;
	do
	{
		PushBack(tmp->data);
		tmp = tmp->next;
	} while (tmp != s.head);
}

SList::~SList()
{
	Clear();
}

void SList::PushBack(const DataType& x)//β�巨
{
	if (head == nullptr)
	{
		head = new LinkNode(x);
		tail = head;
		tail->next = head;
	}
	else
	{
		tail->next = new LinkNode(x);
		tail = tail->next;
		tail->next = head;
	}
}

void SList::PushFront(DataType x)//ͷ�巨
{
	if (head == nullptr)
	{
		PushBack(x);
	}
	else
	{
		LinkNode* tmp = head;
		head = new LinkNode(x);
		head->next = tmp;
		tail->next = head;
	}
}