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
	int GetDepth(BiNode<T>* nood);
	int GetBF(BiNode<T>* nood);
	void AllBF(BiNode<T>* nood);
	BiNode<T>* BFTwo(BiNode<T>* nood);
	BiNode<T>* BFTwoParent(BiNode<T>* r,BiNode<T>* tmp);
	void LL(BiNode<T>* tmp);
	void RR(BiNode<T>* tmp);
	void LR(BiNode<T>* tmp);
	void RL(BiNode<T>* tmp);
	void Insert(const T& Data);
	void Clear(BiNode<T>* n);

private:
	BiNode<T>* root;

};

#endif // !_AVLTREE_H
