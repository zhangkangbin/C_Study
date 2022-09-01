#include <stdio.h>
#include <iostream>
using namespace std;
/**
 * 算法6.8　普里姆算法
 *
 */
#define NodeSize 3
//最大顶点数
#define MVNum 4
//默认为空的权值,默认32767吧。。32767 //表示极大值，即∞
#define _WEIGHT 32767
class DataInfo
{

public:
    //权值
    int weight = _WEIGHT;
    string name = "";
    //是否连接了。
    bool isConnected;

    // string name; //顶点名称
};
DataInfo *mArc[MVNum][MVNum];
DataInfo minWeightArray[MVNum];
string mVexs[MVNum] = {"a", "b", "c", "d"}; //存储顶点数组

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
 * @brief 返回最小权值的下标。
 * 
 * @return int 
 */
int findMinWeight()
{

    int minWeight = _WEIGHT;
    int index = -1;
    for (int i = 0; i < MVNum; i++)
    {

        if (minWeightArray[i].weight < minWeight && !minWeightArray[i].isConnected)
        {

            minWeight = minWeightArray[i].weight;
            index=i;
        }
    }

    return index;
}
void printAll()
{
    cout << "\n ";
    for (int i = 0; i < MVNum; i++)
    {
        for (int j = 0; j < MVNum; j++)
        {
            int temp = mArc[i][j]->weight;
            cout << temp << "  ";
        }
        cout << "\n ";
    }
}
void initData()
{

    for (int i = 0; i < MVNum; i++)
    {
        for (int j = 0; j < MVNum; j++)
        {
            DataInfo *data = new DataInfo();

            data->weight = _WEIGHT;

            mArc[i][j] = data;
        }
    }
}
int mLowCast[MVNum];
/**
 * @brief 最小生成树
 * @v 顶点 从哪个顶点开始。
 */
void createMinTree(string v)
{

    int startVex = getVex(v);

    cout << "\n\n第一个顶点的权值："+v;
    for (int i = 0; i < MVNum; i++)
    {

        //初始化最小权值的集合。
        minWeightArray[i].weight = mArc[startVex][i]->weight;
        minWeightArray[i].name = v;

        /*    int weight=mArc[startVex][i]->weight;
           mLowCast[i]=weight;
           cout<<weight; */
    }

   // minWeightArray[startVex].weight = 0;
    minWeightArray[startVex].isConnected = true;

    for (int i = 1; i < MVNum; i++)
    {
        //找出最小的权值。
        int min = findMinWeight();
        cout << "\n\n边：" << minWeightArray[min].name+"--"<<minWeightArray[min].weight<<"--"<<mVexs[min];

     //  minWeightArray[min].weight = 0;
       //设置为已经连接。
       minWeightArray[min].isConnected = true;

       //再把最小值的边的权值添加进来。
        for (int j = 0; j < MVNum; j++)
        {
            if (!minWeightArray[j].isConnected&&minWeightArray[j].weight > mArc[min][j]->weight)
        {
            minWeightArray[j].weight = mArc[min][j]->weight;
            minWeightArray[j].name = mVexs[min];
            //cout << "\n "<<mVexs[min];
        }
        }

        
    }
       cout << "\n ";
}
int main()
{
    initData();

    printAll();

    int a = getVex("a");
    int b = getVex("b");
    int c = getVex("c");
    int d = getVex("d");

    mArc[a][b]->weight = mArc[b][a]->weight = 2;
    mArc[b][c]->weight = mArc[c][b]->weight = 5;
    mArc[c][d]->weight = mArc[d][c]->weight = 3;
    mArc[a][d]->weight = mArc[d][a]->weight = 1;

    //  mArc[0][0]->weight=3;
    cout << "\n ";
    printAll();
    createMinTree("a");
    return 0;
}
