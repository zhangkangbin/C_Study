/*
 * @Author: zhangkangbin
 * @Date: 2022-10-29 13:24:24
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-14 23:05:37
 * @FilePath: \C_Study\3Test\Test833_2021.cpp
 * @Description:
 */
/*


（1）简述线性结构特点。（8分）


2. 先着色点S，再从右、上、左、下的逆时针顺序依次着色S的邻域。重复这
个过程直到整个区域着色完成。

			1
	4	8	SSS
	5	6


（1）简述栈是什么？栈的特点是什么？（8分）
（2）用栈实现点的着色过程（可用自然语言）。（12分）



4.（1）简要说明动态规划是什么，与分治法有什么区别?（10分）
（2）给出例子说明动态规划求解的过程。（10分）

5.（1）分析斐波那契函数的时间复杂度和空间复杂度。（10分）
（2）用C/C++程序语言写出斐波那契函数的递归形式。（10分）


6. 哈夫曼树是自下而上构建的，这与平常的树不一样，设最下面的一层为第一层，向上为第二层，依次是第三层，......

（1）写出实现二叉树的链表结构和队列结构；（5分） |

（2）根据上述结构写出哈夫曼树从头结点到叶子结点的算法过程，并且描写具体的实现过程；（10分）

（3）写出实现过程。（10分）



7.
（1）关于有向图，用邻接矩阵表示，如果有边则赋值为1，如果没有边则赋值为0。
设计一个算法，通过这个邻接矩阵直接判断图中任意两个点是否可以连通。
写出你的思想（用自然语言来实现）。

（2）给你一个邻接矩阵，写出用上述算法运行该邻接矩阵的过程，并说明点的可达性。



*/

#include <stdio.h>
#include <stdio.h>
#include "base.h"
using namespace std;

/**
 * （2）用C/C++程序语言写出删除单链表,表头节点的代码。（12分）
 *
 */

void deleteHeadNode(SingleLinkNode *&node)
{

	if (node == NULL)
		return;
		
    SingleLinkNode* head=node;
	node = node->next;
    
	free(head);
	cout << "---end---"<<node->data;
}


/**
 3.
 (1）简述冒泡排序的过程（可以用自然语言）。（8分）



冒泡排序就是不断对比交换的过程。比如例子8, 3, 2, 10, 11。

8，比3大，交换两者位置，得
3, 8, 2, 10, 11。

8，比2大，交换两者位置，得

3, 2, 8, 10, 11。

8，比10小，不交换位置，继续往下走用10继续比较，10比11小。完成第一轮交换。

3, 2, 8, 10, 11。

接着继续比较交换，如果一趟里面没有发生交换，证明数列已经有序。跳出冒泡排序

（2）用一个例子体现快速排序的算法过程。（12分）

{8, 2, 3, 10, 11, 7, 20, 9, 15};

快速排序就是选择一个参考值P，把比参考值大的交换到右边，比参考值小的放在左边。最后确认参考值P的位置。
再不断在剩下没有排序好的数里面，选取参考值。再重复以上的流程。

第1趟 7 2 3 8 11 10 20 9 15

第2趟 3 2 7 8 11 10 20 9 15

第3趟 2 3 7 8 11 10 20 9 15

第4趟 2 3 7 8 9 10 11 20 15

第5趟 2 3 7 8 9 10 11 20 15  

第6趟 2 3 7 8 9 10 11 15 20
 * 
 * @return int 
 */

int main()
{
	SingleLinkNode *node = getSingleLinkNode();
	deleteHeadNode(node);

	return 0;
}