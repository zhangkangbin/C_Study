<!--
 * @Author: zhangkangbin
 * @Date: 2022-11-06 11:41:46
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-11 15:20:58
 * @FilePath: \C_Study\2outline\concept.md
 * @Description: 
-->
### 第一章 算法的概念
#### 算法的五个重要特性
- 1，有穷性，算法必须总是在执行有穷步后结束，且每一步都必须在有穷的时间内完成。
- 2，确定性，对于每种情况下，所执行的操作，在算法中有确切的规定，不会产生二义性。
- 3，可行性，算法中所有操作都可以通过已经实现的基本操作运算执行有限次来实现。
- 4，输入，算法有零个或多个输入。
- 4，输出，算法有零个或多个输出。

#### 评估算法好坏的因素包括：

- 1.正确性，能正确的实现预定的功能，满足具体问题的需要
- 2.易读性，易于阅读和理解和交流，便于调式修改和扩充。
- 3.健壮性，即使输入非法的数据，算法也能进行处理，不会产生预料不到的运行结果。
- 4.高效性，一个算法的时空性指该算法的时间性能和空间性能,算法要设计得合理，执行效率高。

#### 最坏时间复杂度
>对相同输入数据的不同数据，算法时间用量的最大值。

#### 平均时间复杂度
> 对所有相同输入数据量的各种不同输入数据，算法时间用量的平均值。



--------------------------------------------------------------------------
--------------------------------------------------------------------------



### 第二章 线性表

#### 线性表的性质
>线性表是一种线性结构，它由n个数据元素组成的有穷序列，数据元素称为结点，结点个数n称为表长，当n=0时，线性表不含任何数据，称为空表。当n>0时，除了第一个结点，呢个数据元素都有一个前驱，除了最后一个结点，每个数据都有一个后继。


#### 顺序表

>将表中的结点依次存放在计算机内存中一组连续的存储单元中，数据元素在线性表中的邻接关系决定它们在存储空间的存储位置，即逻辑结构中相邻的结点其存储的位置也相邻，用顺序存储的线性表称为顺序表。一般使用数组来表示顺序表。




#### 链表



--------------------------------------------------------------------------


### 第三章 栈、队列和数组

#### 栈的性质
>栈是一种运算受限制线性表，有着先进后出的特点。
允许删除和插入数据的一端，叫栈顶，另一端称为栈底。不含任何数据的栈叫空栈，处于栈顶的数据元素称为栈顶元素。

#### 队列性质

>队列是一种插入和删除受限制的线性表，有着先进先出的特点，允许在一端删除，另一端插入数据。允许插入数据的一端称为队列的尾端，允许删除数据的一端称为队列首部。


#### 数组性质

>一维数组又称向量，它是由一组相同类型的数据元素组成的，并存储在一组连续的存储单元中，若一维数组中的数据元素又是一组数据结构，则称为二维数组，以此类推，一般的，一个n维数组可以看出是一个n-1维数组的线性表。





--------------------------------------------------------------------------



### 第五章 树和二叉树

#### 树的性质
>树

#### 树的特点
-  (1)只有根节点，没有双亲结点，其他结点均有唯一的双亲结点。
- （2）除了叶子结点外，每个结点有一个或多个孩子结点。


#### 二叉树
>二叉树是n个元素的有限集合，改集合或者为空集（n=0），或者由一个节点和两棵互不相交的左子树和右子树的二叉树组成。

#### 二叉树的特点
- 1，每个结点最多只有两棵子树，所以二叉树中不存在度大于2的结点。
- 2，子树的次序不能颠倒，某个结点即使一棵子树，也要区分左子树还是右子树。


#### 满二叉树的特点
- 1，叶子结点都在最下一层。
- 2，只有度为0和度为2的结点。


#### 树转成森林的方法

