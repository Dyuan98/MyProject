//功能：完成链栈的基本操作。
#include<malloc.h>
#include<windows.h>
#include<stdio.h>
struct stacknode//用结构体定义链表的结点
{
	int data;
	stacknode *next;
};
//定义相关变量和默认数组
#define SIZE 5//定义默认数组长度
int sourceData[SIZE]={11,22,33,44,55};  //内部数据数组，节省每次建立时输入时间
enum returninfo{success,fail,underflow,range_error};//定义返回信息清单
#define  len sizeof(struct stacknode)//结构体stacknode的长度，即要申请空间的长度
int stackLength;//链栈中数据个数
stacknode *linkStackTop;//链栈的头指针
stacknode *newnodep;    //定义指针，用于新数据进栈
stacknode *usedNodep;   //定义指针，指向出栈结点
bool flag = false;//标志链栈是否建立
//定义相关函数
bool isempty();                    //判断栈是否为空
returninfo display();              //显示栈中所有元素
int getLength();                   //获取栈的长度
int userchoose();                   //得到用户选择
returninfo pop(int &item);         //出栈，并把数据返回
void showMenu();                   //显示菜单
void function(int choose);         //执行指定功能
returninfo initStack();            //初始化链栈
returninfo create();               //根据内部默认数组创建一个栈
returninfo destroy();              //销毁一个栈
returninfo push(int &item);        //将数据进栈	
returninfo poponly();              //出栈不返回数值并且释放当前栈元素的空间
returninfo gettop(int &item);     //得到栈顶元素
/*……………………………………………………………………//
函 数 名:initStack
描    述:初始化链栈
入口参数:无
出口参数:返回初始化是否成功的信息
//……………………………………………………………………*/
returninfo initStack()
{
	linkStackTop = (stacknode *)malloc(len);//申请空间，构建头结点
	if(!linkStackTop)
		return fail;//如果没有申请到空间，返回失败
	linkStackTop->next = NULL;//开始时为空
	stackLength = 0;//开始时链栈的长度为零
	return success;
}
/*……………………………………………………………………//
函 数 名:create
描    述:节省时间，从内部数组创建默认链栈
入口参数:无
出口参数:返回创建是否成功的信息
//……………………………………………………………………*/
returninfo create()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		newnodep = (stacknode *)malloc(len);//申请空间
		if(!newnodep)                        //如果没有申请到空间，返回失败
			return fail;
		newnodep->data = sourceData[i];    //赋值
		newnodep->next = linkStackTop->next;//挂链
		linkStackTop->next = newnodep;             //改链，完成进栈   
		stackLength++;                //栈的长度增加
	}
	return success;                   //返回成功信息
}
/*……………………………………………………………………//
函 数 名:destroy
描    述:销毁一个栈
入口参数:无
出口参数:返回栈是否销毁成功的信息
//……………………………………………………………………*/
returninfo destroy()
{
	if(poponly()==underflow)
		return underflow;//若链栈为空则返回下溢
	while(poponly()==success);       //通过一直出栈，而每次释放空间在出栈中完成
	return success;     //返回成功信息
}
/*……………………………………………………………………//
函 数 名:isempty
描    述:判断栈是否为空
入口参数:无
出口参数:返回栈是否为空的信息
//……………………………………………………………………*/
bool isempty()
{
	if(stackLength==0)
		return true;
	else
		return false;
}
/*……………………………………………………………………//
函 数 名:getLength
描    述:得到栈的长度
入口参数:无
出口参数:返回栈的长度信息
//……………………………………………………………………*/
int getLength()
{
	return stackLength;
}
/*……………………………………………………………………//
函 数 名:push
描    述:数据进栈
入口参数:要进栈的元素数值
出口参数:返回进栈是否成功
//……………………………………………………………………*/
returninfo push(int &item)
{
	newnodep = (stacknode *)malloc(len);  //申请空间
	if(!newnodep)                              //如果没有申请到空间，返回失败
		return fail;
	newnodep->data = item;                     //赋值
	newnodep->next = linkStackTop->next;       //挂链
	linkStackTop->next = newnodep;             //改链，完成进栈              
	stackLength++;                             //栈的长度增加
	return success;                            //本次操作成功
}
/*……………………………………………………………………//
函 数 名:poponly
描    述:出栈但不返回数据并释放空间
入口参数:
出口参数:返回出栈是否成功
//……………………………………………………………………*/
returninfo poponly()
{
	if(!isempty())                      //判断是否为空，并且要保留头结点
	{
		usedNodep = linkStackTop->next;        //指向出栈结点
		linkStackTop->next = usedNodep->next;  //头指针向后
		free(usedNodep);                //用free释放空间
		stackLength--;                  //栈的长度减少
		return success;                 //本次操作成功
	}
	return underflow;                   //返回下溢
}
/*……………………………………………………………………//
函 数 名:pop
描    述:数据出栈，并返回数据
入口参数:通过引用得到栈顶数据
出口参数:返回出栈是否成功
//……………………………………………………………………*/
returninfo pop(int &item)
{
	if(isempty())
		return underflow;            //返回下溢
	usedNodep = linkStackTop->next;         //指向出栈结点
	linkStackTop->next = usedNodep->next;   //头指针向后移动
	item = usedNodep->data;        //将结点的指针域赋值给item
	delete usedNodep;               //释放空间
	stackLength--;                  //栈的长度减少
	return success;                 //本次操作成功
}
/*……………………………………………………………………//
函 数 名:gettop
描    述:返回栈顶数据
入口参数:通过引用得到栈顶数据
出口参数:返回出栈是否成功
//……………………………………………………………………*/
returninfo gettop(int &item)
{
	if(isempty())
		return underflow;     //返回下溢
	item = linkStackTop->next->data;//将栈顶结点的指针域赋值给item
	return success;
}
/*……………………………………………………………………//
函 数 名:display
描    述:显示栈的所有数据
入口参数:通过引用得到栈顶数据
出口参数:返回出栈是否成功
//……………………………………………………………………*/
returninfo display()
{
	stacknode *searchp=linkStackTop->next;//定义指针searchp，准备指向要显示的结点
	if(isempty())
		return underflow;        //返回下溢
	printf("目前栈中的内容是：栈顶-->");
	while(searchp)
	{
		printf("%d ",searchp->data);//显示当前结点数据
		searchp = searchp->next;     //searchp向后移动
	} 
	printf("栈底\n");
	return success;
}
/*……………………………………………………………………//
函 数 名:showMenu
描    述:显示菜单
入口参数:无
出口参数:无
//……………………………………………………………………*/
void showMenu()
{
	printf("=================                \n");
	printf("链栈的基本操作                   \n");
	printf("1、创建一个栈（启用内部默认数组）\n");
	printf("2、销毁一个栈                    \n");
	printf("3、数据进栈                      \n");
	printf("4、数据出栈                      \n");
	printf("5、显示所有数据元素              \n");
	printf("6、读取栈顶元素                  \n");
	printf("7、得到栈中元素个数              \n");
	printf("8、退出                          \n");
	printf("================                 \n");
	if(!flag)
		printf("提示：栈还未建立，要操作请先创建一个栈!\n");
	else
		printf("提示：栈已经建立，可以操作。\n");
}
/*……………………………………………………………………//
函 数 名:userchoose
描    述:得到用户输入的选项
入口参数:无
出口参数:返回输入选项
//……………………………………………………………………*/
int userchoose()
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
	int returndata,item;
	if(choose<=0||choose>8)
		printf("输入的功能编号无效!\n");
	else
	{
		switch(choose)
		{
		case 1:
			if(flag)
				printf("链栈已经建立请勿重复建立，可以执行其他操作!\n");
			else
			{
				returndata=create(); 
				if(returndata==success)
					printf("链栈建立成功!\n");
			}
			flag = true;
			break;
		case 2:
			if(!flag)
			{
				printf("对不起，栈尚未建立,不能执行此操作!\n");
				break;
			}
			returndata=destroy();
				printf("栈已销毁...\n");
			flag = false;
			break;
		case 3:
			if(!flag)
			{
				printf("对不起，链栈尚未建立，不能进栈!\n");
				break;
			}
			printf("请输入要进栈的数据:\n");
			scanf("%d",&item);
			returndata=push(item);//将数据进栈
			if(returndata==fail)
				printf("申请空间失败，无法进栈!");
			else
				printf("进栈成功....\n");
			break;
		case 4:
			returndata=pop(item);
			if(!flag)
				printf("对不起，栈尚未建立，无法出栈!\n");
			else if(returndata==underflow)
				printf("对不起，栈已空，无法出栈!\n");
			else
			{
				printf("%d ",item);
				printf("出栈成功....\n");
			}
			break;
		case 5:
			returndata=display();
			if(returndata==underflow)
				printf("对不起，栈尚未建立\n");
			else
				printf("显示完毕.....\n");
			break;
		case 6:
			returndata=gettop(item);
			if(returndata==underflow)
				printf("对不起，栈尚未建立!\n");
			else
			{
				printf("%d ",item);
				printf("栈顶元素读取成功....\n");
			}
			break;	
		case 7:
			if(isempty())
				printf("对不起，栈尚未建立!\n");
			else
				printf("栈中目前元素个数为: %d\n",getLength());
			break;
		case 8:
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
void main()
{
	SetConsoleTitle("链栈功能演示（C版）");//标题栏设置
	int returnvalue;//定义返回值
	system("color f0");//颜色设置
	returninfo info;//定义变量用来存储构建链表是否成功的返回信息
	info = initStack();//链表初始化
	if(info==fail)//如果失败则提示后退出系统
	{
		printf("对不起，初始化失败!\n");
		system("pause");
		exit(0);
	}
	while(1)//永真循环
	{
		showMenu();//显示菜单
		returnvalue=userchoose();//读取用户的选择
		function(returnvalue);//执行用户的选择
		system("pause");//暂停
		system("cls");//清屏
	}
}
