/*
2014-07-27
glen�޸ļ�¼��
1.������ȫ������           ���
2.�˵��޸�                   ���
3.�ڲ�������������           ���
4.�ļ�������ʱ���Բ�����.txt ���
5.�����ļ��б�ֻ��Ҫ�ṩһ�� ���
6.�����Ƿ��Ȩ�����ֱ������� ���
7.���·���޸���ϣ����Ƿ��ֶ��ڷ���ͨͼ��Ѳ�ͨ�����ֵ99999��ʾ�������Ѿ������ ���



Ŀǰ��Ҫ����������ǣ�
1.�ļ�����ʱ����ֻ�е�û�бߵ����������û�п��ǡ�
���ⰴ��Ŀǰ��������º���ڱߵ�ͳ�ƺ������Ƕ�2��������ڹ����������ݵ���һ�У����¶������
���������Ҳû�е�������ƺ�Ҳ��ü��Կ���һ�¡�
���������к����ʵ��޸���Ļ��ʾ��
�����ʼ��һ�У�����ַ���Խ�磬�����ܷ���


2.���������ļ�
����ܹ���ע��//�͸��� ���ÿһ��ǰ���пո�Ҳ���Թ��˾͸���
����ܹ��˶���ע�;͸��� ���ÿһ��ǰ���пո�Ҳ���Թ��˾͸���

3.������������������һ��ѯ�ʱ�������ھ͸���  

4.������С������������Ҫ�������ǣ������ĸ�����Ŀ�����Щʧ�أ���Ҫ���о�һ�¡�
  ���е���ĸСдת���ɴ�д�����Ƿ���Ҫ������һ�£�ԭ�����Ǹ��ǻ��������Ǵ�д��ĸ���û���������ʱ����ΪСд��ĸ

5.���ͼ����ͨ������ʱֻ����ʾ�ͽ������йص���ͨ��������������ʾ����ͼ����ͨ�͸����ˣ���Ҫ��Ҫ�������ʱͬʱ���������⡣


*/
/*����������
����ͼ�ĳ�������ʵ�֣��洢�ṹʹ���ڽӾ���
ע�⣺����ֻ�ܴ��ı��ļ����룬ÿ����ֻ��Ҫ�洢һ�Ρ�
�磺b---a---c
������Ϊ��
a b c
0 1 10
0 2 20
Ȩֵ����¼�룬���Ϊ��Ȩ����ͼ��Ȩֵȫ����1����
���վͽ�ԭ��ĳ�����ݽṹ�ĺ���������ʵ�־�������һ��

*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

#define MaxListSize 26         //Լ����˳������ֻ��26����ĸ
#define maxsize 26             //����ʹ�õ������С
#define maxvertices 26         //������������ֵΪ26 
#define maxweight 99999        //���������֮�䲻���ڱ�ʱ�����������99999��ģ��
#define defaultfile "�����ļ�����ͼ�̲�ʹ��1.txt"//Ĭ�������ļ�
enum returninfo {success,fail,overflow,underflow,range_error,quit,error,dataError};	//���巵����Ϣ�嵥
int ifbuild;                     //���ڼ�¼�Ƿ�����ͼ��Ϊ0ʱ��ʾû�н�����ͼ��Ϊ1ʱ��ʾ�Ѿ�������ͼ
/************************************************************/
//˳���:ͼ�Ľ����˳������洢������ʵ�ֽ��Ķ�̬��ɾ����
char node[MaxListSize];            //����0���꣬��0-25������
int size=0;                          //˳����ʵ�ʴ�С
//˳�����غ�������
void initList();                    //˳���ĳ�ʼ������
int  ListSize();                   //��˳���Ľ������ĺ���
int  ListEmpty();                  //�ж�˳����Ƿ�Ϊ�յĺ���
int  Find(char item);              //����ĳ�����ĺ���
char Getdata(int pos);             //��ȡĳ��λ�ý��ĺ���
void Insert(char item,int pos);    //����һ����㵽˳�����
int  Delete(int pos);              //��˳�����ɾ��һ�����
void ClearList();                  //��������˳���
//˳�����غ���ʵ��
void initList()//˳���ĳ�ʼ������
{
	size=0;
}
int ListSize()//��˳���Ľ������ĺ���
{
	return size;
}
int ListEmpty()//�ж�˳����Ƿ�Ϊ�յĺ���
{
	if(size==0)
		return 1;
	else
		return 0;
}
int Find(char item)//����ĳ�����ĺ���
{
	int i=0;
	if(size==0)
	{
		return -1;
	}
	while(i<size && item!=node[i])
	{i++;}
	if(i<size)
	{
		return i;
	}
	else return -1;
}
char Getdata(int pos)//��ȡĳ��λ�ý��ĺ���
{
	if(pos<0||pos>size-1)
	{
		printf("�Բ���!λ�ò���Խ�����!\n");
		return  FALSE;
	}
	return node[pos];
}
void Insert( char item,int pos)//����һ����㵽˳�����
{
	int i;
	if(size==MaxListSize)
	{
		printf("˳��������޷�����!\n");
		return;
	}
	else if(pos<0||pos>size)//���������һ��Ԫ���ұ��ǺϷ���
	{
		
		printf("�Բ���!λ�ò���Խ�����!\n");
		return;
	}
	else
	{
		for(i=size;i>pos;i--)
		{
			node[i]=node[i-1];
		}
		node[pos]=item;
		size++;
	}
}
int Delete(int pos)//ɾ��һ��Ԫ��
{
	int i;
	char temp;
	if(size==0)
	{
		printf("˳����ѿ��޷�ɾ��!\n");
		return 0;
	}
	else if(pos<0||pos>size-1)
	{
		printf("�Բ���!λ�ò���Խ�����!\n");
		return 0;
	}
	else
	{
		temp=node[pos];
		for(i=pos;i<size-1;i++)
		{
			node[i]=node[i+1];
		}
		size--;
		return 1;
	}
}
void ClearList()//��������˳���
{
	size=0;
}
/************************************************************/
//����:���ͼ�Ĺ�����ȱ���
char queuedata[maxsize];           //��������
int  front;                        //�������
int  rear;                         //�����β
int  count;                        //���������ʵ��Ԫ�ظ���������
//������غ�������
void initQueue();                  //���г�ʼ��
int  isempty();                    //�ж϶����Ƿ�Ϊ��
void enqueue(char item);           //Ԫ����Ӻ���
char dequeue();                    //���Ӻ���
void showseq();                    //��������
void getfront();                   //����ͷ���ĺ���
//������غ���ʵ��
void initQueue()//���г�ʼ��
{
	//Լ��rear+1=frontʱΪ���������������ܵĿ��Դ���Ԫ�صĿռ�Ϊmaxsize-1
	front=0;//��ͷ��ʼֵ����Զָ��ʵ�ʶ�ͷ
	rear =0;//��β��ʼֵ����Զָ����ÿռ�ĵ�һ����ַ
	count=0;//��������ʼΪ0
}
void enqueue(char item)//�������
{
	if(front==(rear+1)%maxsize)//������������
	{
		printf("�Բ���!��������!�޷����!\n");
	}
	else
	{
		queuedata[rear]=item;//����Ԫ�شӶ�β���
		rear=(rear+1)%maxsize;//��β�ȼ�һ��ȡģ
		count++;//��������һ
	}
}
char dequeue()//ɾ����������
{
	char datatemp;
	if(count==0)//����Ϊ�յ�����
	{
		printf("�Բ���!�����ѿ�!�޷�ɾ��!\n");
		return FALSE;
	}
	else
	{
		datatemp=queuedata[front];//����Ԫ�شӶ�ͷ����
		front=(front+1)%maxsize;//��ͷ����
		count--;//Ԫ�ظ�����һ
		return datatemp;
	}
}
int  isempty()
{
	return front==rear;
}
void showseq()//��ʾ����Ԫ��
{
	int i;
	printf("����ȫ��Ԫ������:\n");
	for(i=front;i!=rear;)//��front��ʼ����
	{
		printf("  %c",queuedata[i]);
		i=(i+1)%maxsize;
	}
	printf("��ǰԪ�ظ���Ϊ: %d\n",count);
	
}
void getfront()//�õ�����ͷ��Ԫ��
{
	if(count==0)//����Ϊ�յ�����
	{
		printf("�Բ���!�����ѿ�!\n");
		return;
	}
	else
	{
		printf("��ͷ��Ԫ�ص�ֵΪ :%d\n",queuedata[front]);
	}
}
/************************************************************/
//ͼ������ͼ�Ļ������ݽṹ
//�������壺
//int flag;											//��־λ
int numofedges=0;									//��¼�ߵ�����
char *nodearray;									//������ʱʹ�õ�һά����
int Edge[maxvertices][maxvertices];					//ͼ�ı���Ϣ,ʹ���˶�ά���飬��һ������
//ע��ʵ�ʱߵ�����ֻ�õ��˱���������Ͻǵ�һ������ 
//ͼ��غ�������
//void graph(int size);								
void initializationofEdge(int size);				//�ߵ��ڽӾ����ʼ�� 
void showVertex();									//��ʾͼ�Ľ��
void showgraph();									//��ʾͼ���ڽӾ���
int  graphempty(){return ListEmpty();}				//�ж�ͼ�Ľ�������Ƿ�Ϊ��
int  numofVertices(){return ListSize();}			//��ͼ�Ľ�����
int  numofEdges(void){return numofedges;}			//��ͼ�ı���
char getvalue(int i);								//��ȡͼĳ������ֵ
int  getweight(int nodestart,int nodeend);			//���������֮��ıߵ�Ȩֵ
void insertVertices(char vertices);					//��ͼ�����һ�����
int  deleteVertex(int v);							//ɾ��һ�����
int  insertEdge(int nodestart,int nodeend,int weight);//���һ����
int  deleteEdge(int nodestart,int nodeend);			//ɾ��һ����
int  getfirstneighbor(int v);                       //Ϊʵ��ͼ�ı������������ȡ���һ�����ڽ��ĺ���
int  getnextneighbor(int nodestart,int nodeend);	//��ȡ����һ�����ڽ��ĺ���
void depthfirstsearch(int v,int visited[],void visit(char item));//������ȱ���
void breadthfirstsearch(int v,int visited[],void visit(char item));//������ȱ���
void showmenu();//�˵���ʾ����
void processmenu();//ִ��ָ������
//ͼ����غ���ʵ��
//void graph(int size)//ͼ�ĳ�ʼ������
//{
//	initializationofEdge(maxvertices); 
//}
void initializationofEdge(int size)  //�ߵ��ڽӾ����ʼ��
{
	int i,j;
	for(i=0;i<size;i++)//�ڽӾ���ĳ�ʼ��
	{
		for(j=0;j<size;j++)
			if(i==j)
			{
				Edge[i][j]=0;//������ͬ���֮��ıߵ�ȨֵΪ0
			}
			else
				Edge[i][j]=maxweight;//��ʼ״̬��ͬ���֮�䲻���ڱ�
	}
	numofedges=0;//��ʼ״̬�ߵ�����Ϊ0
}
void showgraph()//ͼ����ʾ����
{
	int i,j;
	for(i=0;i<ListSize();i++)//���ڽӾ�����ģ��ͼ�ıߵ������Ϣ
	{
		for(j=0;j<ListSize();j++)
		{
			if(i!=j&&getweight(i,j)==maxweight)
				printf("   ��");//��ʾ�������֮��û�б�
			else
				printf("%5d",getweight(i,j));
		}
		printf("\n");
	}
}
void showVertex()//��ʾͼ�����н�㣨���Ա�
{
	int i;
	for(i=0;i<ListSize();i++)//��ʾ����
		printf("%5d",i);
	printf("\n");
	for(i=0;i<ListSize();i++)//��ʾ����
		printf("%5c",Getdata(i));
	printf("\n");
}
char getvalue(int i)//��ȡͼ��ĳ������ֵ
{
	if(i<0||i>ListSize())
	{
		printf("�Բ������Խ�����!\n");
		return FALSE;
	}
	else
		return Getdata(i);//ͨ��˳�������귵����Ӧ�ıߵ������ַ�
}
int getweight(int nodestart,int nodeend)//���������֮��ıߵ�Ȩֵ
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("�Բ������Խ�����!\n");
		return FALSE;
	}
	else
		return Edge[nodestart][nodeend];
}
void insertVertices(char vertices)//���һ�����
{
	Insert(vertices,ListSize());//Ϊ�˼򵥰���ӽ�����˳�������λ��
}
int deleteVertex(int v)//ɾ��һ�����
{
	int i,j,flag;
	for(i=0;i<ListSize();i++)//ɾ������������������������ȫ���ı�����ɾ��
		for(j=0;j<ListSize();j++)
		{
			if(i==v||j==v && Edge[i][j]>0 && Edge[i][j]<maxweight)
			{
				Edge[i][j]=maxweight;
				numofedges--;
			}
		}
		flag=Delete(v);
		if(flag==1)//�ṩһ����־λΪ����ĵ��÷���
			return 1;
		else
			return 0;
}
int insertEdge(int nodestart,int nodeend,int weight)//���һ����
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("�Բ��𣬲���Խ�����!\n");
		return 0;
	}
	else
	{
		Edge[nodestart][nodeend]=weight;
		Edge[nodeend][nodestart]=weight;
		numofedges++;
		return 1;
	}
}
int deleteEdge(int nodestart,int nodeend)//ɾ��һ����
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("�Բ��𣬲���Խ�����!\n");
		return 0;
	}
	else
	{
		Edge[nodestart][nodeend]=maxweight;
		numofedges--;
		return 1;
	}
}
int getfirstneighbor(int v)//��ȡ���һ�����ڽӱ�
{
	int col;
	if(v<0||v>ListSize())
	{
		printf("�Բ��𣬲���Խ�����!\n");
		return FALSE;
	}
	else
	{
		for(col=0;col<=ListSize();col++)
		{
			if(Edge[v][col]>0 && Edge[v][col]<maxweight)
				return col;//���������ڵĽ�㷵�����±�
		}
		return -1;//û���ҵ��򷵻�-1
	}
}
int getnextneighbor(int nodestart,int nodeend)//��ȡ����һ���ڽӱ�
{
	int col;
	//�ҽ��nodestart��<nodestart,nodeend>�ڽӱߵ���һ���ڽӱ�
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("�Բ��𣬲���Խ�����!\n");
		return FALSE;
	}
	else
	{//ʹcolΪnodeend+1���Ѱ�ҵı���nodestart��<nodestart,nodeend>�ڽӱߵ���һ���ڽӱ�
		for(col=nodeend+1;col<=ListSize();col++)
		{
			if(Edge[nodestart][col]>0 && Edge[nodestart][col]<maxweight)
				return col;
		}
		return -1;//û���ҵ��򷵻�-1
	}
}
void printchar(char item)
{
	printf("%5c",item);
}
/************************************************************/
void depthfirstsearch(int startpoint,int visited[],void visit(char item))//������ȱ���
{



}
void breadthfirstsearch( int startpoint,int visited[],void visit(char item))//������ȱ���
{




}

