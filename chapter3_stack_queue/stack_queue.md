<!--
 * @Author: zhangkangbin
 * @Date: 2022-10-06 23:10:29
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-11 17:30:48
 * @FilePath: \C_Study\chapter3_stack_queue\stack_queue.md
 * @Description: 
-->


### 栈和队列

### 栈的定义

- 栈只允许在一端插入或删除的操作的线性表。栈的特征是后进先出。


### 栈的基本操作

1. initStack()初始化
2. is Empty()判空
3. push(val)进栈，若栈未满，将值添加到栈顶。
4. pop() 出栈 ，若栈非空，弹出值，并返回栈顶元素。
5. getTop() 得到栈顶值。若栈非空，返回栈顶元素。
6. destroyStack() 销毁栈，释放栈的占用的存储空间。

#### 栈的顺序存储结构（采用数组实现）

- 存储结构
```C++
class Stack{
   int data[MaxSize]; //这是使用int类型。
   int top;//栈顶下标
};

```
- 初始化
```C++
//初始化。mStack全局变量。
void initStack(){
    mStack.top=-1;//-1代表空。
}

```

- 判空
```C++
bool isEmpty(){

  if(mStack.top==-1){
    return true;
  }
  return false;
}

```

- 进栈

```C++
bool pop(int value){
if(mStack.top==MaxSize-1){
    return false;
}
 //先加1，因为是从-1，开始的。
 mStack.data[++mStack.top]=value;
 return true;
}

```
- 出栈

```C++

bool push(int &value){

 if(isEmpty()){
    return false;
  }
  value=mStack.data[mStack.top--];
  return true;
}

```

- 获得栈顶值

```C++
int getTop(){

if(isEmpty()){
    return -1;
  }
return mStack.data[mStack.top];
}
```


### 栈的链式存储结构

- 采用链式存储结构，适合容量大小未知情况下。
- 全部代码具体实现看 StackLinkNode
- 结构定义

```C++
class StackLinkNode{
  int data;
  StackLinkNode *next;

};
```

- 初始化
```C++
//初始化。mStack全局变量。
void initStackLinkNode()
{
    mRoot = NULL;
}

```

- 进栈

```C++

bool push(int value)
{
    StackLinkNode *node = new StackLinkNode();
    node->data = value;
    node->next=mRoot; //这个设计很巧妙。把数据都填充给当前节点的 next;
    mRoot = node;//mRoot 根节点
    return true;
}

```

- 出栈

```C++
int pop()
{
    StackLinkNode *top = mRoot;
    int data=top->data;
    mRoot=top->next;

    delete top;
    return data;
}


```


- 得到栈顶

```C++
int getTop(){

  if(!mRoot){ return -1; }

   return mRoot->data;
}

```
 

-------------------------------------


### 队列

#### 队列的基本定义
- 队列（queue）,简称队，是一种操作受限制的线性表，只允许在一端插入，另一端删除。向队列插入元素叫入队，删除元素叫出队。其操作特性是先进先出。

#### 队列的基本操作

1. initQueue(); 初始化
2. isEmpty(); 判空。front==rear=0.
3. enQueue();入队。
4. deQueue(); 出队。
5. getHead(); 得到队头



#### 队列的顺序存储（数组实现）

- 不同的教材，对于队头队尾的定义可能不一致。

- 队列的顺序存储类型

```C++
class ArrayQueue{
 int data[MaxSize];//存储数组。
 int front; //队头
 int rear; //队尾
};

```

- 初始化 

```C++
void initQueue(){
   //设置为空
  mQueue.front=mQueue.rear=0;
}
```


- 判空

```C++
bool isEmpty(){
  if(mQueue.front==mQueue.rear){
    return true;
  }
  return false;
}
```

- 入队，队尾插入数据。

```C++

bool enQueue(int value){
  
  bool isFull=(mQueue.rear+1)%MaxSize==mQueue.front;

  if(isFull){
    return false;
  }

  mQueue.data[mQueue.rear]=value;

  mQueue.rear=(mQueue.rear+1)%MaxSize;

  return true;

}

```



- 出队，队头删除数据。

```C++

bool deQueue(){
  
  if(isEmpty()){
    return false;
  }
 //这一步可以不设置，也没有事，是否空是靠队头队尾指针指向的位置。
  mQueue.data[mQueue.front]=-1;//设置为-1，代表空
  //队头加 1。
  mQueue.front=(mQueue.front-1)%MaxSize;

  return true;

}

```


#### 队列的链式存储

- 链式存储结构类型 （完整代码QueueLinkList.cpp）

```C++
class LinkNode{

  int data;
  LinkNode *next;//单链表

};

class LinkQueue{

LinkNode *front,rear;

};


```

- 初始化

```C++

void initQueue(){

  mQueue->front=mQueue->rear=new LinkNode();//指向同一个单链表
  mQueue->front->next=NULL;

}
```

- 判空

```C++
bool isEmpty(){
  //如果空，二者指向同一个地址。
return mQueue->front==mQueue->rear;
}

```


- 入队

```C++
void enQueue(int value){

LinkNode *temp=new LinkNode();
temp->data=value;
temp->next=NULL;

//插到队尾
mQueue->rear->next=temp;
mQueue->rear=temp;

}

```


- 出队

```C++

int deQueue()
{
    int value = -1; //待返回的数据
    if (isEmpty())
    {
        return value;
    }

    LinkNode *data = mQueue->front.next;
    value = data->data;

    mQueue->front.next = data->next;

    if (mQueue.rear == data)
    {
        //只有一个节点情况，尾节点=data;
        mQueue.rear = mQueue.front;
    }

    free(data);

    return value;
}


```

