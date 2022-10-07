<!--
 * @Author: zhangkangbin
 * @Date: 2022-10-06 23:10:29
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-07 23:39:44
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
