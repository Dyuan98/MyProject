//程序名：【程序源码 3-1】顺序表实现线性表的基本功能C版.cpp
//功能：完成线性表的新建、显示、插入、删除、读取、修改、求表长度，数据反转等功能
#include <stdio.h> //读入必须包含的头文件
#include <windows.h>//清屏和颜色设置需要   
#include <iomanip.h>  //数据函数的定义 
#define Maxsize 20      //定义线性表的最大长度
enum returninfo{success,fail,overflow,underflow,range_error};//定义返回信息清单
int dataarray[Maxsize];             //数据域数组
int count;                          //计数器 统计结点个数即线性表的长度
returninfo create(int number);                //顺序表的初始化
bool empty(void) ;                            //判断是否空
int length(void) ;                            //求顺序表的长度
returninfo traverse(void);                    //遍历顺序表所有元素
returninfo get(int position,int &item) ;      //读取一个结点
returninfo replace(int position,int &item);  //修改一个结点
returninfo insert(int position,int &item);   //插入一个结点
returninfo remove(int position);                   //删除一个结点
returninfo invertlist(void);                       //顺序表所有数据反转
void clearscreen(void);                        //清屏
void showmenu(void);                           //显示菜单函数
int userchoice(void);                          //用户的选项
returninfo processmenu(int menuchoice);//菜单函数
/*……………………………………………………………………//
函 数 名:create
描    述:建立链表
入口参数:无
出口参数:返回returninfo枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo create(int number)
{
	count=number;
    printf("请依次输入数据（用空格隔开）：\n");
	for(int i=0;i<count;i++)//从0下标开始
		scanf("%d",&dataarray[i]);//逐个输入数据
	return success;
}
/*……………………………………………………………………//
函 数 名:empty
描    述:判断链表是否为空
入口参数:无
出口参数:bool型
//……………………………………………………………………*/
bool empty(void)   //判断是否为空
{
	if(count==0)     //计数器为0，说明没有数据     
		return true;
	else
		return false;
}
/*……………………………………………………………………//
函 数 名:length
描    述:得到顺序表长度
入口参数:无
出口参数:int型
//……………………………………………………………………*/
int length(void)   //求顺序表的长度
{
	return count; //count中存储的就是数据个数              
}
/*……………………………………………………………………//
函 数 名:traverse
描    述:遍历全部数据
入口参数:无
出口参数:返回returninfo枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo traverse(void)            //遍历顺序表中的所有元素
{
	if(empty())
	    return underflow;                     //空表的处理
	printf("顺序表中的全部数据为:   ");         //提示显示数据开始
	for(int i=0;i<count;i++)                  //循环显示所有数据
		printf("%d ",dataarray[i]);
	printf("\n");                           //最后有一个回车的控制
	return success;                           //本次操作成功
}
/*……………………………………………………………………//
函 数 名:get
描    述:读取一个结点
入口参数:位置，int型引用
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo get(int position, int &item)   //读取一个元素
{
	if(empty())                             //空表的处理
		return underflow;	
	if(position<=0||position>count)         //处理意外
		return range_error;
	item=dataarray[position-1];             //返回读取的数据
	return success;                         //本次操作成功
}
/*……………………………………………………………………//
函 数 名:replace
描    述:修改指定位置数据
入口参数:位置，替换值
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo replace(int position,int &item)  //修改一个元素
{
	if(empty())                                
		return underflow;	
	if(position<=0||position>count)
		return range_error;
	dataarray[position-1]=item; //实际修改数据的语句，由于有0下标，所以此处减一
	return success;
}
/*……………………………………………………………………//
函 数 名:insert
描    述:插入数据到指定位置
入口参数:位置position，数据&item
出口参数:返回returninfo枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo insert(int position,int &item)    //插入一个元素
{
	if(count+1>=Maxsize)
		return overflow;                   //溢出处理
	if(position<=0 || position>count+1)      
		return range_error;
	count++;                                //计数器加一
	for(int i=count;i>=position;i--)        //循环移动数据，反向移动数据
	{
		dataarray[i]=dataarray[i-1];//实际移动数据
	}
	dataarray[position-1]=item;//实际插入的语句
	return success;
}
/*……………………………………………………………………//
函 数 名:remove
描    述:删除指定位置的数据
入口参数:位置position
出口参数:返回returninfo枚举型，判断操作是否成功
//……………………………………………………………………*/
returninfo remove(int position)   //删除一个元素
{
	if(empty())
		return underflow;	
	if(position<=0||position>count)
		return range_error;
	for(int i=position-1;i<count;i++)   //循环移动数据，正向移动数据
		dataarray[i]=dataarray[i+1];
	count--;                            //计数器减一
	return success;
}
/*……………………………………………………………………//
函 数 名:invertlist
描    述:反转顺序表数据
入口参数:无
出口参数:returninfo型，判断操作是否成功
//……………………………………………………………………*/
returninfo invertlist(void)    //顺序表所有数据反转
{
	int halfpos,tempdata;
	if(empty())
		return underflow;
	halfpos=count/2;//计算出中点
	for(int i=0;i<halfpos;i++)
	{
		tempdata=dataarray[i];//通过临时中间变量进行交换数据
		dataarray[i]=dataarray[count-1-i];
		dataarray[count-1-i]=tempdata;
	}
	return success;
}
void clearscreen(void)
{
    system("cls");
}
/*……………………………………………………………………//
函 数 名:showMenu
描    述:显示功能菜单
入口参数:无
出口参数:无
//……………………………………………………………………*/
void showmenu(void)
{
  	printf("顺序表基本功能菜单               \n");
    printf("==================               \n");
    printf("1.输入数据（键盘输入）           \n");
    printf("2.显示数据（遍历全部数据）       \n");
    printf("3.修改数据（要提供位置和新值）   \n");
    printf("4.插入数据（要提供位置和新值）   \n");
    printf("5.删除数据（要提供位置）         \n");
    printf("6.读取数据（要提供位置）         \n");
    printf("7.求表长度                       \n");
	printf("8.数据反转（全部数据逆序存储）   \n");
    printf("9.结束程序                       \n");
	printf("=================                \n");
}
/*……………………………………………………………………//
函 数 名:userchoice
描    述:得到用户输入的选项
入口参数:无
出口参数:返回输入选项
//……………………………………………………………………*/
int userchoice(void)
{	int menuchoice;
	printf("请输入您的选择：");   
	scanf("%d",&menuchoice);
	return menuchoice;
}
/*……………………………………………………………………//
函 数 名:processmenu
描    述:执行用户选择的功能
入口参数:功能选项
出口参数:无
//……………………………………………………………………*/
returninfo processmenu(int menuchoice)
{
	int position,item,returnvalue;
	switch(menuchoice)    //根据用户的选择进行相应的操作
	{
	case 1:		printf("请问你要输入数据的个数，注意要在%d个以内： ",Maxsize);
				scanf("%d",&item);
				if(item>Maxsize)
					printf("对不起，输入数据超限，操作已取消!\n");
				else
				{
					returnvalue=create(item);
					if(returnvalue==success)
					printf("建立顺序表操作成功!\n");
				}
				break;
	case 2:
				returnvalue=traverse(); 
				if(returnvalue==underflow)
					printf("顺序表目前为空，没有数据可以显示!\n");
				else
					printf("顺序表遍历操作成功!\n");
				break;
	case 3:
				printf("请输入要修改数据的位置：");
				scanf("%d",&position);
				printf("请输入要修改的新数据：");
				scanf("%d",&item); 
				returnvalue=replace(position,item);
				if(returnvalue==underflow)
				    printf("对不起，顺序表已空!\n");
				else if(returnvalue==range_error)
					printf("对不起，修改的位置超出了范围!\n");
				else
					printf("修改操作成功!\n");
				break;		
	
	case 4:
				printf("请输入要插入数据的位置：");
				scanf("%d",&position);
				printf("请输入要插入的新数据：");
				scanf("%d",&item);
				returnvalue=insert(position,item);
				if(returnvalue==overflow)
				    printf("对不起，顺序表溢出，无法插入新数据!\n");
				else if(returnvalue==range_error)
					printf("对不起，插入的位置超出了范围!\n");
				else
					printf("插入操作成功!\n");
				break;
			
	case 5:
				printf("请输入要删除数据的位置：");
				scanf("%d",&position);
				returnvalue=remove(position);
				if(returnvalue==underflow)
				    printf("对不起，顺序表已空!\n");
				else if(returnvalue==range_error)
					printf("对不起，删除的位置超出了范围!\n");
				else
					printf("删除操作成功!\n");
				break;
	case 6:
				printf("请输入要读取数据的位置：");
				scanf("%d",&position);
				returnvalue=get(position,item);
				if(returnvalue==underflow)
				    printf("对不起，顺序表已空!\n");
				else if(returnvalue==range_error)
					printf("对不起，读取的位置超出了范围!\n");
				else
					printf("读取的数据为：%d\n读取操作成功!\n",item);
			    break;
			
	case 7:
				printf("顺序表目前的长度为: %d\n",length());
				printf("求顺序表长度操作成功!\n");
				break;
							
	case 8:
				returnvalue=invertlist();
				if(returnvalue==underflow)
				    printf("对不起，顺序表已空!\n");
				else 
					printf("顺序表所有元素反转操作成功!\n");
				break;	
	case 9:     
		        exit(0);
	default:
				printf("对不起，您输入的功能编号有错!请重新输入!!!\n");
		    	break;
		}
		return success;
}
/*……………………………………………………………………//
函 数 名:main
描    述:主函数
入口参数:无
出口参数:无
//……………………………………………………………………*/
void main(void)                     //程序主入口
{   
	SetConsoleTitle("顺序表实现线性表的基本功能（C版）");
	int menuchoice; //定义变量，菜单选单项的选择                
	system("color f0");//修改屏幕的背景色和字的颜色
	clearscreen();//清屏
    while (1)//永真循环
	{
  		showmenu();//显示菜单
		menuchoice=userchoice();//获取用户的选择
		processmenu(menuchoice);//处理用户的选择
		system("pause"); //暂停
		clearscreen();//清屏
    }
}//主函数结束
