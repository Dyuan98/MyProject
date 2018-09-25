//���ܣ������ջ�Ļ���������
#include<malloc.h>
#include<windows.h>
#include<stdio.h>
struct stacknode//�ýṹ�嶨������Ľ��
{
	int data;
	stacknode *next;
};
//������ر�����Ĭ������
#define SIZE 5//����Ĭ�����鳤��
int sourceData[SIZE]={11,22,33,44,55};  //�ڲ��������飬��ʡÿ�ν���ʱ����ʱ��
enum returninfo{success,fail,underflow,range_error};//���巵����Ϣ�嵥
#define  len sizeof(struct stacknode)//�ṹ��stacknode�ĳ��ȣ���Ҫ����ռ�ĳ���
int stackLength;//��ջ�����ݸ���
stacknode *linkStackTop;//��ջ��ͷָ��
stacknode *newnodep;    //����ָ�룬���������ݽ�ջ
stacknode *usedNodep;   //����ָ�룬ָ���ջ���
bool flag = false;//��־��ջ�Ƿ���
//������غ���
bool isempty();                    //�ж�ջ�Ƿ�Ϊ��
returninfo display();              //��ʾջ������Ԫ��
int getLength();                   //��ȡջ�ĳ���
int userchoose();                   //�õ��û�ѡ��
returninfo pop(int &item);         //��ջ���������ݷ���
void showMenu();                   //��ʾ�˵�
void function(int choose);         //ִ��ָ������
returninfo initStack();            //��ʼ����ջ
returninfo create();               //�����ڲ�Ĭ�����鴴��һ��ջ
returninfo destroy();              //����һ��ջ
returninfo push(int &item);        //�����ݽ�ջ	
returninfo poponly();              //��ջ��������ֵ�����ͷŵ�ǰջԪ�صĿռ�
returninfo gettop(int &item);     //�õ�ջ��Ԫ��
/*����������������������������������������������������//
�� �� ��:initStack
��    ��:��ʼ����ջ
��ڲ���:��
���ڲ���:���س�ʼ���Ƿ�ɹ�����Ϣ
//����������������������������������������������������*/
returninfo initStack()
{
	linkStackTop = (stacknode *)malloc(len);//����ռ䣬����ͷ���
	if(!linkStackTop)
		return fail;//���û�����뵽�ռ䣬����ʧ��
	linkStackTop->next = NULL;//��ʼʱΪ��
	stackLength = 0;//��ʼʱ��ջ�ĳ���Ϊ��
	return success;
}
/*����������������������������������������������������//
�� �� ��:create
��    ��:��ʡʱ�䣬���ڲ����鴴��Ĭ����ջ
��ڲ���:��
���ڲ���:���ش����Ƿ�ɹ�����Ϣ
//����������������������������������������������������*/
returninfo create()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		newnodep = (stacknode *)malloc(len);//����ռ�
		if(!newnodep)                        //���û�����뵽�ռ䣬����ʧ��
			return fail;
		newnodep->data = sourceData[i];    //��ֵ
		newnodep->next = linkStackTop->next;//����
		linkStackTop->next = newnodep;             //��������ɽ�ջ   
		stackLength++;                //ջ�ĳ�������
	}
	return success;                   //���سɹ���Ϣ
}
/*����������������������������������������������������//
�� �� ��:destroy
��    ��:����һ��ջ
��ڲ���:��
���ڲ���:����ջ�Ƿ����ٳɹ�����Ϣ
//����������������������������������������������������*/
returninfo destroy()
{
	if(poponly()==underflow)
		return underflow;//����ջΪ���򷵻�����
	while(poponly()==success);       //ͨ��һֱ��ջ����ÿ���ͷſռ��ڳ�ջ�����
	return success;     //���سɹ���Ϣ
}
/*����������������������������������������������������//
�� �� ��:isempty
��    ��:�ж�ջ�Ƿ�Ϊ��
��ڲ���:��
���ڲ���:����ջ�Ƿ�Ϊ�յ���Ϣ
//����������������������������������������������������*/
bool isempty()
{
	if(stackLength==0)
		return true;
	else
		return false;
}
/*����������������������������������������������������//
�� �� ��:getLength
��    ��:�õ�ջ�ĳ���
��ڲ���:��
���ڲ���:����ջ�ĳ�����Ϣ
//����������������������������������������������������*/
int getLength()
{
	return stackLength;
}
/*����������������������������������������������������//
�� �� ��:push
��    ��:���ݽ�ջ
��ڲ���:Ҫ��ջ��Ԫ����ֵ
���ڲ���:���ؽ�ջ�Ƿ�ɹ�
//����������������������������������������������������*/
returninfo push(int &item)
{
	newnodep = (stacknode *)malloc(len);  //����ռ�
	if(!newnodep)                              //���û�����뵽�ռ䣬����ʧ��
		return fail;
	newnodep->data = item;                     //��ֵ
	newnodep->next = linkStackTop->next;       //����
	linkStackTop->next = newnodep;             //��������ɽ�ջ              
	stackLength++;                             //ջ�ĳ�������
	return success;                            //���β����ɹ�
}
/*����������������������������������������������������//
�� �� ��:poponly
��    ��:��ջ�����������ݲ��ͷſռ�
��ڲ���:
���ڲ���:���س�ջ�Ƿ�ɹ�
//����������������������������������������������������*/
returninfo poponly()
{
	if(!isempty())                      //�ж��Ƿ�Ϊ�գ�����Ҫ����ͷ���
	{
		usedNodep = linkStackTop->next;        //ָ���ջ���
		linkStackTop->next = usedNodep->next;  //ͷָ�����
		free(usedNodep);                //��free�ͷſռ�
		stackLength--;                  //ջ�ĳ��ȼ���
		return success;                 //���β����ɹ�
	}
	return underflow;                   //��������
}
/*����������������������������������������������������//
�� �� ��:pop
��    ��:���ݳ�ջ������������
��ڲ���:ͨ�����õõ�ջ������
���ڲ���:���س�ջ�Ƿ�ɹ�
//����������������������������������������������������*/
returninfo pop(int &item)
{
	if(isempty())
		return underflow;            //��������
	usedNodep = linkStackTop->next;         //ָ���ջ���
	linkStackTop->next = usedNodep->next;   //ͷָ������ƶ�
	item = usedNodep->data;        //������ָ����ֵ��item
	delete usedNodep;               //�ͷſռ�
	stackLength--;                  //ջ�ĳ��ȼ���
	return success;                 //���β����ɹ�
}
/*����������������������������������������������������//
�� �� ��:gettop
��    ��:����ջ������
��ڲ���:ͨ�����õõ�ջ������
���ڲ���:���س�ջ�Ƿ�ɹ�
//����������������������������������������������������*/
returninfo gettop(int &item)
{
	if(isempty())
		return underflow;     //��������
	item = linkStackTop->next->data;//��ջ������ָ����ֵ��item
	return success;
}
/*����������������������������������������������������//
�� �� ��:display
��    ��:��ʾջ����������
��ڲ���:ͨ�����õõ�ջ������
���ڲ���:���س�ջ�Ƿ�ɹ�
//����������������������������������������������������*/
returninfo display()
{
	stacknode *searchp=linkStackTop->next;//����ָ��searchp��׼��ָ��Ҫ��ʾ�Ľ��
	if(isempty())
		return underflow;        //��������
	printf("Ŀǰջ�е������ǣ�ջ��-->");
	while(searchp)
	{
		printf("%d ",searchp->data);//��ʾ��ǰ�������
		searchp = searchp->next;     //searchp����ƶ�
	} 
	printf("ջ��\n");
	return success;
}
/*����������������������������������������������������//
�� �� ��:showMenu
��    ��:��ʾ�˵�
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void showMenu()
{
	printf("=================                \n");
	printf("��ջ�Ļ�������                   \n");
	printf("1������һ��ջ�������ڲ�Ĭ�����飩\n");
	printf("2������һ��ջ                    \n");
	printf("3�����ݽ�ջ                      \n");
	printf("4�����ݳ�ջ                      \n");
	printf("5����ʾ��������Ԫ��              \n");
	printf("6����ȡջ��Ԫ��                  \n");
	printf("7���õ�ջ��Ԫ�ظ���              \n");
	printf("8���˳�                          \n");
	printf("================                 \n");
	if(!flag)
		printf("��ʾ��ջ��δ������Ҫ�������ȴ���һ��ջ!\n");
	else
		printf("��ʾ��ջ�Ѿ����������Բ�����\n");
}
/*����������������������������������������������������//
�� �� ��:userchoose
��    ��:�õ��û������ѡ��
��ڲ���:��
���ڲ���:��������ѡ��
//����������������������������������������������������*/
int userchoose()
{
	int choose;
	printf("�����빦��ѡ�");
	scanf("%d",&choose);
	return choose;
}
/*����������������������������������������������������//
�� �� ��:function
��    ��:ִ���û�ѡ��Ĺ���
��ڲ���:����ѡ��
���ڲ���:��
//����������������������������������������������������*/
void function(int choose)
{
	int returndata,item;
	if(choose<=0||choose>8)
		printf("����Ĺ��ܱ����Ч!\n");
	else
	{
		switch(choose)
		{
		case 1:
			if(flag)
				printf("��ջ�Ѿ����������ظ�����������ִ����������!\n");
			else
			{
				returndata=create(); 
				if(returndata==success)
					printf("��ջ�����ɹ�!\n");
			}
			flag = true;
			break;
		case 2:
			if(!flag)
			{
				printf("�Բ���ջ��δ����,����ִ�д˲���!\n");
				break;
			}
			returndata=destroy();
				printf("ջ������...\n");
			flag = false;
			break;
		case 3:
			if(!flag)
			{
				printf("�Բ�����ջ��δ���������ܽ�ջ!\n");
				break;
			}
			printf("������Ҫ��ջ������:\n");
			scanf("%d",&item);
			returndata=push(item);//�����ݽ�ջ
			if(returndata==fail)
				printf("����ռ�ʧ�ܣ��޷���ջ!");
			else
				printf("��ջ�ɹ�....\n");
			break;
		case 4:
			returndata=pop(item);
			if(!flag)
				printf("�Բ���ջ��δ�������޷���ջ!\n");
			else if(returndata==underflow)
				printf("�Բ���ջ�ѿգ��޷���ջ!\n");
			else
			{
				printf("%d ",item);
				printf("��ջ�ɹ�....\n");
			}
			break;
		case 5:
			returndata=display();
			if(returndata==underflow)
				printf("�Բ���ջ��δ����\n");
			else
				printf("��ʾ���.....\n");
			break;
		case 6:
			returndata=gettop(item);
			if(returndata==underflow)
				printf("�Բ���ջ��δ����!\n");
			else
			{
				printf("%d ",item);
				printf("ջ��Ԫ�ض�ȡ�ɹ�....\n");
			}
			break;	
		case 7:
			if(isempty())
				printf("�Բ���ջ��δ����!\n");
			else
				printf("ջ��ĿǰԪ�ظ���Ϊ: %d\n",getLength());
			break;
		case 8:
			printf("ллʹ��...\n");
			exit(0);
			break;
		}
	}
}
/*����������������������������������������������������//
 �� �� ��:main
��    ��:������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void main()
{
	SetConsoleTitle("��ջ������ʾ��C�棩");//����������
	int returnvalue;//���巵��ֵ
	system("color f0");//��ɫ����
	returninfo info;//������������洢���������Ƿ�ɹ��ķ�����Ϣ
	info = initStack();//�����ʼ��
	if(info==fail)//���ʧ������ʾ���˳�ϵͳ
	{
		printf("�Բ��𣬳�ʼ��ʧ��!\n");
		system("pause");
		exit(0);
	}
	while(1)//����ѭ��
	{
		showMenu();//��ʾ�˵�
		returnvalue=userchoose();//��ȡ�û���ѡ��
		function(returnvalue);//ִ���û���ѡ��
		system("pause");//��ͣ
		system("cls");//����
	}
}
