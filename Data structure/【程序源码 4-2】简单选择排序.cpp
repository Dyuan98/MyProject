//功能：使用内置数据，从小到大排序输出。
//思路:利用函数display(int data[],int length)完成显示，利用
//函数 simpleselectsort(int data[],int length)完成排序功能。
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //数组大小预定义,空置0单元
void simpleselectsort(int data[],int length);//简单选择排序函数
void display(int data[],int length);//遍历所有数据
void dataInput(int data[],int length);//用户自定义数据
/*……………………………………………………………………//
函 数 名:main（）
描    述:主函数
入口参数:无
出口参数:无
//……………………………………………………………………*/
int main()
{
	SetConsoleTitle("简单选择排序法");
	int choose,length;
	system("color f0"); 
	int dataUser[MAXSIZE];
	while(1)
	{
		system("cls");
		printf("                ===========================\n");
		printf("                简单选择排序法             \n");
		printf("                1.启用内部默认数组并排序   \n");
		printf("                2.手动输入数据并排序       \n");
		printf("                3.退出\n");
		printf("                ===========================\n");
		int dataDefault[11]={17,60,1,12,5,7,63,30,87,3};//默认数据，空置0单元，里面放置9999作为记号
		printf("请输入功能选项：\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			length = 10;
			printf("已从内部数组创建好10个数据.\n排序前：\n");
			display(dataDefault,length);
			simpleselectsort(dataDefault,length);
			printf("排序后为： \n");
			display(dataDefault,length);
			break;
		case 2:
			printf("请输入数据的个数:（注意不要大于%d）\n",MAXSIZE);
			scanf("%d",&length);
			dataInput(dataUser,length);
			simpleselectsort(dataUser,length);
			printf("排序后为： \n");
			display(dataUser,length);
			break;
		case 3:
			printf("谢谢使用!\n");
			return 0;
		default:
			printf("输入的功能选项有误，请重新输入！\n");
		}
		system("pause");
	}
	return 0;	
}

/*……………………………………………………………………//
函 数 名:inputData
描    述:用户自定义数据的输入
入口参数:数组名，输入数据的长度长度
出口参数:无
//……………………………………………………………………*/
void dataInput(int dataInput[],int length)
{
	int i;
	printf("请输入%d个数据（用空格隔开）:\n",length);
	for(i=0;i<length;i++)
		scanf("%d",&dataInput[i]);
}
/*……………………………………………………………………//
函 数 名:display
描    述:遍历所有数据
入口参数:数组名，线性表长度
出口参数:无
//……………………………………………………………………*/
void display(int data[],int length)//遍历所有数据
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d  ",data[i]);
	}
	printf("\n");
}
/*……………………………………………………………………//
函 数 名:simpleselectsort
描    述:完成元素的排序
入口参数:数组名，线性表长度
出口参数:无
//……………………………………………………………………*/
void simpleselectsort(int data[],int length)  //简单选择排序函数
{
	int pos;//指向未排数据的首位置
	int i,j,item;
	for(pos=0;pos<length;pos++)
	{
		item=data[pos];
		for(i=pos;i<length;i++)
			if(data[i]<=item)
			{
				item=data[i];//保留未排数据最小数据
				j=i;          //保留未排数据最小数据的位置
			}
		data[j]=data[pos];
		data[pos]=item;
	}
}