/************************************************************/
//���ļ�����������
returninfo readfile(char *filename);//���ļ��е�����
//���ļ�������ʵ��
returninfo readfile(char *filename)
{
	FILE *in;
	ClearList();                         //������Ա�ĳ�ʼ�������
	initializationofEdge(maxvertices);   //�ߵĳ�ʼ�������
	char txt[]=".txt";
	int flagtxt=0;//��־λ��Ϊ0ʱ��ʾ�Ѿ��к�׺.txt
    int tempposi=0,tempposj=0;//����һ�����������׺
	char temp;//�ݴ���
	int  tempdata[300];//�ݴ��ϵ��㼰Ȩֵ
	bool flag=true;//��־λ trueʱΪ�����ַ���һ����ת״̬λ���������ߵ���Ϣ
	tempposi = strlen(filename)-4; //�ҵ��������ĸ�λ��
//********************************************************************************
	char content[1000];
	int i=0,j=0,k=0;//����������ѭ��
	int total=0;//��content���������
	int tempInt=0;//��ʱ�洢int������
	int position;//λ��
//***********************************************************************************
	while(filename[tempposi++] != txt[tempposj++] && tempposj<4)
	{
		flagtxt = 1;
		break;
	}
	if(flagtxt == 1)
			strcat(filename,".txt");
	if(!(in=fopen(filename,"r")))//�ļ��򲻿��򲻴���
		return  fail;
	numofedges=0;//������ʼ��Ϊ0
	while(!feof(in))
	{		
		fscanf(in,"%c",&temp);
		if(temp=='/')
		{
			fscanf(in,"%c",&temp);
			if(temp!='/')
			{
				printf("�Բ��������ļ��д�!����ʧ��!ֻ��һ����/��\n");
				return dataError;
			}
			else
			{
				while(temp!='\n')
					fscanf(in,"%c",&temp);
			}
		}
		else if((int)temp>255||(int)temp<0)
		{
			printf("�Բ��������ļ��д�!����ʧ��!\n");
				return dataError;
		}
		else
		{
			content[total++]=temp;
		}
	}
	fclose(in);//�ر��ļ�
	content[total-1]=' ';
	i=0;
	while(i<total)
	{
		if(content[i]>='a'&&content[i]<='z'||content[i]>='A'&&content[i]<='Z')
		{
			insertVertices(content[i]);
			i++;
		}
		else if(content[i]>='0'&&content[i]<='9')
		{
			tempInt=0;//��ʼ��Ϊ0
			position=i;//�������ݿ�ʼλ��
			i++;
			while(content[i]!=' '&&content[i]!='\n')
				i++;
			for(j=i-position-1;j>=0;j--)//���ַ�ת��Ϊ�ɼ������ֵ
			{
				tempInt+=((int)content[position++]-48)*pow(10,j);
			}
			tempdata[k++]=tempInt;	
			i++;
		}
		else if(content[i]==' '&&content[i+1]>='0'&&content[i+1]<='9')//���ǿո�������ֵ����
		{
			tempInt=0;//��ʼ��Ϊ0
			position=i+1;//�������ݿ�ʼλ��
			i+=2;//��Ϊǰ���жϹ�һ�����������2
			while(content[i]!=' '&&content[i]!='\n')
				i++;			
			for(j=i-position-1;j>=0;j--)//���ַ�ת��Ϊ�ɼ������ֵ
			{
				tempInt+=((int)content[position++]-48)*pow(10,j);
			}
			tempdata[k++]=tempInt;	
			i++;
		}
		else if(content[i]=='\n'&&content[i+1]>='0'&&content[i+1]<='9')//���ǻس��������ֵ����
		{
			tempInt=0;//��ʼ��Ϊ0
			position=i+1;//�������ݿ�ʼλ��
			i+=2;//��Ϊǰ���жϹ�һ�����������2
			while(content[i]!=' '&&content[i]!='\n')
				i++;
			for(j=i-position-1;j>=0;j--)//���ַ�ת��Ϊ�ɼ������ֵ
			{
				tempInt+=((int)content[position++]-48)*pow(10,j);
			}
			tempdata[k++]=tempInt;	
			i++;
		}
		else 
			i++;
	}
	if(k%3!=0)
	{
		printf("�Բ��������ļ��д�!����ʧ��!\n");
		return dataError;
	}
	else
	{
		for(i=0;i<k;i++)
		{
			insertEdge(tempdata[i],tempdata[i+1],tempdata[i+2]);
			i+=2;
		}
	}
	ifbuild=1;
	return success;
}




