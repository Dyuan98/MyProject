/*����������
ͼ���ڽӱ�ʵ�ֻ�������
*/
//�������в���Դ����Ҫ��һ��������
#include<windows.h>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
                 haveason,havetwosons,range_error,quit
                };					//���巵����Ϣ�嵥

#define  size 21//������Լ��Ϊ20������1�ŵ�ַ��ʼʹ��
int build;		//��־λ������ĿǰΪ�ձ�
//������
class Node                                       
{
public:
    int	  data;                                     
    Node *next;                             
    Node()                                       
    {                                           
        this->next = NULL;
    }
    Node(int data, Node *next=NULL)             //�����㣬ָ��Ԫ�غͺ�̽��
    {
        this->data = data;
        this->next = next;
    }
};
//�������
class linklist                           
{    
private:	
	Node *head;								//�������ͷָ��
public:
	int   length;							//���ݸ���
    linklist();								//���캯��     
    ~linklist();							//��������
	int   clearlink();						//��������е�����
    int   setheadNULL();					//��ͷ���������ÿ�
    void  printlinklist();					//��������	
    Node *inserthead(int data);				//�ѽ������ڵ�һ��λ����Ϊͷ���
    Node *insert(int x,int i);				//��xֵ���뵽��i��λ��           
    int   getheaddata();					//ȡ��ͷ����е�ֵ
	bool  del(int data) ;					//ɾ��ֵΪdata�Ľ��
    Node  *find(int value, Node* start);	//��start��㿪ʼ��ֵΪvalue�Ľ��      
    Node  *find(int value);					//����ֵΪvalue�Ľ��
	int   *nodetoarraydata();				//����������ת��Ϊ��������
   	int   findsmallernum(int data);			//�ҵ���dataС�����ݸ���
	int   getnextnode(int i);				//�����ڽӵ���һ�����
};
linklist::linklist()          //����յ�����
{
    this->head  =NULL;
	this->length=0;
}
linklist::~linklist()        
{
    this->head  =NULL;//�������ͷŴ˴�û��д
}
int linklist::clearlink()//��������б���Ϣ�ĵ�
{
	Node *searchp=head->next;//head�д洢���ǽ������
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
void linklist::printlinklist()//�����������н��
{
	Node *searchp=head;
	if(searchp==NULL)
		cout<<"�����ݣ�";
	while(searchp!=NULL)                    //ѭ����ʾ��������
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
Node *linklist::insert( int data,int pos) //����data��Ϊ��pos����㣬�����²�����ָ��
{
    Node *followp;
	int j=0; 
	if (head==NULL || pos<=0)                      //ͷ����
    {
        followp = new Node(data, head);
        head = followp;
    }
    else                                        
    {
        Node *searchp=head;
	    while (searchp->next!=NULL&&j<pos-1)           //Ѱ�Ҳ���λ��
        {
            j++;
            searchp = searchp->next;
        }                                        //ѭ��ֹͣʱ��searchpָ���pos-1�������������һ�����
        followp = new Node(data, searchp->next);             //����data��Ϊsearchp���ĺ�̽��
        searchp->next = followp;
		length++;
    }
    return followp;
}
int linklist::getheaddata()//ͷ����Ƿ�Ϊ��
{
	if(head==NULL)
		return -1;
	else
		return head->data;
}
bool linklist::del(int data)  //ɾ��data���
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
Node *linklist::find(int value, Node *start)    //�ӵ�����start��㿪ʼ˳�����ָ��Ԫ��
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
int linklist::findsmallernum(int data)//�������С��ĳ�����ݵĸ���
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
int linklist::getnextnode(int pos)//ȡ����ͷ�����濪ʼ�ĵ�pos������ֵ
{
	Node *searchp=head->next;
	int nextnum=1;//λ�ü�����
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

//��ʽ���ж���
class linkqueue                                //��ʽ������
{
private:
	Node *front, *rear;                       //front��rear�ֱ�ָ����׺Ͷ�β���
public:
    linkqueue();                               //����ն���
    ~linkqueue();                              //����
    bool isempty();                              //�ж��Ƿ�ն���
    void enqueue(int x);                           //���
    int  dequeue();                                 //���ӣ������п����׳��쳣
    void printlinkqueue();
};
linkqueue::linkqueue()                    //����ն���
{
    front = rear = NULL;
}
linkqueue::~linkqueue()                   //��������
{
    Node *searchp=front, *followp;
    while (searchp!=NULL)//�ͷſռ�
    {
        followp = searchp;
        searchp = searchp->next;
        delete followp;
    }
    front = rear = NULL;
}
bool linkqueue::isempty()                   //�ж��Ƿ�ն���
{
    return front==NULL && rear==NULL;
}
void linkqueue::enqueue(int x)               //���
{
    Node *followp = new Node(x);
    if (isempty())
        front = followp;                               //�նӲ���
    else 
        rear->next = followp;                          //�����ڶ���֮β
    rear = followp;
}  
int linkqueue::dequeue()                      //���ӣ����ض�ͷԪ�أ������п����׳��쳣 
{
    if (!isempty())
    {
       int x = front->data;                       //ȡ�ö�ͷԪ��
       Node *searchp=front;
       front = front->next;                     //ɾ����ͷ���
       delete searchp;
       if (front==NULL)                         //�ն���ʱ����ָ��ͬ��
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
void quickSort(int table[], int length, int low, int high)        //һ�˿������򣬵ݹ��㷨
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
int *doquickSort(int array[], int length)               //��������
{
    quickSort(array, length, 0, length-1);				//�ĸ������������������ȡ����ߵ��±�
    return array;
}
/////////////////////////////////////////////////////////
//ͼ���ڽӱ����
class ALGraph
{
private:
	linklist *Graph;					//����һ�������ʵ��������ΪGraph
	linkqueue queue;					//����һ�����ӵ�ʵ��������Ϊqueue��Ϊ������ȱ���׼��
	int nodenumber;						//���ڲ�����Ž����±�λ�ã�ͬʱ��¼������
	int edgenumber;						//ʵ�ʱ�����¼
	int row;							//���ƽ�����������
	int i;								//ѭ������
	int nodenum,edgenum;				//��ʱ�洢������ͱ���
	int node[size];						//��ʱ�洢ͼ�Ľ��
	int *sortednodes;					//�洢�����Ľ��
	int startpoint,endpoint;			//��ʼ������ֹ���
public:
	ALGraph(int nodenumber=1,int edgenumber=0);//����������0�±꣬��nodenumber��1��ʼ��������ʼΪ0
	~ALGraph();
	void inigraph();					//ͼĿǰ����������Ա�������������
	void inputdata(void);				//�ֹ���������
	void autocreatgraph();				//����Ĭ������
	void showgraph();					//��ʾ�ڽӱ�
	void showtotalnodenumber();			//��ʾ����ܸ���
	void showtotaledgenumber();			//��ʾ�ߵ��ܸ���
	int  findnode(int nodedata);		//���ҽ���������е�����	
	void insertmanynodes(int data);		//һ�β���һ�����ʹ�õĲ����㺯��
	void insertonenode(int data);		//һ�ν�������һ�����ʹ�õĲ����㺯��
	Node *findedge(int startpoint,int endpoint);	//��������֮��ı�
	void searchnext(int data);						//������һ���ڽӵ�
	void DFSTraverse();								//������ȱ������
	void TDFSTraverse(int row,int flag[],int stackarray[]);			//������ȱ�������
	void BFSTraverse();								//������ȱ������
	void TBFSTraverse(int row,int flag[]);			//������ȱ����ݹ麯��
};
ALGraph::ALGraph(int nodenumber,int edgenumber)
{
	this->Graph=new linklist[size];//�������ڽӱ��ָ������
	this->nodenumber=nodenumber;
	this->edgenumber=edgenumber;
}
ALGraph::~ALGraph()
{
   delete[] Graph;
}
void ALGraph::inigraph()//ͼĿǰ����������Ա�������������
{
	for(i=1;i<nodenumber;i++)//�˴�ʵ���ϴ�����1ֻѭ������nodeposition-1�����꣬��������������
		Graph[i].clearlink();//�Ȱѱ���Ϣ��������ȫ��ɾ�����ͷſռ�
	for(i=1;i<nodenumber;i++)//�ٰѽ����Ϣ�������е������ÿ�
		Graph[i].setheadNULL();
	nodenumber=1;
	edgenumber=0;
}
void ALGraph::inputdata(void)
{
	inigraph();
	cout<<"�����������:";
	cin>>nodenum;
	if(nodenum<=0)
	{
		cout<<"���������д����β�������!!!"<<endl;
	}
	else
	{
		cout<<"��������:";
		for (i=0; i<nodenum; i++)
		cin>>node[i];
		sortednodes=doquickSort(node,nodenum);
		for (i=0; i<nodenum; i++)
			insertmanynodes(sortednodes[i]);
		cout<<"================"<<endl;
		cout<<"��ǰͼ���ڽӱ�����:"<<endl;
		showgraph();
		cout<<"������߸���:"<<endl;
		cin>>edgenum;
		if(edgenum<=0)
		{
			cout<<"���������д����β�������!!!"<<endl;
		}
		else
		{
			cout<<"������ÿ�������ӵ�������:"<<endl;//��Ҫ���ǵ㲻����
			for(i=0;i<edgenum;i++)
			{
				cin>>startpoint>>endpoint;
				if(findnode(startpoint)!=-1&&findnode(endpoint)!=-1)
					insertedge(findnode(startpoint),findnode(endpoint));
				else
					cout<<startpoint<<"��"<<endpoint<<"֮��ı߲����ڣ�"<<endl;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ���ڽӱ�����:"<<endl;
			showgraph();		
		}
	}
}
void ALGraph::autocreatgraph()//��������ͼĬ������
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
void ALGraph::showgraph()//��ʾͼ���ڽӱ���ʽ
{
	if(nodenumber==1)
		cout<<"Ŀǰͼû������!!!"<<endl;
	else
	{	
		cout<<"����"<<" �����"<<" �߹�ϵ����"<<endl;
		for(int i=1;i<nodenumber;i++)//�˴�ʵ���ϴ�����1ֻѭ������nodeposition-1�����꣬��������������
		{
			cout<<" "<<i<<"   ";
			Graph[i].printlinklist();//��ʾ�������е���������
			cout<<endl;
		} 
	}
}
void ALGraph::showtotalnodenumber()//��ʾ�ܽ�����
{
	cout<<nodenumber-1<<endl;//nodepositionÿ��ָ����һ�����ÿռ䣬��ʵ��������Ҫ��һ
}
void ALGraph::showtotaledgenumber()//��ʾ�ߵ��ܸ���
{
	cout<<edgenumber<<endl;
}
int ALGraph::findnode(int nodedata)//����Ƿ����
{
	row=0;//��ʵ���ݵ�ַ��1��nodenumber-1
	while((row<nodenumber) && (Graph[row].getheaddata()!=nodedata))//��û�������û���ҵ�ʱ
		row++;
    if(row>=nodenumber)//û���ҵ�ʱ
		row=-1;
	return row;
}

Node *ALGraph::findedge(int startpoint,int endpoint) //����startpoint��endpoint֮��ı�        
{           
	return Graph[startpoint].find(endpoint);        
}
void ALGraph::searchnext(int data)//����data�����ڽ��
{
	int *adjvexdataarray;
	if(Graph[findnode(data)].length==1)
	{
		cout<<data<<"û�����ڽ��!!!"<<endl;
	}
	else
	{
		adjvexdataarray=Graph[findnode(data)].nodetoarraydata();
		cout<<data<<"�����ڽ��Ϊ��";
		for(int i=1;i<adjvexdataarray[0];i++)
			cout<<Graph[adjvexdataarray[i]].getheaddata()<<"  ";
		cout<<endl;
		delete[] adjvexdataarray;
	}
}
void ALGraph::DFSTraverse()//������ȱ������
{
	int *flag=new int [nodenumber];	//��㱻���ʱ�־��0��ʾδ�����ʣ�1��ʾ�ѷ���
	for(i=1;i<nodenumber;i++)	//��־λ�����ʼ����ȫ����ֵΪ0
		flag[i]=0; 
	int	*stackarray=new int [nodenumber+1];//����·�������飬��ջ������
	for(i=0;i<nodenumber;i++)//��ʼ״̬ȫ����ֵΪ-1
	{
		stackarray[i]=-1;
	}
	for(i=1;i<nodenumber;i++)		//ÿһ����㶼��Ϊ��ʼ���һ�Σ�ȷ������ͨͼҲ������ɱ���
		if(flag[i]==0)
			TDFSTraverse(i,flag,stackarray);
}
////////////////////////////////////////////////////////////////////////////////////
void ALGraph::TDFSTraverse(int row,int flag[], int stackarray[])//������ȱ�������
{
		int *adjvexdataarray1;	//�ڽӱ���Ϣ����ת���ɵ�����
	int nextnum;			//��һ���ڽӵ�ı��
	int visitednum=1;		//�ѷ��ʽ��ĸ���
    //if(row==-1) return;
	stackarray[0]=1;		//0�������д�ŷ��ʹ��Ľ���������˴�Ԥ��Ϊ1���������ʽ��������Ҫ��һ
	while(row!=-1 && stackarray[0]<nodenumber)//����������ڲ����ѷ��ʵĽ������û�е����ܽ������ѭ��
	{
		if(flag[row]==0)							//���û���ʣ��ͷ���
		{
			cout<<Graph[row].getheaddata()<<"  ";	//�Ѹñ�Ŷ�Ӧ�Ľ�������
			stackarray[stackarray[0]]=row;          //����·����Ϣ
	        stackarray[0]++;                        //stackarray[0]-1Ϊ����ѷ��ʽ�����
			flag[row]=1;
		}
		adjvexdataarray1=Graph[row].nodetoarraydata();//�������������ڽӽ����Ϣת�������飬��ַ��1��ʼ
		///////////////
		//cout<<"������ÿ��ÿһ�н����Ϣת��Ϊ��������Ϣ"<<endl;
		//for(i=1;i<nodenumber;i++)
		//	cout<<adjvexdataarray1[i]<<endl;
		//cout<<"ÿһ�н����Ϣת��Ϊ��������Ϣ����"<<endl;
		///////////////
		nextnum=1;									 //��ʼ�����һ�����ڽ��	                       
	    row=Graph[row].getnextnode(nextnum);		 //��ȡ���ڽ���Ӧ�ڽ�������е��к�
		while(flag[row]==1 && row!=-1 && stackarray[0]<nodenumber)//����ý�㱻���ʹ��������һ���ڽӵ�
			row=adjvexdataarray1[nextnum++];			 //ֱ���ҵ�һ��û�б����ʹ��Ľ���� 
		
		
		//TDFSTraverse(row,flag,stackarray);//���µ�һ�н��룬�ݹ���ɱ�������
		visitednum=stackarray[0]-1;                  //��¼�ѷ������ݸ���
		if(stackarray[0]<nodenumber && row==-1)      //���û�����꣬ͬʱ���ڽ�㶼�������
		{   visitednum--;							 //��ʼ���ݹ���	
			row=stackarray[visitednum];				 //�ӱ����·���л��˵���һ���ѷ��ʽ��
		}
   }
}
/*
void ALGraph::TDFSTraverse(int row,int flag[])//������ȱ�������
{

}
*/

//////////////////////////////////////////////////////////////////////////////////
void ALGraph::BFSTraverse()//������ȱ������
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

////////////////////////////////////////////
//���洦��������
int i;							//ѭ������
int nodestart,nodeend,weight;	//��ʼ�㡢��ֹ�㡢Ȩֵ
void showmenu(void);
void processmenu(void);
//���洦����ʵ��
void showmenu(void)
{
	printf("\t����������������������������������������������������\n");
	printf("\t     ����ͼ��ع�����ʾ(�洢�ṹ�ڽӱ�)             \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      1.����Ĭ���ļ����ݽ�������ͼ                  \n");
	printf("\t      2.�����ļ����������������ļ�                  \n");
	printf("\t      3.��ʾ������ͼ���ڽӱ�                        \n");
	printf("\t      4.��ͼ�Ľ�����ͱ���                          \n");
	printf("\t      5.��ĳ���ߵ�Ȩֵ                              \n");
	printf("\t����������������������������������������������������\n");
	printf("\t      d.������ȱ���                                \n");
	printf("\t      b.������ȱ���                                \n");
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
	char filename[50];//�����û�������ļ�·��
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
		printf("��ǰͼ���ڽӱ�����:\n");
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
	SetConsoleTitle("����ͼ���ò�����ʵ�� �洢�ṹΪ�ڽӱ�");//���ô��ڱ���
	system("color f0");//������ɫΪ�׵׺���
    system("cls");//����
	ifbuild=0;//��ʼʱ����Ϊû�н���ͼ
	int i;//ѭ��ʱʹ�õĿ��Ʊ���
	/*for(i=0;i<4;i++)//�������ĸ�����ĳ�ʼ��
	{
		list[i].headp=(struct nodelink *)malloc(sizeof(nodelink));//��������ͷ���
		list[i].headp->next=NULL;//����ָ���
		list[i].number=0;//��������ʼ��Ϊ0
	}*/
    while (1)//����ѭ��
    {
        showmenu();//��ʾ�˵�
        processmenu();//����˵�
        system("pause");//��ͣһ��
        system("cls");//����
    }
    return 0;//������������
}//����������

