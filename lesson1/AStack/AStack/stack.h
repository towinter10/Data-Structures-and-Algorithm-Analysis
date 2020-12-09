#ifndef _ASTACH_H
#define _ASTACH_H
template <typename T>
class AStack
{
public:
	AStack(int i);//���캯��
	AStack(const AStack<T>& s);//��������
	AStack<T>& operator=(const AStack<T>& s);//��ֵ��������غ���
	~AStack();//��������

public:
	void Push(const T& s);
	void Pop();
	bool Empty();
	//bool Full();
	size_t Size();
	T GetTop();
	void PrintStack();

private:
	T* Arr;
	int Top;
	int Capacity;
};

#endif // !_ASTACH_H