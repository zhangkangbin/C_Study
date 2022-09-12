/*
 * @Author: zhangkangbin
 * @Date: 2022-09-12 16:11:23
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-12 21:56:08
 * @FilePath: \C_Study\chapter6_sort\InsertSort.cpp
 * 插入排序
 */
#include <iostream>
using namespace std;
/**
 * @brief直接插入排序
 *
 * 就是在已排好序的数组中再添加一个数，再排序。循环过程。
 *
 */
#define SIZE 6
int mList[SIZE] = {1, 8, 7, 6, 5, 4};

void printData()
{
     cout << " \n";
    for (int i = 0; i < SIZE; i++)
    {

        cout << " " << mList[i];
    }
}

void insertSort()
{

    int current; //当前的值，用于比较，和后面的赋值。
                 //前一个的下标
    int preIndex;
    //从1开始。默认0，是已经排序的了。因为0时，只有一位数。
    for (int i = 1; i < SIZE; i++)
    {

        current = mList[i];
        preIndex = i - 1;

        while (preIndex > 0 && mList[preIndex] > current)
        {
            //开始找，插入位置
            mList[preIndex + 1] = mList[preIndex];

            preIndex--;
        }

        //插入数据。
        mList[preIndex + 1] = current;
    }
    printData();
}

int main()
{
    printData();
    insertSort();
    return 0;
}
