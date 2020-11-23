#include<iostream>
#include<vector>
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
		BiNode<T>* node = new BiNode(Data);
		BiNode<T>* tmp = Root;
		if (tmp->LChild == nullptr)
		{
			node->Data = Data;
			node->LChild = node->RChild = nullptr;
			tmp->LChild = node;
		}
		else
		{
			//判断右节点是否为空，
		}
	}
}