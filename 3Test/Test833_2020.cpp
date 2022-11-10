/*
 * @Author: zhangkangbin
 * @Date: 2022-10-29 13:24:24
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-10 21:47:37
 * @FilePath: \C_Study\3Test\Test833_2020.cpp
 * @Description:
 */
#include <iostream>
#include <stdio.h>
#include "base.h"
using namespace std;

/*




4. 栈操作有入栈和出栈，初始时栈为空，如果进行一系列进出栈操作后，栈仍然为空，
那么就称该栈操作是正确的，否则为错误，如果入栈用Ⅰ标出，出栈用O表示，则对手一些序列（15分）
A. IIOOIIO
B. IOIIOOIO
C. IIOIOO
D. IIIOOO，


其中BD操作
是正确的，判断给出一个序列的栈操作是否正确，正确返回TRUE，错误返回FALSE。
（1）给出算法的基本设计思想；
（2）写出该算法，并在关键之处给出注释。




*/

/*

1.给定一个单链表，链表内数字各不相同，删除值为X的结点，并返回头结点，
试设计算法并使用C/C++代码实现。（15分）
*/

SingleLinkNode *deleteNode(SingleLinkNode *&node, int key)
{

	SingleLinkNode *head = node;
	//带头结点
	SingleLinkNode *pre = node; //指向上一个节点，方便删除。
	SingleLinkNode *next = node->next;
	bool isFind = false;
	while (next && !isFind)
	{
		if (next->data == key)
		{

			isFind = true;

			break;
		}

		pre = next;
		next = next->next;
	}

	if (isFind)
	{

		pre->next = pre->next->next;

		free(next);
	}

	//返回头节点。
	return head;
}

void testDeleteNode()
{

	SingleLinkNode *node = getSingleLinkNode();
	// deleteNode(node,4);
	SingleLinkNode *head = deleteNode(node, 10);

	printSingleLinkNode(head);
}

/**
2.一个整数数组{2，3，8，10，11，7，20，9，15}，按照该数组元素的顺序，
健立二叉排序树，写出算法思想，写出算法，并在关键处给出注释。（15分）

 */

Node *mHead;
void addData(int key)
{

	Node *temp = new Node();
	temp->data = key;

	if (mHead == NULL)
	{
		mHead = temp;
		return;
	}

	Node *next = mHead;
	while (next)
	{
		if (next->data > key)
		{

			if (next->left == NULL)
			{
				next->left = temp;
				return;
			}
			else
			{
				next = next->left;
			}
		}
		else
		{
			if (next->right == NULL)
			{
				next->right = temp;
				return;
			}
			else
			{
				next = next->right;
			}
		}
	}
}

/**
 3. 给定一串数字序列，试用快速排序将其变成有序序列，试设计算法并写出代码。（15分）
 *
 */

int getPartition(int list[], int low, int high)
{

	//把low当参考值

	int position = list[low];

	while (low < high)
	{

		while (list[high] >= position && low < high)
		{
			high--;
		}
		list[low] = list[high];

		while (list[low] <= position && low < high)
		{
			low++;
		}
		list[high] = list[low];
	}

	list[low] = position;

	printList(list, 9);

	return low;
}

void quickSort(int list[], int low, int high)
{

	if (low < high)
	{
		int position = getPartition(list, low, high);
		quickSort(list, low, position - 1);
		quickSort(list, position + 1, high);
	}
}

void testQuickSort()
{

	int list[9] = {8, 2, 3, 10, 11, 7, 20, 9, 15};

	quickSort(list, 0, 8);
	printList(list, 9);
	cout << "\n --------quick sort test-------\n ";
}
// 3 end---------------------------------------------------------------------

void createTree()
{

	// int list[9]={2,3,8,10,11,7,20,9,15};
	int list[9] = {2, 3, 8, 10, 11, 7, 20, 9, 15};

	for (int i = 0; i < 9; i++)
	{

		cout << list[i] << " ";

		addData(list[i]);
	}

	cout << "\n -------end------\n";
}

/**'
 * 5. 给定一颗二叉树，求出叶子个数，试设计算法并写出代码。（15分）
 * 
 * 思路1:没有左右孩子的称为叶子结点。递归判断如果这个节点没有左右孩子，就加一。
 * 
 * 思路2：设置全局变量，遍历二叉树，判断如果这个节点没有左右孩子，就加一。
 * 这个简单。
 */

int countTreeLeaf(Node *node)
{

	if (node == NULL)
	{
		return 0;
	}

	int result=0;
    if(node->left==NULL&&node->right==NULL){

		return 1;
	}else{
      

	int left = countTreeLeaf(node->left);
	int right = countTreeLeaf(node->right);

	 result=left+right;
	}


	return result;
}

void testCountTreeLeaf()
{

	Node *node = getTestTree2();
	int sum = countTreeLeaf(node);

	Node *node2 = getTestTree();
	int sum2 = countTreeLeaf(node2);
     
	int sum3 = countTreeLeaf(getTestTree3());

	cout << sum << "  " << sum2<< "  " << sum3;
}

int main()
{
	// testDeleteNode();
	// createTree();
	// testQuickSort();
	testCountTreeLeaf();
	return 0;
}