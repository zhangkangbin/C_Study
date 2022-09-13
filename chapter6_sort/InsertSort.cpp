/*
 * @Author: zhangkangbin
 * @Date: 2022-09-12 16:11:23
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-13 23:00:05
 * @FilePath: \C_Study\chapter6_sort\InsertSort.cpp
 * 插入排序
 */
#include <iostream>
using namespace std;

#define SIZE 6

void printData(int list[])
{
    cout << " \n";
    for (int i = 0; i < 9; i++)
    {

        cout << " " << list[i];
    }
}
/**
 * 直接插入排序
 *
 * 就是在已排好序的数组中再添加一个数，再排序。循环过程。
 *
 */
void insertSort()
{
    int listData[SIZE] = {9, 8, 7, 6, 5, 4};
    int current; //当前的值，用于比较，和后面的赋值。
                 //前一个的下标
    int preIndex;
    //从1开始。默认0，是已经排序的了。因为0时，只有一位数。
    for (int i = 1; i < SIZE; i++)
    {

        current = listData[i];
        preIndex = i - 1;

        while (preIndex >= 0 && listData[preIndex] > current)
        {
            //开始找，插入位置
            listData[preIndex + 1] = listData[preIndex];

            preIndex--;
        }

        //插入数据。
        listData[preIndex + 1] = current;
    }
    printData(listData);
}
/**
 * 折半插入查找
 *
 */
void sort()
{
    int listData[SIZE] = {9, 8, 7, 9, 5, 4};

    int preIndex = 0;
    int current = 0;

    for (int i = 1; i < SIZE; i++)
    {

        current = listData[i];
        preIndex = i - 1;
        while (preIndex >= 0 && listData[preIndex] > current)
        { 
            listData[preIndex+1]=listData[preIndex];

            preIndex--;
        }
       
       listData[preIndex+1]=current;

    }
        cout << " \n 折半插入查找 \n ";
        printData(listData);
}
/**
 * 希尔排序
 * 
 */
void shellSort(){ 

   const int length=9 ;
   int listData[length] = {0,2, 3, 7, 9, 5, 6,1,4};

   int gap;
   int i;
   int j;
   int tempData;
   // 8/2=4 , 4/2=2, 2/2=1
   for(gap=length/2;gap>=1;gap=gap/2){
     
     //从第二元素开始，即gap。
    for(i=gap+1;i<length;i++){

        //不断交叉切换子表，下一趟是另一个子表的数据比较。

        if(listData[i]<listData[i-gap])//i-gap前面的数据
        {

            tempData=listData[i];//保存临时数据。

         
            //从间隔子表中找到对应位置。
            for(j=i-gap;j>0&&tempData<listData[j];){

                 //listData[i]=listData[i-gap];
                 listData[j+gap]=listData[j];
                
                //后挪。这里跟直接插入很像，只是i--;变减gap.
                 gap=j-gap;
                
            }
               //这里跟直接插入很像，只是i+1;变加gap.
               //找到数据填充数据。
               listData[j+gap]=tempData;
        }

           

    }
   
    printData(listData);

   }

   


}
int main()
{

    //insertSort();

   // sort();

    //希尔排序
    shellSort();
    return 0;
}

