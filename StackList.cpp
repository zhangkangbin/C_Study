#include <stdio.h>
#include <iostream>
using namespace std;

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