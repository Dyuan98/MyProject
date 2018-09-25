//���Ŷ������Ĳ��������������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
typedef struct
{
  unsigned int weight;               // ������Ÿ�������Ȩֵ
  unsigned int parent,lchild,rchild; // ָ��˫�ס����ӽ���ָ��
}HTNode, *HuffmanTree;               // ��̬��������洢���Ŷ�����
typedef char * * HuffmanCode;        // ��̬��������洢�����������
//ѡ��Ȩֵ��С���������
void Select(HuffmanTree   &HT,int  m, int *mindata1,int *mindata2)   
{   
  int i;
	int min;
	for(i=1; i<=m; i++)              //��HT[1..i-1]��ѡ��parentΪ0��weight��С���������
	{  
		if(HT[i].parent == 0)
		{ 
			min = i;
		    i = m+1;
		}
	}
	for(i=1; i<=m; i++)              //ѡ��parentΪ0��weight��С��������㣬 ��һ�����Ϊmindata1	
	{  
		if(HT[i].parent == 0)
		{ 
			if(HT[i].weight < HT[min].weight)
		    min = i;
		}
	}
	*mindata1 = min;
	for(i=1; i<=m; i++)              //��HT[1..i-1]��ѡ��parentΪ0��weight��С���������
	{  
		if(HT[i].parent == 0 && i!=(*mindata1))
		{ 
			min = i;
		    i = m+1;
		}
	}
	for(i=1; i<=m; i++)              //ѡ��parentΪ0��weight��С��������㣬 �ڶ������Ϊmindata2
	{  
		if(HT[i].parent == 0 && i!=(*mindata1))
		{ 
			if(HT[i].weight < HT[min].weight)
		    min = i;
		}
	}
	*mindata2 = min;
}//Select
//�������������
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w,int n) 
{  // w���n���ַ���Ȩֵ(��>0)���������Ŷ�����HT�����n���ַ��Ĺ���������HC
  int i, j, m, mindata1, mindata2, start;
  char *cd;
  unsigned int c, f;
  if (n<=1) return;
  m = 2 * n - 1;
  HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));  // 0�ŵ�Ԫδ��
  for (i=1; i<=n; i++)                               // Ҷ�ӽ���ʼ��������1-n�ŵ�Ԫ
  {                                                  
    HT[i].weight=w[i];
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  for (i=n+1; i<=m; i++)                            // ��Ҷ�ӽ���ʼ��
  { 
    HT[i].weight=0;
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  printf("\n���Ŷ������Ĺ������������ʾ��\n");
  printf("HT��̬:\n  ���  weight  parent  lchild  rchild");
  for (i=1; i<=m; i++)                             //��ɹ������Ŷ������㷨�ĵ�1������
    printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,
            HT[i].parent,HT[i].lchild, HT[i].rchild);
    printf("    ������������� ...");
  getch();
  // �������Ŷ�����HT
  for (i=n+1; i<=m; i++) 
  {  
  
    Select(HT, i-1, &mindata1, &mindata2);                    //��HT[1..i-1]��ѡ��parentΪ0��weight��С���������
    HT[mindata1].parent = i;  HT[mindata2].parent = i;
    HT[i].lchild = mindata1;  HT[i].rchild = mindata2;        //��ѡȡ�����Ȩֵ��С������Ϊ��������
    HT[i].weight = HT[mindata1].weight + HT[mindata2].weight;
    printf("\nselect: mindata1=%d   mindata2=%d\n", mindata1, mindata2);  //�����Ȩֵ��С������HT�е�λ��
    printf("  ���  weight  parent  lchild  rchild");
    for (j=1; j<=i; j++)                          //���ѡȡ�����Ȩֵ��С�����Ĺ���
      printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,
             HT[j].parent,HT[j].lchild, HT[j].rchild);
    printf("    ������������� ...");
    getch();
  }
  printf("\n%d���ַ��Ĺ������������£�\n",n);
  //��Ҷ�ӵ���������ÿ���ַ��Ĺ���������
  HC=(HuffmanCode)malloc((n+1)*sizeof(char *));  //����n�������ͷָ��
  cd = (char *)malloc(n*sizeof(char));           //���������Ĺ����ռ�
  cd[n-1] = '\0';                                //�����������
  for (i=1; i<=n; ++i) {                         //����ַ������������
    start = n-1;                                 //���������λ��
    for (c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent) //��Ҷ�ӵ������������
      if (HT[f].lchild==c) cd[--start] = '0';
      else cd[--start] = '1';
    HC[i] = (char *)malloc((n-start)*sizeof(char));      //Ϊ��i���ַ��������ռ�
    strcpy(HC[i], &cd[start]);                           //��cd���Ʊ���(��)��HC
  }                                                       
  free(cd);                                              //�ͷŹ����ռ�
  for(i=1;i<=n;i++)
		printf("Ȩֵ<%2d>����:%s\n",HT[i].weight,HC[i]);
} // HuffmanCoding

//������
void   main()   
{   
	system("color f0");
	HuffmanTree   myHuffmanTree;   
    HuffmanCode   myHuffmanCode; 
    int *w,i; 
	int n;         // �������
	int wei;       // Ȩֵ 
	printf("��������Ҫ������������ַ�����:" ); 
	scanf("%d",&n); 
	w=(int *)malloc((n+1)*sizeof(int)); 
	for(i=1;i<=n;i++)
	{ 
		printf("������� %d �ַ���Ȩֵ:",i); 
		fflush(stdin);
		scanf("%d",&wei); 
		w[i]=wei; 
	}   
    
    HuffmanCoding(myHuffmanTree,myHuffmanCode,w,n); 
  
}   
