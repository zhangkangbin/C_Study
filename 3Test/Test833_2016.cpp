/*
 * @Author: zhangkangbin
 * @Date: 2022-10-29 13:34:09
 * @LastEditTime: 2022-10-30 22:43:13
 * @FilePath: \C_Study\3Test\Test833_2016.cpp
 * @Description: 833 2016
 */

#include <iostream>
using namespace std;

//start,2. 编写算法将带头节点的单链表中值重复的节点删除，使所得的链表中各节点值不同。

struct  LinkNode
{
  int data;
  LinkNode *next;
};


void printNode(LinkNode *tree)
{

  if (tree == NULL)
  {
    return;
  }
  cout << tree->data << "  ";
  printNode(tree->next);
}
void deleteRepeatNode(LinkNode *&head){
  
  LinkNode *next=head->next;
  while (next)
  {
    LinkNode *repeat=next->next;
    LinkNode *pre=next;//指向待删除结点的父节点。
    while (repeat)
    {  
       LinkNode *temp=repeat;
      if(temp->data==next->data){
       
        pre->next=temp->next;
        repeat=repeat->next;
        free(temp); 
        
      }else{
       //避免下一个也是相同的，继续往下探索。 
      pre=repeat;
      repeat=repeat->next;
      }
      
    }
    next=next->next;
  }
    cout<<"\n";
    printNode(head);

}
void  testDeleteRepeatNode(){

  LinkNode *head=new LinkNode();

  LinkNode *node=new LinkNode();
  node->data=1;
  head->next=node; 
 
  LinkNode *node2=new LinkNode();
  node2->data=1;
  node->next=node2; 

  LinkNode *node3=new LinkNode();
  node3->data=3;
  node2->next=node3; 

 
 
  LinkNode *node11=new LinkNode();
  node11->data=1;
  node3->next=node11; 

  LinkNode *node111=new LinkNode();
  node111->data=1;
  node11->next=node111; 


  LinkNode *node5=new LinkNode();
  node5->data=5;
  node111->next=node5; 
  
  LinkNode *node6=new LinkNode();
  node6->data=6;
  node5->next=node6;  

  printNode(head);

  deleteRepeatNode(head);

}




/**


3. 给定一组数列（15，8，10，21，6，19，3）分别代表字符A，B，C，D，E，F，G 出现的频度，
试叙述建立哈夫曼树的算法思想，画出哈夫曼树，给出各字符的编码值，并说明这种编码的优点。

4.有关键字为21，15，20，14，10，2的一组记录，在末尾插入关键字5，
将其关键字转换成最大堆和最小堆。
（1）画出最大堆和最小堆；
（2）写出最大堆和最小堆得基本思想；

 * 
 * @return int 
 */

//6. 编程实现二分查找算法，并写出二分查找的代码。
int mList[5]={2,4,6,8,10};
bool binaryFind(int start,int end,int key){
      
     if(start>end){
      
      cout<<"the find end!";
      return false;
     }

     int mind=(start+end)/2;
       cout<<"\n mind:"<<mind;
     if(key==mList[mind]){
       cout<<"\n found key!";
      return true;
      }
     if(key<mList[mind]){

      return find(start,mind-1,key);
     }
    
     return find(mind+1,end,key);



}
int main()
{
  //testDeleteRepeatNode();

  binaryFind(0,5,2);

  return 0;
}
