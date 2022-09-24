/*
 * @Author: zhangkangbin
 * @Date: 2022-09-23 22:21:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-24 12:55:26
 * @FilePath: \C_Study\chapter8_sort\MergeSort.cpp
 * 归并排序
 */
#include <stdio.h>
#include <iostream>
#include "..\baseClass\Base.h"
using namespace std;

#define SIZE 7
int mList[SIZE]; //辅助数组



void merge(int array[], int low, int mid, int high)
{
   //先把数组复制到辅助数组mList;
    for (int k = low; k <= high; k++)
    {
        mList[k] = array[k];
    }
    
    
    int lowIndex = low;
    int highIndex = mid + 1;
    int index = low;

    while ( lowIndex <= mid && highIndex <= high)
    {
        //判断高位低位那个大。就填进去那个。
        if (mList[lowIndex] <= mList[highIndex])
        {
            //低位向前移动
            array[index] = mList[lowIndex++];
        }
        else
        {    //高位向前移动
            array[index] = mList[highIndex++];
        }

         index++;
    }
    //把剩下的值填到前面
    while (lowIndex <= mid)
    {
        array[index++] = mList[lowIndex++];
    }

       //把剩下的值填到后面
    while (highIndex <= high)
    {
        array[index++] = mList[highIndex++];
    }

    // printData(array,SIZE);
}

void mergeSort(int array[], int left, int right)
{
      cout << "\n---:" <<left<<" ： "<<right;
    if (left < right)
    {
        
        int middle = (left + right) / 2;

     


        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        cout << "\n--------------------------:" <<left<<" ： "<<right<<" m: "<<middle;
        merge(array, left, middle, right);
          
        //printData(array,SIZE);
      
    }

    
    
}

int main()
{
    int array[SIZE] = {7,4,5,9,3,2,6};
    //size-1,防止下标越界。
    mergeSort(array, 0, SIZE-1 );

    /* code */
    printData(array,SIZE);

      cout << " _\n" <<(8/2);

    return 0;
}