/************************************************************/
//�����·��ʹ�õı���
int v0;												//���·������ʹ�õ����
int *distance,*path;								//������·������ʹ�õľ��������·������
//�����·���ĺ�������
void dodijkstra();                                  //�������·�����������
void dijkstra(int v0,int distance[],int path[]);    //�����·����������������㡢�������顢·������
//�����·���ĺ���ʵ��
void dodijkstra()//�������·�����������
{
	int *distance;
	int i;//ѭ��ʹ��
	distance=(int *)malloc(ListSize());			//��������
	path=(int *)malloc(ListSize());				//·������
	printf("���濪ʼ��ĳ����㵽����������̾���...\n");
	printf("���������ţ�0~%d\n",ListSize()-1);//��ʾ�������
	scanf("%d",&v0);//�������
	if(v0>=0 && v0<=ListSize())			//����Ų�����ȷ
	{
		dijkstra(v0,distance,path);			//����ʵ�����·������
		printf("�ӽ��%c��������������̾���Ϊ:\n",getvalue(v0));
		for(i=0;i<ListSize();i++)
			if(distance[i]==0)
				printf("�����%c����̾���Ϊ:0\n",getvalue(i));
			else
			if(distance[i]==maxweight)
				printf("�����%c����̾���Ϊ������ͨ��\n",getvalue(i));

			else
				printf("�����%c����̾���Ϊ:%d\n",getvalue(i),distance[i]);
			printf("\n");
			printf("Ѱ��·������:\n");
			printf("�ӽ��%c��������������·������һ�����Ϊ:\n",getvalue(v0));
			for(i=0;i<ListSize();i++)
			{
				if(path[i]!=-1)
					printf("�����%c����һ�����Ϊ:%c\n",getvalue(i),getvalue(path[i]));
			}
	}
	else
	{
		printf("�Բ���!����������!���������������\n");
	}
}
void dijkstra(int v0,int distance[],int path[])//�����·����������������㡢�������顢·������
{
	int nodenumnow;	
	nodenumnow=numofVertices();			//ȡ�ؽ�����
	int *mark=new int[nodenumnow];		//��־λ����
	int mindis,nextnode;					//���·������һ�����
	int i,j;								//ѭ������
	for(i=0;i<nodenumnow;i++)				//��ʼ��
	{
		distance[i]=getweight(v0,i);		//��һ�־��������¼����ʼ�㵽�������е�ı�Ȩֵ
		mark[i]=0;							//���б�־λ����
		if(i!=v0 && distance[i]<maxweight)	//�����ʼ�����Եִ�ĳ�����
			path[i]=v0;						//��Ѹý�����ȷ���·������
		else
			path[i]=-1;						//-1�����·����ͨ
	}
	mark[v0]=1;								//�����ı�־λ��תΪ1
	for(i=1;i<nodenumnow;i++)				//�ڻ�û���ҵ����·���Ľ�㼯����ѡȡ��̾�����nextnode
	{
		mindis=maxweight;					//����Լ����С����Ϊ�����
		for(j=0;j<=nodenumnow;j++)		//ɨ���������е�
		{
			if(mark[j]==0 && distance[j]<mindis)//���û�н������·���Ҿ���С����С����
			{
				nextnode=j;					//��¼���α߶���ĵ�
				mindis=distance[j];			//��¼�������·��
			}
		}
		if(mindis==maxweight)				//��������·��ʱ�㷨����
		{
			return;
		}
		mark[nextnode]=1;//��ǽ��nextnode�Ѿ��ŵ����ҵ����·���ĵļ�����
		for(j=0;j<nodenumnow;j++)//�޸Ľ��v0�������Ľ����̵ľ���
		{
			if(mark[j]==0 && getweight(nextnode,j)<maxweight			
				&& distance[nextnode]+getweight(nextnode,j)<distance[j])//�����µ����·��
			{
				distance[j]=distance[nextnode]+getweight(nextnode,j);   //ˢ�����·��
				path[j]=nextnode;										//�Ѹõ����·��
			}
		}
	}
}
//�����·���ĺ���ʵ��


