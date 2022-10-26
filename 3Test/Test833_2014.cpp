/*
 * @Author: zhangkangbin
 * @Date: 2022-10-25 13:34:09
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-25 16:53:39
 * @FilePath: \C_Study\3Test\Test833_2014.cpp
 * @Description: 
 */

#include <stdio.h> 

#include<fstream>
#include<string>
#include<iomanip>

/**
 * 2013，
第五题
编写程序实现，输入一组数据，用指向指针的方法对输入的数据进行排序，用冒泡法进行排序（编写一个函数实现），
在主函数输入输出。（本题是谭浩强的课后习题）

 */

typedef struct Student{

  int age;

}test,*Stu;

void  sort(int list[]){

Stu stu=new Student;
stu->age=11;
 printf("\n age:%d",stu->age);
 struct Student student;
 student.age=18;

 printf("\n age:%d",student.age);

 }


int main()
{
 int list[5]={2,4,7,1};
  sort(list);
 // printf();

    return 0;
}
