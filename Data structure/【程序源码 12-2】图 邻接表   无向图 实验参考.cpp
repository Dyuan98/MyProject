/*功能描述：
图用邻接表实现基本功能
*/
//本程序有部分源码需要进一步的完善
#include<windows.h>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
                 haveason,havetwosons,range_error,quit
                };					//定义返回信息清单

#define  size 21//结点个数约定为20个，从1号地址开始使用
int build;		//标志位，提醒目前为空表
//结点对象
class Node                                       
{
public:
    int	  data;                                     
    Node *next;                             
    Node()                                       
    {                                           
        this->next = NULL;
    }
    Node(int data, Node *next=NULL)             //构造结点，指定元素和后继结点
    {
        this->data = data;
        this->next = next;
    }
};
//链表对象
class linklist                           
{    
private:	
	Node *head;								//单链表的头指针
public:
	int   length;							//数据个数
    linklist();								//构造函数     
    ~linklist();							//析构函数
	int   clearlink();						//清空链表中的数据
    int   setheadNULL();					//把头结点的链域置空
    void  printlinklist();					//遍历链表	
    Node *inserthead(int data);				//把结点插入在第一个位置作为头结点
    Node *insert(int x,int i);				//把x值插入到第i个位置           
    int   getheaddata();					//取回头结点中的值
	bool  del(int data) ;					//删除值为data的结点
    Node  *find(int value, Node* start);	//从start结点开始找值为value的结点      
    Node  *find(int value);					//查找值为value的结点
	int   *nodetoarraydata();				//把链表数据转换为数组数据
   	int   findsmallernum(int data);			//找到比data小的数据个数
	int   getnextnode(int i);				//返回邻接的下一个结点
};
linklist::linklist()          //构造空单链表
{
    this->head  =NULL;
	this->length=0;
}
linklist::~linklist()        
{
    this->head  =NULL;//链表结点释放此处没有写
}
int linklist::clearlink()//清除掉所有边信息的点
{
	Node *searchp=head->next;//head中存储的是结点名称
	Node *followp;
	while(searchp!=NULL)
	{
		followp=searchp;
		searchp=searchp->next;
		head->next=searchp;
		delete followp;
    }
	head->next=NULL;
  return 1;
}
int  linklist::setheadNULL()
{
	Node *temp=head;
	delete temp;
	head=NULL;
	return 1;
}
void linklist::printlinklist()//遍历链表所有结点
{
	Node *searchp=head;
	if(searchp==NULL)
		cout<<"无数据！";
	while(searchp!=NULL)                    //循环显示所有数据
	{
		cout<<"[ "<<searchp->data;   
		if (searchp->next==NULL) 
			cout<<" |^]"; 
		else 
			cout<<" |-]->";
		searchp=searchp->next;
	}
}
Node *linklist::inserthead(int data)
{
	Node *followp;
    followp = new Node(data, head);
    head = followp;
	length++;
	return followp;
}
Node *linklist::insert( int data,int pos) //插入data作为第pos个结点，返回新插入结点指针
{
    Node *followp;
	int j=0; 
	if (head==NULL || pos<=0)                      //头插入
    {
        followp = new Node(data, head);
        head = followp;
    }
    else                                        
    {
        Node *searchp=head;
	    while (searchp->next!=NULL&&j<pos-1)           //寻找插入位置
        {
            j++;
            searchp = searchp->next;
        }                                        //循环停止时，searchp指向第pos-1个结点或链表最后一个结点
        followp = new Node(data, searchp->next);             //插入data作为searchp结点的后继结点
        searchp->next = followp;
		length++;
    }
    return followp;
}
int linklist::getheaddata()//头结点是否为空
{
	if(head==NULL)
		return -1;
	else
		return head->data;
}
bool linklist::del(int data)  //删除data结点
{
    Node *searchp=head,*followp=head;
    while(searchp->next!=NULL && searchp->data!=data)
	{
		followp=searchp;
		searchp=searchp->next;
	}
	if(searchp->data==data)
	{
		followp->next=searchp->next;
		delete searchp;
		return true;
	}
	else   
		return false; 
}
Node *linklist::find(int value, Node *start)    //从单链表start结点开始顺序查找指定元素
{                                                
    Node *searchp=start;
    while (searchp!=NULL && searchp->data!=value)
	{
        searchp = searchp->next;
	}
    return searchp;
}
Node *linklist::find(int value)    
{
    if (head==NULL)
        return NULL;
    else
    return find(value, head->next); 
}
int *linklist::nodetoarraydata()
{
	int  *followp = new int[size];
	Node *searchp=head->next;
	int  i=1;
	while(searchp!=NULL)
	{
		
		followp[i]=searchp->data;
		i++;
		searchp=searchp->next;
	}
	followp[0]=i;
	return followp;
}
int linklist::findsmallernum(int data)//横向查找小于某个数据的个数
{

    Node *searchp=head->next;
	int nums=0;
    while (searchp!=NULL && searchp->data<data)
	{
       nums++;
	   searchp=searchp->next;
	}
	return nums;
}
int linklist::getnextnode(int pos)//取出从头结点后面开始的第pos个结点的值
{
	Node *searchp=head->next;
	int nextnum=1;//位置计数器
	while(searchp!=NULL && nextnum!=pos)
	{
		searchp=searchp->next;
		nextnum++;
	}
	if(searchp==NULL)
		return -1;
	else 
		return searchp->data;
}

