#ifndef _AVLTREE_H
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
struct BiNode
{
	T Data;
	int bf;
	BiNode<T>* LChild;
	BiNode<T>* RChild;
};

template<typename T>
class AvlTree
{
public:
	AvlTree();
	~AvlTree();

public:
	void Insert(const T& Data);
	void Clear(BiNode<T>* n);

private:
	BiNode<T>* root;

};

#endif // !_AVLTREE_H
