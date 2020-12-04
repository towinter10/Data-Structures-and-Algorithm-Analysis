#include<iostream>
#include"avltree.h"
#include<stack>
#include<vector>
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
void AvlTree<T>::Clear(BiNode<T>* n)
{
	if (n)
	{
		Clear(n->LChild);
		Clear(n->RChild);
		delete n;
	}

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
BiNode<T>* AvlTree<T>::BFTwo(BiNode<T>* node)
{
	stack<BiNode<T>*> s;
	vector<BiNode<T>*> t;
	BiNode<T>* tmp1 = node;
	s.push(node);
	while (s.empty() != true)
	{
		tmp1 = s.top();
		t.push_back(tmp1);
		s.pop();
		if (tmp1->RChild != nullptr)
		{
			s.push(tmp1->RChild);
		}
		if (tmp1->LChild != nullptr)
		{
			s.push(tmp1->LChild);
		}
	}
	BiNode<T>* tmp2 = new BiNode<T>;
	while (t.empty()!= true)
	{
		tmp2 = t.back();
		if (tmp2->bf == 2 || tmp2->bf == -2)
		{
			break;
		}
		else
		{
			t.pop_back();
		}
	}
	return tmp2;
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
		BiNode<T>* L = tmp->LChild;
		tmp->LChild = L->RChild;
		L->RChild = tmp;
		root = L;
	}
	else
	{
		BiNode<T>* L = tmp->LChild;
		BiNode<T>* P = new BiNode<T>;
		AvlTree<T>::BFTwoParent(root, tmp, P);
		tmp->LChild = L->RChild;
		L->RChild = tmp;
		P->LChild = L;

	}
}

//template<typename T>
//void AvlTree<T>::RR(BiNode<T>* tmp);
//
//template<typename T>
//void AvlTree<T>::LR(BiNode<T>* tmp);
//
//template<typename T>
//void AvlTree<T>::RL(BiNode<T>* tmp);


template<typename T>
void AvlTree<T>::Insert(const T& Data)
{
	if (root == nullptr)
	{
		root = new BiNode<T>;
		root->Data = Data;
		root->LChild = root->RChild = nullptr;
		root->bf = 0;
	}
	else
	{
		BiNode<T>* node = new BiNode<T>;
		BiNode<T>* tmp = root;
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
		AllBF(root);
		BiNode<T>* nodet = BFTwo(root);
		//BFTwo(root, nodet);
		if (nodet->bf == 2)
		{
			LL(nodet);
		}

	}
}


int main()
{
	AvlTree<int> t1;
	t1.Insert(10);
	t1.Insert(15);
	t1.Insert(5);
	t1.Insert(3);
	t1.Insert(7);
	t1.Insert(13);
	t1.Insert(17);
	t1.Insert(2);
	t1.Insert(1);
	return  0;
}

//AllBF(root);
//BiNode<T>* nodet = new BiNode<T>;
//BFTwo(root, nodet);
//LL(nodet);