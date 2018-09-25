//功能：用三种细节不同的思路完成直接插入排序法
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //数组大小预定义
int defaultData[] = {-9999,11,77,88,66,33,44,55,22,99,0};//默认数组，结合下面的要空置0单元，这里不会用-9999
void showMenu();                            //显示菜单
void readkeyboarddata(int data[],int length);//从键盘读入数据
void Insertsort1(int dataHandle[], int n); //找到正确位置后成批移动 
void Insertsort2(int dataHandle[], int n); //边比较边移动
void Insertsort3(int dataHandle[], int n); //启动两个数据交换的函数
/*直接插入法思路之一：
通过找到已排空间中的一个正确位置，把待排空件的第一个数据插入到该位置
*/
void Insertsort1(int dataHandle[], int n)  
{  
    int i, j, k,countTraverse;//countTraverse用于后面遍历数组
	int timeMove = 0;     //移动总次数
	int timeCompare = 0;//比较次数
	for (i = 2; i <= n; i++)  //第一个不需要处理，其他的都要当成未排空间的第一个
    {
        //下面找正确位置  
        for (j = i - 1; j >= 1; j--)  
		{
			timeCompare++;
            if (dataHandle[j] < dataHandle[i])  
                break;  
		}
		//如果找到了一个合适的位置  
        if (j != i - 1)  
        {  
            //将比待排空间第一个数据更大的的数据成批向后移动，而且是反向移动
            int temp = dataHandle[i]; 
			timeMove++;//加一次
            for (k = i - 1; k > j; k--)  
			{
                dataHandle[k + 1] = dataHandle[k];  
			}
            //将待排空间第一个数据放到正确位置上  
            dataHandle[k + 1] = temp; //把临时放在外面的待排空间原来的第一个数据放入正确位置
			timeMove++;//加一次
			timeMove+=i-j-1;//减1是由于找正确位置时的for (j = i - 1; j >= 1; j--)  循环条件所致，使相当于下标的j减小了1
            for(countTraverse=1;countTraverse<=n;countTraverse++)//显示本次成批移动的数组内容
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
        }  
    }
	printf("一共比较了%d 次。\n",timeCompare);
	printf("移动的总次数为：%d\n",timeMove);
}  
/*思路：
对上面的排序思路进行一下改写，将搜索和数据后移这二个步骤合并。
*/
void Insertsort2(int dataHandle[], int n)  
{  
    int i, j,countTraverse;//countTraverse用于后面遍历数组  
	int timeMove = 0;//移动总次数
	int timeCompare = 0;//比较次数
    for (i = 2; i <= n; i++)  
	{
        if (dataHandle[i] < dataHandle[i - 1])  
        {
			timeCompare++;
            int temp = dataHandle[i];  
			timeMove++;//加一次
            for (j = i - 1; j >= 1 && dataHandle[j] > temp; j--)//边比边移
			{
				timeCompare++;
                dataHandle[j + 1] = dataHandle[j];  
			}
            dataHandle[j + 1] = temp;
			timeMove++;//加一次
			timeMove+=i-j-1;//减1是由于for (j = i - 1; j >= 1 && dataHandle[j] > temp; j--)中循环条件所致，使相当于下标的j减小了1
			for(countTraverse=1;countTraverse<=n;countTraverse++)//遍历数组
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
        } 
		else 
			timeCompare++;//这里加一次是因为即使不满足if条件，但也互相比较了
	}
	printf("一共比较了%d 次。\n",timeCompare);
	printf("移动的总次数为：%d\n",timeMove);
}  
/*
再对将未排空间第一个数据插入到前面有序区间所用的方法进行改写，
用数据交换代替数据后移。
*/
void Insertsort3(int dataHandle[], int n)  
{  
    int i, j,temp,countTraverse;//countTraverse用于后面遍历数组  
	int timeMove = 0;//移动总次数
	int timeCompare = 0;//比较次数
    for (i = 2; i <= n; i++) //由于未启用零号单元，故i从2开始
	{
        for (j = i - 1; j > 0 && dataHandle[j] > dataHandle[j + 1]; j--)  
		{
			timeCompare++;
			temp = dataHandle[j];
			dataHandle[j] = dataHandle[j+1];
			dataHandle[j+1] = temp;
			timeMove+=3;//两两交换数据算3次
		}
		if(j==i-1)//由于当a[j]<a[j+1]时，也比较了，但是timeCompare没加1，这里补上。
			timeCompare++;
		for(countTraverse=1;countTraverse<=n;countTraverse++)//遍历数组
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
	}
	printf("一共比较了%d 次。\n",timeCompare);
	printf("移动的总次数为：%d\n",timeMove);
} 
/*……………………………………………………………………//
函 数 名:showMenu
描    述:显示功能菜单
入口参数:无
出口参数:无
//……………………………………………………………………*/
void showMenu()
{
	printf("                ===========================\n");
	printf("                直接插入排序法             \n");
	printf("                ===========================\n");
	printf("                1.输入数据并完成排序       \n");
	printf("                2.退出程序                 \n");
	printf("                ===========================\n");
}
/*……………………………………………………………………//
函 数 名:readkeyboarddata
描    述:从键盘录入数据
入口参数:数组名，线性表长度
出口参数:无
//……………………………………………………………………*/
void readkeyboarddata(int dataInput[],int length)     //从键盘读入数据
{
	int i;
	for(i=1;i<=length;i++)//空置0单元所以要用 <=
		scanf("%d",&dataInput[i]);
}
/*……………………………………………………………………//
函 数 名:main（）
描    述:主函数
入口参数:无
出口参数:无
//……………………………………………………………………*/
int main()
{
	int i,dataInput[MAXSIZE],choose,dataHandle[2][MAXSIZE];//dataInput是从键盘输入时的数组，dataHandle是待处理的数组
	int length;//线性表长度
	char choice;
	system("color f0"); 
	SetConsoleTitle("直接插入排序法三种思路比较（C版）");
	while(1)
	{
		system("cls");
		showMenu();
		printf("请选择功能编号:\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			printf("启用内部默认数组?(Y/N)\n");
			fflush(stdin); //消除回车影响
			scanf("%c",&choice);
			if(choice == 'Y'||choice == 'y')
			{
				length = 10;
				printf("内部默认数组为：\n");
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = defaultData[i];//为了下面能够统一调用3个排序函数，不能破坏原数组,所以复制到另外的数组中
					dataHandle[1][i] = defaultData[i];
					dataHandle[2][i] = defaultData[i];
					printf("%d  ",defaultData[i]);
				}
				printf("\n");
			}
			else
			{
				printf("请输入要排序的数据个数：(注意不超过%d个)\n",MAXSIZE-1);
				scanf("%d",&length);
				if(length>MAXSIZE-1)
				{
					printf("你输入的个数超过最大限制\n",length);
					system("pause");
					continue;
				}
				printf("请开始输入数据，一共%d个数据，请用空格分开：\n",length);
				readkeyboarddata(dataInput,length);
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = dataInput[i];//为了下面能够统一调用3个排序函数，不破坏原数组,所以复制到另外的数组中
					dataHandle[1][i] = dataInput[i];
					dataHandle[2][i] = dataInput[i];
				}
			}

			printf("================================================\n");
			printf("第一种思路（即先找正确位置，然后成批移动）：\n");
			Insertsort1(dataHandle[0],length);

			printf("================================================\n");
			printf("第二种思路（即边比边交换数据）：\n");
			Insertsort2(dataHandle[1],length);

			printf("================================================\n");
			printf("第三种思路（即通过交换数据达成插入）：\n");
			Insertsort3(dataHandle[2],length);

			printf("================================================\n");
			system("pause");
			break;
		case 2:
			return 0;
		}	
		
	}
}
