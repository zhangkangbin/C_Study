/*
 * @Author: zhangkangbin
 * @Date: 2022-09-15 14:37:53
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-16 22:41:41
 * @FilePath: \C_Study\chapter6_sort\ExchangeSort.cpp
 * 交换排序：
 * 1，冒泡
 * 2，快速
 */

#include <iostream>
using namespace std;

void printData(int list[])
{
    cout << " \n";

    for (int i = 0; i < 7; i++)
    {

        cout << " " << list[i];
    }
}

/**
 * 冒泡
 *
 * 运气好只需要一趟就完成有序。
 * 没有发生交换后，证明已经有序了。退出循环。
 *
 */
void bubbleSort()
{
    const int length = 7;
    int listData[length] = {1, 2, 3, 4, 5, 7, 6};
    bool isExchange = true;
    //从1,j+1就不会越界。
    int index = 1;
    //如果没有发生交换就退出循环。
    while (isExchange && index < length)
    {
        isExchange = false; //初始化交换状态。

        for (int j = 0; j < (length - index); j++)
        {

            if (listData[j] > listData[j + 1])
            {
                cout << " \n --发生交换！！---" << (j + 1);
                isExchange = true;
                int temp = listData[j + 1];
                listData[j + 1] = listData[j];
                listData[j] = temp;
            }

            // printData(listData);
        }
        cout << "  \n------------------\n";

        index++;
    }
}
int getPartition(int list[], int low, int high)
{

    int partition = list[low]; //第一个值作为参考值

    while (low < high)
    {

        while (low < high && list[high] >= partition)
        {
            high--;
        }
        //直到找到中值小的。
        list[low] = list[high];

        while (low < high && list[low] <= partition)
        {
            low++;
        }
        //中值存放的位置。
        list[high] = list[low];
    }

    list[low] = partition;

    return low;
}

/**
 * 快速排序。
 *
 */
void quickSort(int list[], int low, int high)
{

    int partition = getPartition(list, low, high);

    if (low < high)
    {

        quickSort(list, low, partition - 1); //左子表递归排序。（low,partition-1）

        quickSort(list, partition + 1, high); //右子表递归排序
    }
}

void testQuickSort()
{

    const int length = 5;
    int listData[length] = {3, 5, 1, 6, 2};

    quickSort(listData, 0, (length - 1));

    for (int i = 0; i < length; i++)
    {

        cout << " " << listData[i];
    }
}

int main()
{
   // bubbleSort();
   
   //快速排序
    testQuickSort();
    return 0;
}
