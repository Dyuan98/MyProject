//功能:顺序栈的功能演示
#include<stdio.h>//调入相关的头文件
#include<windows.h>
typedef struct seqStack//用结构体定义顺序栈
{
	int *stackSpace;									//栈空间的具体实现，在下面通过动态申请空间建立数组。
	int stackSize;										//栈的大小，当为0时，栈没有创建空间。
	int top;											//栈顶位置，当为-1时，栈为空。
}stack;													//把定义的栈命名为stack
//定义相关函数
void initStack(stack *st);								//首次初始化一个栈。
bool create(stack *st,int size);						//实际创建一个可以容纳size个元素的栈。
void destroy(stack *st);								//销毁一个栈。
bool isempty(stack *st);								//确定栈是否已空。
bool isfull(stack *st);									//确定栈是否已满。
bool push(stack *st,int *item);							//数据进栈。
bool pop(stack *st,int *item);							//出栈并且返回原栈顶的值
bool gettop(stack *st,int *item);						//取出当前栈顶数据。
void traverse(stack *st);                               //遍历栈中所有数据
//相关函数的实现
void initStack(stack *st)//首次初始化栈
{
    st->stackSpace=NULL;								//初始化，空间起始地址为空。
	st->stackSize=0;									//栈的大小，初始值为0。表示目前还没有建立。
	st->top=-1;											//栈顶位置，当为-1时，栈为空。
}
bool create(stack *st,int size)//按一定大小实际构建栈的函数
{
	if(st->stackSize)									//栈已经存在，不能再创建
		return false;
	if(size<=0)											//size的值必须大于零。
		return false;
	st->stackSpace=(int *)malloc(sizeof(int)*size);		//按照size的大小申请动态数组空间。
	if(!(st->stackSpace))								//没有申请到存储空间，创建栈不成功。
	    return false;
	st->stackSize=size;									//申请到存储空间，创建栈成功，大小为size。
	st->top=-1;											//栈刚建立成功时，栈顶指针为-1。
	return true;
}
void destroy(stack *st)//释放栈的空间，还给操作系统
{
	if(st->stackSpace)
		free(st->stackSpace);							//实际释放语句
	st->stackSpace=NULL;								//空间起始地址恢复为空。
	st->stackSize=0;									//栈的大小恢复为初始值0。表示目前还没有建立。
	st->top=-1;											//栈顶指针恢复为-1。
}
bool isempty(stack *st)//测试栈是否为空
{
    if(!st->stackSize)									//确定栈是否被创建。没有创建视为空。
		return true;
	return st->top==-1 ? true : false ;					//根据栈顶指针的位置返回是否为空。
}
bool isfull(stack *st)//测试栈是否为满
{
	if(!st->stackSize)									//确定栈是否被创建。没有创建视为满。
		return true;
	return (st->top)==(st->stackSize)-1 ? true : false;	//根据栈顶指针的位置返回是否为满。
}
bool push(stack *st,int *item)
{	
    if(!st->stackSize)									//如果栈没有被创建，则不能执行进栈操作。
		return false;
	if(isfull(st))										//如果栈空间已经满，则不能执行进栈操作。
		return false;
	st->top++;											//栈顶指针先行上移
	st->stackSpace[st->top]=*item;                      //当前位置存入要进栈的数据 
	return true;										//返回成功标志。
}
bool pop(stack *st,int *item)//出栈并且返回原栈顶的值
{
 	if(isempty(st))										//如果栈空间已经为空，则不能执行出栈操作。
		return false;
	*item=st->stackSpace[st->top];						//把要出栈的数据保存下来返回去
	st->top--;                                          //把栈顶指针向下移动一个地址
	return true;										//返回成功标志。
}
bool gettop(stack *st,int *item)//读取当前栈顶 
{
 	if(isempty(st))										//如果栈空间已经为空，则不能执行出栈操作。
		return false;
	*item=st->stackSpace[st->top];						//把栈顶数据保存起来返回。
    return true;										//返回成功标志。
}
void traverse(stack *st)//遍历栈中所有数据
{
	if(!st->stackSize)									//当栈中没有数据时则放弃显示所有数据。
		printf("栈尚未建立！\n");						//当栈中有数据时则显示所有数据。
	else
	{
		printf("目前栈中的内容是: ");
		printf("栈底■");
		for(int i=0;i<=st->top;i++)						//栈的空间从0到top指向的位置。
		    printf("%d  ",st->stackSpace[i]);			//输出每一个数据，同时间隔一个空格。
        printf("←top栈顶\n");
	}
}
//主程序开始
void main(void)
{
	SetConsoleTitle("顺序栈的功能演示");
	system("color f0");									//背景白色(f)，字体颜色为黑色(0)
	stack stacknow;										//定义一个栈，命名为stacknow		
	initStack(&stacknow);                               //将这个栈进行第一次初始化
	char yesno,userchoice='9';							//定义字符变量，用在下面的菜单处理
	int newstacksize,pushdata,popdata;					//定义整数变量，用于存储栈的大小，进栈的数据和出栈的数据
	while(1)											//永真循环
	{
		if(userchoice=='9')								//如果用户选择是默认值的话
		{
			system("cls");								//进行一次清屏
			printf("==========================\n");
		    printf("   顺序栈的功能演示          \n");
			printf("==========================\n");
		    printf("1: 创建一个栈             \n");
		    printf("2: 销毁一个栈。           \n");
		    printf("3: 数据进栈。（仅限整数） \n");
		    printf("4: 数据出栈。             \n");
		    printf("5: 显示栈中全部数据       \n");
			printf("6: 读取栈顶数据           \n");
			printf("7: 判断是否空栈。         \n");
		    printf("8: 判断是否满栈。         \n");
			printf("9: 清屏           \n");
		    printf("0: 退出。                 \n");
		}
		printf("请选择:");//提示用户输入
		fflush(stdin);//消除回车键影响
		scanf("%c",&userchoice);//从键盘读取用户的选择
		if(userchoice=='0')	//退出程序
			break;
		switch(userchoice)//根据用户选择分别处理
		{
		case '1'://必须先创建一个栈，才能压入数据
			printf("开始创建栈，请输入栈空间大小:");
			fflush(stdin);
			scanf("%d",&newstacksize);//输入栈的大小
            if(create(&stacknow,newstacksize))//根据输入的大小建立栈
				printf("创建栈成功，栈空间大小是:%d\n",newstacksize);
			else
				printf("创建栈失败！\n");
			break;
		case '2'://销毁一个栈
			printf("你真的要销毁栈吗？请输入(Y/y)确定，其他键为放弃:");
     		fflush(stdin);
			scanf("%c",&yesno);
			if(yesno=='Y'||yesno=='y')
			{
                destroy(&stacknow);//释放栈的空间
			    printf("栈已经销毁！\n");
			}
			break;
		case '3'://把数据压入栈
			printf("向栈压入数据:");
			fflush(stdin);
			scanf("%d",&pushdata);//输入要进栈的数据
            if(push(&stacknow,&pushdata))//如果进栈成功
			{
				printf("数据 %d 已成功进栈！\n",pushdata);
                traverse(&stacknow);		//把目前栈中全部数据显示一遍	
			}
			else
				printf("数据 %d 进栈失败！\n",pushdata);//进栈失败
			break;
		case '4'://从栈中弹出数据
            if(pop(&stacknow,&popdata))//如果出栈成功
			{	
				printf("从栈中成功地弹出数据:%d\n",popdata);//显示出栈的数据
				traverse(&stacknow);//把目前栈中全部数据显示一遍
			}
			else
				printf("出栈操作失败\n");
			break;
		case '5':
			traverse(&stacknow);//把目前栈中全部数据显示一遍
			break;
		case '6':
			if(gettop(&stacknow,&popdata))//仅仅读出栈顶数据
			{	
				printf("栈顶数据为:%d\n",popdata);
				traverse(&stacknow);//把目前栈中全部数据显示一遍
			}
			else
				printf("取栈顶数据操作失败\n");
			break;
		case '7'://栈是否已空
			if(isempty(&stacknow))//如果目前栈为空
				printf("目前是空栈或者栈尚未建立。\n");
			else
				printf("目前是非空栈。\n");
			break;
		case '8'://栈是否已满。
			if(isfull(&stacknow))//如果目前栈为满
                printf("目前是满栈或者栈尚未建立。\n");
			else
				printf("目前栈不满，还可以继续进栈。\n");
			break;
		case '9':
			break;
		default:
			printf("对不起，输入命令有错！\n");
			break;
		}
	}
}
