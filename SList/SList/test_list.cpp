#include"slist.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

void Test2()
{
    SList list1;
    list1.PushBack(1);
    list1.PushBack(3);
    list1.PushBack(4);
    list1.PushBack(2);
    list1.PushBack(6);
    list1.PrintSList();

    /*list1.RemoveAll(2);
    list1.PrintSList();*/

    SList list2 = list1;
    list2.PushBack(2);
    list2.PushBack(3);
    list2.PushBack(4);
    list2.PushBack(2);
    //list2.PushFront(2);
    cout << list2.head->next << endl;
    list2.PrintSList();
    list2.RadixSort(1);
    list2.PrintSList();

}

int main()
{
    //Test1();
    Test2();
    system("pause");
}
