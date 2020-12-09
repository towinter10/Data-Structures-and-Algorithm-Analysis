#include"BHeap.h"

template<typename T>
BinaryHeap<T>::BinaryHeap()
{
	Capacity = 100;
	Size = 0;
	arr = new T[Capacity];
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
	Capacity = 0;
	Size = 0;
	delete arr;
}

template<typename T>
void BinaryHeap<T>::Insert(const T& data)
{

}