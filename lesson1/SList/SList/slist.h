//参考https://www.cnblogs.com/Lynn-Zhang/p/5396637.html
#ifndef _List_h
typedef int DataType;

struct  LinkNode//定义节点类
{
	LinkNode(const DataType x);
	DataType data;
	LinkNode* next;
};
class SList
{
public:
	SList();
	SList(const SList& s);
	~SList();

public:
    void PrintSList();   //打印链表
    void PushBack(const DataType& x);    //在尾部插入一个节点
    void Clear();         //链表置空
    void PopBack();       //删除尾节点
    void PushFront(DataType x);  //头插
    void PopFront();    //删除首节点
    void Insert(LinkNode* pos, DataType x);//固定位置插入一个节点
    void Erase(LinkNode* pos);        //删除某一节点
    LinkNode* Find(DataType x);       //查找节点并返回这个节点的地址
    void Remove(DataType x);     //查找某节点并删除
public:
    LinkNode* head;     //指向头节点
    LinkNode* tail;        //指向尾节点
};
#endif // !_List_h

