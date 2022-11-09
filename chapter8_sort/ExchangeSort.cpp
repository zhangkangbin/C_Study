/*
 * @Author: zhangkangbin
 * @Date: 2022-09-15 14:37:53
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-08 22:46:38
 * @FilePath: \C_Study\chapter8_sort\ExchangeSort.cpp
 * 交换排序：
 * 1，冒泡
 * 2，快速
 */

#include <iostream>
using namespace std;

#define MAXSIZE 8

void printData(int list[], int length)

{
    cout << " \n";

    for (int i = 0; i < length; i++)
    {

        cout << " " << list[i];
    }

    cout << " \n";
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

//快速排序。
int getPartition(int list[], int low, int high)
{

    int partition = list[low]; //第一个值作为参考值

    while (low < high)
    {
        // high 开始
        while (low < high && list[high] >= partition)
        {
            high--;
        }
        //直到找到参考值小的。
        list[low] = list[high];

      /*  cout << "  \n--------high----------\n";

       printData(list, MAXSIZE);

        cout << "  \n----------low--------\n"; */
        while (low < high && list[low] <= partition)
        {
            low++;
        }
        //高低位交换位置。
        list[high] = list[low];

        if (list[high] == list[low])
        {
          //  cout << "  \n-----------<<" << list[low] << "-------\n";
        }
    }
    //最后一个值和参考值P交换位置
    list[low] = partition;
    
    printData(list, MAXSIZE);
   // cout << "  \n-------end-----------\n";
    return low;
}

/**
 * 快速排序。
 *
 */
void quickSort(int list[], int low, int high)
{

    if (low < high)
    {
        //把数组分成两半。partition参考值下标
        int partition = getPartition(list, low, high);

        //递归
        quickSort(list, low, partition - 1); //左子表递归排序。（low,partition-1）

        quickSort(list, partition + 1, high); //右子表递归排序
    }
}
/**
 四趟的结果 
 27 38 13 49 76 97 65 49

 13 27 38 49 76 97 65 49

 13 27 38 49 49 65 76 97

 13 27 38 49 49 65 76 97 
 */
void testQuickSort()
{
   
    //  int listData[MAXSIZE] = {5,3,9,8,4,2,1,7,6};
    int listData[MAXSIZE] = {49, 38, 65, 97, 76, 13, 27, 49};

    quickSort(listData, 0, (MAXSIZE - 1));

/*     for (int i = 0; i < MAXSIZE; i++)
    {

        cout << " " << listData[i];
    } */
}

int main()
{
    // bubbleSort();

    //快速排序
    testQuickSort();

    return 0;
}
