//���ܣ�������ϸ�ڲ�ͬ��˼·���ֱ�Ӳ�������
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //�����СԤ����
int defaultData[] = {-9999,11,77,88,66,33,44,55,22,99,0};//Ĭ�����飬��������Ҫ����0��Ԫ�����ﲻ����-9999
void showMenu();                            //��ʾ�˵�
void readkeyboarddata(int data[],int length);//�Ӽ��̶�������
void Insertsort1(int dataHandle[], int n); //�ҵ���ȷλ�ú�����ƶ� 
void Insertsort2(int dataHandle[], int n); //�߱Ƚϱ��ƶ�
void Insertsort3(int dataHandle[], int n); //�����������ݽ����ĺ���
/*ֱ�Ӳ��뷨˼·֮һ��
ͨ���ҵ����ſռ��е�һ����ȷλ�ã��Ѵ��ſռ��ĵ�һ�����ݲ��뵽��λ��
*/
void Insertsort1(int dataHandle[], int n)  
{  
    int i, j, k,countTraverse;//countTraverse���ں����������
	int timeMove = 0;     //�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
	for (i = 2; i <= n; i++)  //��һ������Ҫ���������Ķ�Ҫ����δ�ſռ�ĵ�һ��
    {
        //��������ȷλ��  
        for (j = i - 1; j >= 1; j--)  
		{
			timeCompare++;
            if (dataHandle[j] < dataHandle[i])  
                break;  
		}
		//����ҵ���һ�����ʵ�λ��  
        if (j != i - 1)  
        {  
            //���ȴ��ſռ��һ�����ݸ���ĵ����ݳ�������ƶ��������Ƿ����ƶ�
            int temp = dataHandle[i]; 
			timeMove++;//��һ��
            for (k = i - 1; k > j; k--)  
			{
                dataHandle[k + 1] = dataHandle[k];  
			}
            //�����ſռ��һ�����ݷŵ���ȷλ����  
            dataHandle[k + 1] = temp; //����ʱ��������Ĵ��ſռ�ԭ���ĵ�һ�����ݷ�����ȷλ��
			timeMove++;//��һ��
			timeMove+=i-j-1;//��1����������ȷλ��ʱ��for (j = i - 1; j >= 1; j--)  ѭ���������£�ʹ�൱���±��j��С��1
            for(countTraverse=1;countTraverse<=n;countTraverse++)//��ʾ���γ����ƶ�����������
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
        }  
    }
	printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
	printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
}  
/*˼·��
�����������˼·����һ�¸�д�������������ݺ������������ϲ���
*/
void Insertsort2(int dataHandle[], int n)  
{  
    int i, j,countTraverse;//countTraverse���ں����������  
	int timeMove = 0;//�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
    for (i = 2; i <= n; i++)  
	{
        if (dataHandle[i] < dataHandle[i - 1])  
        {
			timeCompare++;
            int temp = dataHandle[i];  
			timeMove++;//��һ��
            for (j = i - 1; j >= 1 && dataHandle[j] > temp; j--)//�߱ȱ���
			{
				timeCompare++;
                dataHandle[j + 1] = dataHandle[j];  
			}
            dataHandle[j + 1] = temp;
			timeMove++;//��һ��
			timeMove+=i-j-1;//��1������for (j = i - 1; j >= 1 && dataHandle[j] > temp; j--)��ѭ���������£�ʹ�൱���±��j��С��1
			for(countTraverse=1;countTraverse<=n;countTraverse++)//��������
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
        } 
		else 
			timeCompare++;//�����һ������Ϊ��ʹ������if��������Ҳ����Ƚ���
	}
	printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
	printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
}  
/*
�ٶԽ�δ�ſռ��һ�����ݲ��뵽ǰ�������������õķ������и�д��
�����ݽ����������ݺ��ơ�
*/
void Insertsort3(int dataHandle[], int n)  
{  
    int i, j,temp,countTraverse;//countTraverse���ں����������  
	int timeMove = 0;//�ƶ��ܴ���
	int timeCompare = 0;//�Ƚϴ���
    for (i = 2; i <= n; i++) //����δ������ŵ�Ԫ����i��2��ʼ
	{
        for (j = i - 1; j > 0 && dataHandle[j] > dataHandle[j + 1]; j--)  
		{
			timeCompare++;
			temp = dataHandle[j];
			dataHandle[j] = dataHandle[j+1];
			dataHandle[j+1] = temp;
			timeMove+=3;//��������������3��
		}
		if(j==i-1)//���ڵ�a[j]<a[j+1]ʱ��Ҳ�Ƚ��ˣ�����timeCompareû��1�����ﲹ�ϡ�
			timeCompare++;
		for(countTraverse=1;countTraverse<=n;countTraverse++)//��������
				printf("%d  ",dataHandle[countTraverse]);
			printf("\n");
	}
	printf("һ���Ƚ���%d �Ρ�\n",timeCompare);
	printf("�ƶ����ܴ���Ϊ��%d\n",timeMove);
} 
/*����������������������������������������������������//
�� �� ��:showMenu
��    ��:��ʾ���ܲ˵�
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void showMenu()
{
	printf("                ===========================\n");
	printf("                ֱ�Ӳ�������             \n");
	printf("                ===========================\n");
	printf("                1.�������ݲ��������       \n");
	printf("                2.�˳�����                 \n");
	printf("                ===========================\n");
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
	int i,dataInput[MAXSIZE],choose,dataHandle[2][MAXSIZE];//dataInput�ǴӼ�������ʱ�����飬dataHandle�Ǵ����������
	int length;//���Ա���
	char choice;
	system("color f0"); 
	SetConsoleTitle("ֱ�Ӳ�����������˼·�Ƚϣ�C�棩");
	while(1)
	{
		system("cls");
		showMenu();
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
				length = 10;
				printf("�ڲ�Ĭ������Ϊ��\n");
				for(i=1;i<=length;i++)
				{
					dataHandle[0][i] = defaultData[i];//Ϊ�������ܹ�ͳһ����3���������������ƻ�ԭ����,���Ը��Ƶ������������
					dataHandle[1][i] = defaultData[i];
					dataHandle[2][i] = defaultData[i];
					printf("%d  ",defaultData[i]);
				}
				printf("\n");
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
			}

			printf("================================================\n");
			printf("��һ��˼·����������ȷλ�ã�Ȼ������ƶ�����\n");
			Insertsort1(dataHandle[0],length);

			printf("================================================\n");
			printf("�ڶ���˼·�����߱ȱ߽������ݣ���\n");
			Insertsort2(dataHandle[1],length);

			printf("================================================\n");
			printf("������˼·����ͨ���������ݴ�ɲ��룩��\n");
			Insertsort3(dataHandle[2],length);

			printf("================================================\n");
			system("pause");
			break;
		case 2:
			return 0;
		}	
		
	}
}
