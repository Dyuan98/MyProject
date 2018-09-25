/*
2014-07-27
glen修改记录：
1.程序框架全部梳理           完毕
2.菜单修改                   完毕
3.内部变量名等梳理           完毕
4.文件名读入时可以不输入.txt 完毕
5.数据文件中边只需要提供一次 完毕
6.不论是否带权，两种遍历都对 完毕
7.最短路径修改完毕，但是发现对于非连通图会把不通的最大值99999显示出来，已经解决。 完毕



目前需要解决的问题是：
1.文件读入时对于只有点没有边的情况，好像没有考虑。
另外按照目前的情况，事后对于边的统计好像总是多2，问题出在光标在最后数据的下一行，导致多计数了
建议连结点也没有的情况，似乎也最好加以考虑一下。
在总体运行后能适当修改屏幕提示。
如果开始空一行，会出现反复越界，程序跑飞了


2.对于数据文件
如果能过滤注释//就更好 如果每一行前面有空格也可以过滤就更好
如果能过滤多行注释就更好 如果每一行前面有空格也可以过滤就更好

3.在主函数附近能增加一个询问遍历的入口就更好  

4.两个最小代价生成树主要的问题是，对于四个链表的控制有些失控，需要再研究一下。
  其中的字母小写转换成大写这里是否还需要，考虑一下，原来的那个是基础数据是大写字母，用户键盘输入时可能为小写字母

5.如果图非连通，遍历时只能显示和进入结点有关的连通分量，但是能显示出此图非连通就更好了，主要是要解决遍历时同时计数的问题。


*/
/*功能描述：
无向图的常见功能实现，存储结构使用邻接矩阵
注意：数据只能从文本文件读入，每条边只需要存储一次。
如：b---a---c
则数据为：
a b c
0 1 10
0 2 20
权值必须录入，如果为无权无向图，权值全部以1代替
按照就近原则，某个数据结构的函数声明和实现尽量放在一起。

*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

#define MaxListSize 26         //约定本顺序表最多只存26个字母
#define maxsize 26             //队列使用的数组大小
#define maxvertices 26         //定义结点个数最大值为26 
#define maxweight 99999        //当两个结点之间不存在边时距离无穷大用99999来模拟
#define defaultfile "数据文件无向图教材使用1.txt"//默认数据文件
enum returninfo {success,fail,overflow,underflow,range_error,quit,error,dataError};	//定义返回信息清单
int ifbuild;                     //用于记录是否建立过图，为0时表示没有建立过图，为1时表示已经建立过图
/************************************************************/
//顺序表:图的结点用顺序表来存储，可以实现结点的动态插删问题
char node[MaxListSize];            //启用0坐标，即0-25号坐标
int size=0;                          //顺序表的实际大小
//顺序表相关函数声明
void initList();                    //顺序表的初始化函数
int  ListSize();                   //求顺序表的结点个数的函数
int  ListEmpty();                  //判断顺序表是否为空的函数
int  Find(char item);              //查找某个结点的函数
char Getdata(int pos);             //读取某个位置结点的函数
void Insert(char item,int pos);    //插入一个结点到顺序表中
int  Delete(int pos);              //从顺序表中删除一个结点
void ClearList();                  //销毁整个顺序表
//顺序表相关函数实现
void initList()//顺序表的初始化函数
{
	size=0;
}
int ListSize()//求顺序表的结点个数的函数
{
	return size;
}
int ListEmpty()//判断顺序表是否为空的函数
{
	if(size==0)
		return 1;
	else
		return 0;
}
int Find(char item)//查找某个结点的函数
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
char Getdata(int pos)//读取某个位置结点的函数
{
	if(pos<0||pos>size-1)
	{
		printf("对不起!位置参数越界出错!\n");
		return  FALSE;
	}
	return node[pos];
}
void Insert( char item,int pos)//插入一个结点到顺序表中
{
	int i;
	if(size==MaxListSize)
	{
		printf("顺序表已满无法插入!\n");
		return;
	}
	else if(pos<0||pos>size)//插入在最后一个元素右边是合法的
	{
		
		printf("对不起!位置参数越界出错!\n");
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
int Delete(int pos)//删除一个元素
{
	int i;
	char temp;
	if(size==0)
	{
		printf("顺序表已空无法删除!\n");
		return 0;
	}
	else if(pos<0||pos>size-1)
	{
		printf("对不起!位置参数越界出错!\n");
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
void ClearList()//销毁整个顺序表
{
	size=0;
}
/************************************************************/
//队列:解决图的广度优先遍历
char queuedata[maxsize];           //定义数组
int  front;                        //定义队首
int  rear;                         //定义队尾
int  count;                        //定义队列中实际元素个数计数器
//队列相关函数声明
void initQueue();                  //队列初始化
int  isempty();                    //判断队列是否为空
void enqueue(char item);           //元素入队函数
char dequeue();                    //出队函数
void showseq();                    //遍历函数
void getfront();                   //返回头结点的函数
//队列相关函数实现
void initQueue()//对列初始化
{
	//约定rear+1=front时为队列已满，所以总的可以储存元素的空间为maxsize-1
	front=0;//对头初始值，永远指向实际对头
	rear =0;//队尾初始值，永远指向可用空间的第一个地址
	count=0;//计数器开始为0
}
void enqueue(char item)//数据入队
{
	if(front==(rear+1)%maxsize)//队列满的条件
	{
		printf("对不起!队列已满!无法添加!\n");
	}
	else
	{
		queuedata[rear]=item;//否则元素从队尾入队
		rear=(rear+1)%maxsize;//队尾先加一后取模
		count++;//计数器加一
	}
}
char dequeue()//删除队列数据
{
	char datatemp;
	if(count==0)//队列为空的条件
	{
		printf("对不起!队列已空!无法删除!\n");
		return FALSE;
	}
	else
	{
		datatemp=queuedata[front];//否则元素从队头出队
		front=(front+1)%maxsize;//队头后移
		count--;//元素个数减一
		return datatemp;
	}
}
int  isempty()
{
	return front==rear;
}
void showseq()//显示队列元素
{
	int i;
	printf("队列全部元素如下:\n");
	for(i=front;i!=rear;)//从front开始遍历
	{
		printf("  %c",queuedata[i]);
		i=(i+1)%maxsize;
	}
	printf("当前元素个数为: %d\n",count);
	
}
void getfront()//得到队列头部元素
{
	if(count==0)//队列为空的条件
	{
		printf("对不起!队列已空!\n");
		return;
	}
	else
	{
		printf("队头的元素的值为 :%d\n",queuedata[front]);
	}
}
/************************************************************/
//图：无向图的基础数据结构
//变量定义：
//int flag;											//标志位
int numofedges=0;									//记录边的条数
char *nodearray;									//输入结点时使用的一维数组
int Edge[maxvertices][maxvertices];					//图的边信息,使用了二维数组，是一个方阵
//注意实际边的数据只用到了本数组的左上角的一个方阵 
//图相关函数声明
//void graph(int size);								
void initializationofEdge(int size);				//边的邻接矩阵初始化 
void showVertex();									//显示图的结点
void showgraph();									//显示图的邻接矩阵
int  graphempty(){return ListEmpty();}				//判断图的结点数组是否为空
int  numofVertices(){return ListSize();}			//求图的结点个数
int  numofEdges(void){return numofedges;}			//求图的边数
char getvalue(int i);								//求取图某个结点的值
int  getweight(int nodestart,int nodeend);			//求两个结点之间的边的权值
void insertVertices(char vertices);					//向图中添加一个结点
int  deleteVertex(int v);							//删除一个结点
int  insertEdge(int nodestart,int nodeend,int weight);//添加一条边
int  deleteEdge(int nodestart,int nodeend);			//删除一条边
int  getfirstneighbor(int v);                       //为实现图的遍历而定义的求取其第一个相邻结点的函数
int  getnextneighbor(int nodestart,int nodeend);	//求取其下一个相邻结点的函数
void depthfirstsearch(int v,int visited[],void visit(char item));//深的优先遍历
void breadthfirstsearch(int v,int visited[],void visit(char item));//广度优先遍历
void showmenu();//菜单显示函数
void processmenu();//执行指定功能
//图的相关函数实现
//void graph(int size)//图的初始化函数
//{
//	initializationofEdge(maxvertices); 
//}
void initializationofEdge(int size)  //边的邻接矩阵初始化
{
	int i,j;
	for(i=0;i<size;i++)//邻接矩阵的初始化
	{
		for(j=0;j<size;j++)
			if(i==j)
			{
				Edge[i][j]=0;//两个相同结点之间的边的权值为0
			}
			else
				Edge[i][j]=maxweight;//初始状态不同结点之间不存在边
	}
	numofedges=0;//初始状态边的条数为0
}
void showgraph()//图的显示函数
{
	int i,j;
	for(i=0;i<ListSize();i++)//用邻接矩阵来模拟图的边的相关信息
	{
		for(j=0;j<ListSize();j++)
		{
			if(i!=j&&getweight(i,j)==maxweight)
				printf("   ∞");//表示两个结点之间没有边
			else
				printf("%5d",getweight(i,j));
		}
		printf("\n");
	}
}
void showVertex()//显示图的所有结点（线性表）
{
	int i;
	for(i=0;i<ListSize();i++)//显示坐标
		printf("%5d",i);
	printf("\n");
	for(i=0;i<ListSize();i++)//显示数据
		printf("%5c",Getdata(i));
	printf("\n");
}
char getvalue(int i)//求取图的某个结点的值
{
	if(i<0||i>ListSize())
	{
		printf("对不起参数越界出错!\n");
		return FALSE;
	}
	else
		return Getdata(i);//通过顺序表的坐标返回相应的边的名称字符
}
int getweight(int nodestart,int nodeend)//求两个结点之间的边的权值
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("对不起参数越界出错!\n");
		return FALSE;
	}
	else
		return Edge[nodestart][nodeend];
}
void insertVertices(char vertices)//添加一个结点
{
	Insert(vertices,ListSize());//为了简单把添加结点放在顺序表的最后位置
}
int deleteVertex(int v)//删除一个结点
{
	int i,j,flag;
	for(i=0;i<ListSize();i++)//删除结点必须把与这个结点相关联的全部的边首先删除
		for(j=0;j<ListSize();j++)
		{
			if(i==v||j==v && Edge[i][j]>0 && Edge[i][j]<maxweight)
			{
				Edge[i][j]=maxweight;
				numofedges--;
			}
		}
		flag=Delete(v);
		if(flag==1)//提供一个标志位为后面的调用方便
			return 1;
		else
			return 0;
}
int insertEdge(int nodestart,int nodeend,int weight)//添加一条边
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("对不起，参数越界出错!\n");
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
int deleteEdge(int nodestart,int nodeend)//删除一条边
{
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("对不起，参数越界出错!\n");
		return 0;
	}
	else
	{
		Edge[nodestart][nodeend]=maxweight;
		numofedges--;
		return 1;
	}
}
int getfirstneighbor(int v)//求取其第一个相邻接边
{
	int col;
	if(v<0||v>ListSize())
	{
		printf("对不起，参数越界出错!\n");
		return FALSE;
	}
	else
	{
		for(col=0;col<=ListSize();col++)
		{
			if(Edge[v][col]>0 && Edge[v][col]<maxweight)
				return col;//若存在相邻的结点返回其下标
		}
		return -1;//没有找到则返回-1
	}
}
int getnextneighbor(int nodestart,int nodeend)//求取其下一条邻接边
{
	int col;
	//找结点nodestart的<nodestart,nodeend>邻接边的下一条邻接边
	if(nodestart<0||nodestart>ListSize()||nodeend<0||nodeend>ListSize())
	{
		printf("对不起，参数越界出错!\n");
		return FALSE;
	}
	else
	{//使col为nodeend+1因此寻找的边是nodestart的<nodestart,nodeend>邻接边的下一条邻接边
		for(col=nodeend+1;col<=ListSize();col++)
		{
			if(Edge[nodestart][col]>0 && Edge[nodestart][col]<maxweight)
				return col;
		}
		return -1;//没有找到则返回-1
	}
}
void printchar(char item)
{
	printf("%5c",item);
}
/************************************************************/
void depthfirstsearch(int startpoint,int visited[],void visit(char item))//深度优先遍历
{



}
void breadthfirstsearch( int startpoint,int visited[],void visit(char item))//广度优先遍历
{




}

/************************************************************/
//读文件函数的声明
returninfo readfile(char *filename);//读文件中的数据
//读文件函数的实现
returninfo readfile(char *filename)
{
	FILE *in;
	ClearList();                         //结点线性表的初始化：清空
	initializationofEdge(maxvertices);   //边的初始化：清空
	char txt[]=".txt";
	int flagtxt=0;//标志位，为0时表示已经有后缀.txt
    int tempposi=0,tempposj=0;//定义一个变量处理后缀
	char temp;//暂存结点
	int  tempdata[300];//暂存关系结点及权值
	bool flag=true;//标志位 true时为读入字符，一旦反转状态位，则进入读边的信息
	tempposi = strlen(filename)-4; //找到倒数第四个位置
//********************************************************************************
	char content[1000];
	int i=0,j=0,k=0;//计数器用于循环
	int total=0;//记content数组的内容
	int tempInt=0;//临时存储int型数据
	int position;//位置
//***********************************************************************************
	while(filename[tempposi++] != txt[tempposj++] && tempposj<4)
	{
		flagtxt = 1;
		break;
	}
	if(flagtxt == 1)
			strcat(filename,".txt");
	if(!(in=fopen(filename,"r")))//文件打不开或不存在
		return  fail;
	numofedges=0;//边数初始化为0
	while(!feof(in))
	{		
		fscanf(in,"%c",&temp);
		if(temp=='/')
		{
			fscanf(in,"%c",&temp);
			if(temp!='/')
			{
				printf("对不起，数据文件有错!载入失败!只有一个‘/’\n");
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
			printf("对不起，数据文件有错!载入失败!\n");
				return dataError;
		}
		else
		{
			content[total++]=temp;
		}
	}
	fclose(in);//关闭文件
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
			tempInt=0;//初始化为0
			position=i;//记下数据开始位置
			i++;
			while(content[i]!=' '&&content[i]!='\n')
				i++;
			for(j=i-position-1;j>=0;j--)//将字符转换为可计算的数值
			{
				tempInt+=((int)content[position++]-48)*pow(10,j);
			}
			tempdata[k++]=tempInt;	
			i++;
		}
		else if(content[i]==' '&&content[i+1]>='0'&&content[i+1]<='9')//先是空格后是数字的情况
		{
			tempInt=0;//初始化为0
			position=i+1;//记下数据开始位置
			i+=2;//因为前面判断过一次所以这里加2
			while(content[i]!=' '&&content[i]!='\n')
				i++;			
			for(j=i-position-1;j>=0;j--)//将字符转换为可计算的数值
			{
				tempInt+=((int)content[position++]-48)*pow(10,j);
			}
			tempdata[k++]=tempInt;	
			i++;
		}
		else if(content[i]=='\n'&&content[i+1]>='0'&&content[i+1]<='9')//先是回车后是数字的情况
		{
			tempInt=0;//初始化为0
			position=i+1;//记下数据开始位置
			i+=2;//因为前面判断过一次所以这里加2
			while(content[i]!=' '&&content[i]!='\n')
				i++;
			for(j=i-position-1;j>=0;j--)//将字符转换为可计算的数值
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
		printf("对不起，数据文件有错!载入失败!\n");
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
//求最短路径使用的变量
int v0;												//最短路径问题使用的入口
int *distance,*path;								//解决最短路径问题使用的距离数组和路径数组
//求最短路径的函数声明
void dodijkstra();                                  //启动最短路径函数的入口
void dijkstra(int v0,int distance[],int path[]);    //求最短路径函数，参数：起点、距离数组、路径数组
//求最短路径的函数实现
void dodijkstra()//启动最短路径函数的入口
{
	int *distance;
	int i;//循环使用
	distance=(int *)malloc(ListSize());			//距离数组
	path=(int *)malloc(ListSize());				//路径数组
	printf("下面开始求某个结点到其他结点的最短距离...\n");
	printf("请输入结点编号：0~%d\n",ListSize()-1);//提示给定入口
	scanf("%d",&v0);//给定入口
	if(v0>=0 && v0<=ListSize())			//结点编号参数正确
	{
		dijkstra(v0,distance,path);			//调用实际最短路径函数
		printf("从结点%c到其他各结点的最短距离为:\n",getvalue(v0));
		for(i=0;i<ListSize();i++)
			if(distance[i]==0)
				printf("到结点%c的最短距离为:0\n",getvalue(i));
			else
			if(distance[i]==maxweight)
				printf("到结点%c的最短距离为“非连通”\n",getvalue(i));

			else
				printf("到结点%c的最短距离为:%d\n",getvalue(i),distance[i]);
			printf("\n");
			printf("寻找路径如下:\n");
			printf("从结点%c到其他各结点最短路径的上一个结点为:\n",getvalue(v0));
			for(i=0;i<ListSize();i++)
			{
				if(path[i]!=-1)
					printf("到结点%c的上一个结点为:%c\n",getvalue(i),getvalue(path[i]));
			}
	}
	else
	{
		printf("对不起!结点参数出错!按任意键继续……\n");
	}
}
void dijkstra(int v0,int distance[],int path[])//求最短路径函数，参数：起点、距离数组、路径数组
{
	int nodenumnow;	
	nodenumnow=numofVertices();			//取回结点个数
	int *mark=new int[nodenumnow];		//标志位数组
	int mindis,nextnode;					//最短路径，下一个结点
	int i,j;								//循环变量
	for(i=0;i<nodenumnow;i++)				//初始化
	{
		distance[i]=getweight(v0,i);		//第一轮距离数组记录从起始点到其他所有点的边权值
		mark[i]=0;							//所有标志位清零
		if(i!=v0 && distance[i]<maxweight)	//如果起始结点可以抵达某个结点
			path[i]=v0;						//则把该结点首先放入路径数组
		else
			path[i]=-1;						//-1代表该路径不通
	}
	mark[v0]=1;								//把起点的标志位翻转为1
	for(i=1;i<nodenumnow;i++)				//在还没有找到最短路径的结点集合中选取最短距离结点nextnode
	{
		mindis=maxweight;					//首先约定最小距离为无穷大
		for(j=0;j<=nodenumnow;j++)		//扫描其它所有点
		{
			if(mark[j]==0 && distance[j]<mindis)//如果没有进入最短路径且距离小于最小距离
			{
				nextnode=j;					//记录本次边对面的点
				mindis=distance[j];			//记录本次最短路径
			}
		}
		if(mindis==maxweight)				//当不存在路径时算法结束
		{
			return;
		}
		mark[nextnode]=1;//标记结点nextnode已经放到了找到最短路径的的集合中
		for(j=0;j<nodenumnow;j++)//修改结点v0到其他的结点最短的距离
		{
			if(mark[j]==0 && getweight(nextnode,j)<maxweight			
				&& distance[nextnode]+getweight(nextnode,j)<distance[j])//发现新的最短路径
			{
				distance[j]=distance[nextnode]+getweight(nextnode,j);   //刷新最短路径
				path[j]=nextnode;										//把该点加入路径
			}
		}
	}
}
//求最短路径的函数实现


/************************************************************/
//构造最小生成树的数据结构或函数声明
int	  flag[MaxListSize]={0};                    //初始化标志位全部为0
int   delflag[MaxListSize]={0};                 //初始化已经删除结点的标志位为0
void  clearlist(struct linklist* &list);       //清空链表
bool  empty(struct linklist list);   //是否空链
//结点定义
struct nodelink     //创建一个node来表示边的信息
{
    int pointstart;		                    //边的起点【约定ASCII码小】
	int pointend; 	               		    //边的终点【约定ASCII码大】
	int weight;			                    //边的权值
	nodelink *next;				            //后继结点指针
};
//链表整体定义：含链表和计数器
struct linklist     //定义链表linklist类
{
	struct nodelink *headp; 
	int number;    //统计每个链表中结点的个数
};

linklist list[4];
//其中链表0和1表示Prim算法的初始链表和最终结果链表，
//而链表2和3表示Kruskal算法的初始链表和最终结果链表。

//字母转换函数的声明
char letterchange(char nodenameofedge);	//小写字母换成大写信息

returninfo kruskal(); //kruskal算法
returninfo prim();    //prim算法

//构造最小生成树的函数实现
void clearlist(struct linklist* &list)       //清空链表
{
	struct nodelink *searchp=list->headp->next,*followp=list->headp;    //初始化两个指针//struct nodelink *searchp=list.headp->next,*followp=list.headp; 
	while(searchp!=NULL)
	{
		followp=searchp;
		searchp=searchp->next;
		delete followp;
	}
	list->headp->next=NULL;              //保留了头结点，并且链域置为空
	list->number=0;                      //计数器也清零
}
bool empty(struct linklist list)   //是否空链
{
	if(list.number==0)
		return true;
	else
		return false;
}
//字母转换函数的实现
char letterchange(char nodenameofedge) //处理输入字母信息（如果小写换大写）
{
	char nodenameofedgenow;
    nodenameofedgenow=nodenameofedge;
	if(nodenameofedgenow>='a' && nodenameofedgenow<='z')
		return char(nodenameofedgenow-32);    //小写换大写
	else if(nodenameofedgenow>='A' && nodenameofedgenow<='Z')
		return nodenameofedgenow;         //大写则不改
	else
		return 0;            //表示输入的数据有错
}
//Prim函数开始
returninfo prim()
{
	//数组list[4]：其中0、1坐标用于表示prim算法的初始链表和最终结果链表
	//clearlist(list[0]);//每次调用算法前将初始和最终数据清空
	//list[1].clearlist();  
	linklist *temp=&list[0];
	clearlist(temp);
	temp=&list[1];
	clearlist(temp);

	char beginnode;//进入结点名称
//	node *newnode,*searchp,*followp,*listrear;//新结点、搜索指针、尾随指针、尾部指针
/*	int i,j;//循环遍历
	int nodeflag=0;//结点标志位
  	for(i=0;i<numofVertices();i++)     //标志位归零
		flag[i]=0;
	//cout<<"请在下面范围中输入起始结点名称【A-"<<char('A'+nodenumber-1)<<"】：";
	//cin>>beginnode;
	beginnode=letterchange(beginnode);    //小写转换成大写
	if(beginnode==0) //输入数据有误
		return error;
	i=int(beginnode-'A');//计算出进入结点的序号
    flag[i]=1;       //把该序号代表的起始点的标志位翻转为1
	while(list[1].number!=numofVertices()-1-deletenumber)//这里有一个变量deletenumber暂时不知道干什么
	{
		for(j=0;j<numofVertices();j++)
			if(Edge[i][j]!=0)    //i固定不变，把所在行的列全部过一遍 数组名我改为了Edge
			//如果邻接矩阵中权值不为0,则把该边加到链表中
			{
				newnode=new node(i+'A',j+'A',Edge[i][j]);//结点中存入响应的结点名和权值
				if(list[0].empty()) //如果此时链表为空
				{
					newnode->next=NULL;
					list[0].headp->next=newnode;
					list[0].number++;
				}
				else
				{
					//如果这条边已经存在的话，则无需加入
					searchp=list[0].headp->next;//启动搜索指针
					followp=list[0].headp;      //启动尾随指针 
					while(searchp!=NULL && searchp->weight<Edge[i][j])//升序排列，找正确位置
					{
						followp=searchp;
						searchp=searchp->next;
					}
					while(searchp!=NULL && searchp->weight==Edge[i][j])//当发现权值相等时
					{
						if(searchp->pointstart==i+'A' && searchp->pointend==j+'A')//起点终点也相同
						{
							nodeflag=1;
							delete newnode;//释放新结点
							break;
						}
						searchp=searchp->next;//往后移动指针
					}
					if(followp!=NULL && nodeflag==0)
					{
						newnode->next=followp->next;//插入新结点到链表中
						followp->next=newnode;
						list[0].number++;			//计数器加一
						nodeflag=0;					//重新归零
					}
				}
			}
		if(list[0].number==0 )
		{	if(delflag[i]==1)
			{
			//	cout<<endl<<"你输入的结点 "<<char(i+'A')<<" 已被删除!"<<endl;
			//	cout<<endl<<"【温馨提示】"<<endl
			//		<<"	1.标志值为0表示为暂未选入的结点点群；"<<endl
			//		<<"	2.标志值为1表示已被选入的结点群；"<<endl
			//		<<"	3.标志值为 ▅ 表示已删除结点群。"<<endl<<endl;
				failflag();          //显示标志位信息
				return error;
			}
			//cout<<endl<<"【温馨提示】"<<endl
			//	<<"	1.标志值为0表示为暂未选入的结点点群；"<<endl
			//	<<"	2.标志值为1表示已被选入的结点群；"<<endl
			//	<<"	3.标志值为 ▅ 表示已删除结点群。"<<endl<<endl;
			failflag();          //显示标志位信息
			return fail;
		}
		searchp=list[0].headp->next;	//取当前list[0]链表中权值最小的边
		while(searchp->next!=NULL && 
			flag[int(searchp->pointstart-'A')]+flag[int(searchp->pointend-'A')]==2)
		//此时searchp涉及边的起点和终点均在已选行列，舍弃，否则构成回路。
		{
			list[0].headp->next=searchp->next;
			delete searchp;  //释放空间
			searchp=list[0].headp->next;//重新启动搜索指针
		}
		//此时searchp指向一个有效边，将其加入到list[1]中，并且将结点加入已选行列
		i=flag[int(searchp->pointstart-'A')]<flag[int(searchp->pointend-'A')]?
			(searchp->pointstart-'A'):(searchp->pointend-'A');//选取小者标志位
		flag[i]=1;
		newnode=new node(searchp->pointstart,searchp->pointend,searchp->weight);//三个数据存入结点
		newnode->next=NULL;
		if(list[1].empty()) //如果此时为空
		{
			list[1].headp->next=newnode;
			listrear=newnode;//启用一个链表的尾部指针用于每次插入在最后的位置上
		}
		else
		{
			listrear->next=newnode;//挂链到最后一个结点
			listrear=newnode;//移动尾部指针，为下一次挂链做准备
		}
		list[1].number++;
	}
	for(i=0;i<numofVertices();i++)//扫描判断是否为最小生成树，全部标志位为1则可构成最小生成树，否则不连通
		if(flag[i]!=1 && delflag[i]==0)   //最终状态是全部标志位为1，否则不能构成最小生成树
		{
			//cout<<endl<<"【温馨提示】"<<endl
			//	<<"	1.标志值为0表示为暂未选入的结点点群；"<<endl
			//	<<"	2.标志值为1表示已被选入的结点群；"<<endl
			//	<<"	3.标志值为 ▅ 表示已删除结点群。"<<endl<<endl;
			failflag();          //显示标志位信息
			return fail;
		}
	float total=0;					//总权值清零
	searchp=list[1].headp->next;	//对结果链表进行扫描
	while(searchp!=NULL)			//显示最小生成树信息
	{
//		searchp->display();			//显示当前边的信息
		printf("   (%c,%c)=%d\n",node[searchp->pointstart],node[searchp->pointend],searchp->weight);
		//依次为边的起点、终点、权值
		total+=searchp->weight;		//累加最小生成树的权值
		searchp=searchp->next;
	}
	printf("最小生成树的总权值为：%d\n",total);//显示总权值
	*/	
	return success;
	
}
//Prim函数结束
//Kruskal函数开始
returninfo kruskal() 
{
	int nodenamestart,nodenameend;				//边的开始结点名，结束结点名
	struct nodelink *newnode,*searchp,*followp,*listrear;	//新结点、搜索指针、尾随指针、链表尾部指针
	int mark=0;									//mark标志记录当前结点属于哪个边集
	int noderow,nodecol,tempvalue,tempbigger;	//结点对应的行、列，临时存储使用的变量名两个
	int nodeflag;						//标志链表结点是否可以进入最小生成树，为1进入，为0失败
	int i,j,k;							//循环变量名
	int total=0;//总权值累加器清零
	for(k=0;k<size;k++)			//是否已经进入最小生成树的标志位全部清零
		flag[k]=0;
	linklist *temp=&list[2];
	clearlist(temp);
	temp=&list[3];
	clearlist(temp);
	//clearlist(list[2]);				//每次开始时将初始链表和最终结果链表清空
	//clearlist(list[3]);  
	for(i=0;i<size-1;i++)//扫描邻接矩阵中所有结点所在行和列
		for(j=i+1;j<size;j++)//用行优先法处理处理上三角矩阵的所有非0的权值
		{
			if(Edge[i][j]!=0) //将非零的权值涉及的行列坐标和权值数据加入到链表中【按权值升序排列】
			{
				nodenamestart=i;//利用Ascii码把行坐标转换成结点名
				nodenameend=j;  //利用Ascii码把列坐标转换成结点名
				newnode=(struct nodelink*)malloc(sizeof(nodelink));//newnode=new node();
				newnode->pointstart=nodenamestart;
				newnode->pointend=nodenameend;
				newnode->weight=Edge[i][j];
				
				//申请新结点，把边涉及的两个结点和权值存入
				if(empty(list[2])) //如果此时链表为空，则作为第一个结点挂入
				{
					newnode->next=NULL;
					list[2].headp->next=newnode;
				}
				else
				{
					followp=list[2].headp;
					searchp=list[2].headp->next;
					while(searchp!=NULL && searchp->weight<Edge[i][j])//为了保证有序，找正确位置
					{
						followp=searchp;
						searchp=searchp->next;
					}
					newnode->next=searchp;//找到后挂链，保持权值从小到大排列
					followp->next=newnode;
				}
				list[2].number++;//结果链表个数计数器加一
			}
		}
		//下面将从有序链表结点中按照从小到大的次序选出最小生成树合法的边
		searchp=list[2].headp->next;//启动搜索指针
		while(searchp!=NULL && list[3].number!=size)//当链表没有完而且产生的边数不够时继续产生
		{
			nodeflag=1; //每次开始重新设置为1，假设当前结点是可以加入最小生成树的
			noderow=searchp->pointstart-'A';//把当前起点的结点名换为原邻接矩阵中的行坐标
			nodecol=searchp->pointend-'A';  //把当前终点的结点名换为原邻接矩阵中的列坐标
			if(flag[noderow]+flag[nodecol]==0)  //如果都是为0，说明这两个结点都可以进入最小生成树
			{
				flag[noderow]=++mark;//每当新的边集合开始时标志位不断增加1，用来判断该图是否是联通图
				flag[nodecol]=mark;
			}
			else if(flag[noderow]*flag[nodecol]==0) //只有一个为0
			{
				tempvalue=(flag[noderow]>flag[nodecol])?flag[noderow]:flag[nodecol]; //选择非零的值
				flag[noderow]=tempvalue;//目的是保持进入当前的边集中
				flag[nodecol]=tempvalue;
			}
			else if(flag[noderow]*flag[nodecol]!=0) //如果都不为0的情况，分情况讨论
			{
				if(flag[noderow]==flag[nodecol]) //标志位两者相等，说明在一个边集中，也就是环，必须舍弃
					nodeflag=0;                   //结点舍弃通过标志位翻转为0达成，此中只有这一种情况
				else      //两者都不为0且不相等，说明开始时不在一个边集中，现在联通了，需要合并边集，故取小值
				{
					tempvalue=(flag[noderow]<flag[nodecol])?flag[noderow]:flag[nodecol]; //准备小的标志位
					tempbigger=(flag[noderow]>flag[nodecol])?flag[noderow]:flag[nodecol];//记录大的标志位
					for(k=0;k<size;k++)//所有标志位扫描，等于大标志位的全部刷新为小的标志位
						if(flag[k]==tempbigger)
							flag[k]=tempvalue;
				}
			}
			else     //如果有其他现象则表明有错并且显示所有结点的标志
			{
				return error;
			}
			if(nodeflag==1)//表示这个结点符合最小生成树的条件
			{
				//将此结点添加到最终状态链表中【尾插法】
				newnode=(nodelink *)malloc(sizeof(node));
				newnode->pointstart=searchp->pointstart;
				newnode->pointend=searchp->pointend;
				newnode->weight=searchp->weight;
				newnode->next=NULL;
				if(empty(list[3])) //如果此时链表为空，则作为第一个结点挂入
				{
					list[3].headp->next=newnode;
					listrear=newnode;//启用一个链表的尾部指针用于每次插入在最后的位置上
				}
				else
				{
					listrear->next=newnode;//挂链到最后一个结点
					listrear=newnode;//移动尾部指针，为下一次挂链做准备
				}
				list[3].number++;//计数器加一
			}
			searchp=searchp->next;//继续处理下一个结点，边数足够时马上停止
		}
		for(k=0;k<size;k++)//扫描判断是否为最小生成树，全部标志位为1则可构成最小生成树，否则不连通
			if(flag[k]!=1 && delflag[k]==0)   //只要遇到一个结点标志位不为1而且不是被删除的结点，则失败
			{
				printf("【温馨提示】\n	1.标志值为0表示为孤立结点；\n	2.标志值为非0且相等的表示互联的结点集合；\n3.标志值为 ▅ 表示已删除结点集合。\n\n");
				//failflag();				//显示标志位信息
				//return fail;			//直接退出
			}
			searchp=list[3].headp->next;//启动搜索指针
			while(searchp!=NULL)//显示最后最小生成树的边
			{
				printf("   (%d,%d)=%d\n",searchp->pointstart,searchp->pointend,searchp->weight);//依次为边的起点、终点、权值
				total+=searchp->weight;//总权值累加
				searchp=searchp->next;//移动链表搜索指针
			}
			printf("\n最小生成树的总权值为：%d\n",total);//显示总权值
			return success;
}
//Kruskal函数结束
/************************************************************/
//界面处理函数声明
int i;							//循环变量
int nodestart,nodeend,weight;	//起始点、终止点、权值
void showmenu(void);
void processmenu(void);
//界面处理函数实现
void showmenu(void)
{
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t     无向图相关功能演示(存储结构邻接矩阵)           \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      1.读入默认文件数据建立无向图                  \n");
	printf("\t      2.给定文件名读入其他数据文件                  \n");
	printf("\t      3.显示本无向图的邻接矩阵                      \n");
	printf("\t      4.求图的结点数和边数                          \n");
	printf("\t      5.求某条边的权值                              \n");
	printf("\t      6.添加结点                                    \n");
	printf("\t      7.删除结点                                    \n");
	printf("\t      8.添加边                                      \n");
	printf("\t      9.删除边                                      \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      d.深度优先遍历                                \n");
	printf("\t      b.广度优先遍历                                \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      s.最短路径求解问题                            \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      p.最小代价生成树Prim算法(普利姆算法)          \n");
	printf("\t      k.最小代价生成树Kruskal算法(克鲁斯卡尔算法)   \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      0.结束程序                                    \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}
void processmenu()
{
    char choice,yesno;			//用于用户选择菜单选项
	char newnode;
	int *visited;
	int flag;
	char filename[100];//保存用户输入的文件路径
	int returnvalue;
	printf("请输入选项:");
	scanf(" %c",&choice);
    switch(choice)
    {
    case '1':
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		if(ifbuild==1)
		{
			printf("危险操作，原有数据将被删除!你确定吗?确定按(Y||y)键!否则按任意键返回!\n");
			fflush(stdin);//清空输入缓冲区
			scanf("%c",&yesno);//读取字符
			if(yesno!='y' && yesno!='Y')//如果不是y或者不是Y
			{
				printf("已经取消建立图!\n");
				break;//提示后返回菜单
			}
		}
		readfile(defaultfile);
		printf("调入默认数据文件成功!!!\n");
		printf("本次文件名为：");
		printf(defaultfile);
		printf("\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
	case '2':
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		if(ifbuild==1)
		{
			printf("危险操作，原有数据将被删除!你确定吗?确定按(Y||y)键!否则按任意键!\n");
			fflush(stdin);
			scanf("%c",&yesno);
			if(yesno!='y' && yesno!='Y')
			{
				printf("已经取消建立图!");
				break;
			}
		}
		printf("请输入文件名(建议用1.txt、2.txt等，txt可以不输入)：\n");
		scanf("%s",filename);
		if(readfile(filename)==fail)
		{
			printf("文件读入失败!\n");
			system("pause");
			break;
		}
		printf("读入文件成功!\n");
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
    case '3':
        if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
    case '4':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("当前结点个数为 :%d\n",numofVertices());
		printf("当前图的边数为 : %d\n",numofEdges());
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
	case '5':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("请输入你要读取从哪个结点到哪个结点之间的边的权值:"); 
		printf("注意：最小下标从0开始。"); 
		printf("例如:输入0 1表示读取(从0号结点到1号结点)的边的权值!:");  
		scanf("%d %d",&nodestart,&nodeend);                                           
		weight=getweight(nodestart,nodeend);                                           
		if(weight==maxweight)
		{
			printf("结点 %d 与 %d 即代表下面的结点!!!\n",nodestart,nodeend); 
			printf("结点 %c 与 %c 之间的边的权值为: ∞\n",getvalue(nodestart),getvalue(nodeend)); 
		}
		else
		{
			printf("结点 %d 与 %d 即代表下面的结点!!!\n",nodestart,nodeend);    
			printf("结点 %c 与 %c 之间的边的权值为: %d\n",getvalue(nodestart),getvalue(nodeend),weight); 
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
	case '6':
        if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("================\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("请输入添加的结点的值(char)型:\n");
		scanf(" %c",&newnode);
		insertVertices(newnode);
		printf("结点 %c 已经添加!\n",newnode);
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
    case '7':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("请输入删除第几个结点: 0  到 %d 之间\n",numofVertices()-1);
		scanf("%d",&nodestart);
		printf("危险操作!你确定吗?确定按(Y||y)键!否则按任意键!\n");
		fflush(stdin);
		scanf("%c",&yesno);
		if(yesno=='y'||yesno=='Y')
		{			 
			flag=deleteVertex(nodestart);
			if(flag==1)
				printf("结点 %d 已经被删除!\n",nodestart);
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("当前图的坐标和结点如下:\n");
			showVertex();
			printf("当前图的邻接矩阵如下:\n");
			showgraph();
		}
		else
			printf("本次操作已经放弃!!!\n");
        break;
    case '8':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("请输入边信息：结点编号 结点编号 权值:\n");
		printf("例如:输入0 1 10 表示添加了一条边(从0号结点到1号结点，权值为10)!:\n");
		scanf("%d %d %d",&nodestart,&nodeend,&weight);
		if(insertEdge(nodestart,nodeend,weight)&&insertEdge(nodeend,nodestart,weight))
			printf("从 %d 号结点到 %d 号结点之间已经添加了权值为 %d 的一条边!\n\n",nodestart,nodeend,weight);
        printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
	case '9':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("请输入你要删除从哪到哪个结点的边:\n");
		printf("例如:输入0 1表示删除了一条(从0号结点到1号结点)的一条边!:\n");
		scanf("%d %d",&nodestart,&nodeend);
		printf("危险操作!你确定吗?确定按(Y||y)键!否则按任意键!\n");
		scanf(" %c",&yesno);
		if(yesno=='y'||yesno=='Y')
		{
			if(deleteEdge(nodestart,nodeend)&&deleteEdge(nodeend,nodestart))
				printf("从结点 %d 到结点 %d 的边已被删除!\n",nodestart,nodeend);
			printf("当前图的坐标和结点如下:\n");
			showVertex();
			printf("当前图的邻接矩阵如下:\n");
			showgraph();
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		}
		else
			printf("本次操作已经放弃!!!\n");
		break;
    case 'd':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("此处约定从第一个结点开始遍历。\n");
		printf("深度优先遍历序列为 :\n");
		visited=(int*)calloc(numofVertices(),sizeof(int));
		for(i=0;i<numofVertices();i++)
		{
			visited[i]=0;
		}
		depthfirstsearch(0,visited,printchar);//这里把第一个结点默认为深度优先遍历的初始结点
		printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
    case 'b':
		if(ifbuild==0)
		{
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			break;
		}
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		printf("此处约定从第一个结点开始遍历。\n");
		printf("广度优先遍历序列为 :\n");
		visited=(int*)calloc(numofVertices(),sizeof(int));
		for(i=0;i<numofVertices();i++)
			visited[i]=0;
		breadthfirstsearch(0,visited,printchar);//这里把第一个结点默认为广度优先遍历的初始结点
		printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        break;
	case 's':
        if(ifbuild==0)
		{
			printf("================\n");
			printf("图未建立，本次操作失败!!!\n");
			printf("================\n");
			break;
		}
        printf("================\n");
		printf("当前图的坐标和结点如下:\n");
		showVertex();
		printf("当前图的邻接矩阵如下:\n");
        showgraph();
		dodijkstra();
		printf("================\n");
        break;
	case 'p':
		if(ifbuild==0)
		{
			printf("\n\n目前没有图的信息，无法操作!请按任意键继续...\n");
			break;
		}
		printf("\n您选择了无向图最小生成树的Prim算法：\n");
		returnvalue= prim();
		if(returnvalue==error)
			printf("\n数据有错，计算失败!请按任意键继续...\n");
		else if(returnvalue==fail)
			printf("\n\n构成最小生成树的条件不满足!请按任意键继续...\n");
		else
			printf("\n\nPrim算法成功!请按任意键继续...\n");
		break;
	case 'k':
		if(ifbuild==0)
		{
			printf("\n目前没有图的信息，无法操作!请按任意键继续...\n");
			break;
		}
		printf("\n您选择了无向图最小生成树的Kruskal算法：\n");
		returnvalue= kruskal();
		if(returnvalue==fail)
			printf("\n\n构成最小生成树的条件不满足!请按任意键继续...\n");
		else if(returnvalue==error)
			printf("\n\n数据有错，计算失败!请按任意键继续...\n");
		else
			printf("\n\nKruskal算法成功!请按任意键继续...\n");
		break;
    case '0':
		printf("您选择了退出，谢谢使用...\n");
        system("pause");
        exit(1);
    default:
        printf("输入有错，请重新输入...\n");
    }
}
/************************************************************/
//程序主入口
int main(void) 
{
	SetConsoleTitle("无向图常用操作的实现 存储结构为邻接矩阵");//设置窗口标题
	system("color f0");//设置颜色为白底黑字
    system("cls");//清屏
	ifbuild=0;//开始时设置为没有建立图
	int i;//循环时使用的控制变量
	for(i=0;i<4;i++)//建立了四个链表的初始化
	{
		list[i].headp=(struct nodelink *)malloc(sizeof(nodelink));//建立链表头结点
		list[i].headp->next=NULL;//链域指向空
		list[i].number=0;//结点个数初始化为0
	}
    while (1)//永真循环
    {
        showmenu();//显示菜单
        processmenu();//处理菜单
        system("pause");//暂停一下
        system("cls");//清屏
    }
    return 0;//结束本次运行
}//主函数结束
/************************************************************/