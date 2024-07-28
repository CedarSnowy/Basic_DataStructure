#include <iostream>
#include "vector.h" // 假设你将Vector类定义在了名为Vector.h的头文件中

using namespace std;

int main()
{

    int x = -20;
    x += 3;
    cout << (x >> 2);
    // // 创建一个空的整数向量
    // Vector<int> intVector;

    // cout << "Size: " << intVector.size() << ", Capacity: " << intVector.capacity() << endl;
    // // 在第0个位置插入元素1，并在第0个位置之后插入元素2
    // intVector.insert(0, 4);
    // intVector.insert(1, 3);
    // intVector.insert(2, 2);
    // intVector.insert(3, 1);

    // // 输出当前向量的元素个数和容量
    // cout << "Size: " << intVector.size() << ", Capacity: " << intVector.capacity() << endl;

    // // 输出向量中的所有元素，并尝试删除第2个元素
    // for (int i = 0; i < intVector.size(); i++) {
    //     cout << intVector.get(i) << " ";
    // }
    // cout << endl;
    // intVector.remove(2);

    // // 输出删除元素后的向量中的所有元素，并尝试在第1个位置插入元素3
    // for (int i = 0; i < intVector.size(); i++) {
    //     cout << intVector.get(i) << " ";
    // }
    // cout << endl;
    // intVector.insert(1, 5);
    // intVector.insert(1, 6);


    // intVector.traverse();
    // intVector.mergeSort(0,intVector.size());
    // intVector.traverse();


    // return 0;
}
