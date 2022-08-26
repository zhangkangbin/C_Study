/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-26 15:25:58
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-26 18:20:05
 * @FilePath: \C_Study\chapter4_tree\AdjacencyMatrix.cpp
 * 算法6.2　（邻接矩阵）采用邻接矩阵表示法创建无向图
 */
#include <stdio.h>
#include <iostream>
using namespace std;
string vexs[3] = {"a", "b", "c"}; //存储顶点数组
int arc[3][3] = {
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

    for (int i = 0; i < 3; i++)
    {
        //如果相等则输出为0，不等则输出为-1。
        if (v.compare(vexs[i])==0)
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
int isConnected(string v1,string v2){
    int value1=getVex(v1);
    int value2=getVex(v2);
    
    if(arc[value1][value2]){
       
        cout <<"\n"+v1+"和"+v2+"有边\n";

        return 1;
    }
      cout <<"\n"+v1+"和"+v2+"无边\n";
    return 0;
}

int main()
{

    int b=getVex("b");
    int c=getVex("c");
    cout<<"\nb:"<<b;
    cout<<"\nc:"<<c;
    //二者都修改。如果需要添加权值，只要把1修改对应就行。
    arc[b][c]=arc[c][b]=1;
 

    //判断a 和c 是否连通
    isConnected("a","c");
    isConnected("b","c");
    cout << "\n ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = arc[i][j];
            cout << temp << "  ";
        }
        cout << "\n ";
    }
    

    return 0;
}
