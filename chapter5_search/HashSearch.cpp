/*
 * @Author: zhangkangbin
 * @Date: 2022-09-10 21:11:10
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-10 23:52:40
 * @FilePath: \C_Study\chapter5_search\HashSearch.cpp
 * @Description:
 * 哈希表的查找
 * 采用线性探测法处理冲突。
 */

#include <iostream>
using namespace std;

#define SIZE 7

class HashTable
{
public:
    int key;
};

int mTable[SIZE] = {13, -1,9,2, 17, 4, 20};

int getKey(int key)
{
    int result = key % 7;
    cout << "\n getKey:"
         << result;
    return result;
}

int searchKey(int value)
{
   
    int key = getKey(value);
    //-1代表null
    if (mTable[key] == -1)
    {
        cout <<"\n not found value!"<<value<<"  \n ";
        return -1;
    }

    if (mTable[key] == value)
    {
        cout <<"\n  found value success! "<<value<<"  \n ";
        return key;
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout <<"-----------"<<i;
         key=getKey(value+1);
          //按照线性探测法计算下一个哈希地址
        if (mTable[key] == value)
        {
            cout <<"\n  found value success!"<<value<<" \n ";
            return i;
        }
        if (mTable[key] == -1)
        {
           cout <<"\n not found value!"<<value<<"  \n ";
            return -1;
        }
    }
      cout <<"\n not found value!"<<value<<"  \n ";
      return -1;
}

bool addData(int value)
{

    return true;
}
int main()
{

    int data;
    

     while (data!=-1)
     {
         cout<<"\n输入你要查找的数值\n";
         cin >> data;  
         searchKey(data);
     }
     
  
   // searchKey(27);
   // searchKey(13);
   // getKey(4);
  //  getKey(17);
    return 0;
}
