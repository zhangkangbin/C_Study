//算法6.9　克鲁斯卡尔算法

#include <iostream>
using namespace std;

typedef char VerTexType; //假设顶点的数据类型为字符型
typedef int ArcType;
#define MVNum 100	 //最大顶点数
#define MaxInt 32767 //表示极大值，即∞

//----------------图的邻接矩阵---------------------
typedef struct
{
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum;			//图的当前点数和边数
} AMGraph;

//辅助数组Edges的定义
struct
{
	VerTexType Head; //边的始点
	VerTexType Tail; //边的终点
	ArcType lowcost; //边上的权值
} Edge[(MVNum * (MVNum - 1)) / 2];
//辅助数组Vexset的定义
int Vexset[MVNum];

int LocateVex(AMGraph G, VerTexType v)
{
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vexs[i] == v)
			return i;
	return -1;
} // LocateVex

void CreateUDN(AMGraph &G)
{
	//采用邻接矩阵表示法，创建无向网G
	int i, j, k;
	/* 	cout <<"请输入总顶点数，总边数，以空格隔开:";
		cin >> G.vexnum >> G.arcnum;						//输入总顶点数，总边数
		cout << endl; */
	G.vexnum = G.arcnum = 4;

	/* 	cout << "输入点的名称，如a" << endl;
		for(i = 0; i < G.vexnum; ++i){
			cout << "请输入第" << (i+1) << "个点的名称:";
			cin >> G.vexs[i];                        		//依次输入点的信息
		}
		cout << endl;
	 */
	G.vexs[0] = 'a';
	G.vexs[1] = 'b';
	G.vexs[2] = 'c';
	G.vexs[3] = 'd';

	for (i = 0; i < G.vexnum; ++i)
	{
		//初始化邻接矩阵，边的权值均置为极大值MaxInt
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt;
		}
	}

	/* 	cout << "输入边依附的顶点及权值，如a b 6" << endl;
		for(k = 0; k < G.arcnum;++k){						//构造邻接矩阵
			VerTexType v1 , v2;
			ArcType w;
			cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
			cin >> v1 >> v2 >> w;                           //输入一条边依附的顶点及权值
			i = LocateVex(G, v1);  j = LocateVex(G, v2);	//确定v1和v2在G中的位置，即顶点数组的下标
			G.arcs[i][j] = w;								//边<v1, v2>的权值置为w
			G.arcs[j][i] = G.arcs[i][j];					//置<v1, v2>的对称边<v2, v1>的权值为w
			Edge[k].lowcost = w;
			Edge[k].Head = v1;
			Edge[k].Tail = v2;
		}//for
	 */

	G.arcs[0][3] = G.arcs[3][0] = 1;
	Edge[0].lowcost = 1;
	Edge[0].Head = 'a';
	Edge[0].Tail = 'd';

	G.arcs[1][2] = G.arcs[2][1] = 2;
	Edge[1].lowcost = 2;
	Edge[1].Head = 'b';
	Edge[1].Tail = 'c';

	G.arcs[2][0] = G.arcs[0][2] = 3;
	Edge[2].lowcost = 3;
	Edge[2].Head = 'a';
	Edge[2].Tail = 'c';

	G.arcs[1][3] = G.arcs[3][1] = 4;
	Edge[3].lowcost = 4;
	Edge[3].Head = 'b';
	Edge[3].Tail = 'd';

} // CreateUDN

void printData()
{
	cout << "\n------- ";
	for (int i = 0; i < 4; i++)
	{
		cout << Edge[i].lowcost;
	}
	cout << "\n ";
}
//----------冒泡排序-------------------
void Sort(AMGraph G)
{
	int m = G.arcnum - 2;
	int flag = 1;
	//修正算法6.9　克鲁斯卡尔算法源码，辅助数组Edges排序问题 0<m为0<=m。
	while ((0 <= m) && flag == 1)
	{
		flag = 0;
		for (int j = 0; j <= m; j++)
		{
			if (Edge[j].lowcost > Edge[j + 1].lowcost)
			{
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j + 1].Head;
				Edge[j + 1].Head = temp_Head;

				VerTexType temp_Tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j + 1].Tail;
				Edge[j + 1].Tail = temp_Tail;

				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j + 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;

			} // if
		}	  // for
		printData();
		--m;
	} // while

	cout << "\n ";
} // Sort
void printVexset(){
   cout << "\n ";
	for(int i=0;i<4;i++){

   	cout << Vexset[i] << "  ";
	}

	cout << "\n ";

}
void MiniSpanTree_Kruskal(AMGraph G)
{
	//无向网G以邻接矩阵形式存储，构造G的最小生成树T，输出T的各条边
	int i, j, v1, v2, vs1, vs2;

	Sort(G); //将数组Edge中的元素按权值从小到大排序

	for (i = 0; i < G.vexnum; ++i)
	{				   //辅助数组，表示各顶点自成一个连通分量
		Vexset[i] = i; //用于判断顶点是否已连接。
	}

	for (i = 0; i < G.arcnum; ++i)
	{
		//依次查看排好序的数组Edge中的边是否在同一连通分量上
		v1 = LocateVex(G, Edge[i].Head); // v1为边的始点Head的下标
		v2 = LocateVex(G, Edge[i].Tail); // v2为边的终点Tail的下标

		vs1 = Vexset[v1]; //获取边Edge[i]的始点所在的连通分量vs1
		vs2 = Vexset[v2]; //获取边Edge[i]的终点所在的连通分量vs2
		if (vs1 != vs2)
		{ //边的两个顶点分属不同的连通分量

			cout << Edge[i].Head << "-->" << Edge[i].Tail << endl; //输出此边

			for (j = 0; j < G.vexnum; ++j)
			{

				//合并vs1和vs2两个分量，即两个集合统一编号
				if (Vexset[j] == vs2)
				{
					Vexset[j] = vs1; //集合编号为vs2的都改为vs1
				}
			}

		} 

		printVexset();
	}	  
} // MiniSpanTree_Kruskal


void printAll(AMGraph G)
{
	cout << "\n ";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int temp = G.arcs[i][j];
			cout << temp << "  ";
		}
		cout << "\n ";
	}
}
int main()
{
	cout << "************算法6.9　克鲁斯卡尔算法**************" << endl
		 << endl;
	AMGraph G;
	CreateUDN(G);

	printAll(G);

	cout << endl;
	cout << "*****无向网G创建完成！*****" << endl;

	cout << endl;
	MiniSpanTree_Kruskal(G);

	return 0;

} /// main
