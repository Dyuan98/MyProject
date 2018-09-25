//������ʽ
#include<windows.h>
#include<stdio.h>
#include<string.h>
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
haveason,havetwosons,range_error,quit};            //���巵����Ϣ�嵥
#define expmaxsize 50							   //�궨�����鳤��
char defaultexp[]="12/6*(3*2+5)";				   //Ĭ�ϱ��ʽ
int startbuild;									   //��־λ���ж��Ƿ��ǵ�һ��������ʽ
char answer;
char infixexp[expmaxsize];					       //�洢���ʽ�ַ����и���ʽ
char postfixexp[expmaxsize];                       //�洢���ʽ�ַ��������ʽ
char charstack[expmaxsize];                        //�洢�ַ���ջ�����ڽ���׺���ʽתΪ��׺���ʽ
double doublestack[expmaxsize];                    //�洢��ֵ��ջ������ʵ�ʵı��ʽ����
int inputexp(int choice);                          //������ѧ���ʽ
int change();                                      //����׺���ʽתΪ��׺���ʽ
int compute();                                     //�����׺���ʽpostfixexp��ֵ
int precedence(char op);                           //��������������ȼ�
void showmenu();                                   //��ʾ�˵�
void processmenu();                                //���ܺ���
void showinfixexp();                               //��ʾ�и����ʽ
void showpostfixexp();                             //��ʾ������ʽ

