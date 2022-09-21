

/*
 * @Author: zhangkangbin
 * @Date: 2022-09-20 20:30:39
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-21 10:48:35
 * @FilePath: \C_Study\chapter7_search\BinarySortSearch.cpp
 * 二叉排序树,又称二叉查找树。
 */

#include <stdio.h>
#include <iostream>
using namespace std;

class Node
{

public:
    int data;

    Node *left;
    Node *right;
};

class Search
{

private:
    Node *mHead = NULL;

public:
    void addData(int value);
    bool addData(Node*& node, int value);
    bool addDataHead(int value);
};


bool Search::addDataHead(int value){

   if (mHead == NULL)
    {
        mHead = new Node();
        mHead->data = value;
        mHead->left = mHead->right = NULL;
        return true;
    }


return addData(mHead,value);

}

/**
 * 这个递归方式还是有些问题。
 * 
 * @param node 
 * @param value 
 * @return true 
 * @return false 
 */
bool Search::addData(Node*& node, int value)
{

    if (node == NULL)
    {

        node = new Node();
        node->data = value;
        node->left = node->right = NULL;

        return true;
    }

    if (node->data == value)
    {
        //相同值，插入失败。其实可以改改。

        return false;
    }
    //从左找插入点。
    if (node->data > value)
    {

        return addData(node->left, value);
    }
    else
    {

        //从右找插入点。
        return addData(node->right, value);
    }

    return false;
}
/**
 * 非递归方式实现
 * 
 * @param value 
 */
void Search::addData(int value)

{
    if (mHead == NULL)
    {
        mHead = new Node();
        mHead->data = value;
        mHead->left = mHead->right = NULL;
        return;
    }

    Node *p=mHead;

    while (p)
    {

        if (p->data > value)
        {

            if (p->left == NULL)
            {

                Node *child = new Node();
                child->data = value;
                child->left = child->right = NULL;

                p->left = child;

                return;
            }
             p=p->left;
        }
        else
        { //往右查找插入位置。
            if (p->right == NULL)
            {

                Node *child = new Node();
                child->data = value;
                child->left = child->right = NULL;

                p->right = child;
              
                return;
            }

            p=p->right;
        }

      
    }
}

int main()
{

    int list[6] = {6, 5, 7, 3, 1};
    Search search;

    for (int i = 0; i < 5; i++)
    {

       // search.addData(list[i]);
        search.addDataHead(list[i]);
    }
    /*     int key = 0;
        Node *mHead=new Node();
        mHead=NULL;
        while (key != -1)
        {
            cin >> key;
            cout << " ----please enter value------\n";
            cout << "n ----add value------" << key;
            addData(mHead, key);
        } */

    return 0;
}
