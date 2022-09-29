/*
 * @Author: zhangkangbin
 * @Date: 2022-09-27 23:51:48
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-09-29 15:04:31
 * @FilePath: \C_Study\chapter7_search\B_Tree.cpp
 *
 *B+树。通常用于数据库和操作系统的文件系统中。这个不是重点

  B树（B-树,-号，是翻译成中文的误解。） ，又称多路平衡查找树。

  一般考查找，毕竟删除的代码实在太多了。

 */
#include <stdio.h>
#include <iostream>
using namespace std;
#define FALSE 0
#define TRUE 1
#define M 3

class BTreeNode
{
public:
    int keyNum; //节点的大小

    BTreeNode *parent;
    BTreeNode *ptr[M + 1]; //子树指针矢量，子树指针数组。

    int key[M + 1]; //关键字矢量，0号单元未用
};
class Result
{
public:
    BTreeNode *pt; //指向找到的结点
    int i;         // 1..m，在结点中的关键字序号
    int tag;       // 1：查找成功，0：查找失败
};
BTreeNode *mRootTree = NULL;
/**
 * ptr子树指针矢量
 *
 */
void splitNode(BTreeNode *&tree, BTreeNode *&parent, int mid)
{

    int i;
    parent = new BTreeNode();

    for (i = mid + 1; i <= M; i++)
    {
        // i= 2, 3
        cout << " \n ------------splitNode: i:" <<i<<"   "<< (i - mid - 1);
        parent->key[i - mid - 1] = tree->key[i];
        parent->ptr[i - mid - 1] = tree->ptr[i];
    }

    if (parent->ptr[0])
    {
        //当ap有子树的时候
        for (i = 0; i <= 1; i++)
        {

            parent->ptr[i]->parent = parent;
        }
    }

    parent->keyNum = (M - mid) - 1;
    parent->parent = tree->parent;
    
    //修改tree的记录个数
    tree->keyNum = tree->keyNum - (M - mid);
}
int seachIndex(BTreeNode *tree, int key)
{
    cout << " \n seachIndex : key:" << key;
    int endNum;
    if (tree)
    {
        endNum = tree->keyNum;
    }
    else
    {
        return 0;
    }

    int i = 0;
    if (endNum == 0)
    {
        return i; //树存在，但仅有一个为空根节点
    }

    if (key >= tree->key[endNum]) //节点不为空，但当前值比最大的key还大
    {
        return endNum;
    }

    //节点不为空，但当前值比最小的key还小.
    if (key <= tree->key[1])
    {
        //因为0单元没有用，所以最小下标为1.
        return i;
    }

    //有合适的位置，即处于当前结点的最大和最小值之间，或找到了
    //在中间查找位置
    for (i = 1; i < endNum; i++)
    {
        if (tree->key[i] <= key && key < tree->key[i + 1])
        {
            return i;
        }
    }

    return 0;
}
/**
 * 新建节点
 *
 */
void newRoot(BTreeNode *&tree, int key, BTreeNode *&ap)
{

    BTreeNode *newTree = new BTreeNode();
    newTree->key[1] = key;
    newTree->ptr[0] = tree;
    newTree->ptr[1] = ap;
    newTree->keyNum = 1;
    newTree->parent = NULL;

    ap->parent = newTree;
    tree->parent = newTree;

    tree = newTree;
}
Result searchBTree(int key)
{

    bool isFound = false;
    int index = 0;
    BTreeNode *pNext = mRootTree;
    BTreeNode *parent = NULL;
    while (pNext && !isFound)
    {
        index = seachIndex(pNext, key);

        if (index > 0 && pNext->key[index] == key)
        {

            isFound = true;
        }
        else
        {
            parent = pNext;
            pNext = pNext->ptr[index];
        }
    }
    Result result;
    //查找成功，包装一个结果返回。
    if (isFound)
    {
        result.pt = pNext;
        result.i = index;
        result.tag = TRUE;
        return result;
    }
    else
    {
        //失败
        result.pt = parent;
        result.i = index;
        result.tag = FALSE;
        return result;
    }
}

void insert(BTreeNode *&tree, int keyIndex, int key)
{
    int j;

    for (j = M - 1; j > keyIndex; j--)
    {

        //将插入位置之后的key全部后移一位
        tree->key[j + 1] = tree->key[j];
    }
    for (j = M; j > keyIndex; j--)
    {
        //相应地也移动其后ptr的位置
        tree->ptr[j] = tree->ptr[j - 1];
    }

    tree->key[keyIndex + 1] = key;

    tree->ptr[keyIndex + 1] = NULL;
    tree->keyNum++;
}

/**
 *
 *  插入数据
 *
 * @param key
 * start function
 */
void insertData(int key)
{

    //先查找到插入的位置。
    Result result = searchBTree(key);
    // 1：查找成功，0：查找失败。
    if (result.tag == TRUE)
    {
        //相同的数不重复插入。
        return;
    }
    int i = result.i;
    int xKey = key;
    BTreeNode *ap = NULL;
    bool isFinished = false;
    BTreeNode *next = result.pt;
    while (next && !isFinished)
    {
        //插入数据
        insert(next, i, xKey);
        
        //如果是否超过子树最大阶。
        if (next->keyNum < M)
        {
            isFinished = true;
        }

        else
        {
            //超过最大阶个数，开始分裂
            int mid = M / 2;

            splitNode(next, ap, mid);

            xKey = ap->key[0];
            cout<<"\n key:"<<xKey;
            next = next->parent;

            if (next)
            {

                i = seachIndex(next, xKey);
            }
        }
    }
    //是空树或者根结点已分裂为结点*q和*ap
    // ap为子树指针
    if (!isFinished)
    {
        newRoot(mRootTree, xKey, ap);
    }
}
void InitialBTree(BTreeNode *&T)
{
    //初始化一个空的根
    T->keyNum = 0;
    T->parent = NULL;
    for (int i = 0; i < M + 1; i++)
    {
        T->ptr[i] = NULL;
    }
}

int main()
{
    mRootTree = new BTreeNode();
    InitialBTree(mRootTree);
    int a[11] = {45, 24, 53, 90, 3, 12, 50, 61, 70, 100};
    for (int i = 0; i < 4; i++)
    {

        insertData(a[i]);
    }
    cout<<mRootTree;
	cout<<"OK";

    return 0;
}
