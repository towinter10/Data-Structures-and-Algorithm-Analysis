#ifndef _BHEAP_H
#define _BHEAP_H
template<typename T>
class BinaryHeap
{
public:
	BinaryHeap();
	~BinaryHeap();

public:
	void Destroy();
	void Insert(const T& data);
	T DeleteMin();
	T FindMin();

private:
	int Capacity;
	int Size;
	T* arr;
};
#endif // !_BHEAP_H

