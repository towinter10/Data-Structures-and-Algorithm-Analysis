#include<iostream>
#include <cmath>
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

int GetNum(LinkNode* pos, int x)
{
	int num = pos->data;
	int tmp = pow(10, x - 1);
	num = num / tmp;
	num = num % 10;
	return num;
}

void Initiate(LinkNode** head)
{
	(*head) = (LinkNode*)malloc(sizeof(LinkNode));
	(*head)->next = nullptr;
}

void insert(LinkNode* head, LinkNode* node)
{
	if (head == nullptr) return;
	else
	{
		LinkNode* p;
		p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = node;
		node->next = nullptr;
	}

}


void SList::RadixSort(int x)//桶排序
{
	LinkNode* p[10];
	LinkNode* q;
	int i, j, k,l;

	for (j = 1; j <= x; j++)
	{
		for (i = 0; i < 10; i++)
		{
			
			Initiate(&p[i]);
		}
		while (head != nullptr)
		{
			q = head;
			k = GetNum(q, j);
			insert(p[k], q);
			q = q->next;
		}
	}
	//Clear();
	for (l = 0; l < 10; l++)
	{
		while (p[l]->next != nullptr)
		{
			PushBack(p[l]->next->data);
			p[l] = p[l]->next;
		}
	}
}

void SList::Merge(SList& s)    //合并（针对有序链表）,合并后依然有序
{
	//  1. _head为空
	//  2. 链表s为空
	if (head == NULL)
	{
		head = s.head;
		tail = s.tail;
	}
	if (s.head == NULL)
	{
		return;
	}
	//  3. 两个链表都不为空
	LinkNode* phead = head;
	if (phead->data <= s.head->data)
	{
		phead = phead->next;
	}
	else
	{
		head = s.head;
		s.head = s.head->next;
	}
	LinkNode* cur = head;
	while (1)
	{
		if (phead->data <= s.head->data)
		{
			head->next = phead;
			head = head->next;
			if (phead == tail)
			{
				head->next = s.head;
				tail = s.tail;
				tail->next = cur;
				break;
			}
			phead = phead->next;
		}
		else
		{
			head->next = s.head;
			head = head->next;
			if (s.head == s.tail)
			{
				head->next = phead;
				tail->next = cur;
				break;
			}
			s.head = s.head->next;
		}

	}
	head = cur;
}