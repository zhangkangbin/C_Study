/*
 * @Author: zhangkangbin
 * @Date: 2022-10-25 13:34:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-21 15:00:57
 * @FilePath: \C_Study\3Test\Test833_2013.cpp
 * @Description:
 */

#include <iostream>
using namespace std;

/**
2.假设一个小球从 200 米高的空中落下，每次反弹一半高度，求第 5 次落下
小球经过的路径是多少求第八次反弹高度是多少

 *
 */

void getHigh()
{

  double maxHigh = 200;

  double sumPath = 200; //计算前面五次回弹高度的和

  for (int i = 1; i <= 8; i++)
  {

    maxHigh = maxHigh / 2.00;

    if (i <= 5)
    {
      //计算前面五次回弹高度的和。
      sumPath = maxHigh + sumPath;
    }

    // cout<<i<<":"<<maxHigh<<"米  ";
  }
  cout << "第八次回弹高度:" << maxHigh << "米  ";
  cout << "\n五次回弹的高度:" << sumPath << "米  ";
}

/**
 * 2013，
第五题
编写程序实现，输入一组数据，用指向指针的方法对输入的数据进行排序，用冒泡法进行排序（编写一个函数实现），
在主函数输入输出。（本题是谭浩强的课后习题）

 */

typedef struct Student
{

  int age;
  char name[14] = "runoob3210";
  struct Student *myself; //必须带*指针
} My, *Stu;

void sort()
{
  int list[5];
  cout << ("输入五个数：");
  for (int i = 0; i < 5; i++)
  {
    cin >> list[i];
  }

  //这一步是排序。

  //输出。
  for (int i = 0; i < 5; i++)
  {

    cout << list[i] << " ";
  }
}

//--start---------------------第五题-----------------------------------

struct StudentInfo
{
  int number;
  char name[15];
  int age;
  StudentInfo *next;
};
StudentInfo *mHead;
StudentInfo *mLast;

void initStudentInfo()
{ //带头结点。
  mHead = new StudentInfo();
  mLast = mHead;
}

void addData()
{

  for (int i = 0; i < 5; i++)
  {
    StudentInfo *data = new StudentInfo();
    data->age = 18 + i;
    data->number = i;
    mLast->next = data;

    mLast = data;
  }

  cout << "---end---";
}
void printAll()
{

  if (!mHead)
  {
    return;
  }
  StudentInfo *next = mHead->next; //带头结点。
  cout << "\n--------------";
  while (next)
  {

    cout << "\n"
         << next->number << "  " << next->age;
    next = next->next;
  }
}
bool deleteData(int number)
{

  if (!mHead)
  {
    return false;
  }

  StudentInfo *next = mHead->next; //带头结点。
  StudentInfo *pre = mHead;
  bool isFind = false;
  while (next)
  {

    cout << "\n"
         << next->number << "  " << next->age;

    if (next->number == number)
    {
      isFind = true;
      break;
    }
    pre = next;
    next = next->next;
  }

  if (isFind)
  {
    StudentInfo *delNode = next; //待删除的结点 delNode
    pre->next = delNode->next;
    free(delNode);
  }
  cout << "\n isFind :" << isFind;
  printAll();

  return isFind;
}

//----end-------------------第五题-----------------------------------
int main()
{

  //第五题
  // sort();
  // printf();

  /*   initStudentInfo();
    addData();
    deleteData(22);
   */
  getHigh(); //第二题
  return 0;
}
