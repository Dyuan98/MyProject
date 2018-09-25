//���ܣ�������ϸ�ڲ�ͬ��˼·���ð������
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //�����СԤ����
#define defaultlength 8
int defaultData[3][defaultlength] = {{99,11,22,33,44,55,8,3},{10,9,3,15,6,66,77,88},{0,11,88,55,33,66,22,77}};
//Ĭ�����飬��������Ҫ����0��Ԫ�����ﲻ����0
void showMainMenu();                            //��ʾ���˵�
void showSubMenu();                              //��ʾ�Ӳ˵�
void readkeyboarddata(int data[],int length);//�Ӽ��̶�������
void Swap(int &a, int &b);//�����������ݣ��������ã�
void startCompare(int dataHandle[][MAXSIZE],int length);//��ʼ�Ƚ�
void BubbleSort1(int dataHandle[], int n); //˼·һ
void BubbleSort2(int dataHandle[], int n); //˼·��
void BubbleSort3(int dataHandle[], int n);//˼·��
/*
�����鳤��ΪN��
1���Ƚ����ڵ�ǰ��������ݣ����ǰ�����ݴ��ں�������ݣ��ͽ��������ݽ�����
2������������ĵ�0�����ݵ�N-1�����ݽ���һ�α���������һ�����ݾ�"��"�������N-1��λ�á�
3��N=N-1�����N��Ϊ0���ظ�ǰ�����������������ɡ�
*/
//ð������1  
void BubbleSort1(int dataHandle[], int n)  
{  
	int i, j,countTraverse;//countTraverse���ں����������
	int timeMove = 0;     //�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
	for (i = 0; i < n; i++)  
		for (j = 2; j <= n - i; j++)
		{
			timeCompare++;
			if (dataHandle[j - 1] > dataHandle[j])
			{
				Swap(dataHandle[j - 1], dataHandle[j]);  
				timeMove+=3;
				for(countTraverse=1;countTraverse<=n;countTraverse++)//��ʾ���γ����ƶ�����������
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
			}
		}
		printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
		printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
}  
/*
����Ե�һ�ַ��������Ż�������һ����־�������һ�˷����˽�������Ϊtrue������Ϊfalse��
���������һ��û�з���������˵�������Ѿ���ɡ�
*/
//ð������2  
void BubbleSort2(int dataHandle[], int n)  
{  
	int j, k,countTraverse;//countTraverse���ں����������
	bool flag;  
	int timeMove = 0;     //�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
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
				for(countTraverse=1;countTraverse<=n;countTraverse++)//��ʾ���γ����ƶ�����������
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
				flag = true;  
			}  
		}
			k--;  
	}  
	printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
	printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
}  
/*
������һ�����Ż��������100���������飬��ǰ��10�����򣬺���90�������ź����Ҷ�����ǰ��10�����֣�
��ô�ڵ�һ�˱����������������λ�ñض�С��10�������λ��֮������ݱض��Ѿ������ˣ���¼����λ�ã�
�ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�
*/
//ð������3  
void BubbleSort3(int dataHandle[], int n)  
{  
    int j, k,countTraverse;//countTraverse���ں����������
    int flag;  
	int timeMove = 0;     //�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
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
				for(countTraverse=1;countTraverse<=n;countTraverse++)//��ʾ���γ����ƶ�����������
					printf("%d  ",dataHandle[countTraverse]);
				printf("\n");
            }  
		}
    }  
	printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
	printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
}  
//������������
void Swap(int &a, int &b)  
{  
    int c = a;  
    a = b;  
    b = c;  
}  
/*����������������������������������������������������//
�� �� ��:startCompare
��    ��:ִ�бȽϳ���
��ڲ���:Ҫ�Ƚϵ����飬�����鳤��
���ڲ���:��
//����������������������������������������������������*/
void startCompare(int dataHandle[][MAXSIZE],int length)
{
	printf("================================================\n");
	printf("��һ��˼·�������ڱȽϣ���\n");
	BubbleSort1(dataHandle[0],length);
		
	printf("================================================\n");
	printf("�ڶ���˼·��������һ����־λ����\n");
	BubbleSort2(dataHandle[1],length);
			
	printf("================================================\n");
	printf("������˼·������סһ��λ�ã���\n");
	BubbleSort3(dataHandle[2],length);
	
	printf("================================================\n");
}
/*����������������������������������������������������//
�� �� ��:showMenu
��    ��:��ʾ���ܲ˵�
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void showMainMenu()
{
	printf("                ===========================\n");
	printf("                ð������                 \n");
	printf("                ===========================\n");
	printf("                 1.�������ݲ��������      \n");
	printf("                 2.�˳�����                \n");
	printf("                ===========================\n");
}
void showSubMenu()
{
	printf("                ===========================\n");
	printf("                �밴��Ҫѡ��Ĭ������       \n");
	printf("                 1.�������м�����          \n");
	printf("                 2.�������һ��������      \n");
	printf("                 3.����������              \n");
	printf("                 4.�������˵�              \n");
	printf("                ===========================\n");
	printf("������ѡ��:");
}
/*����������������������������������������������������//
�� �� ��:readkeyboarddata
��    ��:�Ӽ���¼������
��ڲ���:�����������Ա���
���ڲ���:��
//����������������������������������������������������*/
void readkeyboarddata(int dataInput[],int length)     //�Ӽ��̶�������
{
	int i;
	for(i=1;i<=length;i++)//����0��Ԫ����Ҫ�� <=
		scanf("%d",&dataInput[i]);
}
/*����������������������������������������������������//
�� �� ��:main����
��    ��:������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
int main()
{
	SetConsoleTitle("ð�����򷨣�����˼·�Ƚϣ�");
	int i,dataInput[MAXSIZE],choose,dataHandle[3][MAXSIZE];//dataInput�ǴӼ�������ʱ�����飬dataHandle�Ǵ����������
	int length;//���Ա���
	int choiceSub;
	char choice;
	system("color f0"); 
	while(1)
	{
		system("cls");
		showMainMenu();
		printf("��ѡ���ܱ��:\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			printf("�����ڲ�Ĭ������?(Y/N)\n");
			fflush(stdin); //�����س�Ӱ��
			scanf("%c",&choice);
			if(choice == 'Y'||choice == 'y')
			{
				while(1)
				{
				length = defaultlength-1;//ȡĬ�����ݸ���
				system("cls");
				showSubMenu();
				//fflush(stdin); //�����س�Ӱ��
			    scanf("%d",&choiceSub);
				if(choiceSub>4||choiceSub<0)
				{
					printf("�Բ�����������!\n");
					system("pause");
					continue;
				}
				if(choiceSub == 4)
					break;
				printf("�ڲ�Ĭ������Ϊ��\n");
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = defaultData[choiceSub-1][i];//Ϊ�������ܹ�ͳһ����3���������������ƻ�ԭ����,���Ը��Ƶ������������
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
				printf("������Ҫ��������ݸ�����(ע�ⲻ����%d��)\n",MAXSIZE-1);
				scanf("%d",&length);
				if(length>MAXSIZE-1)
				{
					printf("������ĸ��������������\n",length);
					system("pause");
					continue;
				}
				printf("�뿪ʼ�������ݣ�һ��%d�����ݣ����ÿո�ֿ���\n",length);
				readkeyboarddata(dataInput,length);
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = dataInput[i];//Ϊ�������ܹ�ͳһ����3�������������ƻ�ԭ����,���Ը��Ƶ������������
					dataHandle[1][i] = dataInput[i];
					dataHandle[2][i] = dataInput[i];
				}
				startCompare(dataHandle,length);
				system("pause");
			}
			break;
		case 2:
			printf("ллʹ��!\n");
			return 0;
		}	
		
	}
}