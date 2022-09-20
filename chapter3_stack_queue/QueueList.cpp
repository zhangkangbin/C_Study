
#include <stdio.h>
#include <iostream>
using namespace std;

/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-21 10:53:40
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-21 13:58:04
 * @FilePath: \C_Study\chapter3\QueueList.cpp
 *队列
 *队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，
 而在表的后端（rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。
 进行插入操作的端称为队尾，进行删除操作的端称为队头。

 使用数组实现的队列，牺牲一个单元来区分队空和队满。
 */
#define MaxSize 5
class QueueList
{

private:
    string mData[MaxSize];
    int mFront = 0; //队头，删除操作

    int mRear = 0; //队尾 ，插入操作

public:
    void initQueue();
    bool isEmpty();
    //入队
    bool enQueue(string value);
    //出队
    string deQueue();
    string getHead();
    void printAllData();
};

bool QueueList::isEmpty()
{
    if (mFront == mRear)
    {
        return true;
    }

    return false;
}

bool QueueList::enQueue(string value)
{
    bool isFull = (mRear + 1) % MaxSize == mFront;
    if (isFull)
    {
        cout << "\n queue is full. \n " << value << " this value does not add to the list.";
        return false;
    }
    mData[mRear] = value;
    mRear = (mRear + 1) % MaxSize;

    return false;
}

string QueueList::deQueue()
{

    if (mFront == mRear)
    {
        cout << "\n queue is empty! \n ";

        return "";
    }

    string data = mData[mFront];
    mData[mFront] = "";
    mFront = (mFront + 1) % MaxSize;

    return data;
}
void QueueList::printAllData()
{

    for (int i = 0; i < MaxSize; i++)
    {
        string temp = mData[i];
        if (temp.compare("") != 0)
        {
            cout << "\n"
                 << i << ":" << temp;
        }
    }
}
int main()
{
    QueueList list;

    list.enQueue("a");
    list.enQueue("b");
    list.enQueue("c");
    list.enQueue("d");
    
    cout << list.deQueue();
    cout << list.deQueue();
    cout << list.deQueue();
    cout << list.deQueue();
    //  cout << (5 % MaxSize);

    list.printAllData();

    return 0;
}