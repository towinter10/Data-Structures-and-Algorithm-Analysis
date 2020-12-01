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
int AvlTree<T>::GetDepth(BiNode<T>* nood)
{
	int m, n;
	if (nood == nullptr)
	{
		return 0;
	}
	else
	{
		m = GetDepth(nood->LChild);
		n = GetDepth(nood->RChild);
		if (m > n)
		{
			return m + 1;
		}
		else {
			return n + 1;
		}
	}
}

template<typename T>
int AvlTree<T>::GetBF(BiNode<T>* nood)
{
	int m = 0, n = 0;
	if (nood != nullptr)
	{
		m = GetDepth(nood->LChild);
		n = GetDepth(nood->RChild);
	}
	return m - n;

}

template<typename T>
void AvlTree<T>::AllBF(BiNode<T>* nood)
{
	if (nood != nullptr)
	{
		nood->bf = GetBF(nood);
		AllBF(nood->LChild);
		AllBF(nood->RChild);
	}
}

template<typename T>
void AvlTree<T>::BFTwo(BiNode<T>* nood, BiNode<T>* tmp)
{
	if (nood != nullptr)
	{
		if (nood->bf == 2 || nood->bf == -2)
		{
			tmp = nood;
		}
		BFTwo(nood->LChild, tmp);
		BFTwo(nood->RChild, tmp);
	}
}

template<typename T>
void AvlTree<T>::BFTwoParent(BiNode<T>* r,BiNode<T>* tmp, BiNode<T>* parent)
{
	if (r != nullptr)
	{
		if (r->LChild != nullptr)
		{
			if (r->LChild == tmp || r->RChild == tmp)
			{
				parent = tmp;
			}
		}
		if (r->RChild != nullptr)
		{
			if (r->LChild == tmp || r->RChild == tmp)
			{
				parent = tmp;
			}
		}
		BFTwoParent(r->LChild, tmp, parent);
		BFTwoParent(r->RChild, tmp, parent);
	}
}

template<typename T>
void AvlTree<T>::LL(BiNode<T>* tmp)
{
	if (tmp == root)
	{

	}
}

template<typename T>
void AvlTree<T>::RR(BiNode<T>* tmp);

template<typename T>
void AvlTree<T>::LR(BiNode<T>* tmp);

template<typename T>
void AvlTree<T>::RL(BiNode<T>* tmp);


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