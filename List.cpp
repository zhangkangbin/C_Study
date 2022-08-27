/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-18 18:38:29
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-27 10:57:52
 * @FilePath: \C_Study\List.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <iostream>
using namespace std;

/**
 * 指针学习。
 * 通俗理解为地址的指向。
 * 
 */
class Node{

   public:
   string data;
   Node *dataNode;
};
int main()
{
   /* 我的第一个 C 程序 */
   printf("\n\n\n this  is from List! \n\n\n");


   Node *a=new Node();
   Node *b=a;
  
   b->data="bbb";
   cout<<("a:"+a->data+"\n");
   cout<<("b:"+b->data+"\n");

   a->data="aaa";
   cout<<("a:"+a->data+"\n");
   cout<<("b:"+b->data+"\n\n");

   Node *c=new Node();
   c->data="ccc";
 //  n=c;
 //b指向了c的地址。
    b=c;
    //修改a不再影响b的值。
    a->data="aaa11";
   cout<<("a:"+a->data+"\n");
   cout<<("b:"+b->data+"\n");
   cout<<("c:"+c->data+"\n");
  
   
   cout<<("c:"+c->data+"\n");

   Node *test=new Node();
  
     cout<<"c::\n" << test->dataNode;
   return 0;
}