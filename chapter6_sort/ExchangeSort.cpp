/*
 * @Author: zhangkangbin
 * @Date: 2022-09-15 14:37:53
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-15 15:27:39
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
    int listData[length] = {1,2,3,4,5,7,6};
    bool isExchange = true;
    //从1,j+1就不会越界。
    int index = 1;
    //如果没有发生交换就退出循环。
    while (isExchange && index < length)
    {
        isExchange=false; //初始化交换状态。

        for (int j = 0; j < (length - index); j++)
        {  
          

            if (listData[j] > listData[j + 1])
            {
                cout << " \n --发生交换！！---"<<(j+1);
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

/**
 * 快速排序。
 * 
 */
void quickSort(){


}

int main()
{
    bubbleSort();
    return 0;
}
