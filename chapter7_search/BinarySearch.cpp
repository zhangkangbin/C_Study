/*
 * @Author: zhangkangbin
 * @Date: 2022-09-08 17:42:53
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-12-22 09:54:46
 * @FilePath: \C_Study\chapter7_search\BinarySearch.cpp
 * @Description:  二分查找（折半查找）
 * 时间复杂度O(log2n)
 *
 * 优点：对比次数少，查找效率高。
 * 缺点：对表结构要求高，只能用于顺序存储的有序表。查找前需要排序。
 *
 */
#include <iostream>
using namespace std;

#define SIZE 5

//默认是，有序的数据表
int mData[SIZE] = {1, 2, 4, 6, 8};

/**
 * 二分查找
 * @brief 非递归版本
 *
 * @param key
 * @return int
 */
int searchKey(int key)
{

    int startIndex = 0;
    int endIndex = SIZE;
    //开始下标大于 停止
    while (startIndex <= endIndex)
    {

        int mind = (startIndex + endIndex) / 2;

        if (mData[mind] == key)
        {
            return mind;
        }
        //往右查找，即大的一边。
        if (mData[mind] < key)
        {

            startIndex = mind + 1;
        }
        else
        {
            //往左查找，即小的一边。
            endIndex = mind - 1;
        }
        cout << "\n startIndex:" << startIndex << " " << endIndex;
    }
    cout << "\n ";
    return -1;
}
/**
 * @brief 递归版二分查找。
 * 
 * @param key 
 * @param startIndex 
 * @param endIndex 
 * @return int 
 */
int searchRecursion(int key, int startIndex, int endIndex)
{   
    //开始下标大于 停止
    if(startIndex>endIndex){

        return -1;
    }
     cout << "\n startIndex:" << startIndex << " " << endIndex;
    int mind = (startIndex + endIndex) / 2;
    if (mData[mind] == key)
    {
        return mind;
    }
    //往右查找，即大的一边。
    if (mData[mind] < key)
    {

        startIndex = mind + 1;

        return searchRecursion(key, startIndex, endIndex);
    }
    else
    {
        //往左查找，即小的一边。
        endIndex = mind - 1;
        return searchRecursion(key, startIndex, endIndex);
    }

  

    return -1;

}
int main()
{
    // cout<<"\n"<<searchKey(1);
    // cout<<"\n"<<searchKey(4);
    //  cout<<"\n"<<searchKey(8);
    cout << "\n\n"
         << searchKey(9);
    // cout<<"\n"<<searchKey(0);
    int result=searchRecursion(8,0,SIZE);
    cout<<" \n result:"<< result;
    return 0;
}
