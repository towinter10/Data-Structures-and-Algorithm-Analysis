#include"slist.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

void Test2()
{
    SList list1;
    list1.PushBack(1);
    list1.PushBack(3);
    list1.PushBack(4);
    list1.PushBack(2);
    list1.PushBack(6);
    list1.PrintSList();

    /*list1.RemoveAll(2);
    list1.PrintSList();*/

    SList list2 = list1;
    list2.PushBack(2);
    list2.PushBack(3);
    list2.PushBack(4);
    list2.PushBack(2);
    //list2.PushFront(2);
    cout << list2.head->next << endl;
    list2.PrintSList();
    //list2.RadixSort(1);
    list2.PrintSList();

}

void Initiate(LinkNode** head)
{
	(*head) = (LinkNode*)malloc(sizeof(LinkNode));
	(*head)->next = NULL;
}

void Insert(LinkNode* head, int num)
{
	if (head == NULL) return;
	else
	{
		LinkNode* p, * q;
		q = head;
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = num;
		p->next = NULL;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

LinkNode* GetFirstNode(LinkNode* head)
{
	if (head->next == NULL)  return NULL;
	else
	{
		LinkNode* p;
		p = head->next;
		head->next = p->next;
		return p;
	}
}

void AppendNode(LinkNode* head, LinkNode* node)
{
	if (head == NULL) return;
	else
	{
		LinkNode* p;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
		node->next = NULL;
	}
}

void Total(LinkNode* L, LinkNode* head)
{
	LinkNode* p;
	p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = head->next;
}

int Power(int a, int n)
{
	int y;
	if (n == 0)
		return 1;
	else
	{
		y = Power(a, n / 2);
		y = y * y;
		if (n % 2 == 1)
			y = y * a;
	}
	return y;
}

int GetNum(LinkNode* p, int i)
{
	int data = p->data;
	int a;
	i--;
	a = data / Power(10, i);
	return a % 10;
}
//第二个形参表示参加排序的整数最大位数一共有count位数字
void radix_sort(LinkNode* head, int count)
{
	LinkNode* p[10], * q;
	int i, j, k;

	for (j = 1; j <= count; j++)
	{
		//十个头结点初始化
		for (i = 0; i < 10; i++)
		{
			Initiate(&p[i]);
		}
		//链表从头到尾扫描，并将扫描到的节点脱离链表。
		while (head->next != NULL)
		{
			q = GetFirstNode(head);
			k = GetNum(q, j); //取得链表节点第j位的元素值k
			AppendNode(p[k], q); //将该节点连接到10个链表相应的位置
		}
		//将10个链表从0-9依次连接到head节点后面
		for (i = 0; i < 10; i++)
		{
			Total(head, p[i]);
		}
	}

	for (i = 0; i < 10; i++)
	{
		delete(p[i]);
	}


}

void printSL(LinkNode* head)
{
	LinkNode* p;
	p = head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
    //Test1();
    //Test2();
    LinkNode* head;
    Initiate(&head);
    Insert(head, 61113);
    Insert(head, 94212);
    Insert(head, 31232);
    Insert(head, 653);
    Insert(head, 2332);
    Insert(head, 123);
    Insert(head, 23);
    radix_sort(head, 5); //表示参加排序的整数最大位数一共有4位数字
    printSL(head);
    system("pause");
}
