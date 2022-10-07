<!--
 * @Author: zhangkangbin
 * @Date: 2022-10-06 23:10:29
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-07 23:58:41
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