/*
 * @Author: zhangkangbin
 * @Date: 2022-10-29 13:24:24
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-01 19:47:24
 * @FilePath: \C_Study\3Test\Test833_2017.cpp
 * @Description: 
 */
/*

2. 设计一个算法，判断一个算数表达式中的括号是否配对。
算数表达式保存在带头结点的单循环链表中，每个结点有两个域ch和link，
其中ch域为字符类型。

（1）写出设计思想；
（2）用C语言编写程序，关键之处给予注释。





8. 无向连通常权图的最小生成树可以采用贪心算法求导，如Prim，Kruskal。

（1）描述最小生成树的性质，并证明之;

（2）描述Prim∶ Kruskal思想，并计算时间复杂度。


*/

// 3 start----------------------------------------------------------

/**
3.一颗二叉树，其左右子树都空，或都不空，则为“严格二叉树”，
用先序遍历和后序遍历能确定一颗严格二叉树，
二叉树的
前序序列为ABDECFHIGJLKMN，
后序序列为DEBHIFLJMNKGCA。

（1）画出二叉树；
（2）根据这类二叉树描述前序序列和后序序列的设计思想；
（3）根据所写的设计思想给出程序。

 * 
 */
#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;
};

/**
 * 前序输出
 * 
 */
void preNode(Node *node){

    if(node==NULL){
        return;
    }
  cout <<node->data<<"  ";
 
  preNode(node->left);
  preNode(node->right);

}

/**
 * 后序
 * 
 * @param node 
 */
void afterNode(Node *node){

    if(node==NULL){
        return;
    }
 
 
  afterNode(node->left);
  afterNode(node->right);

  cout <<node->data<<"  ";

}

void testPre(){

Node *node=new Node();
node->data=1;


Node *nodeLeft=new Node();
nodeLeft->data=2;

Node *nodeLeft1=new Node();
nodeLeft1->data=4;
nodeLeft->left=nodeLeft1;


Node *nodeRight=new Node();
nodeRight->data=3;

node->left=nodeLeft;
node->right=nodeRight;

cout <<" \n 前序： ";
preNode(node);

cout <<" \n 后序： ";
afterNode(node);

}

// 3 end----------------------------------------------------------

int  main(){

    testPre();
     
    return 0;
}