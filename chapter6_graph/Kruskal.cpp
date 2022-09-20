/*
 * @Author: zhangkangbin
 * @Date: 2022-09-05 13:50:00
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-05 17:22:23
 * @FilePath: \C_Study\chapter4_tree\Kruskal.cpp
 * @Description:
 */

//　克鲁斯卡尔算法

#include <iostream>
using namespace std;
#define MAX_SIZE 4
int mVertex[MAX_SIZE][MAX_SIZE];
string mVertexString[MAX_SIZE] = {"a", "b", "c", "d"}; //存储顶点数组
//辅助数组，一个集合。
int mVertexSet[MAX_SIZE];
class EdgeInfo
{

public:
    //边的信息，头和尾，权值
    int lowCost;
    string head;
    string tail;
};
EdgeInfo mEdgeInfo[MAX_SIZE];
/**
 * @brief 初始化 矩阵顶点。
 *
 */
void initVertex()
{
    EdgeInfo info;

    mVertex[0][3] = mVertex[3][0] = 1;
    info.head = "a";
    info.tail = "d";
    info.lowCost = 1;
    mEdgeInfo[0] = info;

    mVertex[1][2] = mVertex[2][1] = 2;
    info.head = "b";
    info.tail = "c";
    info.lowCost = 2;
    mEdgeInfo[1] = info;

    info.head = "b";
    info.tail = "d";
    info.lowCost = 4;
    mEdgeInfo[2] = info;

    mVertex[2][0] = mVertex[0][2] = 3;
    info.head = "a";
    info.tail = "c";
    info.lowCost = 3;
    mEdgeInfo[3] = info;
}
void printData()
{
    cout << "\n------- \n";
    for (int i = 0; i < 4; i++)
    {
        cout << mEdgeInfo[i].lowCost << "  ";
    }
    cout << "\n ";
}
//----------冒泡排序-------------------
void sortEdge(EdgeInfo info[])
{

    int m = MAX_SIZE - 2;
    int flag = 1;
    //修正算法6.9　克鲁斯卡尔算法源码，辅助数组Edges排序问题 0<m为0<=m。
    while ((0 <= m) && flag == 1)
    {
        flag = 0;
        for (int j = 0; j <= m; j++)
        {
            if (info[j].lowCost > info[j + 1].lowCost)
            {
                flag = 1;

                string temp_head = info[j].head;
                info[j].head = info[j + 1].head;
                info[j + 1].head = temp_head;

                string temp_tail = info[j].tail;
                info[j].tail = info[j + 1].tail;
                info[j + 1].tail = temp_tail;

                int temp_lowCost = info[j].lowCost;
                info[j].lowCost = info[j + 1].lowCost;
                info[j + 1].lowCost = temp_lowCost;

            } // if
        }     // for
      //  printData();
        --m;
    } // while

    cout << "\n ";
}


/**
 * @brief 得到顶点的位置。
 *
 * @param v 顶点
 * @return int 顶点的位置
 */
int getVex(string v)
{

    for (int i = 0; i < MAX_SIZE; i++)
    {
        //compare如果相等则输出为0，不等则输出为-1。
        if (v.compare(mVertexString[i]) == 0)
        {

            return i;
        }
    }

    return -1;
}
void printVexset(){
   cout << "\n ";
	for(int i=0;i<MAX_SIZE;i++){

   	cout << mVertexSet[i] << "  ";
	}

	cout << "\n ";

}

/**
 * @brief
 *
 */
void kruskal()
{

    // 1，先对边的权值进行排序。
    sortEdge(mEdgeInfo);

    //初始化辅助数组。
    for (int i = 0; i < MAX_SIZE; i++)
    {                      //辅助数组，表示各顶点自成一个连通分量
        mVertexSet[i] = i; //用于判断顶点是否已连接。
    }

    //开始连接顶点
    for (int i = 0; i < MAX_SIZE; i++)
    {
     
      EdgeInfo info=mEdgeInfo[i];

      int vHeadIndex=getVex(info.head);
      int vTailIndex=getVex(info.tail);

	  int vs1Head = mVertexSet[vHeadIndex]; //获取边Edge[i]的始点所在的连通分量vs1
	  int vs2Tail = mVertexSet[vTailIndex]; //获取边Edge[i]的终点所在的连通分量vs2


      
      if(vs1Head==vs2Tail){
        return;
      }

    cout << info.head << "-->" << info.tail<< endl; //输出此边

    for (int j = 0; j < MAX_SIZE; j++)
    {   //找到和尾部连接的顶点。
       // 0 1 1 0  --0 0 和 1 1分别是两组顶点。
       // 0 0 0 0  把所以1 改成 0 就是代表把他们都连接起来了。
        if(mVertexSet[j]==vs2Tail){
          //都连接起来。
          mVertexSet[j]=vs1Head;
        }
    }

    printVexset();

    }
}
int main(int argc, char const *argv[])
{

    initVertex();
    kruskal();
   // printData();
    return 0;
}
