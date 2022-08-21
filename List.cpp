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


   
   return 0;
}