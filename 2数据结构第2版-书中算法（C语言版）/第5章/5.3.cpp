/*
 * @Author: zhangkangbin 784908058@qq.com
 * @Date: 2022-08-23 22:37:58
 * @LastEditors: zhangkangbin 784908058@qq.com
 * @LastEditTime: 2022-08-24 19:17:50
 * @FilePath: \C_Study\2数据结构第2版-书中算法（C语言版）\第5章\5.3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//算法5.3 先序遍历的的顺序建立二叉链表
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)
{	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

//用算法5.1 中序遍历的递归算法							
void InOrderTraverse(BiTree T)
{  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"所建立的二叉链表中序序列：\n";
	InOrderTraverse(tree);
	cout<<endl;
}
