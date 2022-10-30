<!--
 * @Author: zhangkangbin 
 * @Date: 2022-08-18 18:31:13
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-10-30 23:49:04
 * @FilePath: \C_Study\README.md
-->
# C_Study

###
###   [数据结构可视化网站☆ ](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html) 


Get start
8.24, 学习到二叉树尾声了。 

### 特性矩阵的压缩存储

- 对称矩阵

#### 稀疏矩阵
- 画图


### 5，树和二叉树
- 二叉树叶节点统计
-  二叉树深度统计


### 6，图
- 邻接矩阵，表示法创建无向图✓
- 邻接表，表示法创建的无向图 ✓

### 邻接矩阵
- 深度优先算法 ✓ 8.29
- 广度优先算法✓  8.29


### 7 查找

-   [顺序查找](chapter5_search/SequentialSearch.cpp) 重点
-   [二分查找查找](chapter5_search/BinarySearch.cpp)  重点
-   [分块查找]() 没写
-   [二叉排序树](chapter7_search/BinarySortSearch.cpp) get
- 二叉排序树插入数据。
- 二叉排序树删除数据，没写。代码贼多。
-   [平衡二叉树AVL（红黑树）]书上代码都没有。高分笔记也没有。
 用插入的成本，来弥补查找的效率。因为插入时候，如果树不平衡，就需要调整树的结构。有额外的开销。
 适合插入少，查询多的时候。
-   [B树查找]() 暂时没写 ，一般只考查找（重点）和插入。
-   [哈希表(散列)的查找](chapter5_search/HashSearch.cpp) 9.10

### 8 排序

-  插入排序

   -  直接插入排序 掌握 ✓ 9.12
   - 折半插入排序 掌握 
   - 希尔插入排序 掌握 ✓ 9.13

###   交换排序

- 冒泡排序 掌握 ✓ 9.14 21
- 快速排序 ☆  ✓ 9.16  21


###   选择排序
- 简单选择排序 ☆ ✓
- 堆排序 ☆ ✓ 9.19


###   归并排序 ✓ 9.24,22
###   基数排序

## 文件操作 9.22
- 数据类型	描述
- ofstream	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
- ifstream	该数据类型表示输入文件流，用于从文件读取信息。
- fstream	该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。



### 字符串相关的库函数

- String.h

### 动态规划和静态规划
- 1. 递归与分治策略、回溯法
- 2. 贪心算法、分支限界法、动态规划


###   算法性质比较


| 排序算法 | 最优 | 平均复杂度 |  最差  | 空间复杂度 | 稳定性 |
|:--------:|:----:|:----------:|:------:|:----------:|:------:|
| 插入排序 | O(n) |   O(n²)    | O(n²)  |    O(1)    |  稳定  |
|   希尔   | O(n) |   nlog2n   | nlog²n |    O(1)    | 不稳定 |


 
