#ifndef _ASTACH_H
#define _ASTACH_H
template <typename T>
class AStack
{
public:
	AStack(int i);//构造函数
	AStack(const AStack<T>& s);//拷贝函数
	AStack<T>& operator=(const AStack<T>& s);//赋值运算符重载函数
	~AStack();//析构函数

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