//��������������Դ�� 3-1��˳���ʵ�����Ա�Ļ�������C��.cpp
//���ܣ�������Ա���½�����ʾ�����롢ɾ������ȡ���޸ġ�����ȣ����ݷ�ת�ȹ���
#include <stdio.h> //������������ͷ�ļ�
#include <windows.h>//��������ɫ������Ҫ   
#include <iomanip.h>  //���ݺ����Ķ��� 
#define Maxsize 20      //�������Ա����󳤶�
enum returninfo{success,fail,overflow,underflow,range_error};//���巵����Ϣ�嵥
int dataarray[Maxsize];             //����������
int count;                          //������ ͳ�ƽ����������Ա�ĳ���
returninfo create(int number);                //˳���ĳ�ʼ��
bool empty(void) ;                            //�ж��Ƿ��
int length(void) ;                            //��˳���ĳ���
returninfo traverse(void);                    //����˳�������Ԫ��
returninfo get(int position,int &item) ;      //��ȡһ�����
returninfo replace(int position,int &item);  //�޸�һ�����
returninfo insert(int position,int &item);   //����һ�����
returninfo remove(int position);                   //ɾ��һ�����
returninfo invertlist(void);                       //˳����������ݷ�ת
void clearscreen(void);                        //����
void showmenu(void);                           //��ʾ�˵�����
int userchoice(void);                          //�û���ѡ��
returninfo processmenu(int menuchoice);//�˵�����
/*����������������������������������������������������//
�� �� ��:create
��    ��:��������
��ڲ���:��
���ڲ���:����returninfoö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo create(int number)
{
	count=number;
    printf("�������������ݣ��ÿո��������\n");
	for(int i=0;i<count;i++)//��0�±꿪ʼ
		scanf("%d",&dataarray[i]);//�����������
	return success;
}
/*����������������������������������������������������//
�� �� ��:empty
��    ��:�ж������Ƿ�Ϊ��
��ڲ���:��
���ڲ���:bool��
//����������������������������������������������������*/
bool empty(void)   //�ж��Ƿ�Ϊ��
{
	if(count==0)     //������Ϊ0��˵��û������     
		return true;
	else
		return false;
}
/*����������������������������������������������������//
�� �� ��:length
��    ��:�õ�˳�����
��ڲ���:��
���ڲ���:int��
//����������������������������������������������������*/
int length(void)   //��˳���ĳ���
{
	return count; //count�д洢�ľ������ݸ���              
}
/*����������������������������������������������������//
�� �� ��:traverse
��    ��:����ȫ������
��ڲ���:��
���ڲ���:����returninfoö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo traverse(void)            //����˳����е�����Ԫ��
{
	if(empty())
	    return underflow;                     //�ձ�Ĵ���
	printf("˳����е�ȫ������Ϊ:   ");         //��ʾ��ʾ���ݿ�ʼ
	for(int i=0;i<count;i++)                  //ѭ����ʾ��������
		printf("%d ",dataarray[i]);
	printf("\n");                           //�����һ���س��Ŀ���
	return success;                           //���β����ɹ�
}
/*����������������������������������������������������//
�� �� ��:get
��    ��:��ȡһ�����
��ڲ���:λ�ã�int������
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo get(int position, int &item)   //��ȡһ��Ԫ��
{
	if(empty())                             //�ձ�Ĵ���
		return underflow;	
	if(position<=0||position>count)         //��������
		return range_error;
	item=dataarray[position-1];             //���ض�ȡ������
	return success;                         //���β����ɹ�
}
/*����������������������������������������������������//
�� �� ��:replace
��    ��:�޸�ָ��λ������
��ڲ���:λ�ã��滻ֵ
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo replace(int position,int &item)  //�޸�һ��Ԫ��
{
	if(empty())                                
		return underflow;	
	if(position<=0||position>count)
		return range_error;
	dataarray[position-1]=item; //ʵ���޸����ݵ���䣬������0�±꣬���Դ˴���һ
	return success;
}
/*����������������������������������������������������//
�� �� ��:insert
��    ��:�������ݵ�ָ��λ��
��ڲ���:λ��position������&item
���ڲ���:����returninfoö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo insert(int position,int &item)    //����һ��Ԫ��
{
	if(count+1>=Maxsize)
		return overflow;                   //�������
	if(position<=0 || position>count+1)      
		return range_error;
	count++;                                //��������һ
	for(int i=count;i>=position;i--)        //ѭ���ƶ����ݣ������ƶ�����
	{
		dataarray[i]=dataarray[i-1];//ʵ���ƶ�����
	}
	dataarray[position-1]=item;//ʵ�ʲ�������
	return success;
}
/*����������������������������������������������������//
�� �� ��:remove
��    ��:ɾ��ָ��λ�õ�����
��ڲ���:λ��position
���ڲ���:����returninfoö���ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo remove(int position)   //ɾ��һ��Ԫ��
{
	if(empty())
		return underflow;	
	if(position<=0||position>count)
		return range_error;
	for(int i=position-1;i<count;i++)   //ѭ���ƶ����ݣ������ƶ�����
		dataarray[i]=dataarray[i+1];
	count--;                            //��������һ
	return success;
}
/*����������������������������������������������������//
�� �� ��:invertlist
��    ��:��ת˳�������
��ڲ���:��
���ڲ���:returninfo�ͣ��жϲ����Ƿ�ɹ�
//����������������������������������������������������*/
returninfo invertlist(void)    //˳����������ݷ�ת
{
	int halfpos,tempdata;
	if(empty())
		return underflow;
	halfpos=count/2;//������е�
	for(int i=0;i<halfpos;i++)
	{
		tempdata=dataarray[i];//ͨ����ʱ�м�������н�������
		dataarray[i]=dataarray[count-1-i];
		dataarray[count-1-i]=tempdata;
	}
	return success;
}
void clearscreen(void)
{
    system("cls");
}
/*����������������������������������������������������//
�� �� ��:showMenu
��    ��:��ʾ���ܲ˵�
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void showmenu(void)
{
  	printf("˳���������ܲ˵�               \n");
    printf("==================               \n");
    printf("1.�������ݣ��������룩           \n");
    printf("2.��ʾ���ݣ�����ȫ�����ݣ�       \n");
    printf("3.�޸����ݣ�Ҫ�ṩλ�ú���ֵ��   \n");
    printf("4.�������ݣ�Ҫ�ṩλ�ú���ֵ��   \n");
    printf("5.ɾ�����ݣ�Ҫ�ṩλ�ã�         \n");
    printf("6.��ȡ���ݣ�Ҫ�ṩλ�ã�         \n");
    printf("7.�����                       \n");
	printf("8.���ݷ�ת��ȫ����������洢��   \n");
    printf("9.��������                       \n");
	printf("=================                \n");
}
/*����������������������������������������������������//
�� �� ��:userchoice
��    ��:�õ��û������ѡ��
��ڲ���:��
���ڲ���:��������ѡ��
//����������������������������������������������������*/
int userchoice(void)
{	int menuchoice;
	printf("����������ѡ��");   
	scanf("%d",&menuchoice);
	return menuchoice;
}
/*����������������������������������������������������//
�� �� ��:processmenu
��    ��:ִ���û�ѡ��Ĺ���
��ڲ���:����ѡ��
���ڲ���:��
//����������������������������������������������������*/
returninfo processmenu(int menuchoice)
{
	int position,item,returnvalue;
	switch(menuchoice)    //�����û���ѡ�������Ӧ�Ĳ���
	{
	case 1:		printf("������Ҫ�������ݵĸ�����ע��Ҫ��%d�����ڣ� ",Maxsize);
				scanf("%d",&item);
				if(item>Maxsize)
					printf("�Բ����������ݳ��ޣ�������ȡ��!\n");
				else
				{
					returnvalue=create(item);
					if(returnvalue==success)
					printf("����˳�������ɹ�!\n");
				}
				break;
	case 2:
				returnvalue=traverse(); 
				if(returnvalue==underflow)
					printf("˳���ĿǰΪ�գ�û�����ݿ�����ʾ!\n");
				else
					printf("˳�����������ɹ�!\n");
				break;
	case 3:
				printf("������Ҫ�޸����ݵ�λ�ã�");
				scanf("%d",&position);
				printf("������Ҫ�޸ĵ������ݣ�");
				scanf("%d",&item); 
				returnvalue=replace(position,item);
				if(returnvalue==underflow)
				    printf("�Բ���˳����ѿ�!\n");
				else if(returnvalue==range_error)
					printf("�Բ����޸ĵ�λ�ó����˷�Χ!\n");
				else
					printf("�޸Ĳ����ɹ�!\n");
				break;		
	
	case 4:
				printf("������Ҫ�������ݵ�λ�ã�");
				scanf("%d",&position);
				printf("������Ҫ����������ݣ�");
				scanf("%d",&item);
				returnvalue=insert(position,item);
				if(returnvalue==overflow)
				    printf("�Բ���˳���������޷�����������!\n");
				else if(returnvalue==range_error)
					printf("�Բ��𣬲����λ�ó����˷�Χ!\n");
				else
					printf("��������ɹ�!\n");
				break;
			
	case 5:
				printf("������Ҫɾ�����ݵ�λ�ã�");
				scanf("%d",&position);
				returnvalue=remove(position);
				if(returnvalue==underflow)
				    printf("�Բ���˳����ѿ�!\n");
				else if(returnvalue==range_error)
					printf("�Բ���ɾ����λ�ó����˷�Χ!\n");
				else
					printf("ɾ�������ɹ�!\n");
				break;
	case 6:
				printf("������Ҫ��ȡ���ݵ�λ�ã�");
				scanf("%d",&position);
				returnvalue=get(position,item);
				if(returnvalue==underflow)
				    printf("�Բ���˳����ѿ�!\n");
				else if(returnvalue==range_error)
					printf("�Բ��𣬶�ȡ��λ�ó����˷�Χ!\n");
				else
					printf("��ȡ������Ϊ��%d\n��ȡ�����ɹ�!\n",item);
			    break;
			
	case 7:
				printf("˳���Ŀǰ�ĳ���Ϊ: %d\n",length());
				printf("��˳����Ȳ����ɹ�!\n");
				break;
							
	case 8:
				returnvalue=invertlist();
				if(returnvalue==underflow)
				    printf("�Բ���˳����ѿ�!\n");
				else 
					printf("˳�������Ԫ�ط�ת�����ɹ�!\n");
				break;	
	case 9:     
		        exit(0);
	default:
				printf("�Բ���������Ĺ��ܱ���д�!����������!!!\n");
		    	break;
		}
		return success;
}
/*����������������������������������������������������//
�� �� ��:main
��    ��:������
��ڲ���:��
���ڲ���:��
//����������������������������������������������������*/
void main(void)                     //���������
{   
	SetConsoleTitle("˳���ʵ�����Ա�Ļ������ܣ�C�棩");
	int menuchoice; //����������˵�ѡ�����ѡ��                
	system("color f0");//�޸���Ļ�ı���ɫ���ֵ���ɫ
	clearscreen();//����
    while (1)//����ѭ��
	{
  		showmenu();//��ʾ�˵�
		menuchoice=userchoice();//��ȡ�û���ѡ��
		processmenu(menuchoice);//�����û���ѡ��
		system("pause"); //��ͣ
		clearscreen();//����
    }
}//����������
