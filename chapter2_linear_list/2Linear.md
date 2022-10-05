<!--
 * @Author: zhangkangbin
 * @Date: 2022-10-03 10:31:56
 * @LastEditTime: 2022-10-05 17:01:08
 * @FilePath: \C_Study\chapter2_linear_list\2Linear.md
 * 
-->

### 线性表
描述线性结构的定义。


### 线性表的基本操作

#### 初始化 initList();
#### 求表长 getLength()
#### 查找元素 locateElem();
#### 插入 insert();
#### 删除 delete();
#### 输出 printList();
#### 判断空 isEmpty();
#### 释放表中元素。clearList();


### 顺序表的定义




### 单链表定义

todo

#### 单链表数据结构的定义

```C++
class Node{
  public:
    int data;
    Node *next;
};
```

#### 单链表建立
1. 带头结点
2. 不带头结点

#### 单链表插入
1. 尾插法（这个用的多）
2. 头插法



### 双链表
+ 由于单链表只有一个指向后继的指针，使得单链表只能从头到尾遍历。要访问某个节点的前驱节点时（插入删除时），只能再次从头开始遍历。访问节点的后继节点时间复杂度 O(1),访问节点前驱节点时间复杂度 o(n).

- 为了克服单链表的缺点，所以引入双链表。
- 这里一般重点考插入数据的代码片段。

```C++
class{
   public:
    int data;
    Node *prior;
    Node *next;
};

```

双链表插入数据，代码片段

```C++

temp->next=node->next;
temp->prior=node;
node->next->prior=temp;
node->next=temp;//这步必须在最后。


```

```C++

node->prior->next=node->next;

node->next->prior=node->prior;


```