/************************************************************/
//������С�����������ݽṹ��������
int	  flag[MaxListSize]={0};                    //��ʼ����־λȫ��Ϊ0
int   delflag[MaxListSize]={0};                 //��ʼ���Ѿ�ɾ�����ı�־λΪ0
void  clearlist(struct linklist* &list);       //�������
bool  empty(struct linklist list);   //�Ƿ����
//��㶨��
struct nodelink     //����һ��node����ʾ�ߵ���Ϣ
{
    int pointstart;		                    //�ߵ���㡾Լ��ASCII��С��
	int pointend; 	               		    //�ߵ��յ㡾Լ��ASCII���
	int weight;			                    //�ߵ�Ȩֵ
	nodelink *next;				            //��̽��ָ��
};
//�������嶨�壺������ͼ�����
struct linklist     //��������linklist��
{
	struct nodelink *headp; 
	int number;    //ͳ��ÿ�������н��ĸ���
};

linklist list[4];
//��������0��1��ʾPrim�㷨�ĳ�ʼ��������ս������
//������2��3��ʾKruskal�㷨�ĳ�ʼ��������ս������

//��ĸת������������
char letterchange(char nodenameofedge);	//Сд��ĸ���ɴ�д��Ϣ

returninfo kruskal(); //kruskal�㷨
returninfo prim();    //prim�㷨

