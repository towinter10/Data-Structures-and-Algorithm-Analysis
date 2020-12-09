#ifndef _QUEUE_H
#define _QUEUE_H
template <typename T>
class Queue
{
public:
	Queue(int num);
	Queue(const Queue<T>& q);
	//Queue<T>& operator=(const Queue<T>& q);
	~Queue();

public:
	void Enqueue(const T& q);
	void Dequeue();
	void PrintQueue();
	bool Empty();
	bool Full();

private:
	T* Arr;
	size_t Capacity;
	size_t Front;
	size_t Rear;
	size_t Size;
};


#endif // !_QUEUE_H
#pragma once
