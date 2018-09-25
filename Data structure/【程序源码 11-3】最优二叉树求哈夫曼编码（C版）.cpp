//最优二叉树的产生与哈夫曼编码
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
typedef struct
{
  unsigned int weight;               // 用来存放各个结点的权值
  unsigned int parent,lchild,rchild; // 指向双亲、孩子结点的指针
}HTNode, *HuffmanTree;               // 动态分配数组存储最优二叉树
typedef char * * HuffmanCode;        // 动态分配数组存储哈夫曼编码表
//选择权值最小的两个结点
void Select(HuffmanTree   &HT,int  m, int *mindata1,int *mindata2)   
{   
  int i;
	int min;
	for(i=1; i<=m; i++)              //在HT[1..i-1]中选择parent为0且weight最小的两个结点
	{  
		if(HT[i].parent == 0)
		{ 
			min = i;
		    i = m+1;
		}
	}
	for(i=1; i<=m; i++)              //选择parent为0且weight最小的两个结点， 第一个序号为mindata1	
	{  
		if(HT[i].parent == 0)
		{ 
			if(HT[i].weight < HT[min].weight)
		    min = i;
		}
	}
	*mindata1 = min;
	for(i=1; i<=m; i++)              //在HT[1..i-1]中选择parent为0且weight最小的两个结点
	{  
		if(HT[i].parent == 0 && i!=(*mindata1))
		{ 
			min = i;
		    i = m+1;
		}
	}
	for(i=1; i<=m; i++)              //选择parent为0且weight最小的两个结点， 第二个序号为mindata2
	{  
		if(HT[i].parent == 0 && i!=(*mindata1))
		{ 
			if(HT[i].weight < HT[min].weight)
		    min = i;
		}
	}
	*mindata2 = min;
}//Select
//构造哈夫曼编码
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w,int n) 
{  // w存放n个字符的权值(均>0)，构造最优二叉树HT并求出n个字符的哈夫曼编码HC
  int i, j, m, mindata1, mindata2, start;
  char *cd;
  unsigned int c, f;
  if (n<=1) return;
  m = 2 * n - 1;
  HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));  // 0号单元未用
  for (i=1; i<=n; i++)                               // 叶子结点初始化并放入1-n号单元
  {                                                  
    HT[i].weight=w[i];
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  for (i=n+1; i<=m; i++)                            // 非叶子结点初始化
  { 
    HT[i].weight=0;
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  printf("\n最优二叉树的构造过程如下所示：\n");
  printf("HT初态:\n  结点  weight  parent  lchild  rchild");
  for (i=1; i<=m; i++)                             //完成构造最优二叉树算法的第1个步骤
    printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,
            HT[i].parent,HT[i].lchild, HT[i].rchild);
    printf("    按任意键，继续 ...");
  getch();
  // 建立最优二叉树HT
  for (i=n+1; i<=m; i++) 
  {  
  
    Select(HT, i-1, &mindata1, &mindata2);                    //在HT[1..i-1]中选择parent为0且weight最小的两个结点
    HT[mindata1].parent = i;  HT[mindata2].parent = i;
    HT[i].lchild = mindata1;  HT[i].rchild = mindata2;        //将选取根结点权值最小的树作为左右子树
    HT[i].weight = HT[mindata1].weight + HT[mindata2].weight;
    printf("\nselect: mindata1=%d   mindata2=%d\n", mindata1, mindata2);  //根结点权值最小的树在HT中的位置
    printf("  结点  weight  parent  lchild  rchild");
    for (j=1; j<=i; j++)                          //输出选取根结点权值最小的树的过程
      printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,
             HT[j].parent,HT[j].lchild, HT[j].rchild);
    printf("    按任意键，继续 ...");
    getch();
  }
  printf("\n%d个字符的哈夫曼编码如下：\n",n);
  //从叶子到根逆向求每个字符的哈夫曼编码
  HC=(HuffmanCode)malloc((n+1)*sizeof(char *));  //分配n个编码的头指针
  cd = (char *)malloc(n*sizeof(char));           //分配求编码的工作空间
  cd[n-1] = '\0';                                //编码结束符。
  for (i=1; i<=n; ++i) {                         //逐个字符求哈夫曼编码
    start = n-1;                                 //编码结束符位置
    for (c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent) //从叶子到根逆向求编码
      if (HT[f].lchild==c) cd[--start] = '0';
      else cd[--start] = '1';
    HC[i] = (char *)malloc((n-start)*sizeof(char));      //为第i个字符编码分配空间
    strcpy(HC[i], &cd[start]);                           //从cd复制编码(串)到HC
  }                                                       
  free(cd);                                              //释放工作空间
  for(i=1;i<=n;i++)
		printf("权值<%2d>编码:%s\n",HT[i].weight,HC[i]);
} // HuffmanCoding

//主函数
void   main()   
{   
	system("color f0");
	HuffmanTree   myHuffmanTree;   
    HuffmanCode   myHuffmanCode; 
    int *w,i; 
	int n;         // 编码个数
	int wei;       // 权值 
	printf("请输入需要哈夫曼编码的字符个数:" ); 
	scanf("%d",&n); 
	w=(int *)malloc((n+1)*sizeof(int)); 
	for(i=1;i<=n;i++)
	{ 
		printf("请输入第 %d 字符的权值:",i); 
		fflush(stdin);
		scanf("%d",&wei); 
		w[i]=wei; 
	}   
    
    HuffmanCoding(myHuffmanTree,myHuffmanCode,w,n); 
  
}   