//链式队列对象
class linkqueue                                //链式队列类
{
private:
	Node *front, *rear;                       //front、rear分别指向队首和队尾结点
public:
    linkqueue();                               //构造空队列
    ~linkqueue();                              //析构
    bool isempty();                              //判断是否空队列
    void enqueue(int x);                           //入队
    int  dequeue();                                 //出队，若队列空则抛出异常
    void printlinkqueue();
};
linkqueue::linkqueue()                    //构造空队列
{
    front = rear = NULL;
}
linkqueue::~linkqueue()                   //析构函数
{
    Node *searchp=front, *followp;
    while (searchp!=NULL)//释放空间
    {
        followp = searchp;
        searchp = searchp->next;
        delete followp;
    }
    front = rear = NULL;
}
bool linkqueue::isempty()                   //判断是否空队列
{
    return front==NULL && rear==NULL;
}
void linkqueue::enqueue(int x)               //入队
{
    Node *followp = new Node(x);
    if (isempty())
        front = followp;                               //空队插入
    else 
        rear->next = followp;                          //插入在队列之尾
    rear = followp;
}  
int linkqueue::dequeue()                      //出队，返回队头元素，若队列空则抛出异常 
{
    if (!isempty())
    {
       int x = front->data;                       //取得队头元素
       Node *searchp=front;
       front = front->next;                     //删除队头结点
       delete searchp;
       if (front==NULL)                         //空队列时，两指针同步
          rear = NULL;
       return x;
    }
	else 
		return -1;
}
void linkqueue::printlinkqueue()
{
	Node *searchp=front;
    while (searchp!=NULL)
    {
       
        cout<<searchp->data<<"---";
		searchp=searchp->next;
    }
}
void quickSort(int table[], int length, int low, int high)        //一趟快速排序，递归算法
{                                                          
    int lowtemp, hightemp;
    int basedata;                         
    if (low>=0 && low<length && high>=0 && high<length && low<high) 
    {
        lowtemp=low;
		hightemp=high;
        basedata=table[lowtemp];                         
        while (lowtemp!=hightemp)
        {
            while (lowtemp<hightemp && basedata<=table[hightemp])         
                hightemp--;
            if (lowtemp<hightemp)
                table[lowtemp++]=table[hightemp];             
            while (lowtemp<hightemp && table[lowtemp]<basedata)          
                lowtemp++;
            if (lowtemp<hightemp)
                table[hightemp--]=table[lowtemp];            
        }
        table[lowtemp]=basedata;                            
        quickSort(table, length, low, hightemp-1);           
        quickSort(table, length, lowtemp+1, high);        
    }
}
int *doquickSort(int array[], int length)               //快速排序
{
    quickSort(array, length, 0, length-1);				//四个参数：数组名、长度、两边的下标
    return array;
}
/////////////////////////////////////////////////////////
//图的邻接表对象
class ALGraph
{
private:
	linklist *Graph;					//构造一个链表的实例，起名为Graph
	linkqueue queue;					//构造一个链队的实例，起名为queue，为广度优先遍历准备
	int nodenumber;						//用于产生存放结点的下标位置，同时记录结点个数
	int edgenumber;						//实际边数记录
	int row;							//控制结点数组的行数
	int i;								//循环变量
	int nodenum,edgenum;				//临时存储结点数和边数
	int node[size];						//临时存储图的结点
	int *sortednodes;					//存储排序后的结点
	int startpoint,endpoint;			//起始结点和终止结点
public:
	ALGraph(int nodenumber=1,int edgenumber=0);//结点数组空置0下标，故nodenumber从1开始，边数起始为0
	~ALGraph();
	void inigraph();					//图目前的数据清空以备重新输入数据
	void inputdata(void);				//手工输入数据
	void autocreatgraph();				//启用默认数据
	void showgraph();					//显示邻接表
	void showtotalnodenumber();			//显示结点总个数
	void showtotaledgenumber();			//显示边的总个数
	int  findnode(int nodedata);		//查找结点在数组中的行数	
	void insertmanynodes(int data);		//一次插入一批结点使用的插入结点函数
	void insertonenode(int data);		//一次仅仅插入一个结点使用的插入结点函数
	Node *findedge(int startpoint,int endpoint);	//查找两点之间的边
	void searchnext(int data);						//查找下一个邻接点
	void DFSTraverse();								//深度优先遍历入口
	void TDFSTraverse(int row,int flag[],int stackarray[]);			//深度优先遍历函数
	void BFSTraverse();								//广度优先遍历入口
	void TBFSTraverse(int row,int flag[]);			//广度优先遍历递归函数
};
ALGraph::ALGraph(int nodenumber,int edgenumber)
{
	this->Graph=new linklist[size];//定义了邻接表的指针数组
	this->nodenumber=nodenumber;
	this->edgenumber=edgenumber;
}
ALGraph::~ALGraph()
{
   delete[] Graph;
}
void ALGraph::inigraph()//图目前的数据清空以备重新输入数据
{
	for(i=1;i<nodenumber;i++)//此处实际上从坐标1只循环到达nodeposition-1的坐标，这正好是数据量
		Graph[i].clearlink();//先把边信息的链表结点全部删除和释放空间
	for(i=1;i<nodenumber;i++)//再把结点信息在数组中的链域置空
		Graph[i].setheadNULL();
	nodenumber=1;
	edgenumber=0;
}
void ALGraph::inputdata(void)
{
	inigraph();
	cout<<"请输入结点个数:";
	cin>>nodenum;
	if(nodenum<=0)
	{
		cout<<"输入数据有错，本次操作放弃!!!"<<endl;
	}
	else
	{
		cout<<"请输入结点:";
		for (i=0; i<nodenum; i++)
		cin>>node[i];
		sortednodes=doquickSort(node,nodenum);
		for (i=0; i<nodenum; i++)
			insertmanynodes(sortednodes[i]);
		cout<<"================"<<endl;
		cout<<"当前图的邻接表如下:"<<endl;
		showgraph();
		cout<<"请输入边个数:"<<endl;
		cin>>edgenum;
		if(edgenum<=0)
		{
			cout<<"输入数据有错，本次操作放弃!!!"<<endl;
		}
		else
		{
			cout<<"请输入每条边连接的两个点:"<<endl;//还要考虑点不存在
			for(i=0;i<edgenum;i++)
			{
				cin>>startpoint>>endpoint;
				if(findnode(startpoint)!=-1&&findnode(endpoint)!=-1)
					insertedge(findnode(startpoint),findnode(endpoint));
				else
					cout<<startpoint<<"与"<<endpoint<<"之间的边不存在！"<<endl;
			}
			cout<<"================"<<endl;
			cout<<"当前图的邻接表如下:"<<endl;
			showgraph();		
		}
	}
}
void ALGraph::autocreatgraph()//启用有向图默认数据
{
	int defaultnodenum=8,
		defaultnode[]={11,33,22,44,55,88,77,66},
		defaultedgenum=12,
		defaultedge[12][2]=
			{{11,22},{11,44},{11,77},
			 {22,33},{22,44},
			 {33,88},
			 {44,55},
			 {55,88},
			 {66,77},{77,66},
			 {77,44},
			 {88,66}};
	inigraph();
	for (i=0; i<defaultnodenum; i++)
		sortednodes=doquickSort(defaultnode,defaultnodenum);
	for (i=0; i<defaultnodenum; i++)
	    insertmanynodes(sortednodes[i]);
	for(i=0;i<defaultedgenum;i++)
	 	insertedge(findnode(defaultedge[i][0]),findnode(defaultedge[i][1]));
}
void ALGraph::showgraph()//显示图的邻接表形式
{
	if(nodenumber==1)
		cout<<"目前图没有数据!!!"<<endl;
	else
	{	
		cout<<"坐标"<<" 结点名"<<" 边关系链表"<<endl;
		for(int i=1;i<nodenumber;i++)//此处实际上从坐标1只循环到达nodeposition-1的坐标，这正好是数据量
		{
			cout<<" "<<i<<"   ";
			Graph[i].printlinklist();//显示了链表中的所有数据
			cout<<endl;
		} 
	}
}
void ALGraph::showtotalnodenumber()//显示总结点个数
{
	cout<<nodenumber-1<<endl;//nodeposition每次指向下一个可用空间，故实际数量需要减一
}
void ALGraph::showtotaledgenumber()//显示边的总个数
{
	cout<<edgenumber<<endl;
}
int ALGraph::findnode(int nodedata)//结点是否存在
{
	row=0;//真实数据地址从1到nodenumber-1
	while((row<nodenumber) && (Graph[row].getheaddata()!=nodedata))//当没找完而且没有找到时
		row++;
    if(row>=nodenumber)//没有找到时
		row=-1;
	return row;
}