//������С�������ĺ���ʵ��
void clearlist(struct linklist* &list)       //�������
{
	struct nodelink *searchp=list->headp->next,*followp=list->headp;    //��ʼ������ָ��//struct nodelink *searchp=list.headp->next,*followp=list.headp; 
	while(searchp!=NULL)
	{
		followp=searchp;
		searchp=searchp->next;
		delete followp;
	}
	list->headp->next=NULL;              //������ͷ��㣬����������Ϊ��
	list->number=0;                      //������Ҳ����
}
bool empty(struct linklist list)   //�Ƿ����
{
	if(list.number==0)
		return true;
	else
		return false;
}
//��ĸת��������ʵ��
char letterchange(char nodenameofedge) //����������ĸ��Ϣ�����Сд����д��
{
	char nodenameofedgenow;
    nodenameofedgenow=nodenameofedge;
	if(nodenameofedgenow>='a' && nodenameofedgenow<='z')
		return char(nodenameofedgenow-32);    //Сд����д
	else if(nodenameofedgenow>='A' && nodenameofedgenow<='Z')
		return nodenameofedgenow;         //��д�򲻸�
	else
		return 0;            //��ʾ����������д�
}
//Prim������ʼ
returninfo prim()
{
	//����list[4]������0��1�������ڱ�ʾprim�㷨�ĳ�ʼ��������ս������
	//clearlist(list[0]);//ÿ�ε����㷨ǰ����ʼ�������������
	//list[1].clearlist();  
	linklist *temp=&list[0];
	clearlist(temp);
	temp=&list[1];
	clearlist(temp);

	char beginnode;//����������
//	node *newnode,*searchp,*followp,*listrear;//�½�㡢����ָ�롢β��ָ�롢β��ָ��
/*	int i,j;//ѭ������
	int nodeflag=0;//����־λ
  	for(i=0;i<numofVertices();i++)     //��־λ����
		flag[i]=0;
	//cout<<"�������淶Χ��������ʼ������ơ�A-"<<char('A'+nodenumber-1)<<"����";
	//cin>>beginnode;
	beginnode=letterchange(beginnode);    //Сдת���ɴ�д
	if(beginnode==0) //������������
		return error;
	i=int(beginnode-'A');//���������������
    flag[i]=1;       //�Ѹ���Ŵ������ʼ��ı�־λ��תΪ1
	while(list[1].number!=numofVertices()-1-deletenumber)//������һ������deletenumber��ʱ��֪����ʲô
	{
		for(j=0;j<numofVertices();j++)
			if(Edge[i][j]!=0)    //i�̶����䣬�������е���ȫ����һ�� �������Ҹ�Ϊ��Edge
			//����ڽӾ�����Ȩֵ��Ϊ0,��Ѹñ߼ӵ�������
			{
				newnode=new node(i+'A',j+'A',Edge[i][j]);//����д�����Ӧ�Ľ������Ȩֵ
				if(list[0].empty()) //�����ʱ����Ϊ��
				{
					newnode->next=NULL;
					list[0].headp->next=newnode;
					list[0].number++;
				}
				else
				{
					//����������Ѿ����ڵĻ������������
					searchp=list[0].headp->next;//��������ָ��
					followp=list[0].headp;      //����β��ָ�� 
					while(searchp!=NULL && searchp->weight<Edge[i][j])//�������У�����ȷλ��
					{
						followp=searchp;
						searchp=searchp->next;
					}
					while(searchp!=NULL && searchp->weight==Edge[i][j])//������Ȩֵ���ʱ
					{
						if(searchp->pointstart==i+'A' && searchp->pointend==j+'A')//����յ�Ҳ��ͬ
						{
							nodeflag=1;
							delete newnode;//�ͷ��½��
							break;
						}
						searchp=searchp->next;//�����ƶ�ָ��
					}
					if(followp!=NULL && nodeflag==0)
					{
						newnode->next=followp->next;//�����½�㵽������
						followp->next=newnode;
						list[0].number++;			//��������һ
						nodeflag=0;					//���¹���
					}
				}
			}
		if(list[0].number==0 )
		{	if(delflag[i]==1)
			{
			//	cout<<endl<<"������Ľ�� "<<char(i+'A')<<" �ѱ�ɾ��!"<<endl;
			//	cout<<endl<<"����ܰ��ʾ��"<<endl
			//		<<"	1.��־ֵΪ0��ʾΪ��δѡ��Ľ���Ⱥ��"<<endl
			//		<<"	2.��־ֵΪ1��ʾ�ѱ�ѡ��Ľ��Ⱥ��"<<endl
			//		<<"	3.��־ֵΪ �| ��ʾ��ɾ�����Ⱥ��"<<endl<<endl;
				failflag();          //��ʾ��־λ��Ϣ
				return error;
			}
			//cout<<endl<<"����ܰ��ʾ��"<<endl
			//	<<"	1.��־ֵΪ0��ʾΪ��δѡ��Ľ���Ⱥ��"<<endl
			//	<<"	2.��־ֵΪ1��ʾ�ѱ�ѡ��Ľ��Ⱥ��"<<endl
			//	<<"	3.��־ֵΪ �| ��ʾ��ɾ�����Ⱥ��"<<endl<<endl;
			failflag();          //��ʾ��־λ��Ϣ
			return fail;
		}
		searchp=list[0].headp->next;	//ȡ��ǰlist[0]������Ȩֵ��С�ı�
		while(searchp->next!=NULL && 
			flag[int(searchp->pointstart-'A')]+flag[int(searchp->pointend-'A')]==2)
		//��ʱsearchp�漰�ߵ������յ������ѡ���У����������򹹳ɻ�·��
		{
			list[0].headp->next=searchp->next;
			delete searchp;  //�ͷſռ�
			searchp=list[0].headp->next;//������������ָ��
		}
		//��ʱsearchpָ��һ����Ч�ߣ�������뵽list[1]�У����ҽ���������ѡ����
		i=flag[int(searchp->pointstart-'A')]<flag[int(searchp->pointend-'A')]?
			(searchp->pointstart-'A'):(searchp->pointend-'A');//ѡȡС�߱�־λ
		flag[i]=1;
		newnode=new node(searchp->pointstart,searchp->pointend,searchp->weight);//�������ݴ�����
		newnode->next=NULL;
		if(list[1].empty()) //�����ʱΪ��
		{
			list[1].headp->next=newnode;
			listrear=newnode;//����һ�������β��ָ������ÿ�β���������λ����
		}
		else
		{
			listrear->next=newnode;//���������һ�����
			listrear=newnode;//�ƶ�β��ָ�룬Ϊ��һ�ι�����׼��
		}
		list[1].number++;
	}
	for(i=0;i<numofVertices();i++)//ɨ���ж��Ƿ�Ϊ��С��������ȫ����־λΪ1��ɹ�����С��������������ͨ
		if(flag[i]!=1 && delflag[i]==0)   //����״̬��ȫ����־λΪ1�������ܹ�����С������
		{
			//cout<<endl<<"����ܰ��ʾ��"<<endl
			//	<<"	1.��־ֵΪ0��ʾΪ��δѡ��Ľ���Ⱥ��"<<endl
			//	<<"	2.��־ֵΪ1��ʾ�ѱ�ѡ��Ľ��Ⱥ��"<<endl
			//	<<"	3.��־ֵΪ �| ��ʾ��ɾ�����Ⱥ��"<<endl<<endl;
			failflag();          //��ʾ��־λ��Ϣ
			return fail;
		}
	float total=0;					//��Ȩֵ����
	searchp=list[1].headp->next;	//�Խ���������ɨ��
	while(searchp!=NULL)			//��ʾ��С��������Ϣ
	{
//		searchp->display();			//��ʾ��ǰ�ߵ���Ϣ
		printf("   (%c,%c)=%d\n",node[searchp->pointstart],node[searchp->pointend],searchp->weight);
		//����Ϊ�ߵ���㡢�յ㡢Ȩֵ
		total+=searchp->weight;		//�ۼ���С��������Ȩֵ
		searchp=searchp->next;
	}
	printf("��С����������ȨֵΪ��%d\n",total);//��ʾ��Ȩֵ
	*/	
	return success;
	
}
//Prim��������
//Kruskal������ʼ
returninfo kruskal() 
{
	int nodenamestart,nodenameend;				//�ߵĿ�ʼ����������������
	struct nodelink *newnode,*searchp,*followp,*listrear;	//�½�㡢����ָ�롢β��ָ�롢����β��ָ��
	int mark=0;									//mark��־��¼��ǰ��������ĸ��߼�
	int noderow,nodecol,tempvalue,tempbigger;	//����Ӧ���С��У���ʱ�洢ʹ�õı���������
	int nodeflag;						//��־�������Ƿ���Խ�����С��������Ϊ1���룬Ϊ0ʧ��
	int i,j,k;							//ѭ��������
	int total=0;//��Ȩֵ�ۼ�������
	for(k=0;k<size;k++)			//�Ƿ��Ѿ�������С�������ı�־λȫ������
		flag[k]=0;
	linklist *temp=&list[2];
	clearlist(temp);
	temp=&list[3];
	clearlist(temp);
	//clearlist(list[2]);				//ÿ�ο�ʼʱ����ʼ��������ս���������
	//clearlist(list[3]);  
	for(i=0;i<size-1;i++)//ɨ���ڽӾ��������н�������к���
		for(j=i+1;j<size;j++)//�������ȷ������������Ǿ�������з�0��Ȩֵ
		{
			if(Edge[i][j]!=0) //�������Ȩֵ�漰�����������Ȩֵ���ݼ��뵽�����С���Ȩֵ�������С�
			{
				nodenamestart=i;//����Ascii���������ת���ɽ����
				nodenameend=j;  //����Ascii���������ת���ɽ����
				newnode=(struct nodelink*)malloc(sizeof(nodelink));//newnode=new node();
				newnode->pointstart=nodenamestart;
				newnode->pointend=nodenameend;
				newnode->weight=Edge[i][j];
				
				//�����½�㣬�ѱ��漰����������Ȩֵ����
				if(empty(list[2])) //�����ʱ����Ϊ�գ�����Ϊ��һ��������
				{
					newnode->next=NULL;
					list[2].headp->next=newnode;
				}
				else
				{
					followp=list[2].headp;
					searchp=list[2].headp->next;
					while(searchp!=NULL && searchp->weight<Edge[i][j])//Ϊ�˱�֤��������ȷλ��
					{
						followp=searchp;
						searchp=searchp->next;
					}
					newnode->next=searchp;//�ҵ������������Ȩֵ��С��������
					followp->next=newnode;
				}
				list[2].number++;//������������������һ
			}
		}
		//���潫�������������а��մ�С����Ĵ���ѡ����С�������Ϸ��ı�
		searchp=list[2].headp->next;//��������ָ��
		while(searchp!=NULL && list[3].number!=size)//������û������Ҳ����ı�������ʱ��������
		{
			nodeflag=1; //ÿ�ο�ʼ��������Ϊ1�����赱ǰ����ǿ��Լ�����С��������
			noderow=searchp->pointstart-'A';//�ѵ�ǰ���Ľ������Ϊԭ�ڽӾ����е�������
			nodecol=searchp->pointend-'A';  //�ѵ�ǰ�յ�Ľ������Ϊԭ�ڽӾ����е�������
			if(flag[noderow]+flag[nodecol]==0)  //�������Ϊ0��˵����������㶼���Խ�����С������
			{
				flag[noderow]=++mark;//ÿ���µı߼��Ͽ�ʼʱ��־λ��������1�������жϸ�ͼ�Ƿ�����ͨͼ
				flag[nodecol]=mark;
			}
			else if(flag[noderow]*flag[nodecol]==0) //ֻ��һ��Ϊ0
			{
				tempvalue=(flag[noderow]>flag[nodecol])?flag[noderow]:flag[nodecol]; //ѡ������ֵ
				flag[noderow]=tempvalue;//Ŀ���Ǳ��ֽ��뵱ǰ�ı߼���
				flag[nodecol]=tempvalue;
			}
			else if(flag[noderow]*flag[nodecol]!=0) //�������Ϊ0����������������
			{
				if(flag[noderow]==flag[nodecol]) //��־λ������ȣ�˵����һ���߼��У�Ҳ���ǻ�����������
					nodeflag=0;                   //�������ͨ����־λ��תΪ0��ɣ�����ֻ����һ�����
				else      //���߶���Ϊ0�Ҳ���ȣ�˵����ʼʱ����һ���߼��У�������ͨ�ˣ���Ҫ�ϲ��߼�����ȡСֵ
				{
					tempvalue=(flag[noderow]<flag[nodecol])?flag[noderow]:flag[nodecol]; //׼��С�ı�־λ
					tempbigger=(flag[noderow]>flag[nodecol])?flag[noderow]:flag[nodecol];//��¼��ı�־λ
					for(k=0;k<size;k++)//���б�־λɨ�裬���ڴ��־λ��ȫ��ˢ��ΪС�ı�־λ
						if(flag[k]==tempbigger)
							flag[k]=tempvalue;
				}
			}
			else     //�������������������д�����ʾ���н��ı�־
			{
				return error;
			}
			if(nodeflag==1)//��ʾ�����������С������������
			{
				//���˽����ӵ�����״̬�����С�β�巨��
				newnode=(nodelink *)malloc(sizeof(node));
				newnode->pointstart=searchp->pointstart;
				newnode->pointend=searchp->pointend;
				newnode->weight=searchp->weight;
				newnode->next=NULL;
				if(empty(list[3])) //�����ʱ����Ϊ�գ�����Ϊ��һ��������
				{
					list[3].headp->next=newnode;
					listrear=newnode;//����һ�������β��ָ������ÿ�β���������λ����
				}
				else
				{
					listrear->next=newnode;//���������һ�����
					listrear=newnode;//�ƶ�β��ָ�룬Ϊ��һ�ι�����׼��
				}
				list[3].number++;//��������һ
			}
			searchp=searchp->next;//����������һ����㣬�����㹻ʱ����ֹͣ
		}
		for(k=0;k<size;k++)//ɨ���ж��Ƿ�Ϊ��С��������ȫ����־λΪ1��ɹ�����С��������������ͨ
			if(flag[k]!=1 && delflag[k]==0)   //ֻҪ����һ������־λ��Ϊ1���Ҳ��Ǳ�ɾ���Ľ�㣬��ʧ��
			{
				printf("����ܰ��ʾ��\n	1.��־ֵΪ0��ʾΪ������㣻\n	2.��־ֵΪ��0����ȵı�ʾ�����Ľ�㼯�ϣ�\n3.��־ֵΪ �| ��ʾ��ɾ����㼯�ϡ�\n\n");
				//failflag();				//��ʾ��־λ��Ϣ
				//return fail;			//ֱ���˳�
			}
			searchp=list[3].headp->next;//��������ָ��
			while(searchp!=NULL)//��ʾ�����С�������ı�
			{
				printf("   (%d,%d)=%d\n",searchp->pointstart,searchp->pointend,searchp->weight);//����Ϊ�ߵ���㡢�յ㡢Ȩֵ
				total+=searchp->weight;//��Ȩֵ�ۼ�
				searchp=searchp->next;//�ƶ���������ָ��
			}
			printf("\n��С����������ȨֵΪ��%d\n",total);//��ʾ��Ȩֵ
			return success;
}
//Kruskal��������
/************************************************************/
//���洦��������
int i;							//ѭ������
int nodestart,nodeend,weight;	//��ʼ�㡢��ֹ�㡢Ȩֵ
void showmenu(void);
void processmenu(void);
//���洦����ʵ��
void showmenu(void)
{
	printf("\t����������������������������������������������������\n");
	printf("\t     ����ͼ��ع�����ʾ(�洢�ṹ�ڽӾ���)           \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      1.����Ĭ���ļ����ݽ�������ͼ                  \n");
	printf("\t      2.�����ļ����������������ļ�                  \n");
	printf("\t      3.��ʾ������ͼ���ڽӾ���                      \n");
	printf("\t      4.��ͼ�Ľ�����ͱ���                          \n");
	printf("\t      5.��ĳ���ߵ�Ȩֵ                              \n");
	printf("\t      6.��ӽ��                                    \n");
	printf("\t      7.ɾ�����                                    \n");
	printf("\t      8.��ӱ�                                      \n");
	printf("\t      9.ɾ����                                      \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      d.������ȱ���                                \n");
	printf("\t      b.������ȱ���                                \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      s.���·���������                            \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      p.��С����������Prim�㷨(����ķ�㷨)          \n");
	printf("\t      k.��С����������Kruskal�㷨(��³˹�����㷨)   \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      0.��������                                    \n");
	printf("\t����������������������������������������������������\n");
}
void processmenu()
{
    char choice,yesno;			//�����û�ѡ��˵�ѡ��
	char newnode;
	int *visited;
	int flag;
	char filename[100];//�����û�������ļ�·��
	int returnvalue;
	printf("������ѡ��:");
	scanf(" %c",&choice);
    switch(choice)
    {
    case '1':
		printf("��������������������������������������������������������������������������\n");
		if(ifbuild==1)
		{
			printf("Σ�ղ�����ԭ�����ݽ���ɾ��!��ȷ����?ȷ����(Y||y)��!�������������!\n");
			fflush(stdin);//������뻺����
			scanf("%c",&yesno);//��ȡ�ַ�
			if(yesno!='y' && yesno!='Y')//�������y���߲���Y
			{
				printf("�Ѿ�ȡ������ͼ!\n");
				break;//��ʾ�󷵻ز˵�
			}
		}
		readfile(defaultfile);
		printf("����Ĭ�������ļ��ɹ�!!!\n");
		printf("�����ļ���Ϊ��");
		printf(defaultfile);
		printf("\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������������������������������������������������������������������������\n");
        break;
	case '2':
		printf("��������������������������������������������������������������������������\n");
		if(ifbuild==1)
		{
			printf("Σ�ղ�����ԭ�����ݽ���ɾ��!��ȷ����?ȷ����(Y||y)��!���������!\n");
			fflush(stdin);
			scanf("%c",&yesno);
			if(yesno!='y' && yesno!='Y')
			{
				printf("�Ѿ�ȡ������ͼ!");
				break;
			}
		}
		printf("�������ļ���(������1.txt��2.txt�ȣ�txt���Բ�����)��\n");
		scanf("%s",filename);
		if(readfile(filename)==fail)
		{
			printf("�ļ�����ʧ��!\n");
			system("pause");
			break;
		}
		printf("�����ļ��ɹ�!\n");
		printf("��������������������������������������������������������������������������\n");
        break;
    case '3':
        if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������������������������������������������������������������������������\n");
        break;
    case '4':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��ǰ������Ϊ :%d\n",numofVertices());
		printf("��ǰͼ�ı���Ϊ : %d\n",numofEdges());
		printf("��������������������������������������������������������������������������\n");
        break;
	case '5':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
        printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������Ҫ��ȡ���ĸ���㵽�ĸ����֮��ıߵ�Ȩֵ:"); 
		printf("ע�⣺��С�±��0��ʼ��"); 
		printf("����:����0 1��ʾ��ȡ(��0�Ž�㵽1�Ž��)�ıߵ�Ȩֵ!:");  
		scanf("%d %d",&nodestart,&nodeend);                                           
		weight=getweight(nodestart,nodeend);                                           
		if(weight==maxweight)
		{
			printf("��� %d �� %d ����������Ľ��!!!\n",nodestart,nodeend); 
			printf("��� %c �� %c ֮��ıߵ�ȨֵΪ: ��\n",getvalue(nodestart),getvalue(nodeend)); 
		}
		else
		{
			printf("��� %d �� %d ����������Ľ��!!!\n",nodestart,nodeend);    
			printf("��� %c �� %c ֮��ıߵ�ȨֵΪ: %d\n",getvalue(nodestart),getvalue(nodeend),weight); 
		}
		printf("��������������������������������������������������������������������������\n");
        break;
	case '6':
        if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("================\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������ӵĽ���ֵ(char)��:\n");
		scanf(" %c",&newnode);
		insertVertices(newnode);
		printf("��� %c �Ѿ����!\n",newnode);
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������������������������������������������������������������������������\n");
        break;
    case '7':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("������ɾ���ڼ������: 0  �� %d ֮��\n",numofVertices()-1);
		scanf("%d",&nodestart);
		printf("Σ�ղ���!��ȷ����?ȷ����(Y||y)��!���������!\n");
		fflush(stdin);
		scanf("%c",&yesno);
		if(yesno=='y'||yesno=='Y')
		{			 
			flag=deleteVertex(nodestart);
			if(flag==1)
				printf("��� %d �Ѿ���ɾ��!\n",nodestart);
			printf("��������������������������������������������������������������������������\n");
			printf("��ǰͼ������ͽ������:\n");
			showVertex();
			printf("��ǰͼ���ڽӾ�������:\n");
			showgraph();
		}
		else
			printf("���β����Ѿ�����!!!\n");
        break;
    case '8':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
        printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("���������Ϣ������� ����� Ȩֵ:\n");
		printf("����:����0 1 10 ��ʾ�����һ����(��0�Ž�㵽1�Ž�㣬ȨֵΪ10)!:\n");
		scanf("%d %d %d",&nodestart,&nodeend,&weight);
		if(insertEdge(nodestart,nodeend,weight)&&insertEdge(nodeend,nodestart,weight))
			printf("�� %d �Ž�㵽 %d �Ž��֮���Ѿ������ȨֵΪ %d ��һ����!\n\n",nodestart,nodeend,weight);
        printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������������������������������������������������������������������������\n");
        break;
	case '9':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("��������Ҫɾ�����ĵ��ĸ����ı�:\n");
		printf("����:����0 1��ʾɾ����һ��(��0�Ž�㵽1�Ž��)��һ����!:\n");
		scanf("%d %d",&nodestart,&nodeend);
		printf("Σ�ղ���!��ȷ����?ȷ����(Y||y)��!���������!\n");
		scanf(" %c",&yesno);
		if(yesno=='y'||yesno=='Y')
		{
			if(deleteEdge(nodestart,nodeend)&&deleteEdge(nodeend,nodestart))
				printf("�ӽ�� %d ����� %d �ı��ѱ�ɾ��!\n",nodestart,nodeend);
			printf("��ǰͼ������ͽ������:\n");
			showVertex();
			printf("��ǰͼ���ڽӾ�������:\n");
			showgraph();
			printf("��������������������������������������������������������������������������\n");
		}
		else
			printf("���β����Ѿ�����!!!\n");
		break;
    case 'd':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
        printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("�˴�Լ���ӵ�һ����㿪ʼ������\n");
		printf("������ȱ�������Ϊ :\n");
		visited=(int*)calloc(numofVertices(),sizeof(int));
		for(i=0;i<numofVertices();i++)
		{
			visited[i]=0;
		}
		depthfirstsearch(0,visited,printchar);//����ѵ�һ�����Ĭ��Ϊ������ȱ����ĳ�ʼ���
		printf("\n��������������������������������������������������������������������������\n");
        break;
    case 'b':
		if(ifbuild==0)
		{
			printf("��������������������������������������������������������������������������\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("��������������������������������������������������������������������������\n");
			break;
		}
		printf("��������������������������������������������������������������������������\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		printf("�˴�Լ���ӵ�һ����㿪ʼ������\n");
		printf("������ȱ�������Ϊ :\n");
		visited=(int*)calloc(numofVertices(),sizeof(int));
		for(i=0;i<numofVertices();i++)
			visited[i]=0;
		breadthfirstsearch(0,visited,printchar);//����ѵ�һ�����Ĭ��Ϊ������ȱ����ĳ�ʼ���
		printf("\n��������������������������������������������������������������������������\n");
        break;
	case 's':
        if(ifbuild==0)
		{
			printf("================\n");
			printf("ͼδ���������β���ʧ��!!!\n");
			printf("================\n");
			break;
		}
        printf("================\n");
		printf("��ǰͼ������ͽ������:\n");
		showVertex();
		printf("��ǰͼ���ڽӾ�������:\n");
        showgraph();
		dodijkstra();
		printf("================\n");
        break;
	case 'p':
		if(ifbuild==0)
		{
			printf("\n\nĿǰû��ͼ����Ϣ���޷�����!�밴���������...\n");
			break;
		}
		printf("\n��ѡ��������ͼ��С��������Prim�㷨��\n");
		returnvalue= prim();
		if(returnvalue==error)
			printf("\n�����д�����ʧ��!�밴���������...\n");
		else if(returnvalue==fail)
			printf("\n\n������С������������������!�밴���������...\n");
		else
			printf("\n\nPrim�㷨�ɹ�!�밴���������...\n");
		break;
	case 'k':
		if(ifbuild==0)
		{
			printf("\nĿǰû��ͼ����Ϣ���޷�����!�밴���������...\n");
			break;
		}
		printf("\n��ѡ��������ͼ��С��������Kruskal�㷨��\n");
		returnvalue= kruskal();
		if(returnvalue==fail)
			printf("\n\n������С������������������!�밴���������...\n");
		else if(returnvalue==error)
			printf("\n\n�����д�����ʧ��!�밴���������...\n");
		else
			printf("\n\nKruskal�㷨�ɹ�!�밴���������...\n");
		break;
    case '0':
		printf("��ѡ�����˳���ллʹ��...\n");
        system("pause");
        exit(1);
    default:
        printf("�����д�����������...\n");
    }
}
/************************************************************/
//���������
int main(void) 
{
	SetConsoleTitle("����ͼ���ò�����ʵ�� �洢�ṹΪ�ڽӾ���");//���ô��ڱ���
	system("color f0");//������ɫΪ�׵׺���
    system("cls");//����
	ifbuild=0;//��ʼʱ����Ϊû�н���ͼ
	int i;//ѭ��ʱʹ�õĿ��Ʊ���
	for(i=0;i<4;i++)//�������ĸ�����ĳ�ʼ��
	{
		list[i].headp=(struct nodelink *)malloc(sizeof(nodelink));//��������ͷ���
		list[i].headp->next=NULL;//����ָ���
		list[i].number=0;//��������ʼ��Ϊ0
	}
    while (1)//����ѭ��
    {
        showmenu();//��ʾ�˵�
        processmenu();//����˵�
        system("pause");//��ͣһ��
        system("cls");//����
    }
    return 0;//������������
}//����������
/************************************************************/