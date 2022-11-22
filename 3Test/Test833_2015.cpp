/*
 * @Author: zhangkangbin
 * @Date: 2022-10-25 13:34:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-21 15:28:14
 * @FilePath: \C_Study\3Test\Test833_2015.cpp
 * @Description:
 */

#include <iostream>
using namespace std;

/**
 * 2013，
第五题
编写程序实现，输入一组数据，用指向指针的方法对输入的数据进行排序，用冒泡法进行排序（编写一个函数实现），
在主函数输入输出。（本题是谭浩强的课后习题）

 */

typedef struct Student
{

  int age;

} test, *Stu;

void sort(int list[])
{

  Stu stu = new Student;
  stu->age = 11;
  printf("\n age:%d", stu->age);
  struct Student student;
  student.age = 18;

  printf("\n age:%d", student.age);
}

/**
 * 3,已知A、B和C为三个递增有序的线性表，
 * 先要求对A表作如下操作删去那些既在B表中出现又在C表中出现的元素。

 * @return int
 */

void deleteCommon()
{
  // 3 和 6 是大家共有的。
  int A[5] = {1, 3, 4, 6, 7};
  int B[5] = {2, 3, 5, 6, 8};
  int C[5] = {1, 3, 4, 6, 7};
  int count = 1;
  for (int i = 0; i < 5; i++)
  {
    count = 1;
    int number = A[i];

    for (int b = 0; b < 5; b++)
    {

      if (number < B[b])
      {
        break;
      }
      if (number == B[b])
      {
        count++;
        break;
      }
    }
    for (int c = 0; c < 5; c++)
    {

      if (number < C[c])
      {
        break;
      }
      if (number == C[c])
      {
        count++;
        break;
      }
    }

    if (count == 3)
    {
      cout << A[i] << "  ";
    }
    //再删除表中元素。
  }
}
// start-4.--------------------------------------------------------------
/**
 *4.假设二叉树以二叉链存储，设计一个算法，判断一颗二叉树是否为完全二叉树。

 思路：层次遍历，一个一个结点判断。左右都不为空或者左右都空。
 *
 */


/**
2. 从键盘上输入一个后缀表达式试编写算法计算表达式的值。规定∶逆波兰表达的长度不超过一行，
以$符作为输入结束，操作数之间用空格分隔，操作符只可能有-+/*四种运算。
例如∶23434+2+2*$

 * 
 * 
 */
struct Tree
{

  int data;
  Tree *left;
  Tree *right;
};

struct Node
{
  Tree *data;
  Node *next;
};

Node *mRear; //入队
Node *mFront;

void initLink()
{

  mFront = mRear = new Node();
}

void enQ(Tree *tree)
{

  if (tree == NULL)
    return;

  Node *temp = new Node();
  temp->data = tree;
  mRear->next = temp;

  mRear = temp;
}

void deQ(Tree *&tree)
{

  if (mFront == mRear)
  {
    tree = NULL;
  }

  Node *data = mFront->next;

  tree = data->data;
  if (data == mRear)
  {
    mRear = mFront;
  }
  mFront->next = data->next;

  free(data);
}

bool isFullTree(Tree *tree)
{

  if (tree == NULL)
    return true;

  // 左右都不为空
  if (tree->left != NULL && tree->right != NULL)
  {

    return true;
  }

  // 或者左右都空
  if (tree->left == NULL && tree->right == NULL)
  {

    return true;
  }
  cout << " \n 非满树";
  return false;
}
void pdTree()
{

  Tree *head = new Tree();
  head->data = 888;

  Tree *left = new Tree();
  left->data = 1;

  Tree *right = new Tree();
  right->data = 2;

  head->left = left;
  head->right = right;

  Tree *left1 = new Tree();
  Tree *right1 = new Tree();
  left->left = left1;
  left->right = right1;

  initLink();

  enQ(head);
  bool isFull = true;
  while (mFront != mRear && isFull)
  {

    Tree *temp = NULL;
    deQ(temp);

    if (temp == NULL)
    {

      cout << " \n 空链表！";
    }
    else
    {
      cout << " \n data:" << temp->data;

      if (!isFullTree(temp))
      {

        isFull = false;
        break;
      }
      enQ(temp->left);
      enQ(temp->right);
    }
  }

  cout << " \n is full tree:" << isFull;
}

// end -4.--------------------------------------------------------------
/**
 * @brief
 *
 */
void printNode(Tree *tree)
{

  if (tree == NULL)
  {
    return;
  }
  cout << tree->data << "  ";
  printNode(tree->left);
  printNode(tree->right);
}

/**

5. 编写递归算法，对于二叉树中每一个元素值为x的结点，删去以它为根的子树，并释放相应的空间。

 * @return int
 */


void deleteReturnNode(int x, Tree *&node){

  if(node==NULL){
    return;
  }
  
  if(x==node->data){
    node->left=NULL;
    node->right=NULL;

    free(node->left);
    free(node->right);

    return;
  }

  if (node->data>x)
  {
   deleteReturnNode(x,node->left);
  }else{

   deleteReturnNode(x,node->right);
  }
  

}

//非递归方式
void deleteNode(int x, Tree *&head)
{



  Tree *next = head;

  while (next)
  {
    if (next->data == x)
    {
      //释放左右节点
      next->left = NULL;
      next->right = NULL;
      delete (next->left);
      delete (next->right);
      break;
    }
    else if (next->data > x)
    {
      next = next->left; //往左边找
    }
    else
    {
      next = next->right; //往右边找
    }
  }



}
void test5()
{
  Tree *head = new Tree();
  head->data = 6;

  Tree *left = new Tree();
  left->data = 3;

  Tree *left1 = new Tree();
  left1->data = 31;

  Tree *left2 = new Tree();
  left2->data = 32;

  left->left = left1;
  left->right = left2;

  Tree *right = new Tree();
  right->data = 9;

  head->left = left;
  head->right = right;
 
   printNode(head);
   //非递归方式
  deleteNode(3, head);

  cout << "\n ";
  printNode(head);

 //递归方式
  deleteReturnNode(6,head);
   
  cout << "\n ";
  printNode(head);
}
int main()
{
  // deleteCommon();
  //  pdTree();

  test5();
  // printf();

  return 0;
}
