/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-18 18:38:29
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-28 18:20:52
 * @FilePath: \C_Study\List.cpp
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
void test(int &t){

   
}
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

   int list[3]={6,7,8};
   int i=0;

   //list[++i]=i+1;
   list[i]=i++;
   cout<<"\n"<<list;

   return 0;
}