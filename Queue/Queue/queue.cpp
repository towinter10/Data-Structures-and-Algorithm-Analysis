#include<iostream>
#include"queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue(int num)
	:Front(0)
	, Rear(0)
	£¬Size(0)
{
	Capacity = num + 1;
	Arr = new T[Capacity];
}

template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
	Front = q.Front;
	Rear = q.Rear;
	Capacity = q.Capacity;
	Size = q.Size;
	Arr = new T[Capacity];
	for (int i = 0; i <= Capacity; i++)
	{
		Arr[i] = q.Arr[i];
	}
}

template <typename T>
Queue<T>::~Queue()
{
	if (Arr != nullptr)
		delete Arr;
}

template <typename T>
void Queue<T>::Enqueue(const T& q)
{
	if (Full())
	{
		cout << "this queue is full" << endl;
	}
	else
	{
		Arr[Rear] = q;
		Rear = (Rear + 1) % Capacity;
		Size = Size + 1;
	}
}

template <typename T>
void Queue<T>::Dequeue()
{
	if (Empty())
	{
		cout << "this queue is empty" << endl;
	}
	else
	{
		Front = (Front + 1) % Capacity;
		Size = Size - 1;
	}
}

template <typename T>
bool Queue<T>::Empty()
{
	return Front == Rear;
}

template <typename T>
bool Queue<T>::Full()
{
	return Front == (Rear + 1) % Capacity;
}

template <typename T>
void Queue<T>::PrintQueue()
{
	if (Empty())
	{
		cout << "this queue is empty" << endl;
	}
	else
	{
		if (Front < Rear)
		{
			for (int i = Front; i < Rear; i++)
			{
				cout << Arr[i] << "->";
			}
			cout << endl;
		}
		else
		{
			for (int i = Front; i < Capacity; i++)
			{
				cout << Arr[i] << "->";
			}
			for (int i = 0; i < Rear; i++)
			{
				cout << Arr[i] << "->";
			}
			cout << endl;
		}
	}
}

void test1()
{
	Queue<int>	q1(5);
	cout<<q1.Empty()<<endl;
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);
	q1.Enqueue(4);
	q1.Enqueue(5);
	q1.PrintQueue();
	cout<<q1.Full()<<endl;
	q1.Dequeue();
	cout << q1.Full() << endl;
	q1.PrintQueue();
	q1.Enqueue(6);
	cout << q1.Full() << endl;
	q1.PrintQueue();
}

int main()
{
	test1();
	system("pause");
	return 0;
}