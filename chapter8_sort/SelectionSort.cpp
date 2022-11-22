/*
 * @Author: zhangkangbin
 * @Date: 2022-09-17 08:01:30
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-21 15:43:44
 * @FilePath: \C_Study\chapter8_sort\SelectionSort.cpp
 * 选择排序
 * 1，简单选择排序 ，不稳定。
 * 2，堆排序。 不稳定
 */

#include <iostream>
using namespace std;



void printData(int list[], int start,int length)
{
    cout << " \n";

    for (int i = start; i < length; i++)
    {

        cout << " " << list[i];
    }

    cout << " \n";
}

/**
 * 左孩子：2i
 * 右孩子：2i+1
 * 父节点：i/2
 * 所在层次： log2(n+1)
 *
 * @param list
 * @param k
 * @param length
 */
void headAdjust(int list[], int k, int length)
{
    // 0 位用于存储数据。
    list[0] = list[k];

    // k=4  ，2*4为他的左孩子。
    // k=1  ，2*1为他的左孩子。

    for (int i = 2 * k; i <= length;)
    {

        //左右二个孩子比较，取大的一个。
        if (i < length && list[i] < list[i + 1])
        {
            i++;
        }
        //如果根节点大于子节点。跳出循环。
        if (list[0] >= list[i])
        {
            break;
        }
        else
        {
            //子节点赋值根节点。
            list[k] = list[i];

            //继续往下筛选
            k = i;
        }

        i = i * 2;
    }
    //根节点赋值。
    list[k] = list[0];

   
    printData(list, 0,length);
}

/**
 * 堆排序,顺序表的存储结构 .
 *
 * 左孩子：2i
 * 右孩子：2i+1
 * 父节点：i/2
 * 所在层次： log2(n+1)
 *
 */
void heapSort()
{

    const int length = 9;
    //顺序表的存储结构  0用于存储位。
    int list[length] = {0, 53,17,78,32,45,65,87,9};
   //1，建立堆
    for (int i = length / 2; i > 0; i--)
    {
        //反复调整堆。
        headAdjust(list, i, length);
    }

   cout << "\n---------------- \n";
      //2，堆排序，在堆里面进行最终的排序。
    for(int i=length-1;i>1;i--){
          //这一步是为了把最大的数，放到数组结尾。（元素下坠）
          int temp=list[1];
          list[1]=list[i];
          list[i]=temp;
             cout << "\n------iiiiiiiiiiiiiiiiiiiiiiiiiiiiii----------"<<i<<" \n";
          //再次调整，把最大的调整到list[1],
          headAdjust(list, 1, i-1);//i-1 ，不再调整结尾了。

    }
   //0是存储位，不输出0了。
    printData(list,1, length);
}

/**
 * 简单选择排序。
​ 我们熟知的选择排序，其实采用的即为贪心策略。
​ 它所采用的贪心策略即为每次从未排序的数据中选取最小值，
 并把最小值放在未排序数据的起始位置，直到未排序的数据为0，则结束排序。
 * 
 */
void simpleSelectionSort()
{

    const int length = 7;
    int list[length] = {2, 8, 3, 1, 9, 5, 1};

    int min;

    for (int i = 0; i < length - 1; i++)
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
        if (min != i)
        {

            int temp = list[min];

            list[min] = list[i];

            list[i] = temp;
        }
        else
        {
            cout << " " << list[i];
            cout << " " << list[min];
        }
    }

    printData(list, 0,length);
}

int main()
{
    // simpleSelectionSort();

    heapSort();
    return 0;
}
