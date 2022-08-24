//�㷨5.2 ��������ķǵݹ��㷨
#include<iostream>
using namespace std;

//�������Ķ��������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//��ջ�Ķ���
typedef struct StackNode
{
	BiTNode data;
	struct StackNode *next;
}StackNode,*LinkStack;

//���㷨5.3 ���������˳������������
void CreateBiTree(BiTree &T)
{	
	//�������������������н���ֵ��һ���ַ�������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

void InitStack(LinkStack &S)
{
	//����һ����ջS��ջ��ָ���ÿ�
	S=NULL;
}

bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}

void Push(LinkStack &S,BiTree e)
{
	//��ջ������Ԫ��*e
	StackNode *p=new StackNode;
	p->data=*e;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S,BiTree e)
{
	if(S!=NULL)//ԭ����д����if(S==NULL)return ERROR;
	{	
		*e=S->data;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
} 
  
void InOrderTraverse1(BiTree T)
{ 
  // �������������T�ķǵݹ��㷨
	LinkStack S; BiTree p;
	BiTree q=new BiTNode;
	InitStack(S); p=T;
	while(p||!StackEmpty(S))
	{
		if(p) 
		{            				
			Push(S,p);				//p�ǿո�ָ���ջ������������
			p=p->lchild;
		}       
		else
		{             				
			Pop(S,q);               //pΪ�ո�ָ����ջ�����ʸ���㣬����������
			cout<<q->data;
			p=q->rchild; 
		}
	}								// while
}									// InOrderTraverse

void main()
{
	BiTree tree;
	cout<<"�����뽨���������������У�\n";
	CreateBiTree(tree);
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse1(tree);
	cout<<endl;
}
