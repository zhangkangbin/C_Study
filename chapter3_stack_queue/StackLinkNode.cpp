/*
 * @Author: zhangkangbin
 * @Date: 2022-10-09 00:08:58
 * @LastEditTime: 2022-10-09 10:51:28
 * @FilePath: \C_Study\chapter3_stack_queue\StackLinkNode.cpp
 * 采用链表实现栈。
 */

#include <stdio.h>
#include <iostream>
using namespace std;

class StackLinkNode
{

public:
    int data;
    StackLinkNode *next;
};

StackLinkNode *mRoot;

void initStackLinkNode()
{
    mRoot = NULL;
}
bool push(int value)
{

    StackLinkNode *node = new StackLinkNode();
    node->data = value;
    node->next=mRoot; //这个设计很巧妙。把数据都填充给当前节点的 next;

    mRoot = node;

    return true;
}

int pop()
{
    StackLinkNode *top = mRoot;
    int data=top->data;
    mRoot=top->next;

    delete top;
    return data;
}


int getTop(){

    if(!mRoot){
        cout << "top is null \n";
        return -1;
    }
  // cout << "top: "  << mRoot->data<<"\n";
   return mRoot->data;
}

void printAllData()
{

    StackLinkNode *temp = mRoot;
    while (temp)
    {
        cout << temp->data<< "  " ;
        temp = temp->next;
    }
}
int main()
{
    initStackLinkNode();
      getTop();
    push(3);
    push(6);
    push(9);//进栈
    // push(1);
    //pop();
    getTop();
    pop();//出栈

    push(10);

    getTop();
    printAllData();
    return 0;
}
