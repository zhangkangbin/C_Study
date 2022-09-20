#include <stdio.h>
#include <iostream>
using namespace std;
/**
 * @date 2022.08.20
 * 
 * 栈（stack）又名堆栈，它是一种运算受限的线性表。限定仅在表尾进行插入和删除操作的线性表。
 * 这一端被称为栈顶，相对地，把另一端称为栈底。向一个栈插入新元素又称作进栈、入栈或压栈，
 * 它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；从一个栈删除元素又称作出栈或退栈，
 * 它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。
 * 
 * 后进先出。
 * 
 */
#define MaxSize 4

class StackList
{

private:
   string mData[MaxSize];
   int mTop = -1; //栈顶

public:
   bool push(string value);
   bool pop();
   string getTop();
   void printAllData();
   void destroyStack();
};

bool StackList::push(string value)
{

   if (mTop >= (MaxSize - 1))
   {
      // stack is full.
      return false;
   }
   mData[++mTop] = value;
   /*    cout << "\n"
           << value << "top:" << mTop; */
   return false;
}

bool StackList::pop()
{

   if (mTop >= 0)
   {

      mData[mTop--] = "";
      return true;
   }

   return false;
}

string StackList::getTop()
{
   if (mTop != -1)
   {

      return mData[mTop];
   }

   return "NULL";
}
void StackList::printAllData()
{
   cout << mTop;
   for (int i = 0; i < MaxSize; i++)
   {
      string temp = mData[i];
      if (temp.compare("") != 0)
      {
         cout << "\n"
              << i << ":" << temp;
      }
   }
}
//清空数组
void StackList::destroyStack(){

   for (int i = 0; i < mTop; i++)
   {
     mData[i]="";
   
   }
   mTop=-1;
   //mData

}
int main()
{

   StackList list;
   list.push("00");
   list.push("11");
   list.push("22");
   list.push("33");
   list.push("44");
   list.pop();
   list.pop();
   // list.push("55");
   list.printAllData();
   list.destroyStack();
   cout << "\ntop:" << list.getTop();

   return 0;
}