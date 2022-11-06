/*
 * @Author: zhangkangbin
 * @Date: 2022-10-25 13:34:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-04 22:05:32
 * @FilePath: \C_Study\3Test\Test833_2012.c
 * @Description: 
 */

#include <stdio.h> 

typedef struct Book{
   int data;
   Books *book;
}Books;

/**
 * 2012，第一题，N项和。
 * 
 * @param n 
 * @return float 
 */
float getResult(int n){
 float result=1;
 for(int i=2;i<=n;i++){
 
  if(i%2==0){
     //偶数项为减，1.0保证精度。
    result=result-(1.0/i);
  }else{
     //奇数项为加
    result=result+(1.0/i);
  }

 }

return result;

}
int main()
{
    /* code */
    printf("getResult:%f",getResult(2));
    printf("\ngetResult:%f",1.0/5);
    printf("\n");
   

    return 0;
}
