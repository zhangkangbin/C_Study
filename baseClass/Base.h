/*
 * @Author: zhangkangbin
 * @Date: 2022-09-19 22:21:42
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-19 22:26:42
 * @FilePath: \C_Study\baseClass\Base.cpp
 * @Description:
 */
#include <iostream>
using namespace std;
class Base
{
private:
    /* data */
public:
    Base(/* args */);
    ~Base();
    void printData(int list[], int length)
    {
       printData(list,0,length); 
    }
    void printData(int list[], int start, int length)
    {
        cout << " \n";

        for (int i = start; i < length; i++)
        {

            cout << " " << list[i];
        }

        cout << " \n";
    }
};

