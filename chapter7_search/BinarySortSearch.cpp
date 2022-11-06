

/*
 * @Author: zhangkangbin
 * @Date: 2022-09-20 20:30:39
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-06 15:13:46
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
    // Node *mHead = NULL;

public:
    Node *mHead = NULL;
    bool searchData(int value);
    bool recursionSearchData(Node *node, int value);
    void addData(int value);
    bool addData(Node *&node, int value);
    bool addDataHead(int value);
};

bool Search::addDataHead(int value)
{

    if (mHead == NULL)
    {
        mHead = new Node();
        mHead->data = value;
        mHead->left = mHead->right = NULL;
        return true;
    }

    return addData(mHead, value);
}

/**
 * 递归查找到，添加数据的位置。
 *
 * @param node
 * @param value
 * @return bool
 */
bool Search::addData(Node *&node, int value)
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

    Node *child = new Node();
    child->data = value;

    if (mHead == NULL)
    {
        mHead = child;
        mHead->data = value;
        mHead->left = mHead->right = NULL;
        return;
    }

    Node *p = mHead;

    while (p)
    {

        if (p->data > value)
        {

            if (p->left == NULL)
            {

                child->left = child->right = NULL;

                p->left = child;

                return;
            }
            p = p->left;
        }
        else
        { //往右查找插入位置。
            if (p->right == NULL)
            {

                child->left = child->right = NULL;

                p->right = child;

                return;
            }

            p = p->right;
        }
    }
}
/**
 * 查找
 *
 * @param key
 * @return boo
 */
bool Search::searchData(int key)
{

    if (mHead == NULL)
    {
        return false;
    }

    Node *p = mHead;

    while (p)
    {
        if (p->data == key)
        {
            cout << "\n  find data: " << key << "\n";

            return true;
        }

        //如果顶点大于key,那么key在左边。
        if (p->data > key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    cout << "\n  not find data: " << key << "\n";
    return false;
}
/**
 * 用递归，查找数据
 *
 * @param key
 * @return true
 * @return false
 */
bool Search::recursionSearchData(Node *node, int key)
{

    if (node == NULL)
    {
        cout << "\n  not find data: " << key << "\n";
        return false;
    }

    if (node->data == key)
    {
        cout << "\n  find data: " << key << "\n";

        return true;
    }

    if (node->data > key)
    {

        return recursionSearchData(node->left, key);
    }
    else
    {

        return recursionSearchData(node->right, key);
    }
}
int main()
{

    int list[6] = {6, 5, 7, 3, 1};
    Search search;

    for (int i = 0; i < 5; i++)
    {

        // search.addData(list[i]);
        //插入数据
        search.addDataHead(list[i]);
    }

    /*     search.searchData(7);
        search.searchData(6);
        search.searchData(1);
        search.searchData(8); */

    //递归查找数据
    search.recursionSearchData(search.mHead, 7);
    search.recursionSearchData(search.mHead, 6);
    search.recursionSearchData(search.mHead, 1);
    search.recursionSearchData(search.mHead, 8);
    search.recursionSearchData(search.mHead, 0);

    return 0;
}
