/*
 * @Author: zhangkangbin
 * @Date: 2022-11-02 23:19:43
 * @LastEditTime: 2022-11-10 19:39:19
 * @FilePath: \C_Study\3Test\base.h
 * 公共类。方便测试使用。
 */

#ifndef LABEL
#define LABEL
#include <stdio.h>
#include <iostream>
using namespace std;
// 二叉树
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//单链表
struct SingleLinkNode
{
    int data;
    SingleLinkNode *next;
};

SingleLinkNode* getSingleLinkNode()
{

    SingleLinkNode *head = new SingleLinkNode();
    SingleLinkNode *last = head;

    for (int i = 2; i <= 10; i = i + 2)
    {

        SingleLinkNode *node = new SingleLinkNode();
        node->data = i;
        last->next = node;
        last = node;
    }

    return head;
}
void printSingleLinkNode(SingleLinkNode *node)
{

    if (node == NULL)
    {
        return;
    }
   cout<<"\n";
   SingleLinkNode *next = node->next;
    while (next)
    {
       cout<<next->data<<" ,";
       next=next->next;
    }
    
}
/**
 结构如下：
      1
    /   \
   2      3
  /
 4
 * @return Node*
 */
Node *getTestTree()
{

    Node *node = new Node();
    node->data = 1;

    Node *nodeLeft = new Node();
    nodeLeft->data = 2;

    Node *nodeLeft4 = new Node();
    nodeLeft4->data = 4;
    nodeLeft->left = nodeLeft4;

    Node *nodeRight = new Node();
    nodeRight->data = 3;

    node->left = nodeLeft;
    node->right = nodeRight;

    return node;
}
/**
 结构如下：
        1
      /    \
     2       3
    / \     /  \
   4   5   6    7
  /
 8
 * @return Node*
 */
Node *getTestTree2()
{

    Node *node = new Node();
    node->data = 1;

    Node *nodeLeft = new Node();
    nodeLeft->data = 2;

    Node *nodeLeft4 = new Node();
    nodeLeft4->data = 4;
    nodeLeft->left = nodeLeft4;

    Node *nodeLeft8 = new Node();
    nodeLeft8->data = 8;
    nodeLeft4->left = nodeLeft8;

    Node *nodeLeft25 = new Node();
    nodeLeft25->data = 5;
    nodeLeft->right = nodeLeft25;

    Node *nodeRight = new Node();
    nodeRight->data = 3;

    Node *nodeRight6 = new Node();
    nodeRight6->data = 6;

    Node *nodeRight7 = new Node();
    nodeRight7->data = 7;

    nodeRight->left = nodeRight6;
    nodeRight->right = nodeRight7;

    node->left = nodeLeft;
    node->right = nodeRight;

    return node;
}

/**
 结构如下：
      1
    /   \
   2      3
  / \
 4   5
 * @return Node*
 */
Node *getTestTree3()
{

    Node *node = new Node();
    node->data = 1;

    Node *nodeLeft = new Node();
    nodeLeft->data = 2;

    Node *nodeLeft4 = new Node();
    nodeLeft4->data = 4;
    nodeLeft->left = nodeLeft4;

    Node *nodeLeft5 = new Node();
    nodeLeft5->data = 5;
    nodeLeft->right = nodeLeft5;


    Node *nodeRight = new Node();
    nodeRight->data = 3;

    node->left = nodeLeft;
    node->right = nodeRight;

    return node;
}

/**
     1
    /   
   2     
   \
     4
 * 
 * @return Node* 
 */

Node *getTestTree4()
{

    Node *node = new Node();
    node->data = 1;

    Node *nodeLeft = new Node();
    nodeLeft->data = 2;

    node->left=nodeLeft;

    Node *nodeLeft4 = new Node();
    nodeLeft4->data = 4;
    nodeLeft->right = nodeLeft4;


    return node;
}
void printList(int list[],int length){

	cout << " \n";
    for (int i = 0; i < length; i++)
	{

		cout << list[i] << " ";
	}
    cout << " \n";
}
#endif