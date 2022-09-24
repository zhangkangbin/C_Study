/*
 * @Author: zhangkangbin
 * @Date: 2022-09-19 22:21:42
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-24 11:19:04
 * @FilePath: \C_Study\baseClass\Base.h
 * @Description:
 */

#ifndef LABEL
#define LABEL
#include <iostream>
using namespace std;
void printDataS(int list[], int start, int length)
{
    cout << " \n";

    for (int i = start; i < length; i++)
    {

        cout << " " << list[i];
    }

    cout << " \n";
}

void printData(int list[], int length)
{
    printDataS(list, 0, length);
}


#endif