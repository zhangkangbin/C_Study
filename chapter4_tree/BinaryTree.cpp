/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-23 13:58:39
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-23 16:54:55
 * @FilePath: \C_Study\chapter4_tree\BinaryTree.cpp
 * 二叉树
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class TreeNode{

   public:
   int data;
   TreeNode *mLeftChild;
   TreeNode *mRightChild;
};

class BinaryTree{

   public:
   TreeNode *mRootNode=NULL;
   TreeNode *mParentNode=NULL;
   void insertData(int value);
   void preOrder(TreeNode *node);
   void inOrder(TreeNode *node);
   void postOrder(TreeNode *node);
   void printfAllData();

};
/**
 * 递归方式
 * 先遍历
 * 
 */
void BinaryTree::preOrder(TreeNode *node){

   if(node!=NULL){
     
   //  cout<<"\nleft:"+1;
     cout<<"\nleft:"<<node->data;
     preOrder(node->mLeftChild);
     preOrder(node->mRightChild);

   }else{
  //  cout<<"\n mRootNode is empty!";
   } 

/* 
王道书上的代码应该是有问题的。
//非递归方式需要一个父节点？。
   TreeNode *tempNode=node;
   
   while (tempNode!=NULL)

   {
   

       if(tempNode!=NULL){
         //psuh(temp);指针进栈。

         tempNode=tempNode->mLeftChild;

       }else{
            //pop(temp);指针退栈。
           cout<<"\nleft:"<<node->data;
           tempNode=tempNode->mRightChild;

       }
   }
    */
   
}

/** 
 *   中序
 * 
 * @param node 
 */
void BinaryTree::inOrder(TreeNode *node){

   if(node!=NULL){
     

     inOrder(node->mLeftChild);
     //中序
     cout<<"\nleft:"<<node->data;
     inOrder(node->mRightChild);

   }else{
   // cout<<"\n mRootNode is empty!";
   }

}


/** 
 *   后序
 * 
 * @param node 
 */
void BinaryTree::postOrder(TreeNode *node){

   if(node!=NULL){
     

     postOrder(node->mLeftChild);
    
     postOrder(node->mRightChild);
      //后序
     cout<<"\nleft:"<<node->data;

   }else{
   // cout<<"\n mRootNode is empty!";
   }

}


/**
 * todo:功能待完善。
 * 
 * @param value 
 */
void BinaryTree::insertData(int value){

if(mRootNode==NULL){
   mRootNode=new TreeNode();
   mParentNode=mRootNode;
}
  TreeNode *node=new TreeNode();
  node->data=value;

  if(mParentNode->mLeftChild==NULL){

   mParentNode->mLeftChild=node;
    return;
  }

  if(mParentNode->mRightChild==NULL){

   mParentNode->mRightChild=node;

   return;
  }

  //mParentNode=node;
}

int main()
{
 

  BinaryTree tree;
  tree.insertData(1);
  tree.insertData(2);
  tree.preOrder(tree.mRootNode);
 // tree.inOrder(tree.mRootNode);
//  tree.postOrder(tree.mRootNode);
   
   return 0;
}