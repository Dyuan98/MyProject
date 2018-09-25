//����:˳��ջ�Ĺ�����ʾ
#include<stdio.h>//������ص�ͷ�ļ�
#include<windows.h>
typedef struct seqStack//�ýṹ�嶨��˳��ջ
{
	int *stackSpace;									//ջ�ռ�ľ���ʵ�֣�������ͨ����̬����ռ佨�����顣
	int stackSize;										//ջ�Ĵ�С����Ϊ0ʱ��ջû�д����ռ䡣
	int top;											//ջ��λ�ã���Ϊ-1ʱ��ջΪ�ա�
}stack;													//�Ѷ����ջ����Ϊstack
//������غ���
void initStack(stack *st);								//�״γ�ʼ��һ��ջ��
bool create(stack *st,int size);						//ʵ�ʴ���һ����������size��Ԫ�ص�ջ��
void destroy(stack *st);								//����һ��ջ��
bool isempty(stack *st);								//ȷ��ջ�Ƿ��ѿա�
bool isfull(stack *st);									//ȷ��ջ�Ƿ�������
bool push(stack *st,int *item);							//���ݽ�ջ��
bool pop(stack *st,int *item);							//��ջ���ҷ���ԭջ����ֵ
bool gettop(stack *st,int *item);						//ȡ����ǰջ�����ݡ�
void traverse(stack *st);                               //����ջ����������
//��غ�����ʵ��
void initStack(stack *st)//�״γ�ʼ��ջ
{
    st->stackSpace=NULL;								//��ʼ�����ռ���ʼ��ַΪ�ա�
	st->stackSize=0;									//ջ�Ĵ�С����ʼֵΪ0����ʾĿǰ��û�н�����
	st->top=-1;											//ջ��λ�ã���Ϊ-1ʱ��ջΪ�ա�
}
bool create(stack *st,int size)//��һ����Сʵ�ʹ���ջ�ĺ���
{
	if(st->stackSize)									//ջ�Ѿ����ڣ������ٴ���
		return false;
	if(size<=0)											//size��ֵ��������㡣
		return false;
	st->stackSpace=(int *)malloc(sizeof(int)*size);		//����size�Ĵ�С���붯̬����ռ䡣
	if(!(st->stackSpace))								//û�����뵽�洢�ռ䣬����ջ���ɹ���
	    return false;
	st->stackSize=size;									//���뵽�洢�ռ䣬����ջ�ɹ�����СΪsize��
	st->top=-1;											//ջ�ս����ɹ�ʱ��ջ��ָ��Ϊ-1��
	return true;
}
void destroy(stack *st)//�ͷ�ջ�Ŀռ䣬��������ϵͳ
{
	if(st->stackSpace)
		free(st->stackSpace);							//ʵ���ͷ����
	st->stackSpace=NULL;								//�ռ���ʼ��ַ�ָ�Ϊ�ա�
	st->stackSize=0;									//ջ�Ĵ�С�ָ�Ϊ��ʼֵ0����ʾĿǰ��û�н�����
	st->top=-1;											//ջ��ָ��ָ�Ϊ-1��
}
bool isempty(stack *st)//����ջ�Ƿ�Ϊ��
{
    if(!st->stackSize)									//ȷ��ջ�Ƿ񱻴�����û�д�����Ϊ�ա�
		return true;
	return st->top==-1 ? true : false ;					//����ջ��ָ���λ�÷����Ƿ�Ϊ�ա�
}
bool isfull(stack *st)//����ջ�Ƿ�Ϊ��
{
	if(!st->stackSize)									//ȷ��ջ�Ƿ񱻴�����û�д�����Ϊ����
		return true;
	return (st->top)==(st->stackSize)-1 ? true : false;	//����ջ��ָ���λ�÷����Ƿ�Ϊ����
}
bool push(stack *st,int *item)
{	
    if(!st->stackSize)									//���ջû�б�����������ִ�н�ջ������
		return false;
	if(isfull(st))										//���ջ�ռ��Ѿ���������ִ�н�ջ������
		return false;
	st->top++;											//ջ��ָ����������
	st->stackSpace[st->top]=*item;                      //��ǰλ�ô���Ҫ��ջ������ 
	return true;										//���سɹ���־��
}
bool pop(stack *st,int *item)//��ջ���ҷ���ԭջ����ֵ
{
 	if(isempty(st))										//���ջ�ռ��Ѿ�Ϊ�գ�����ִ�г�ջ������
		return false;
	*item=st->stackSpace[st->top];						//��Ҫ��ջ�����ݱ�����������ȥ
	st->top--;                                          //��ջ��ָ�������ƶ�һ����ַ
	return true;										//���سɹ���־��
}
bool gettop(stack *st,int *item)//��ȡ��ǰջ�� 
{
 	if(isempty(st))										//���ջ�ռ��Ѿ�Ϊ�գ�����ִ�г�ջ������
		return false;
	*item=st->stackSpace[st->top];						//��ջ�����ݱ����������ء�
    return true;										//���سɹ���־��
}
void traverse(stack *st)//����ջ����������
{
	if(!st->stackSize)									//��ջ��û������ʱ�������ʾ�������ݡ�
		printf("ջ��δ������\n");						//��ջ��������ʱ����ʾ�������ݡ�
	else
	{
		printf("Ŀǰջ�е�������: ");
		printf("ջ�ס�");
		for(int i=0;i<=st->top;i++)						//ջ�Ŀռ��0��topָ���λ�á�
		    printf("%d  ",st->stackSpace[i]);			//���ÿһ�����ݣ�ͬʱ���һ���ո�
        printf("��topջ��\n");
	}
}
//������ʼ
void main(void)
{
	SetConsoleTitle("˳��ջ�Ĺ�����ʾ");
	system("color f0");									//������ɫ(f)��������ɫΪ��ɫ(0)
	stack stacknow;										//����һ��ջ������Ϊstacknow		
	initStack(&stacknow);                               //�����ջ���е�һ�γ�ʼ��
	char yesno,userchoice='9';							//�����ַ���������������Ĳ˵�����
	int newstacksize,pushdata,popdata;					//�����������������ڴ洢ջ�Ĵ�С����ջ�����ݺͳ�ջ������
	while(1)											//����ѭ��
	{
		if(userchoice=='9')								//����û�ѡ����Ĭ��ֵ�Ļ�
		{
			system("cls");								//����һ������
			printf("==========================\n");
		    printf("   ˳��ջ�Ĺ�����ʾ          \n");
			printf("==========================\n");
		    printf("1: ����һ��ջ             \n");
		    printf("2: ����һ��ջ��           \n");
		    printf("3: ���ݽ�ջ�������������� \n");
		    printf("4: ���ݳ�ջ��             \n");
		    printf("5: ��ʾջ��ȫ������       \n");
			printf("6: ��ȡջ������           \n");
			printf("7: �ж��Ƿ��ջ��         \n");
		    printf("8: �ж��Ƿ���ջ��         \n");
			printf("9: ����           \n");
		    printf("0: �˳���                 \n");
		}
		printf("��ѡ��:");//��ʾ�û�����
		fflush(stdin);//�����س���Ӱ��
		scanf("%c",&userchoice);//�Ӽ��̶�ȡ�û���ѡ��
		if(userchoice=='0')	//�˳�����
			break;
		switch(userchoice)//�����û�ѡ��ֱ���
		{
		case '1'://�����ȴ���һ��ջ������ѹ������
			printf("��ʼ����ջ��������ջ�ռ��С:");
			fflush(stdin);
			scanf("%d",&newstacksize);//����ջ�Ĵ�С
            if(create(&stacknow,newstacksize))//��������Ĵ�С����ջ
				printf("����ջ�ɹ���ջ�ռ��С��:%d\n",newstacksize);
			else
				printf("����ջʧ�ܣ�\n");
			break;
		case '2'://����һ��ջ
			printf("�����Ҫ����ջ��������(Y/y)ȷ����������Ϊ����:");
     		fflush(stdin);
			scanf("%c",&yesno);
			if(yesno=='Y'||yesno=='y')
			{
                destroy(&stacknow);//�ͷ�ջ�Ŀռ�
			    printf("ջ�Ѿ����٣�\n");
			}
			break;
		case '3'://������ѹ��ջ
			printf("��ջѹ������:");
			fflush(stdin);
			scanf("%d",&pushdata);//����Ҫ��ջ������
            if(push(&stacknow,&pushdata))//�����ջ�ɹ�
			{
				printf("���� %d �ѳɹ���ջ��\n",pushdata);
                traverse(&stacknow);		//��Ŀǰջ��ȫ��������ʾһ��	
			}
			else
				printf("���� %d ��ջʧ�ܣ�\n",pushdata);//��ջʧ��
			break;
		case '4'://��ջ�е�������
            if(pop(&stacknow,&popdata))//�����ջ�ɹ�
			{	
				printf("��ջ�гɹ��ص�������:%d\n",popdata);//��ʾ��ջ������
				traverse(&stacknow);//��Ŀǰջ��ȫ��������ʾһ��
			}
			else
				printf("��ջ����ʧ��\n");
			break;
		case '5':
			traverse(&stacknow);//��Ŀǰջ��ȫ��������ʾһ��
			break;
		case '6':
			if(gettop(&stacknow,&popdata))//��������ջ������
			{	
				printf("ջ������Ϊ:%d\n",popdata);
				traverse(&stacknow);//��Ŀǰջ��ȫ��������ʾһ��
			}
			else
				printf("ȡջ�����ݲ���ʧ��\n");
			break;
		case '7'://ջ�Ƿ��ѿ�
			if(isempty(&stacknow))//���ĿǰջΪ��
				printf("Ŀǰ�ǿ�ջ����ջ��δ������\n");
			else
				printf("Ŀǰ�Ƿǿ�ջ��\n");
			break;
		case '8'://ջ�Ƿ�������
			if(isfull(&stacknow))//���ĿǰջΪ��
                printf("Ŀǰ����ջ����ջ��δ������\n");
			else
				printf("Ŀǰջ�����������Լ�����ջ��\n");
			break;
		case '9':
			break;
		default:
			printf("�Բ������������д�\n");
			break;
		}
	}
}
