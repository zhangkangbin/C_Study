/*
 * @Author: zhangkangbin
 * @Date: 2022-11-02 23:19:43
 * @LastEditTime: 2022-11-02 23:23:14
 * @FilePath: \C_Study\3Test\base.h
 * 公共类。方便测试使用。
 */

#ifndef LABEL
#define LABEL
//代码部分
#include <stdio.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct SingleLinkNode
{
    int data;
    Node *next;
};
/**
 结构如下：
      1 
    /   \    
   2      3
  /
 4
 * @return Node* 
 */
Node* getTestTree()
{

    Node *node = new Node();
    node->data = 1;

    Node *nodeLeft = new Node();
    nodeLeft->data = 2;

    Node *nodeLeft1 = new Node();
    nodeLeft1->data = 4;
    nodeLeft->left = nodeLeft1;

    Node *nodeRight = new Node();
    nodeRight->data = 3;

    node->left = nodeLeft;
    node->right = nodeRight;

    return node;
}
int get()
{

    /* 我的第一个 C 程序 */
    printf("\n\n\n this is from list \n\n\n");

    return 0;
}
#endif