/*
 * @Author: zhangkangbin
 * @Date: 2022-09-17 08:01:30
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-17 08:40:53
 * @FilePath: \C_Study\chapter6_sort\SelectionSort.cpp
 * 选择排序
 * 1，简单选择排序 ，不稳定。
 * 2，堆排序。
 */

#include <iostream>
using namespace std;

void printData(int list[], int length)
{
    cout << " \n";

    for (int i = 0; i < length; i++)
    {

        cout << " " << list[i];
    }

    cout << " \n";
}
void simpleSelectionSort()
{

    const int length = 7;
    int list[length] = {2, 8, 3,1,9,5,1 };

    int min;


    for (int i = 0; i < length-1; i++)
    {

        min = i;
        for (int j = i + 1; j < length; j++)
        {
            //保存最小的。
            if (list[j] < list[min])
            {
                min = j;
                
            }
        }
       
       

        //如果刚好处于最小的位置。min=i，比如2, 8, 3,1,9,5,1。3就刚好在第四趟处于最小的值。
        if(min!=i){

            int temp=list[min];

            list[min] = list[i];
            
            list[i] = temp;
         
        } else{
              cout << " " << list[i];
              cout << " " << list[min];
        }

       
    }

    printData(list, length);
}

int main()
{
    simpleSelectionSort();
    return 0;
}
