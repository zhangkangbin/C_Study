/*
 * @Author: zhangkangbin
 * @Date: 2022-10-29 13:24:24
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-06 12:39:34
 * @FilePath: \C_Study\3Test\Test833_2018.cpp
 * @Description:
 */
#include <iostream>
#include <stdio.h>
#include "base.h"
using namespace std;

/*

3.假设二叉树采用二叉链表存储结构存储，设计一个算法，求出该二叉树的最大宽度（具体结点数最多的那一层上的结点个数）。

分析：那一层最多结点数。利用层次遍历。层次遍历需要辅助队列。
*/

int mMaxWidth = 0;

//辅助结构
Node *mNodeList[4];
int mRear = 0;  //插入数据
int mFront = 0; //取数据

void push(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    int index = (mRear + 1) % 4;
    bool isFull = index == mFront;

    if (isFull)
    {
        return;
    }
    mNodeList[index] = node;
    mRear = index;
}

Node *pop()
{

    if (mRear == mFront)
    {
        return NULL;
    }

    mFront = (mFront + 1) % 4;
    Node *data = mNodeList[mFront];

    return data;
}
//层次遍历
int countTreeWidth(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    push(node);

    int max = 1;
   	int last = 1; //默认第一层为一个。根节点。
    int tempMaxWidth = 0;
    while (mRear != mFront)
    {
        Node *data = pop();
        if (data == NULL)
        {
           break;
        }

       // cout << data->data << "__ ";

        if (data->left != NULL)
        {
            push(data->left);
            tempMaxWidth++;
        }
        
         if (data->right != NULL)
        {
            push(data->right);
            tempMaxWidth++;
        }

        if (--last == 0) {
			last = tempMaxWidth;//last 等于上一层的子树个数。
             //判断那一层更大，进行赋值。
			if (max < tempMaxWidth) { 
				max = tempMaxWidth;
			}
            cout<<"\n"<<tempMaxWidth<<"\n";
			tempMaxWidth = 0;
		}


 
          cout<<"\n width:"<<max;
    }

    return 0;
}

int main()
{
    countTreeWidth(getTestTree2());
    //  cout << getTestTree()->data;

    return 0;
}

/*
7.一个背包最多可装载的重量C=9，列表给出了四种物品，
每种物品重量不同具有不同价值，有不同的分配方案。（0-1背包问题）


（1）列出求总价值的公式；
（2）写出算法思想；（3）写出代码。
*/

/*
8.利用分治策略分别求一个数组里的最小最大值。

*/