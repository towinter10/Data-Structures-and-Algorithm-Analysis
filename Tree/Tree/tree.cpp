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
void BiTree<T>::Clear(BiNode<T>* n)
{
	if (n)
	{
		Clear(n->LChild);
		Clear(n->RChild);
		delete n;
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

/*使用自建队列结构实现层次排序
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
*/
//使用C++库函数实现层次排序
template<typename T>
void BiTree<T>::LevOrder(vector<T>& arr)
{
	queue<BiNode<T>*> q;
	if (Root != nullptr)
	{
		q.push(Root);
	}
	while (q.empty() != true)
	{
		BiNode<T>* node = q.front();
		arr.push_back(node->Data);
		q.pop();
		if (node->LChild != nullptr)
		{
			q.push(node->LChild);
		}
		if (node->RChild != nullptr)
		{
			q.push(node->RChild);
		}
	}
}

template<typename T>
void BiTree<T>::PreOrder(vector<T>& arr)
{
	stack<BiNode<T>*> s;
	BiNode<T>* tmp = Root;
	s.push(Root);
	while (s.empty() != true)
	{
		tmp = s.top();
		arr.push_back(tmp->Data);
		s.pop();
		if (tmp->RChild != nullptr)
		{
			s.push(tmp->RChild);
		}
		if (tmp->LChild != nullptr)
		{
			s.push(tmp->LChild);
		}
	}
}

template<typename T>
void BiTree<T>::InOrder(vector<T>& arr)
{
	stack<BiNode<T>*> s;
	BiNode<T>* tmp = Root;
	while (tmp != nullptr || s.empty() != true)
	{
		if (tmp!= nullptr)
		{
			s.push(tmp);
			tmp = tmp->LChild;
		}
		else
		{
			tmp = s.top();
			arr.push_back(tmp->Data);
			s.pop();
			tmp = tmp->RChild;
		}
	}

}

template<typename T>
void BiTree<T>::PostOrder(vector<T>& arr)
{
	stack<BiNode<T>*> s;
	s.push(Root);
	BiNode<T>* tmp;
	while (s.empty() != true)
	{
		tmp = s.top();
		if (tmp->LChild == nullptr && tmp->RChild == nullptr)
		{
			arr.push_back(tmp->Data);
			s.pop();
		}
		else
		{
			if (tmp->RChild != nullptr)
			{
				s.push(tmp->RChild);
				tmp->RChild = nullptr;
			}
			if (tmp->LChild != nullptr)
			{
				s.push(tmp->LChild);
				tmp->LChild = nullptr;
			}
		}
	}

}

void test2()
{
	BiTree<int> t1;
	t1.CreatBiTree(5);
	t1.CreatBiTree(10);
	t1.CreatBiTree(3);
	t1.CreatBiTree(4);
	t1.CreatBiTree(8);
	t1.CreatBiTree(6);
	vector<int> arr;
	t1.PostOrder(arr);
}

int main()
{
	test2();
	system("pause");
	return 0;
}