#include <iostream>
#include "list.h" // 假设需要测试的源文件为 list.h 和 list.cpp

int main()
{
    List<int> list;
    list.insertAsLast(3);
    list.insertAsLast(5);
    list.insertAsLast(1);
    std::cout << "first element: " << list.first()->data << std::endl;
    std::cout << "last element: " << list.last()->data << std::endl;


    list.insertAsLast(2);
    list.insertAsLast(4);
    list.insertAsLast(6);

    list.traverse();

    ListNodePosi<int> head = list.first();
    list.mergeSort(head,list.size());
    list.traverse();

    return 0;
}
