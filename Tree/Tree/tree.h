#ifndef _TREE_H
/*双亲孩子表示
template<typename T>
struct ChildNode
{
	int child; //孩子
	struct ChildNode<T>* next; //指针
};

template<typename T>
struct ChildHeadNode
{
	struct T data; //节点数据
	int parent; //双亲节点下标
	struct ChildHeadNode<T>* fristchild;
};

template<typename T>
struct Tree
{
	ChildHeadNode<T>* nodes;
	int r, n;
};
*/
//二叉树
//节点定义
template<typename T>
struct BiNode
{
	T Data;
	BiNode<T>* LChild;
	BiNode<T>* RChild;
};

//树类定义
template<typename T>
class BiTree
{
public:
	BiTree();
	BiTree(const T& Data);
	BiTree(const BiTree<T>& t);
	~BiTree();
public:
	void CreatBiTree(const T& Data);
	void Clear(BiNode<T>* n);
	void PreOrder(vector<T>& arr);
	void InOrder(vector<T>& arr);
	void PostOrder(vector<T>& arr);

private:
	BiNode<T>* Root;

};



#endif // !_TREE_H

