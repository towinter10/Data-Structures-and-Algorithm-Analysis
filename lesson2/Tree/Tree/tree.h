#ifndef _TREE_H
#define _TREE_H
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
#include<vector>
//#include"queue.h"
#include<queue>
#include<stack>
using namespace std;
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
	//BiTree(const BiTree<T>& t);
	~BiTree();
public:
	void CreatBiTree(const T& Data);//创建二叉树
	void Clear(BiNode<T>* n);//	清除
	void LevOrder(vector<T>& arr);//层次遍历
	void PreOrder(vector<T>& arr);//先序遍历
	void InOrder(vector<T>& arr);//中序遍历
	void PostOrder(vector<T>& arr);//后序遍历

private:
	BiNode<T>* Root;

};

#endif // !_TREE_H

