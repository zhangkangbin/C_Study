/*
 * @Author: zhangkangbin
 * @Date: 2022-11-26 21:22:45
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-26 23:14:16
 * @FilePath: \C_Study\chapter10_algorithm\algorithm.cpp
 * @Description:
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int list[5] = {1, 5, 2, 4, 3};

int get(int number, int start)
{

    int max=1;
    for (int i = start; i < 5; i++)
    {

        if (number < list[i])
        {
            cout<<""<<list[i]<<" ";
          
             max=get(list[i],i+1);
            // cout<<"\n";
        }

        
    }

    return max;
}

int getMax()
{

    int max = 1;
    for (int i = 0; i < 5; i++)
    {
         max=1;
         max= get(list[i],i+1);

         cout<<"\n max:"<<max<<"\n";
        
    }

    return max;
}

int main(int argc, char const *argv[])
{
    getMax();
    return 0;
}
