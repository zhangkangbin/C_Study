
#include <stdio.h>
#include <iostream>
using namespace std;

/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-21 10:53:40
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-21 21:19:01
 * @FilePath: \C_Study\chapter3\QueueLinkList.cpp
 *队列
 *队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，
 而在表的后端（rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。
 进行插入操作的端称为队尾，进行删除操作的端称为队头。

 使用链表实现的队列

 //todo:待完成修改结构。
 */
#define MaxSize 5

class Node{
 public:

 string mNodeData;
 Node *mNodeNext;

};

class QueueLinkList
{

private:

    Node *mFront ; //队头，删除操作

    Node *mRear ; //队尾 ，插入操作

public:
    void initQueue();
    bool isEmpty();
    //入队
    bool enQueue(string value);
    //出队
    string deQueue();
    void initQueueList();
    void printAllData();
};
void QueueLinkList::initQueueList(){

    mFront=mRear=new Node();
  //  mFront->mNodeNext=NULL;
}
bool QueueLinkList::isEmpty()
{
    if (mFront == mRear)
    {
        return true;
    }

    return false;
}

bool QueueLinkList::enQueue(string value)
{
    Node *node=new Node();
    node->mNodeData=value;
    mRear->mNodeNext=node;
    //指针指向node地址。.和front脱离。
    mRear=node;

    return false;
}

string QueueLinkList::deQueue()
{

    if (mFront == mRear)
    {
        cout << "\n queue is empty! \n ";

        return "empty";
    }
    Node *temp=mFront->mNodeNext;
    string  data=temp->mNodeData;
     mFront->mNodeNext=temp->mNodeNext;
    //判断是否出队到最后一个。
     if(mRear==temp){
        //重新赋值为空队列条件。
        mRear=mFront;
     }
     free(temp);
    return "\n"+data+"\n";
}
void QueueLinkList::printAllData()
{

    Node *node=mFront;
    while(node!=NULL){

        cout<<node->mNodeData;

        node=node->mNodeNext;
    }
    
}
int main()
{
    QueueLinkList list;
    list.initQueueList();
    cout << list.isEmpty()+"\n";
     list.enQueue("a");
    list.enQueue("b");
    list.enQueue("c");
    list.enQueue("d");

    cout << list.deQueue();
    cout << list.deQueue();
    cout << list.deQueue();
    cout << list.deQueue();
    cout << list.deQueue();
    list.enQueue("e");
    list.enQueue("f");
    list.enQueue("g");
    list.deQueue();

    list.printAllData();
   

    return 0;
}