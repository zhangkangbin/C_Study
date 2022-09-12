/*
 * @Author: zhangkangbin
 * @Date: 2022-09-08 17:38:53
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-12 16:39:24
 * @FilePath: \C_Study\chapter5_search\SequentialSearch.cpp
 * @Description:
 */
#include <iostream>
using namespace std;
#define SIZE 6
// 0位为哨兵位置。
int mList[SIZE] = {0, 9, 4, 6, 7, 8};
/**
 * @brief 顺序查找
 * 这个可以直接参考@link list/ArrayList的findData
 *
 * @return int
 */
void findData(int key)
{
    int isFind = 0;

    //设置哨兵值，哨兵主要是为了减少数组下标越界的判断，增加查找效率。
    mList[0] = key;

    for (int i = SIZE; i--;)
    {

        if (mList[i] == key)
        {
            isFind = i;

            break;
        }
        cout << "\n  -----";
    }

    if (isFind)
    {
        cout << "\n  data found successfully!";
    }
    else
    {
        cout << "\n data not found !";
    }
}
int main()
{


    int key=0;

    while(key!=-1){
    cout << "\n please input the keyword you need to find \n";
     cin >> key;
    findData(key);

   }
    return 0;
}
