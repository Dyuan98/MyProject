//功能：用三种细节不同的思路完成冒泡排序法
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //数组大小预定义
#define defaultlength 8
int defaultData[3][defaultlength] = {{99,11,22,33,44,55,8,3},{10,9,3,15,6,66,77,88},{0,11,88,55,33,66,22,77}};
//默认数组，结合下面的要空置0单元，这里不会用0
void showMainMenu();                            //显示主菜单
void showSubMenu();                              //显示子菜单
void readkeyboarddata(int data[],int length);//从键盘读入数据
void Swap(int &a, int &b);//交换两个数据（利用引用）
void startCompare(int dataHandle[][MAXSIZE],int length);//开始比较
void BubbleSort1(int dataHandle[], int n); //思路一
void BubbleSort2(int dataHandle[], int n); //思路二
void BubbleSort3(int dataHandle[], int n);//思路三
/*
设数组长度为N。
1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就"沉"到数组第N-1个位置。
3．N=N-1，如果N不为0就重复前面二步，否则排序完成。
*/
//冒泡排序1  
void BubbleSort1(int dataHandle[], int n)  
{  
	int i, j,countTraverse;//countTraverse用于后面遍历数组
	int timeMove = 0;     //移动总次数
	int timeCompare = 0;//比较次数
	for (i = 0; i < n; i++)  
		for (j = 2; j <= n - i; j++)
		{
			timeCompare++;
			if (dataHandle[j - 1] > dataHandle[j])
			{
				Swap(dataHandle[j - 1], dataHandle[j]);  
				timeMove+=3;
				for(countTraverse=1;countTraverse<=n;countTraverse++)//显示本次成批移动的数组内容
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
			}
		}
		printf("一共比较了%d 次。\n",timeCompare);
		printf("移动的总次数为：%d\n",timeMove);
}  
/*
下面对第一种方法进行优化，设置一个标志，如果这一趟发生了交换，则为true，否则为false。
明显如果有一趟没有发生交换，说明排序已经完成。
*/
//冒泡排序2  
void BubbleSort2(int dataHandle[], int n)  
{  
	int j, k,countTraverse;//countTraverse用于后面遍历数组
	bool flag;  
	int timeMove = 0;     //移动总次数
	int timeCompare = 0;//比较次数
	k = n;  
	flag = true;  
	while (flag)  
	{  
		flag = false;  
		for (j = 2; j <= k; j++)  
		{
			timeCompare++;
			if (dataHandle[j - 1] > dataHandle[j])  
			{  
				Swap(dataHandle[j - 1], dataHandle[j]);  
				timeMove+=3;
				for(countTraverse=1;countTraverse<=n;countTraverse++)//显示本次成批移动的数组内容
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
				flag = true;  
			}  
		}
			k--;  
	}  
	printf("一共比较了%d 次。\n",timeCompare);
	printf("移动的总次数为：%d\n",timeMove);
}  
/*
再做进一步的优化。如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，
那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了，记录下这位置，
第二次只要从数组头部遍历到这个位置就可以了。
*/
//冒泡排序3  
void BubbleSort3(int dataHandle[], int n)  
{  
    int j, k,countTraverse;//countTraverse用于后面遍历数组
    int flag;  
	int timeMove = 0;     //移动总次数
	int timeCompare = 0;//比较次数
    flag = n;  
    while (flag > 0)  
    {  
        k = flag;  
        flag = 0;  
        for (j = 2; j <= k; j++)  
		{
			timeCompare++;
            if (dataHandle[j - 1] > dataHandle[j])  
            {  
                Swap(dataHandle[j - 1], dataHandle[j]);  
                flag = j;  
				timeMove+=3;
				for(countTraverse=1;countTraverse<=n;countTraverse++)//显示本次成批移动的数组内容
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
            }  
		}
    }  
	printf("一共比较了%d 次。\n",timeCompare);
	printf("移动的总次数为：%d\n",timeMove);
}  
//交换两个数据
void Swap(int &a, int &b)  
{  
    int c = a;  
    a = b;  
    b = c;  
}  
/*……………………………………………………………………//
函 数 名:startCompare
描    述:执行比较程序
入口参数:要比较的数组，及数组长度
出口参数:无
//……………………………………………………………………*/
void startCompare(int dataHandle[][MAXSIZE],int length)
{
	printf("================================================\n");
	printf("第一种思路（即相邻比较）：\n");
	BubbleSort1(dataHandle[0],length);
		
	printf("================================================\n");
	printf("第二种思路（即设置一个标志位）：\n");
	BubbleSort2(dataHandle[1],length);
			
	printf("================================================\n");
	printf("第三种思路（即记住一个位置）：\n");
	BubbleSort3(dataHandle[2],length);
	
	printf("================================================\n");
}
/*……………………………………………………………………//
函 数 名:showMenu
描    述:显示功能菜单
入口参数:无
出口参数:无
//……………………………………………………………………*/
void showMainMenu()
{
	printf("                ===========================\n");
	printf("                冒泡排序法                 \n");
	printf("                ===========================\n");
	printf("                 1.输入数据并完成排序      \n");
	printf("                 2.退出程序                \n");
	printf("                ===========================\n");
}
void showSubMenu()
{
	printf("                ===========================\n");
	printf("                请按需要选择默认数组       \n");
	printf("                 1.此数组中间有序          \n");
	printf("                 2.此数组后一部分有序      \n");
	printf("                 3.此数组乱序              \n");
	printf("                 4.返回主菜单              \n");
	printf("                ===========================\n");
	printf("请输入选择:");
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
	SetConsoleTitle("冒泡排序法（三种思路比较）");
	int i,dataInput[MAXSIZE],choose,dataHandle[3][MAXSIZE];//dataInput是从键盘输入时的数组，dataHandle是待处理的数组
	int length;//线性表长度
	int choiceSub;
	char choice;
	system("color f0"); 
	while(1)
	{
		system("cls");
		showMainMenu();
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
				while(1)
				{
				length = defaultlength-1;//取默认数据个数
				system("cls");
				showSubMenu();
				//fflush(stdin); //消除回车影响
			    scanf("%d",&choiceSub);
				if(choiceSub>4||choiceSub<0)
				{
					printf("对不起，输入有误!\n");
					system("pause");
					continue;
				}
				if(choiceSub == 4)
					break;
				printf("内部默认数组为：\n");
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = defaultData[choiceSub-1][i];//为了下面能够统一调用3个排序函数，不能破坏原数组,所以复制到另外的数组中
					dataHandle[1][i] = defaultData[choiceSub-1][i];
					dataHandle[2][i] = defaultData[choiceSub-1][i];
					printf("%d  ",defaultData[choiceSub-1][i]);
				}
				printf("\n");
				startCompare(dataHandle,length);
				system("pause");
				}
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
				startCompare(dataHandle,length);
				system("pause");
			}
			break;
		case 2:
			printf("谢谢使用!\n");
			return 0;
		}	
		
	}
}