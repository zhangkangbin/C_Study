/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-26 15:25:58
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-29 00:24:37
 * @FilePath: \C_Study\chapter4_tree\AdjacencyMatrix.cpp
 * 算法6.2　（邻接矩阵）采用邻接矩阵表示法创建无向图
 */
#include <stdio.h>
#include <iostream>
using namespace std;
//最大顶点数
#define MVNum 3
string mVexs[MVNum] = {"a", "b", "c"}; //存储顶点数组\
//存放顶点的是否访问过的布尔值。
bool mVisited[MVNum];
int mArc[MVNum][MVNum] = {
    //_____ a    b    c
    /*a*/ {0, 0, 0},
    /*b*/ {0, 0, 0},
    /*c*/ {0, 0, 0}

};

/**
 * @brief 得到顶点的位置。
 *
 * @param v 顶点
 * @return int 顶点的位置
 */
int getVex(string v)
{

    for (int i = 0; i < MVNum; i++)
    {
        //如果相等则输出为0，不等则输出为-1。
        if (v.compare(mVexs[i]) == 0)
        {

            return i;
        }
    }

    return -1;
}

/**
 * 判断二个顶点是否有边。
 *
 * @param v1
 * @param v2
 * @return int
 */
int isConnected(string v1, string v2)
{
    int value1 = getVex(v1);
    int value2 = getVex(v2);

    if (mArc[value1][value2])
    {

        cout << "\n" + v1 + "和" + v2 + "有边\n";

        return 1;
    }
    cout << "\n" + v1 + "和" + v2 + "无边\n";
    return 0;
}

/**
 * 邻接矩阵，深度优先遍历
 *
 * @param vertex //深度优先
 */
void dfsFind(int vertex)
{

    cout << "顶值：" + mVexs[vertex] + "  ";

    mVisited[vertex] = true;

    //第二步得到顶点二维数组中为1的点。即它的边。
    //这样写，好理解多了。
    for (int i = 0; i < MVNum; i++)
    {

        if (mArc[vertex][i] && !mVisited[i])
        {

            dfsFind(i);
        }
    }

    // firstAdjVex(vIndex);
}
int firstAdjVex(int vIndex)
{

    for (int i = 0; i < MVNum; i++)
    {

        if (mArc[vIndex][i])
        {

            return i;
        }
    }

    return -1;
}
void startDFS(string vertex)
{
    //第一步：得到顶点的位置。
    int vIndex = getVex(vertex);
    dfsFind(vIndex);
}
/**
 * @brief 清空访问状态
 * 
 */
void initVisited(){

    for(int i=0;i<MVNum;i++){

        mVisited[i]=false;
    }
}
int main()
{

    int a = getVex("a");
    int b = getVex("b");
    int c = getVex("c");
    cout << "\na:" << a;
    cout << "\nb:" << b;
    cout << "\nc:" << c;
    //二者都修改。如果需要添加权值，只要把1修改对应就行。
    mArc[a][b] = mArc[b][a] = 1;
    mArc[b][c] = mArc[c][b] = 1;
    mArc[a][c] = mArc[c][a] = 1;

    //判断a 和c 是否连通
    isConnected("a", "c");
    isConnected("b", "c");
    cout << "\n ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = mArc[i][j];
            cout << temp << "  ";
        }
        cout << "\n ";
    }

    cout << "\n ---a ---\n";

    startDFS("a");
    cout << "\n ---b--- \n";
    initVisited();
    startDFS("b");
    cout << "\n ---c ---\n";
    initVisited();
    startDFS("c");
    return 0;
}
