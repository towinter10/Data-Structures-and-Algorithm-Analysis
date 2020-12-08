/**/
//拷贝构造函数与赋值函数https://www.cnblogs.com/this-543273659/archive/2011/09/18/2180575.html
/**/
#include<iostream>
#include<stdlib.h>
using namespace std;
#include"stack.h"

template <typename T>
AStack<T>::AStack(int i)//构造函数
	:Top(-1)
{
	Capacity = i;
	Arr = new T[Capacity];
}

template <typename T>
AStack<T>::AStack(const AStack<T>& s)//拷贝构造函数
{
	Top = s.Top;
	Capacity = s.Capacity;
	Arr = new T[Capacity];
	for (size_t i = 0; i <= Top; i++)
	{
		Arr(i) = s.Arr(i);
	}
}

template <typename T>
AStack<T>& AStack<T>::operator=(const AStack<T>& s)//赋值运算符重载函数
{
	if (Capacity < s.Capacity)
	{
		Capacity = s.Capacity;
		Arr = new T[Capacity];
	}
	Top = s.Top;
	for (size_t i = 0; i <= Top; i++)
	{
		Arr(i) = s.Arr(i);
	}
	return *this;
}

template <typename T>
AStack<T>::~AStack()//析构函数
{
	if (Arr != nullptr)
	{
		delete Arr;
	}
}

template <typename T>
void AStack<T>::Push(const T& s)//入栈
{
	if (Top == Capacity-1)
	{
		cout << "stack is full" << endl;
	}
	else
	{
		Top++;
		Arr[Top] = s;
	}
}

template <typename T>
void AStack<T>::Pop()//出栈
{
	if (Top == -1)
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		Top--;
	}
}

template <typename T>
bool AStack<T>::Empty()
{
	return Top == -1;
}

template <typename T>
size_t AStack<T>::Size()
{
	return Top + 1;
}

template <typename T>
T AStack<T>::GetTop()
{
	return Arr[Top];
}

template <typename T>
void AStack<T>::PrintStack()
{
	for (int i = Top; i >= 0; --i)
	{
		cout << Arr[i] << "->";
	}
	cout << endl;

}

int main()
{
	AStack<int> s1(10);
	s1.Push(10);
	s1.Push(12);
	s1.Push(23);
	s1.Pop();
	s1.PrintStack();
	s1.Size();
	s1.Empty();
	system("pause");
	return 0;
}