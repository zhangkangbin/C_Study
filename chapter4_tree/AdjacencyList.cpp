/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-26 18:22:04
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-27 10:42:38
 * @FilePath: \C_Study\chapter4_tree\AdjacencyList.cpp
 * 算法6.2　(邻接表)采用邻接表表示法创建无向图\
 * 就是数组套链表。
*****邻接表表示法创建的无向图*****
像这样
a->1
b->0->2
c->1
 */
#include <stdio.h>
#include <iostream>
using namespace std;
#define NodeSize 3
class Node{
    public:
    string name;//顶点名称
    int nameIndex;//顶点下标位置
    Node *nextNode;
};
class Adjacency{
   public:
   Node nodeList[NodeSize];
   int getVex(string v);
   void  printfList();

};

void Adjacency::printfList(){

    for(int i=0;i<NodeSize;i++){

        cout<< nodeList[i].name;
        Node *node= nodeList[i].nextNode;

    
        while(node!=NULL){

          cout<<" ->"<< node->nameIndex;
          node=node->nextNode;
 
        } 
          cout<<"\n";
    }

}
/**
 * @brief 得到顶点的位置。
 * 
 * @param v 顶点
 * @return int 顶点的位置
 */
int Adjacency::getVex(string v)
{
    
    for (int i = 0; i < 3; i++)
    {
        //如果相等则输出为0，不等则输出为-1。
        if (v.compare(nodeList[i].name)==0)
        {

            return i;
        }
    }

    return -1;
}
int main()
{
    Adjacency list;

    //填充顶点
    list.nodeList[0].name="a";
    list.nodeList[1].name="b";
    list.nodeList[2].name="c";

    list.nodeList[0].nextNode=NULL;
    list.nodeList[1].nextNode=NULL;
    list.nodeList[2].nextNode=NULL;


    //连接（填充）顶点与顶点之的边。

    int aIndex=list.getVex("a");//得到a的在数组的位置。
    int bIndex=list.getVex("b");//得到b的在数组的位置。

    Node *nodeA=new Node();
    nodeA->name="b";
    nodeA->nameIndex=bIndex;
    //衔接在一起
    nodeA->nextNode=list.nodeList[aIndex].nextNode;
    list.nodeList[aIndex].nextNode=nodeA;


    Node *nodeC=new Node();
    nodeC->name="c";
    nodeC->nameIndex=list.getVex("c");
    //衔接在一起
    nodeC->nextNode=list.nodeList[aIndex].nextNode;
    list.nodeList[aIndex].nextNode=nodeC;
    list.printfList();



   
    return 0;
}
