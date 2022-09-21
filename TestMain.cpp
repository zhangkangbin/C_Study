/*
 * @Author: zhangkangbin
 * @Date: 2022-09-19 22:38:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-21 01:02:06
 * @FilePath: \C_Study\TestMain.cpp
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include <iostream>
using namespace std;

class Node
{

public:
   int data;

   Node *left;
};

void testObj(Node &obj)
{

   Node node;
   node.data = 9988;

   obj = node;
}
Node *curent;
Node *obj;
void testObj2(int key)
{
   Node *node = new Node();
   node->data = key;
   if (obj == NULL)
   {
      obj = node;
   }
   else
   {

      curent->left = node;
   }

   curent = node;
}

int main()
{
   // get();

   /*    int node=33;
      cout<<"\n ---------! d\n\n\n"<<node;
      test(node);

      cout<<"\n --------- d\n\n\n"<<node; */

   Node node;
   //  node->data=123;
   node.data = 123;

   // cout<<"\n --------- d\n\n\n"<<node->data;
   testObj(node);

   cout << "\n ----修改后----- d\n\n\n"
        << node.data;

   int list[6] = {6, 5, 7, 3, 1};

   for (int i = 0; i < 5; i++)
   {

      testObj2(list[i]);
   }

   cout << "\n ----修改后2----- d\n\n\n"
        << obj->data;
    cout<<"\n ----修改后2----- d\n\n\n"<<obj->left->data;
    cout<<"\n ----修改后2----- d\n\n\n"<<obj->left->left->data;

   get();

   return 0;
}