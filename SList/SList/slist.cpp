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

void SList::PushBack(const DataType& x)//尾插法
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

void SList::PushFront(DataType x)//头插法
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

void SList::PopBack()//尾删
{
	if (head == nullptr)
	{
		cout << "this list is empty." << endl;
	}
	else if(head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		LinkNode* tmp = head;
		while (tmp->next != tail)//循环到倒数第二个节点
		{
			tmp = tmp->next;
		}
		delete tail;
		tail = tmp;
		tail->next = head;
	}
}

void SList::PopFront()//头删
{
	if (head == nullptr || head == tail)
	{
		PopBack();
	}
	else
	{
		LinkNode* tmp = head;
		tmp = tmp->next;
		delete head;
		head = tmp;
		tail->next = head;
	}
}

LinkNode* SList::Find(DataType x)//查找x所在位置
{
	if (head == NULL)
	{
		cout << "this list is empty." << endl;
		return nullptr;
	}
	else
	{
		LinkNode* tmp = head;
		do
		{
			if (tmp->data == x)
			{
				return tmp;
			}
			tmp = tmp->next;
		} while (tmp != head);
		return nullptr;
	}
}

void SList::Insert(LinkNode* pos, DataType x)
{
	assert(pos);
	if (pos == tail)
	{
		PushBack(x);
	}
	else
	{
		LinkNode* tmp = new LinkNode(x);
		tmp->next = pos->next;
		pos->next = tmp;
	}
}

void SList::Erase(LinkNode* pos)
{
	assert(pos);
	if (pos == tail)
	{
		PopBack();
	}
	if (pos == head)
	{
		PopFront();
	}
	else
	{
		LinkNode* prev = head;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		delete pos;
	}
}

void SList::Remove(DataType x)      //查找某节点并删除
{
	if (head == nullptr)
	{
		cout << "This SList is empty !" << endl;
	}
	else
	{
		LinkNode* tmp = Find(x);
		if (tmp != nullptr)
		{
			Erase(tmp);
		}
	}
}

void SList::PrintSList()
{
	//头结点为空时，无需打印链表
	if (head == nullptr)
	{
		cout << "This SList is Empty !" << endl;
		return;
	}
	else
	{
		LinkNode* tmp = head;
		do {
			cout << tmp->data << "-->";
			tmp = tmp->next;
		} while (tmp != head);
		cout << endl;
	}
}

void SList::Clear()         //链表置空
{
	LinkNode* begin = head;
	while (begin != tail)
	{
		head = head->next;
		delete begin;
		begin = head;
	}
	head = nullptr;
	tail = nullptr;
}