Node *ALGraph::findedge(int startpoint,int endpoint) //查找startpoint与endpoint之间的边        
{           
	return Graph[startpoint].find(endpoint);        
}
void ALGraph::searchnext(int data)//查找data的相邻结点
{
	int *adjvexdataarray;
	if(Graph[findnode(data)].length==1)
	{
		cout<<data<<"没有相邻结点!!!"<<endl;
	}
	else
	{
		adjvexdataarray=Graph[findnode(data)].nodetoarraydata();
		cout<<data<<"的相邻结点为：";
		for(int i=1;i<adjvexdataarray[0];i++)
			cout<<Graph[adjvexdataarray[i]].getheaddata()<<"  ";
		cout<<endl;
		delete[] adjvexdataarray;
	}
}
void ALGraph::DFSTraverse()//深度优先遍历入口
{
	int *flag=new int [nodenumber];	//结点被访问标志，0表示未被访问，1表示已访问
	for(i=1;i<nodenumber;i++)	//标志位数组初始化，全部赋值为0
		flag[i]=0; 
	int	*stackarray=new int [nodenumber+1];//保存路径的数组，起到栈的作用
	for(i=0;i<nodenumber;i++)//初始状态全部赋值为-1
	{
		stackarray[i]=-1;
	}
	for(i=1;i<nodenumber;i++)		//每一个结点都作为起始结点一次，确保非联通图也可以完成遍历
		if(flag[i]==0)
			TDFSTraverse(i,flag,stackarray);
}
////////////////////////////////////////////////////////////////////////////////////
void ALGraph::TDFSTraverse(int row,int flag[], int stackarray[])//深度优先遍历函数
{
		int *adjvexdataarray1;	//邻接边信息链表转换成的数组
	int nextnum;			//下一个邻接点的编号
	int visitednum=1;		//已访问结点的个数
    //if(row==-1) return;
	stackarray[0]=1;		//0号坐标中存放访问过的结点数量，此处预设为1，则最后访问结点数量需要减一
	while(row!=-1 && stackarray[0]<nodenumber)//如果进入点存在并且已访问的结点数量没有到达总结点量则循环
	{
		if(flag[row]==0)							//如果没访问，就访问
		{
			cout<<Graph[row].getheaddata()<<"  ";	//把该编号对应的结点名输出
			stackarray[stackarray[0]]=row;          //保存路径信息
	        stackarray[0]++;                        //stackarray[0]-1为存放已访问结点个数
			flag[row]=1;
		}
		adjvexdataarray1=Graph[row].nodetoarraydata();//把链表中所有邻接结点信息转换成数组，地址从1开始
		///////////////
		//cout<<"这里是每次每一行结点信息转换为数组后的信息"<<endl;
		//for(i=1;i<nodenumber;i++)
		//	cout<<adjvexdataarray1[i]<<endl;
		//cout<<"每一行结点信息转换为数组后的信息结束"<<endl;
		///////////////
		nextnum=1;									 //开始处理第一个相邻结点	                       
	    row=Graph[row].getnextnode(nextnum);		 //获取相邻结点对应在结点数组中的行号
		while(flag[row]==1 && row!=-1 && stackarray[0]<nodenumber)//如果该结点被访问过则查找下一个邻接点
			row=adjvexdataarray1[nextnum++];			 //直到找到一个没有被访问过的结点编号 
		
		
		//TDFSTraverse(row,flag,stackarray);//从新的一行进入，递归完成遍历工作
		visitednum=stackarray[0]-1;                  //记录已访问数据个数
		if(stackarray[0]<nodenumber && row==-1)      //结点没访问完，同时相邻结点都访问完毕
		{   visitednum--;							 //开始回溯过程	
			row=stackarray[visitednum];				 //从保存的路径中回退到上一个已访问结点
		}
   }
}
/*
void ALGraph::TDFSTraverse(int row,int flag[])//深度优先遍历函数
{

}
*/

