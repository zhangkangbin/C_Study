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
//默认为空的权值。
#define _WEIGHT 0
class DataInfo
{

public:
    //权值 默认-1吧。
    int weight = _WEIGHT;
    //是否被访问过。
    bool isVisited;
   
   // string name; //顶点名称
};
DataInfo *mArc[MVNum][MVNum];
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
            DataInfo *data=new DataInfo() ;

            data->weight=_WEIGHT;
          
            mArc[i][j]=data;

           
        }
    }
}
int mLowCast[MVNum];
/**
 * @brief 最小生成树
 * @v 顶点 从哪个顶点开始。
 */
void createMinTree(string v){


    int startVex= getVex(v);

    cout <<"\n\n第一个顶点的权值：";
    for(int i=0;i<MVNum;i++){

        int weight=mArc[startVex][i]->weight;
        mLowCast[i]=weight;
        cout<<weight;
    }


}
int main()
{
   initData();
   
    printAll();


    int a=getVex("a");
    int b=getVex("b");
    int c=getVex("c");
    int d=getVex("d");

     mArc[a][b]->weight=mArc[b][a]->weight=2;
     mArc[b][c]->weight=mArc[c][b]->weight=5;
     mArc[c][d]->weight=mArc[d][c]->weight=3;
     mArc[a][d]->weight=mArc[d][a]->weight=1;


  //  mArc[0][0]->weight=3;
    cout << "\n ";
    printAll();
    createMinTree("a");
    return 0;
}
