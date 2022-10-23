/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-26 15:25:58
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-16 13:41:48
 * @FilePath: \C_Study\chapter6_graph\AdjacencyMatrix.cpp
 * 算法6.2　（邻接矩阵）采用邻接矩阵表示法创建无向图
 * 
 * 邻接矩阵 ，如果在已有的矩阵下，添加删除都要修改数组。效率很低。
 * 优势是：判断二个顶点是否有边的效率高。
 */
#include <stdio.h>
#include <iostream>
using namespace std;
//最大顶点数
#define MVNum 4
string mVexs[MVNum] = {"a", "b", "c", "d"}; //存储顶点数组
//存放顶点的是否访问过的布尔值。
bool mVisited[MVNum];
//修改成有向图,只需要动矩阵。
int mArc[MVNum][MVNum] = {
    //_____a  b  c  d
    /*a*/ {0, 0, 0, 0},
    /*b*/ {0, 0, 0, 0},
    /*c*/ {0, 0, 0, 0},
    /*d*/ {0, 0, 0, 0}

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

class BfsNode
{

public:
    int vertexIndex;
    BfsNode *nodeNext;
};

BfsNode *mFrontDelete = new BfsNode(); //队头，删除操作

BfsNode *mRearInsert = mFrontDelete; //队尾 ，插入操作

/**
 * @brief 进栈
 *
 * @param vertex
 */
void enterQueue(int vertex)
{

    BfsNode *node = new BfsNode();
    node->vertexIndex = vertex;
    mRearInsert->nodeNext = node;
    mRearInsert = node;

    // cout << " \n进栈:" + mVexs[vertex]+"  ";
}
/**
 * @brief 退栈
 *
 * @param vertex
 */
int outQueue()
{

    if (mFrontDelete == mRearInsert)
    {

        return -1;
    }

    BfsNode *node = mFrontDelete->nodeNext;

    //出栈的数据
    int index = node->vertexIndex;

    // cout << " 出栈:" + mVexs[index];
    mFrontDelete->nodeNext = node->nodeNext;
    if (node == mRearInsert)
    {
        mRearInsert = mFrontDelete;
    }

    delete node;

    return index;
}
/**
 * @brief 广度优先
 * 需要辅助链表，进行退栈进栈。
 * 队形如下：
 *   -------
 * a  b c     d
 *   -------
 *
 * @param vertex
 */
void bfsFind(int vertex)
{

    //  mVisited[vertex]=true;
    int nextIndex = -1; //下一个要访问的节点。
    for (int i = 0; i < MVNum; i++)
    {
        //  cout<<"i："<<i<<"\n";
        if (mArc[vertex][i] && !mVisited[i])
        {
            cout << "顶点：" << i << " " + mVexs[i] + "  ";
            mVisited[i] = true;
            //进栈
            enterQueue(i);
        }
    }
}

/**
 * @brief //广度优先
 *
 * @param vertex 从哪个顶点开始遍历。
 */

void bfsFindStart(string vertex)
{
    //第一步：得到顶点的位置。
    int vIndex = getVex(vertex);
    //第一个顶点入队。
    enterQueue(vIndex);
    //遍历剩下的节点。

    cout << "顶点：" << vIndex << " " + mVexs[vIndex] + "  ";
    mVisited[vIndex] = true;

    int temp = outQueue();
    while (temp != -1)
    {
        //调用遍历。
        bfsFind(temp);
        //出队。
        temp = outQueue();
    }

    // bfsFind(vIndex);
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
void initVisited()
{

    for (int i = 0; i < MVNum; i++)
    {

        mVisited[i] = false;
    }
}

void printAll()
{
    cout << "\n ";
    for (int i = 0; i < MVNum; i++)
    {
        for (int j = 0; j < MVNum; j++)
        {
            int temp = mArc[i][j];
            cout << temp << "  ";
        }
        cout << "\n ";
    }
}
int main()
{

    int a = getVex("a");
    int b = getVex("b");
    int c = getVex("c");
    int d = getVex("d");
    cout << "\na:" << a;
    cout << "\nb:" << b;
    cout << "\nc:" << c;
    cout << "\nd:" << d;
    //二者都修改。如果需要添加权值，只要把1修改对应就行。
    mArc[a][b] = mArc[b][a] = 1;
    mArc[b][c] = mArc[c][b] = 1;

    //  mArc[a][c] = mArc[c][a] = 1;
   // mArc[a][d] = mArc[d][a] = 1;

    //判断a 和c 是否连通
    isConnected("a", "c");
    isConnected("b", "c");
    //打印数据
    printAll();

    cout << "\n -------a顶点深度优先 --------------\n\n";

    startDFS("a");
    cout << "\n \n-----b顶点深度优先--------------- \n\n";
    initVisited();
    startDFS("b");
    cout << "\n\n------c顶点深度优先 ---------------\n\n";
    initVisited();
    startDFS("c");
    

    cout << "\n -------a顶点广度深度优先 ---------------\n\n";
    initVisited();
    //广度优先
    bfsFindStart("a");
    //初始化访问状态。
    cout << "\n -------b顶点广度深度优先 ---------------\n\n";
    initVisited();
    bfsFindStart("b");
    
    //初始化访问状态。
    cout << "\n -------d顶点广度深度优先 ---------------\n\n";
    initVisited();
    bfsFindStart("d");

    
    return 0;
}
