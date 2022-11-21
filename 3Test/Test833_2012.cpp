/*
 * @Author: zhangkangbin
 * @Date: 2022-10-25 13:34:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-21 12:39:15
 * @FilePath: \C_Study\3Test\Test833_2012.cpp
 * @Description:
 */

#include <stdio.h>
#include "base.h"
using namespace std;

typedef struct Book
{
   int data;
   Book *book;
} ;

/**
 * 2012，第一题，N项和。
 *
 * @param n
 * @return float
 */
float getResult(int n)
{
   float result = 1;
   for (int i = 2; i <= n; i++)
   {

      if (i % 2 == 0)
      {
         //偶数项为减，1.0保证精度。
         result = result - (1.0 / i);
      }
      else
      {
         //奇数项为加
         result = result + (1.0 / i);
      }
   }

   return result;
}

/**
 * 杨辉三角
 *
 * @return int
 */


void printTwoArray(int list[6][6], int size)
{

 
}

void forYH()
{

   int size = 6;

   int list[6][6] = {1};
   //从1 开始
   for (int i = 1; i < 6; i++)
   {
      list[i][0] = 1;//将每一行第一列先初始化为1，防止越界
      for (int j = 1; j < i+1; j++)
      { 
         //核心是这句话。这个数是上上面一行的二个数相加。
         list[i][j] = list[i - 1][j - 1] + list[i - 1][j];
      }
   }

  for (int i = 0; i < size; i++)
   {

      for (int j = 0; j < i+1; j++)
      {

         cout << list[i][j]<<" " ;
      }

      printf("\n");
   }
}
int main()
{
   /* code */
/*    printf("getResult:%f", getResult(2));
   printf("\ngetResult:%f", 1.0 / 5);
   printf("\n"); */
   forYH();
   return 0;
}
