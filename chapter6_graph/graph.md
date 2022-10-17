<!--
 * @Author: zhangkangbin
 * @Date: 2022-10-16 13:17:06
 * @LastEditTime: 2022-10-17 23:39:33
 * @FilePath: \C_Study\chapter6_graph\graph.md
-->
### 图


#### 图的定义
 

#### 图存储结构的分类

1. 邻接矩阵法（数组实现）

- 结构如下
```C++
//修改成有向图,只需要动矩阵。
int mArc[4][4] = {
    //_____a  b  c  d
    /*a*/ {0, 0, 0, 0},
    /*b*/ {0, 0, 0, 0},
    /*c*/ {0, 0, 0, 0},
    /*d*/ {0, 0, 0, 0}

};
```
2. 邻接表法 （链表形的数组）

- 结构如下
```C++
class Node{
    public:
    string name;//顶点名称
    int nameIndex;//顶点下标位置
    Node *nextNode;
};
class Adjacency{
   public:
   Node nodeList[NodeSize];//链表数组
};

```
<img src="res/邻接表法.jpg" width="100%">