#include<iostream>

#include"tree.h"
using namespace std;



template<typename T>
BiTree<T>::BiTree()
	:Root(nullptr)
{}

template<typename T>
BiTree<T>::BiTree(const T& Data)
{
	Root = new BiNode<T>;
	Root->Data = Data;
	Root->LChild = Root->RChild = nullptr;
}

template<typename T>
BiTree<T>::~BiTree()
{
	if (Root)
	{
		Clear(Root);
		Root = nullptr;
	}
}

template<typename T>
void BiTree<T>::CreatBiTree(const T& Data)
{
	if (Root == nullptr)
	{
		Root = new BiNode<T>;
		Root->Data = Data;
		Root->LChild = Root->RChild = nullptr;
	}
	else
	{
		BiNode<T>* node = new BiNode<T>;
		BiNode<T>* tmp = Root;
		while (1)
		{
			if (Data < tmp->Data)
			{
				if (tmp->LChild == nullptr)
				{
					node->Data = Data;
					node->LChild = node->RChild = nullptr;
					tmp->LChild = node;
					break;
				}
				else
				{
					tmp = tmp->LChild;
				}
			}
			else
			{
				if (tmp->RChild == nullptr)
				{
					node->Data = Data;
					node->LChild = node->RChild = nullptr;
					tmp->RChild = node;
					break;
				}
				else
				{
					tmp = tmp->RChild;
				}
			}
		}

		
	
	}
}
template<typename T>
void BiTree<T>::LevOrder()
{
	Queue<T> q(1024);
	if (Root != nullptr)
	{
		q.Enqueue(Root);
	}
	while (q.Empty() != true)
	{
		BiNode<T> node = q.Frist();
		q.Dequeue();
		if (node->LChild != nullptr)
		{
			q.Enqueue(node->LChild);
		}
		if (node->RChild != nullptr)
		{
			q.Enqueue(node->RChild);
		}
	}
}
