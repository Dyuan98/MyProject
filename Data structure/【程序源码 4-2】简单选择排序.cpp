//���ܣ�ʹ���������ݣ���С�������������
//˼·:���ú���display(int data[],int length)�����ʾ������
//���� simpleselectsort(int data[],int length)��������ܡ�
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 21  //�����СԤ����,����0��Ԫ
void simpleselectsort(int data[],int length);//��ѡ��������
void display(int data[],int length);//������������
void dataInput(int data[],int length);//�û��Զ�������
/*����������������������������������������������������//
�� �� ��:main����
��    ��:������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
int main()
{
	SetConsoleTitle("��ѡ������");
	int choose,length;
	system("color f0"); 
	int dataUser[MAXSIZE];
	while(1)
	{
		system("cls");
		printf("                ===========================\n");
		printf("                ��ѡ������             \n");
		printf("                1.�����ڲ�Ĭ�����鲢����   \n");
		printf("                2.�ֶ��������ݲ�����       \n");
		printf("                3.�˳�\n");
		printf("                ===========================\n");
		int dataDefault[11]={17,60,1,12,5,7,63,30,87,3};//Ĭ�����ݣ�����0��Ԫ���������9999��Ϊ�Ǻ�
		printf("�����빦��ѡ�\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			length = 10;
			printf("�Ѵ��ڲ����鴴����10������.\n����ǰ��\n");
			display(dataDefault,length);
			simpleselectsort(dataDefault,length);
			printf("�����Ϊ�� \n");
			display(dataDefault,length);
			break;
		case 2:
			printf("���������ݵĸ���:��ע�ⲻҪ����%d��\n",MAXSIZE);
			scanf("%d",&length);
			dataInput(dataUser,length);
			simpleselectsort(dataUser,length);
			printf("�����Ϊ�� \n");
			display(dataUser,length);
			break;
		case 3:
			printf("ллʹ��!\n");
			return 0;
		default:
			printf("����Ĺ���ѡ���������������룡\n");
		}
		system("pause");
	}
	return 0;	
}

/*����������������������������������������������������//
�� �� ��:inputData
��    ��:�û��Զ������ݵ�����
��ڲ���:���������������ݵĳ��ȳ���
���ڲ���:��
//����������������������������������������������������*/
void dataInput(int dataInput[],int length)
{
	int i;
	printf("������%d�����ݣ��ÿո������:\n",length);
	for(i=0;i<length;i++)
		scanf("%d",&dataInput[i]);
}
/*����������������������������������������������������//
�� �� ��:display
��    ��:������������
��ڲ���:�����������Ա���
���ڲ���:��
//����������������������������������������������������*/
void display(int data[],int length)//������������
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d  ",data[i]);
	}
	printf("\n");
}
/*����������������������������������������������������//
�� �� ��:simpleselectsort
��    ��:���Ԫ�ص�����
��ڲ���:�����������Ա���
���ڲ���:��
//����������������������������������������������������*/
void simpleselectsort(int data[],int length)  //��ѡ��������
{
	int pos;//ָ��δ�����ݵ���λ��
	int i,j,item;
	for(pos=0;pos<length;pos++)
	{
		item=data[pos];
		for(i=pos;i<length;i++)
			if(data[i]<=item)
			{
				item=data[i];//����δ��������С����
				j=i;          //����δ��������С���ݵ�λ��
			}
		data[j]=data[pos];
		data[pos]=item;
	}
}