int inputexp(int choice)                           //������ѧ���ʽ
{
	if(startbuild==0)
        startbuild=1;
    else
    {
		printf("��ȫ��ʾ�� ԭ��ѧ���ʽ�Ѿ������������Ὣ���ƻ�!\n");
        printf("��ȷ�ϼ������д˲���  (Y|y):\n");
		fflush(stdin);
		scanf("%c",&answer);
        if(answer=='Y'||answer=='y')
        {
            startbuild=1;
        }
        else
        {
            return fail;
        }
    }
    if(startbuild==1)
    {
        if(choice==1)
        {
            strcpy(infixexp,defaultexp);
        }
        else
        {
            printf("�����ü���������ѧ���ʽ���ַ�����ʽ (ע����Ӣ�����뷨)��\n");
            printf("������6.3*(1.2+2.5)-9*2\n");
            printf("ע�⣺����ʱ�ݲ�֧�ָ������磺-9/3\n");
            printf("������Ϸ���ѧ���ʽ���ַ�����ʽ��\n");
			scanf("%s",infixexp);
        }
    }
	return success;
}
void showinfixexp()//��ʾ�и����ʽ
{
    printf("%s",infixexp);
}
void showpostfixexp()//��ʾ������ʽ
{
    printf("%s",postfixexp);
}
int precedence(char op)//��������������ȼ�
{
    switch(op)
	{
	   case '+':
	   case '-':
		   return 1;//�Ӽ�ͬ��Ϊ1
	   case '*':
	   case '/':
		   return 2;//�˳�ͬ��Ϊ2
	   case '@':
	   case '(':
	   default:
		   return 0;//����Ϊ0
	}
}
int change()//����׺���ʽתΪ��׺���ʽ
{
	int posi=0;                  //ɨ��infixexp��ָʾpostfixexp�Ĵ����ַ���λ��
	int posj=0;
	int posk=0;
	char charnow=infixexp[posi];
	charstack[posk]='@';         //����@��ջ�ף���������͵����ȼ�0
	                             //����ɨ��infixexp��׺���ʽ�е��ַ�
	while(charnow!='\0')         //���ʽû�н���ʱһֱ��
	{
		if(charnow==' ')        //���ڿո����κδ���
			charnow=infixexp[++posi];
		else if(charnow=='(')   //����'('��ֱ�ӽ�ջ
		{
			charstack[++posk]=charnow;
			charnow=infixexp[++posi];
		}
		else if(charnow==')')   //����')'��ʹ�����ڵ���ͣ����ջ�е���������γ�ջ��д��postfixexp
		{
			char topitem;
			if(posk<0)
			{
				printf("\n������������ʱջ�ѿ�!\n");
				return fail;
			}
			topitem=charstack[posk--];
			while((topitem!='(')&&(topitem!='@'))
			{
				postfixexp[posj++]=topitem;
				topitem=charstack[posk--];
			}
			if(topitem=='@')
			{
				printf("\n���ʽ����: ���Ų�ƥ�� !\n");
				return fail;
			}
			charnow=infixexp[++posi];
		}
		//���������������ʹ�ݴ���ջ���Ĳ�����charnow���ȼ����������ջ��д��postfixexp
		else if((charnow=='+')||(charnow=='-')||(charnow=='*')||(charnow=='/'))
		{
			char topitem;
			if(posk<0)
			{
				printf("\n����ȡ��������ʱ��ȡջ��ʱջ�ѿ�!\n");
				return fail;
			}
			topitem=charstack[posk];
			while(precedence(topitem)>=precedence(charnow))//����precedence()��������������ȼ�
			{   
				postfixexp[posj++]=topitem;
				posk--;
				if(posk<0)
				{
					printf("\n����ȡջ��ʱջ�ѿ�!\n");			   
					return fail;
				}	
				topitem=charstack[posk];
			}
			charstack[++posk]=charnow;
			charnow=infixexp[++posi];
		}
		else//����ֵ��ÿһλ����postfixexp 
		{
			if((charnow<'0'||charnow>'9') && charnow!='.')//�������֣�Ҳ����С����
			{
				printf("\n���ʽ���� :���ַǷ�����������ֵķ���!\n");
				return fail;
			}
			else
			{
				while((charnow>='0'&&charnow<='9')||(charnow=='.'))
				{ 
					postfixexp[posj++]=charnow;
					charnow=infixexp[++posi];				   
				}
			}
			postfixexp[posj++]=' ';//ÿ�����ֺ���Ÿ��ո�
		}
	}
	//infixexp�������
	//���ݴ���ջ�е������������ջ��д��postfixexp
	charnow=charstack[posk--];
	while(charnow!='@')
	{
		if(charnow=='(')
		{
			printf("\n���ʽ����: ���Ų�ƥ�� !\n");
			return fail;
		}
		else
		{
			postfixexp[posj++]=charnow;
			charnow=charstack[posk--];
		}
	}
	postfixexp[posj++]='\0';
	return success;
}
int compute()//�����׺���ʽpostfixexp��ֵ
{
	double partinteger,partdecimal;  //���ڱ��渡������partintegerΪ�������֣�partdecimalΪС������
	double topX,topY;          //����ÿ��������������������
	int posi=0;  //���ڱ�����׺���ʽ
	int posj=-1;
	double tentimes=10.0;
	while(postfixexp[posi])
	{
		if(postfixexp[posi]==' ')//�����ո�������
		{
			posi++;
			continue;
		}
		switch(postfixexp[posi])
		{
	       case '+'://��ջ������Ԫ�صļӷ����͸���partinteger
			   if(posi<1)
			   {
				   printf("\n���ʽ����1 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topX+topY;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '-'://��ջ������Ԫ�صļ��������partinteger
			   if(posi<1)
			   {
				   printf("\n���ʽ���� 2!\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topY-topX;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '*'://��ջ������Ԫ�صĳ˷���������partinteger
			   if(posi<1)
			   {
				   printf("\n���ʽ����3 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topX*topY;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '/'://��ջ������Ԫ�صĳ������̸���partinteger
			   if(posi<1)
			   {
				   printf("\n���ʽ����4 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   if(topX!=0.0)
				   partinteger=topY/topX;
			   else
			   {
				   printf("\n���ʽ���� : ����Ϊ0 !\n");
				   return fail;
			   }
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   default:
			   //����partinteger����ɨ�赽���������ֵ�ֵ
			   partinteger=0;										//��׼Ϊ0
			   while(postfixexp[posi]>=48 && postfixexp[posi]<=57)	//�����ַ��Ƿ�Ϊ�ַ�����
			   {
				   partinteger=partinteger*10+postfixexp[posi]-48;  //�ַ�����ת�����������֣���ʵ�ֶ�λ��
				   posi++;											//ѭ���ƶ�����һ���ַ�
			   }
			   //����partdecimal����ɨ�赽��С�����ֵ�ֵ
			   if(postfixexp[posi]=='.')							//һ������С���㣬�������С������
			   {
				   partdecimal=0;									//��׼Ϊ0
				   posi++;											//С������һλ
				   while(postfixexp[posi]>=48 && postfixexp[posi]<=57)
				   {
					   partdecimal=partdecimal+(postfixexp[posi]-48)/tentimes;
					   posi++;
					   tentimes*=10;
				   }
				   partinteger+=partdecimal;	//���������ֺ�С�����ֺ���һ��			   			   
			   }
			   doublestack[++posj]=partinteger;
		}
	}
	if(posj<0)
	{
		printf("\n���ʽ���� 6!\n");
		return fail;
	}
	partinteger=doublestack[posj--];
	if(posj<0)
	{
		if(partinteger-(int)partinteger!=0)
			printf("\n�������ǣ�\n%f\n",partinteger);
		else
			printf("\n�������ǣ�\n%.0f\n",partinteger);
		return success;
	}
	else
	{
		printf("\n���ʽ���� 7!\n");
		return fail;
	}
}
void showmenu()
{
    printf("        ������ʽ������ʾ        \n");
    printf("==================================\n");
    printf("1.����Ĭ�ϱ��ʽ                  \n");
    printf("2.��������                        \n");
    printf("3.������ʽ                      \n");
    printf("0.�˳�							 \n");
    printf("==================================\n");
}
void processmenu()
{
    char choice;				//�����û�ѡ��˵�ѡ��
    int  returnvalue;			//������Ϣ����
    printf("������ѡ�");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice)
    {
    case '1'://1.����Ĭ������
        printf("================\n");
        returnvalue=inputexp(1);
        if(returnvalue==fail)
            printf("�Ѿ�ȡ���������ʽ!\n");
        else if(returnvalue==success)
        {
            printf("��ǰ���ʽ�ַ���Ϊ: \n");
            showinfixexp();
            printf("\n���ʽ�����ɹ�!\n");
        }
        printf("================\n");
        break;
    case '2'://2.���ü�������
        printf("================\n");
        returnvalue=inputexp(2);
        if(returnvalue==fail)
            printf("�Ѿ�ȡ���������ʽ!\n");
        else if(returnvalue==success)
        {
            printf("��ǰ���ʽ�ַ���Ϊ: \n");
            showinfixexp();
            printf("\n���ʽ�����ɹ�!\n");
        }
        printf("================\n");
        break;
	case '3'://3.������ʽ
        printf("================\n");
		printf("��ǰ���ʽ�ַ���Ϊ: \n");
		showinfixexp();
		if(change()==success)
		{
			printf("\n��Ӧ�ĺ�׺���ʽ��\n");
			showpostfixexp();
			printf("\n������ʽ��ʼ... \n");
			compute();
		}
		printf("================\n");
        break;
    case '0':
        printf("��ѡ�����˳���ллʹ��...\n");
        system("pause");
        exit(1);
    default:
        printf("�����д�����������...\n");
    }
}
//���������
int main(void) 
{
	SetConsoleTitle("������ʽ��C�棩");
    system("color f0");
    system("cls");
    startbuild=0;
    while (1)
    {
        showmenu();
        processmenu();
        system("pause");
        system("cls");
    }
    return 0;
}//����������