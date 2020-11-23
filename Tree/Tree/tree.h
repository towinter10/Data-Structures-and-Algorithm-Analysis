#ifndef _TREE_H
/*˫�׺��ӱ�ʾ
template<typename T>
struct ChildNode
{
	int child; //����
	struct ChildNode<T>* next; //ָ��
};

template<typename T>
struct ChildHeadNode
{
	struct T data; //�ڵ�����
	int parent; //˫�׽ڵ��±�
	struct ChildHeadNode<T>* fristchild;
};

template<typename T>
struct Tree
{
	ChildHeadNode<T>* nodes;
	int r, n;
};
*/
//������
//�ڵ㶨��
template<typename T>
struct BiNode
{
	T Data;
	BiNode<T>* LChild;
	BiNode<T>* RChild;
};

//���ඨ��
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

