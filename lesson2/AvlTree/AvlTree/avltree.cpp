#include<iostream>
#include"avltree.h"
using namespace std;

template<typename T>
AvlTree<T>::AvlTree()
{
	root = nullptr;
}

template<typename T>
AvlTree<T>::~AvlTree()
{
	Clear(root);
}

template<typename T>
void AvlTree<T>::Insert(const T& Data)
{
	if (root == nullptr)
	{
		root = new BiNode<T>;
		root->Data = Data;
		root->LChild = Root->RChild = nullptr;
		root->bf = 0;
	}

}