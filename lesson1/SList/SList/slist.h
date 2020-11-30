//�ο�https://www.cnblogs.com/Lynn-Zhang/p/5396637.html
#ifndef _List_h
typedef int DataType;

struct  LinkNode//����ڵ���
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
    void PrintSList();   //��ӡ����
    void PushBack(const DataType& x);    //��β������һ���ڵ�
    void Clear();         //�����ÿ�
    void PopBack();       //ɾ��β�ڵ�
    void PushFront(DataType x);  //ͷ��
    void PopFront();    //ɾ���׽ڵ�
    void Insert(LinkNode* pos, DataType x);//�̶�λ�ò���һ���ڵ�
    void Erase(LinkNode* pos);        //ɾ��ĳһ�ڵ�
    LinkNode* Find(DataType x);       //���ҽڵ㲢��������ڵ�ĵ�ַ
    void Remove(DataType x);     //����ĳ�ڵ㲢ɾ��
public:
    LinkNode* head;     //ָ��ͷ�ڵ�
    LinkNode* tail;        //ָ��β�ڵ�
};
#endif // !_List_h