//////////////////////////////////////////////////////////////////////////////////
void ALGraph::BFSTraverse()//广度优先遍历入口
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

////////////////////////////////////////////
//界面处理函数声明
int i;							//循环变量
int nodestart,nodeend,weight;	//起始点、终止点、权值
void showmenu(void);
void processmenu(void);
//界面处理函数实现
void showmenu(void)
{
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t     无向图相关功能演示(存储结构邻接表)             \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      1.读入默认文件数据建立无向图                  \n");
	printf("\t      2.给定文件名读入其他数据文件                  \n");
	printf("\t      3.显示本无向图的邻接表                        \n");
	printf("\t      4.求图的结点数和边数                          \n");
	printf("\t      5.求某条边的权值                              \n");
	printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t      d.深度优先遍历                                \n");
	printf("\t      b.广度优先遍历                                \n");
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
	char filename[50];//保存用户输入的文件路径
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
		printf("当前图的邻接表如下:\n");
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
	SetConsoleTitle("无向图常用操作的实现 存储结构为邻接表");//设置窗口标题
	system("color f0");//设置颜色为白底黑字
    system("cls");//清屏
	ifbuild=0;//开始时设置为没有建立图
	int i;//循环时使用的控制变量
	/*for(i=0;i<4;i++)//建立了四个链表的初始化
	{
		list[i].headp=(struct nodelink *)malloc(sizeof(nodelink));//建立链表头结点
		list[i].headp->next=NULL;//链域指向空
		list[i].number=0;//结点个数初始化为0
	}*/
    while (1)//永真循环
    {
        showmenu();//显示菜单
        processmenu();//处理菜单
        system("pause");//暂停一下
        system("cls");//清屏
    }
    return 0;//结束本次运行
}//主函数结束

