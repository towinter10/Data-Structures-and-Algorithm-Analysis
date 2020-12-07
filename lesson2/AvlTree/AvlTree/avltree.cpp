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
	if (root)
	{
		Clear(root);
		root = nullptr;
	}
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
BiNode<T>* AvlTree<T>::BFTwoParent(BiNode<T>* r,BiNode<T>* tmp)
{
	BiNode<T>* parent = new BiNode<T>;
	stack<BiNode<T>*> s;
	s.push(r);
	while (s.empty()!= true)
	{
		parent = s.top();
		s.pop();
		if (parent->LChild != nullptr)
		{
			if (parent->LChild == tmp)
			{
				break;
			}
			else
			{
				s.push(parent->LChild);
			}
		}
		if (parent->RChild != nullptr)
		{
			if (parent->RChild == tmp)
			{
				break;
			}
			else
			{
				s.push(parent->RChild);
			}
		}
	}
	return parent;
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
		BiNode<T>* P = BFTwoParent(root, tmp);
		tmp->LChild = L->RChild;
		L->RChild = tmp;
		if (P->LChild == tmp)
		{
			P->LChild = L;
		}
		else
		{
			P->RChild = L;
		}


	}
}

template<typename T>
void AvlTree<T>::RR(BiNode<T>* tmp)
{
	if (tmp == root)
	{
		BiNode<T>* R = tmp->RChild;
		tmp->RChild = R->LChild;
		R->LChild = tmp;
		root = R;
	}
	else
	{
		BiNode<T>* R = tmp->RChild;
		BiNode<T>* P = BFTwoParent(root, tmp);
		tmp->RChild = R->LChild;
		R->LChild = tmp;
		if (P->LChild == tmp)
		{
			P->LChild = R;
		}
		else
		{
			P->RChild = R;
		}

	}
}

template<typename T>
void AvlTree<T>::LR(BiNode<T>* tmp)
{
	BiNode<T>* L = tmp->LChild;
	RR(L);
	LL(tmp);
}

template<typename T>
void AvlTree<T>::RL(BiNode<T>* tmp)
{
	BiNode<T>* R = tmp->RChild;
	LL(R);
	RR(tmp);
}


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
					node->bf = 0;
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
					node->bf = 0;
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
		if (nodet->bf == 2)
		{
			if (Data < nodet->LChild->Data)
			{
				LL(nodet);
			}
			else
			{
				LR(nodet);
			}
		}
		if (nodet->bf == -2)
		{
			if (Data > nodet->RChild->Data)
			{
				RR(nodet);
			}
			else
			{
				RL(nodet);
			}
		}
		AllBF(root);
	}
}


void Test1()//LL
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
}

void Test2()//RR
{
	AvlTree<int> t2;
	t2.Insert(10);
	t2.Insert(15);
	t2.Insert(5);
	t2.Insert(3);
	t2.Insert(7);
	t2.Insert(13);
	t2.Insert(17);
	t2.Insert(8);
	t2.Insert(9);
}

void Test3()//RL
{
	AvlTree<int> t3;
	t3.Insert(2);
	t3.Insert(1);
	t3.Insert(5);
	t3.Insert(4);
	t3.Insert(6);
	t3.Insert(3);
}

void Test4()
{
	AvlTree<int> t4;
	t4.Insert(2);
	t4.Insert(1);
	t4.Insert(0);
	t4.Insert(3);
	t4.Insert(4);
	t4.Insert(5);
	t4.Insert(6);
	t4.Insert(9);
	t4.Insert(8);
	t4.Insert(7);
}
int main()
{
	Test4();
	return 0;
}
