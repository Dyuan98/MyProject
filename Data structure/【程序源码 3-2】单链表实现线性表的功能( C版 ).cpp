//��������������Դ�� 3-2��������ʵ�����Ա�Ĺ��ܣ���C�棩.cpp
//���ܣ���ɵ�������½�����ʾ�����롢ɾ������ȡ���޸ġ���ת�ȹ��ܡ�
#include <stdio.h>//������������ͷ�ļ�
#include <malloc.h>//��̬���ٿռ�Ҫ�õ�ͷ�ļ�
#include<windows.h>//��������ɫ������Ҫ
#define  len sizeof(struct node)//�ṹ��node�ĳ��ȣ���Ҫ����ռ�ĳ���
#define MAXNUMOFBASE 5//���峣����ʾ������������
enum  returninfo{success,fail,overflow,underflow,range_error};//���巵����Ϣ�嵥
int   sourcedata[MAXNUMOFBASE]={11,22,33,55,66};  //�ڲ��������飬��ʡÿ�ν���ʱ����ʱ��
struct node                                        //���ṹ��
{
	int data;                                      //������
	struct node *next;                                    //ָ����
};
struct node *headp;                                //ȫ�ֱ�����������ͷָ��
int count;                                         //ȫ�ֱ����������˼�������ͳ�����Ա���
//���ܺ���
void initList();                                   //��ʼ����������headp
int length();                                      //��������
void showMenu();                                   //��ʾ�˵�
bool empty();                                      //�ж��Ƿ����
int  userchoose();                                 //�����û���ѡ��
returninfo create();                               //ʹ�����ݽ�������
void clearlist(void);                              //�������
returninfo traverse();                             //��������
returninfo invertlist();                           //��ת��������
void function(int choose);                         //ִ��ָ������
int getcount(){return count;};                     //�õ���ǰ������
returninfo remove(int position);                   //ɾ�����
returninfo insert(int position,int item);          //������
returninfo retrieve(int position, int &item);      //��ȡһ����� 
returninfo replace(int position,int &item);        //�޸�һ�����
/*����������������������������������������������������//
�� �� ��:IniList
��    ��:��ʼ������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void initList()
{
	headp=(struct node *)malloc(len);//����ͷ���ռ�
	headp->next=NULL;               //βָ��ָ��գ���NULL
	count=0;                        //����������
}
/*����������������������������������������������������//
�� �� ��:length
��    ��:�õ�������
��ڲ���:��
���ڲ���:int��
//����������������������������������������������������*/
int length()
{
	return count;   //����������
}
/*����������������������������������������������������//
�� �� ��:empty
��    ��:�ж������Ƿ�Ϊ��
��ڲ���:��
���ڲ���:bool��
//����������������������������������������������������*/
bool empty()
{
	if(headp->next==NULL) //���headp->next==NULL��Ϊ�� 
		return true;
	else
		return false;
}
/*����������������������������������������������������//
�� �� ��:clearlist
��    ��:�������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void clearlist(void)        //�������
{
	struct node *searchp=headp->next,*followp=headp;    //��ʼ������ָ�룬����ʱͬʱ����ֵ
    while(searchp!=NULL) //�ӿ�ʼ������һֱѭ��         
	{	
		followp=searchp;       //β��ָ��ָ��searchpָ��Ľ�㣬���ں�����ͷŲ���
		searchp=searchp->next;//ָ��ָ����һ�����
		free(followp);       //ɾ������ָ����ָ��Ľ��
	}
	headp->next=NULL;         //������ͷ���
	count=0;                  //����������
}
/*����������������������������������������������������//
�� �� ��:create
��    ��:��������
��ڲ���:��
���ڲ���:����returnvalueö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo create()
{
	struct node *searchp=headp,*newnodep;    //��������ָ�룬���ں���Ĺ���
	int i;
	for(i=0;i<MAXNUMOFBASE;i++)             //ѭ���������
	{
		newnodep=(struct node *)malloc(len);//����ռ�,�˴���������ʧ�ܲ�û�д���
		newnodep->data=sourcedata[i];       //�������е����ݴ�������Ľ��
		searchp->next=newnodep;            //��ʼ����
		searchp=searchp->next;             //����ָ��searchpָ��ǰ���һ�����
		count++;                           //��������1
	}
	searchp->next=NULL;                   //��������
	return success;                       //���ؽ�������ɹ�����Ϣ
}
/*����������������������������������������������������//
�� �� ��:remove
��    ��:ɾ��ָ��λ�õ�����
��ڲ���:λ��position
���ڲ���:����returnvalueö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo remove(int position)               //ɾ��ָ��λ�õĽ��
{
	int i;
	node *searchp=headp->next,*followp=headp;//��������Ҫ��followp�ſ�ɾ���ҵ��Ľ��
	for(i=0;i<position&&searchp!=NULL;i++)   //��searchp��=NULL��Ϊ��ֹ����
	{
		followp=searchp;                     //followpʼ�ո���searchp
		searchp=searchp->next;               //searchpָ����һ�����
	}
	followp->next=searchp->next;           //ͨ����������ɾ�����
	free(searchp);                        //�ͷ�searchp��ָ�����ռ�Ŀռ�
	count--;                               //��������1
	return success;                        //����ɾ���ɹ���Ϣ
}
/*����������������������������������������������������//
�� �� ��:insert
��    ��:�������ݵ�ָ��λ��
��ڲ���:λ��position������item
���ڲ���:����returnvalueö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo insert(int position,int item)                     //��ָ��λ�ò�����Ϣ
{
	int i;
	node *searchp=headp,*newnodep=(struct node *)malloc(len);//����ռ�
	newnodep->data=item;                                     //��Ҫ�����ֵ��ֵ������������
	for(i=0;i<position&&searchp->next!=NULL;i++)             //ͨ��ѭ��ʹsearchpָ��ָ��λ�õ�ǰ��
	{
		searchp=searchp->next;                               //searchpָ����һ��
	}
	newnodep->next=searchp->next;                           //�����Ĳ�����俪ʼ
	searchp->next=newnodep;                                 //���½��ҵ�����
	count++;                                                //��������1
	return success;                                         //���ز���ɹ���Ϣ
}
/*����������������������������������������������������//
�� �� ��:traverse
��    ��:����ȫ������
��ڲ���:��
���ڲ���:����returnvalueö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo traverse()      //����ȫ������
{
	node *searchp;        //����һ��ָ��ṹ��node��ָ��
	if(empty())           //���ж������Ƿ�Ω��
	{
		return underflow;//���Ϊ�յĻ�����������Ϣ
	}
	searchp=headp->next;//����ͷ���
	while(searchp!=NULL)//ͨ��ѭ����������ȫ������
	{
		printf("%d  ",searchp->data);//�����ǰ���������
		searchp=searchp->next;       //searchp������һ��
	}
	printf("\n");                    //����
	return success;                  //���ز���ɹ���Ϣ
}
/*����������������������������������������������������//
�� �� ��:invertlist
��    ��:��ת��������
��ڲ���:��
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo invertlist()           //��ת��������
{
	node *nowp,*midp,*lastp;     //���ö������ָ��
	if(empty())                  //���ж������Ƿ�Ϊ��
		return underflow;        //��Ϊ�շ���������Ϣ
	nowp=headp->next;            //����nowpָ��ʵ�ʵ�һ�����
	midp=NULL;                   //midp�ȸ�ֵΪNULL
	while(nowp!=NULL)            //ͨ��ѭ���ı������򣬵��ﷴת��Ŀ��    
	{
		lastp=midp;              //ͨ�����漸��������Դ�ɷ�ת��Ч��
		midp=nowp;
		nowp=nowp->next;
		midp->next=lastp;
	}
	headp->next=midp;         //ͷָ��ָ��֮ǰ�����һ����㣬��ת
	return success;
}
/*����������������������������������������������������//
�� �� ��:retrieve
��    ��:��ȡһ�����
��ڲ���:λ�ã�int������
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo retrieve(int position, int &item)   
{
	if(empty())                              //�������⣬�ձ�
		return underflow;	
	if(position<=0||position>=count+1)       //�������⣬��Χ����ȷ
		return range_error;
	node *searchp=headp->next;             //��������ָ�룬��ʼ��
	for(int i=1; i<position && searchp!=NULL;i++)   //��ʾ��ע��С�ں� 
        searchp=searchp->next;    //˳����ʷ�ʽ����ѭ�����㷨���Ӷ���O(n)
	item=searchp->data;           //���ض�ȡ������
	return success;               //���β����ɹ�
}
/*����������������������������������������������������//
�� �� ��:replace
��    ��:�޸�ָ��λ������
��ڲ���:λ�ã��滻ֵ
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo replace(int position,int &item)//�޸�����
{
	if(empty())                                //�������⣬�ձ�                            
		return underflow;	
	if(position<=0||position>=count+1)         //�������⣬��Χ����ȷ
		return range_error;
	node *searchp=headp->next;                  //��������ָ��
	for(int i=1; i<position && searchp!=NULL;i++)//ͨ��ѭ���ҵ�λ��
        searchp=searchp->next; 
	searchp->data=item;           //ʵ���޸����ݵ����
	return success;
}
/*����������������������������������������������������//
�� �� ��:showMenu
��    ��:��ʾ���ܲ˵�
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void showMenu()
{
	printf("===========================        \n");
	printf("     ������Ļ�������              \n");
	printf("===========================        \n");
	printf("1.�������ݣ��ڲ��������ṩ5�����ݣ�\n");
	printf("2.��ʾ���ݣ�����ȫ�����ݣ�         \n");
	printf("3.�������ݣ�Ҫ�ṩλ�ú���ֵ��     \n");
	printf("4.ɾ�����ݣ�Ҫ�ṩλ�ã�           \n");
	printf("5.��ȡ���ݣ�Ҫ�ṩλ�ã�           \n");
	printf("6.�޸����ݣ�Ҫ�ṩλ�ú���ֵ��     \n");
	printf("7.�����                         \n");
	printf("8.��ת������������                 \n");
	printf("9.�˳�����                         \n");
	printf("===========================        \n");
}
/*����������������������������������������������������//
�� �� ��:userchoose
��    ��:�õ��û������ѡ��
��ڲ���:��
���ڲ���:��������ѡ��
//����������������������������������������������������*/
int userchoose()                //�����û���ѡ��
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
	int returnvalue,position,item;
	if(choose<=0||choose>9)              //������Ĺ��ܱ�Ŵ���9��С��0����ʾ�û���Ч
		printf("����Ĺ��ܱ����Ч!\n");
	else
	{
		switch(choose)
		{
		case 1:
			returnvalue=create(); 
			if(returnvalue==success)
				printf("������������ɹ�!\n");
			break;
		case 2:
			returnvalue=traverse();
			if(returnvalue==underflow)
			{
				printf("�Բ����ǿձ���������ʾ!\n");
			}
			else
			{
				printf("��ʾ���...\n");
			}
			break;
		case 3:
			printf("������Ҫ�����λ��:");
			scanf("%d",&position);
			if(position<=0||position>getcount()+1)
			{
				printf("�Բ����������λ�ó�����Χ!\n");
			}
			else
			{
				printf("������Ҫ���������:  \n");
				scanf("%d",&item);
				returnvalue=insert(position-1,item);//ע�����λ�õĲ���
				printf("����ɹ�....\n");
			}
			break;
		case 4:
			printf("������Ҫɾ�����ݵ�λ��:");
			scanf("%d",&position);
			if(position<0||position>getcount())
			{
				printf("�Բ����������λ�ó�����Χ!\n");
			}
			else
			{
				returnvalue=remove(position-1);//ע�����λ�õĲ���
				printf("ɾ���ɹ�....\n");
			}
			break;
		case 5:
			printf("������Ҫ��ȡ���ݵ�λ�ã�");
			scanf("%d",&position);
			returnvalue=retrieve(position,item);
			if(returnvalue==underflow)
			    printf("�Բ��������ѿ�!\n");
			else if(returnvalue==range_error)
				printf("�Բ��𣬶�ȡ��λ�ó����˷�Χ!\n");
			else
				printf("��ȡ������Ϊ��%d  ��ȡ�����ɹ�!\n",item);
		    break;
		case 6:
			printf("������Ҫ�޸����ݵ�λ�ã�");
			scanf("%d",&position);
			printf("������Ҫ�޸ĵ������ݣ�");
            scanf("%d",&item);
			returnvalue=replace(position,item);
			if(returnvalue==underflow)
			    printf("�Բ��������ѿ�!\n");
			else if(returnvalue==range_error)
				printf("�Բ����޸ĵ�λ�ó����˷�Χ!\n");
			else
				printf("�޸Ĳ����ɹ�!\n");
			break;	
		case 7:
			printf("����Ŀǰ�ĳ���Ϊ: %d\n",length());
			printf("�������Ȳ����ɹ�!\n");
			break;
		case 8:
			printf("��תǰΪ��\n");
			traverse();
			invertlist();
			printf("�������ݷ�ת�ɹ�...\n");
			printf("��ת�������Ϊ��\n");
			traverse();
			break;
		case 9:
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
int main()
{
	SetConsoleTitle("������ʵ�����Ա�Ĺ��ܣ�C�棩");
	int returnchoose;
	initList();            //��ʼ������    
	while(1)               //����ѭ������������ִ�иó���
	{
		system("color f0");//���ñ�����ǰ��ɫ
		showMenu();        //��ʾ�˵�
		returnchoose=userchoose();//�õ��û���ѡ��
		function(returnchoose);   //�����û���ѡ��chooseִ���ض��Ĺ���
		system("pause");          //��ͣһ��
		system("cls");            //����
	}
	return(-1); 
}
