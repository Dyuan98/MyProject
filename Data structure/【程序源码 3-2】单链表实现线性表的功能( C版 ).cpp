//程序名：【程序源码 3-2】单链表实现线性表的功能（纯C版）.cpp
//功能：完成单链表的新建、显示、插入、删除、读取、修改、反转等功能。
#include <stdio.h>//读入必须包含的头文件
#include <malloc.h>//动态开辟空间要用的头文件
#include<windows.h>//清屏和颜色设置需要
#define  len sizeof(struct node)//结构体node的长度，即要申请空间的长度
#define MAXNUMOFBASE 5//定义常量表示数组的最大容量
enum  returninfo{success,fail,overflow,underflow,range_error};//定义返回信息清单
int   sourcedata[MAXNUMOFBASE]={11,22,33,55,66};  //内部数据数组，节省每次建立时输入时间
struct node                                        //结点结构体
{
	int data;                                      //数据域
	struct node *next;                                    //指针域
};
struct node *headp;                                //全局变量，定义了头指针
int count;                                         //全局变量，定义了计数器，统计线性表长度
//功能函数
void initList();                                   //初始化链表，启动headp
int length();                                      //求链表长度
void showMenu();                                   //显示菜单
bool empty();                                      //判断是否空链
int  userchoose();                                 //返回用户的选择
returninfo create();                               //使用数据建立链表
void clearlist(void);                              //清空链表
returninfo traverse();                             //遍历链表
returninfo invertlist();                           //反转链表数据
void function(int choose);                         //执行指定功能
int getcount(){return count;};                     //得到当前结点个数
returninfo remove(int position);                   //删除结点
returninfo insert(int position,int item);          //插入结点
returninfo retrieve(int position, int &item);      //读取一个结点 
returninfo replace(int position,int &item);        //修改一个结点
/*……………………………………………………………………//
函 数 名:IniList
描    述:初始化链表
入口参数:无
出口参数:无
//……………………………………………………………………*/
void initList()
{
	headp=(struct node *)malloc(len);//申请头结点空间
	headp->next=NULL;               //尾指针指向空，即NULL
	count=0;                        //计数器清零
}
/*……………………………………………………………………//
函 数 名:length
描    述:得到链表长度
入口参数:无
出口参数:int型
//……………………………………………………………………*/
int length()
{
	return count;   //返回链表长度
}
/*……………………………………………………………………//
函 数 名:empty
描    述:判断链表是否为空
入口参数:无
出口参数:bool型
//……………………………………………………………………*/
bool empty()
{
	if(headp->next==NULL) //如果headp->next==NULL则为空 
		return true;
	else
		return false;
}
/*……………………………………………………………………//
函 数 名:clearlist
描    述:清空链表
入口参数:无
出口参数:无
//……………………………………………………………………*/
void clearlist(void)        //清空链表
{
	struct node *searchp=headp->next,*followp=headp;    //初始化两个指针，定义时同时赋初值
    while(searchp!=NULL) //从开始到结束一直循环         
	{	
		followp=searchp;       //尾随指针指向searchp指向的结点，便于后面的释放操作
		searchp=searchp->next;//指针指向下一个结点
		free(followp);       //删除跟随指针所指向的结点
	}
	headp->next=NULL;         //保留了头结点
	count=0;                  //计数器清零
}
/*……………………………………………………………………//
函 数 名:create
描    述:建立链表
入口参数:无
出口参数:返回returnvalue枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo create()
{
	struct node *searchp=headp,*newnodep;    //定义两个指针，便于后面的挂链
	int i;
	for(i=0;i<MAXNUMOFBASE;i++)             //循环创建结点
	{
		newnodep=(struct node *)malloc(len);//申请空间,此处对于申请失败并没有处理
		newnodep->data=sourcedata[i];       //把数组中的数据存入链表的结点
		searchp->next=newnodep;            //开始挂链
		searchp=searchp->next;             //搜索指针searchp指向当前最后一个结点
		count++;                           //计数器加1
	}
	searchp->next=NULL;                   //挂链结束
	return success;                       //返回建立链表成功的信息
}
/*……………………………………………………………………//
函 数 名:remove
描    述:删除指定位置的数据
入口参数:位置position
出口参数:返回returnvalue枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo remove(int position)               //删除指定位置的结点
{
	int i;
	node *searchp=headp->next,*followp=headp;//单链表需要用followp才可删除找到的结点
	for(i=0;i<position&&searchp!=NULL;i++)   //用searchp！=NULL作为截止条件
	{
		followp=searchp;                     //followp始终跟着searchp
		searchp=searchp->next;               //searchp指向下一个结点
	}
	followp->next=searchp->next;           //通过改链真正删除结点
	free(searchp);                        //释放searchp所指结点所占的空间
	count--;                               //计数器减1
	return success;                        //返回删除成功信息
}
/*……………………………………………………………………//
函 数 名:insert
描    述:插入数据到指定位置
入口参数:位置position，数据item
出口参数:返回returnvalue枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo insert(int position,int item)                     //在指定位置插入信息
{
	int i;
	node *searchp=headp,*newnodep=(struct node *)malloc(len);//申请空间
	newnodep->data=item;                                     //将要插入的值赋值给结点的数据域
	for(i=0;i<position&&searchp->next!=NULL;i++)             //通过循环使searchp指向指定位置的前面
	{
		searchp=searchp->next;                               //searchp指向下一个
	}
	newnodep->next=searchp->next;                           //真正的插入语句开始
	searchp->next=newnodep;                                 //将新结点挂到链表
	count++;                                                //计数器加1
	return success;                                         //返回插入成功信息
}
/*……………………………………………………………………//
函 数 名:traverse
描    述:遍历全部数据
入口参数:无
出口参数:返回returnvalue枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo traverse()      //遍历全部数据
{
	node *searchp;        //定义一个指向结构体node的指针
	if(empty())           //先判断链表是否惟恐
	{
		return underflow;//如果为空的话返回下溢信息
	}
	searchp=headp->next;//跳过头结点
	while(searchp!=NULL)//通过循环输出链表的全部数据
	{
		printf("%d  ",searchp->data);//输出当前结点数据域
		searchp=searchp->next;       //searchp向下移一个
	}
	printf("\n");                    //换行
	return success;                  //返回插入成功信息
}
/*……………………………………………………………………//
函 数 名:invertlist
描    述:反转链表数据
入口参数:无
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo invertlist()           //反转链表数据
{
	node *nowp,*midp,*lastp;     //启用多个辅助指针
	if(empty())                  //先判断链表是否为空
		return underflow;        //若为空返回下溢信息
	nowp=headp->next;            //否则nowp指向实际第一个结点
	midp=NULL;                   //midp先赋值为NULL
	while(nowp!=NULL)            //通过循环改变链表方向，到达反转的目的    
	{
		lastp=midp;              //通过下面几句改链可以达成反转的效果
		midp=nowp;
		nowp=nowp->next;
		midp->next=lastp;
	}
	headp->next=midp;         //头指针指向之前的最后一个结点，反转
	return success;
}
/*……………………………………………………………………//
函 数 名:retrieve
描    述:读取一个结点
入口参数:位置，int型引用
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo retrieve(int position, int &item)   
{
	if(empty())                              //处理意外，空表
		return underflow;	
	if(position<=0||position>=count+1)       //处理意外，范围不正确
		return range_error;
	node *searchp=headp->next;             //定义搜索指针，初始化
	for(int i=1; i<position && searchp!=NULL;i++)   //提示：注意小于号 
        searchp=searchp->next;    //顺序访问方式，用循环，算法复杂度是O(n)
	item=searchp->data;           //返回读取的数据
	return success;               //本次操作成功
}
/*……………………………………………………………………//
函 数 名:replace
描    述:修改指定位置数据
入口参数:位置，替换值
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo replace(int position,int &item)//修改数据
{
	if(empty())                                //处理意外，空表                            
		return underflow;	
	if(position<=0||position>=count+1)         //处理意外，范围不正确
		return range_error;
	node *searchp=headp->next;                  //启动搜索指针
	for(int i=1; i<position && searchp!=NULL;i++)//通过循环找到位置
        searchp=searchp->next; 
	searchp->data=item;           //实际修改数据的语句
	return success;
}
/*……………………………………………………………………//
函 数 名:showMenu
描    述:显示功能菜单
入口参数:无
出口参数:无
//……………………………………………………………………*/
void showMenu()
{
	printf("===========================        \n");
	printf("     单链表的基本操作              \n");
	printf("===========================        \n");
	printf("1.输入数据（内部用数组提供5个数据）\n");
	printf("2.显示数据（遍历全部数据）         \n");
	printf("3.插入数据（要提供位置和新值）     \n");
	printf("4.删除数据（要提供位置）           \n");
	printf("5.读取数据（要提供位置）           \n");
	printf("6.修改数据（要提供位置和新值）     \n");
	printf("7.求表长度                         \n");
	printf("8.反转链表所有数据                 \n");
	printf("9.退出程序                         \n");
	printf("===========================        \n");
}
/*……………………………………………………………………//
函 数 名:userchoose
描    述:得到用户输入的选项
入口参数:无
出口参数:返回输入选项
//……………………………………………………………………*/
int userchoose()                //返回用户的选择
{
	int choose;
	printf("请输入功能选项：");
	scanf("%d",&choose);
	return choose;
}
/*……………………………………………………………………//
函 数 名:function
描    述:执行用户选择的功能
入口参数:功能选项
出口参数:无
//……………………………………………………………………*/
void function(int choose)
{
	int returnvalue,position,item;
	if(choose<=0||choose>9)              //若输入的功能编号大于9或小于0则提示用户无效
		printf("输入的功能编号无效!\n");
	else
	{
		switch(choose)
		{
		case 1:
			returnvalue=create(); 
			if(returnvalue==success)
				printf("建立链表操作成功!\n");
			break;
		case 2:
			returnvalue=traverse();
			if(returnvalue==underflow)
			{
				printf("对不起是空表，无内容显示!\n");
			}
			else
			{
				printf("显示完毕...\n");
			}
			break;
		case 3:
			printf("请输入要插入的位置:");
			scanf("%d",&position);
			if(position<=0||position>getcount()+1)
			{
				printf("对不起你输入的位置超出范围!\n");
			}
			else
			{
				printf("请输入要插入的数据:  \n");
				scanf("%d",&item);
				returnvalue=insert(position-1,item);//注意这个位置的参数
				printf("插入成功....\n");
			}
			break;
		case 4:
			printf("请输入要删除数据的位置:");
			scanf("%d",&position);
			if(position<0||position>getcount())
			{
				printf("对不起你输入的位置超出范围!\n");
			}
			else
			{
				returnvalue=remove(position-1);//注意这个位置的参数
				printf("删除成功....\n");
			}
			break;
		case 5:
			printf("请输入要读取数据的位置：");
			scanf("%d",&position);
			returnvalue=retrieve(position,item);
			if(returnvalue==underflow)
			    printf("对不起，链表已空!\n");
			else if(returnvalue==range_error)
				printf("对不起，读取的位置超出了范围!\n");
			else
				printf("读取的数据为：%d  读取操作成功!\n",item);
		    break;
		case 6:
			printf("请输入要修改数据的位置：");
			scanf("%d",&position);
			printf("请输入要修改的新数据：");
            scanf("%d",&item);
			returnvalue=replace(position,item);
			if(returnvalue==underflow)
			    printf("对不起，链表已空!\n");
			else if(returnvalue==range_error)
				printf("对不起，修改的位置超出了范围!\n");
			else
				printf("修改操作成功!\n");
			break;	
		case 7:
			printf("链表目前的长度为: %d\n",length());
			printf("求链表长度操作成功!\n");
			break;
		case 8:
			printf("反转前为：\n");
			traverse();
			invertlist();
			printf("所有数据反转成功...\n");
			printf("反转后的数据为：\n");
			traverse();
			break;
		case 9:
			printf("谢谢使用...\n");
			exit(0);
			break;
		}
	}
}
/*……………………………………………………………………//
函 数 名:main
描    述:主函数
入口参数:无
出口参数:无
//……………………………………………………………………*/
int main()
{
	SetConsoleTitle("单链表实现线性表的功能（C版）");
	int returnchoose;
	initList();            //初始化链表    
	while(1)               //永真循环，用来反复执行该程序
	{
		system("color f0");//设置背景和前景色
		showMenu();        //显示菜单
		returnchoose=userchoose();//得到用户的选择
		function(returnchoose);   //根据用户的选择choose执行特定的功能
		system("pause");          //暂停一下
		system("cls");            //清屏
	}
	return(-1); 
}
