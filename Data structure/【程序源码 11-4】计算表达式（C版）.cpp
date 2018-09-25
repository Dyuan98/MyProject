//计算表达式
#include<windows.h>
#include<stdio.h>
#include<string.h>
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
haveason,havetwosons,range_error,quit};            //定义返回信息清单
#define expmaxsize 50							   //宏定义数组长度
char defaultexp[]="12/6*(3*2+5)";				   //默认表达式
int startbuild;									   //标志位：判断是否是第一次输入表达式
char answer;
char infixexp[expmaxsize];					       //存储表达式字符串中根形式
char postfixexp[expmaxsize];                       //存储表达式字符串后根形式
char charstack[expmaxsize];                        //存储字符的栈，用于将中缀表达式转为后缀表达式
double doublestack[expmaxsize];                    //存储数值的栈，用于实际的表达式计算
int inputexp(int choice);                          //建立数学表达式
int change();                                      //将中缀表达式转为后缀表达式
int compute();                                     //计算后缀表达式postfixexp的值
int precedence(char op);                           //返回运算符的优先级
void showmenu();                                   //显示菜单
void processmenu();                                //功能函数
void showinfixexp();                               //显示中根表达式
void showpostfixexp();                             //显示后根表达式

int inputexp(int choice)                           //建立数学表达式
{
	if(startbuild==0)
        startbuild=1;
    else
    {
		printf("安全提示： 原数学表达式已经建立，操作会将其破坏!\n");
        printf("您确认继续进行此操作  (Y|y):\n");
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
            printf("下面用键盘输入数学表达式的字符串形式 (注意用英文输入法)：\n");
            printf("范例：6.3*(1.2+2.5)-9*2\n");
            printf("注意：输入时暂不支持负数，如：-9/3\n");
            printf("请输入合法数学表达式的字符串形式：\n");
			scanf("%s",infixexp);
        }
    }
	return success;
}
void showinfixexp()//显示中根表达式
{
    printf("%s",infixexp);
}
void showpostfixexp()//显示后根表达式
{
    printf("%s",postfixexp);
}
int precedence(char op)//返回运算符的优先级
{
    switch(op)
	{
	   case '+':
	   case '-':
		   return 1;//加减同级为1
	   case '*':
	   case '/':
		   return 2;//乘除同级为2
	   case '@':
	   case '(':
	   default:
		   return 0;//其他为0
	}
}
int change()//将中缀表达式转为后缀表达式
{
	int posi=0;                  //扫描infixexp，指示postfixexp的待存字符的位置
	int posj=0;
	int posk=0;
	char charnow=infixexp[posi];
	charstack[posk]='@';         //放入@于栈底，并具有最低的优先级0
	                             //依次扫描infixexp中缀表达式中的字符
	while(charnow!='\0')         //表达式没有结束时一直做
	{
		if(charnow==' ')        //对于空格不做任何处理
			charnow=infixexp[++posi];
		else if(charnow=='(')   //对于'('，直接进栈
		{
			charstack[++posk]=charnow;
			charnow=infixexp[++posi];
		}
		else if(charnow==')')   //对于')'，使括号内的仍停留在栈中的运算符依次出栈并写入postfixexp
		{
			char topitem;
			if(posk<0)
			{
				printf("\n在遇到右括号时栈已空!\n");
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
				printf("\n表达式错误: 括号不匹配 !\n");
				return fail;
			}
			charnow=infixexp[++posi];
		}
		//对于四则运算符，使暂存在栈顶的不低于charnow优先级的运算符出栈并写入postfixexp
		else if((charnow=='+')||(charnow=='-')||(charnow=='*')||(charnow=='/'))
		{
			char topitem;
			if(posk<0)
			{
				printf("\n当读取到操作符时读取栈顶时栈已空!\n");
				return fail;
			}
			topitem=charstack[posk];
			while(precedence(topitem)>=precedence(charnow))//函数precedence()返回运算符的优先级
			{   
				postfixexp[posj++]=topitem;
				posk--;
				if(posk<0)
				{
					printf("\n当读取栈顶时栈已空!\n");			   
					return fail;
				}	
				topitem=charstack[posk];
			}
			charstack[++posk]=charnow;
			charnow=infixexp[++posi];
		}
		else//把数值中每一位放入postfixexp 
		{
			if((charnow<'0'||charnow>'9') && charnow!='.')//不是数字，也不是小数点
			{
				printf("\n表达式错误 :发现非法运算符或数字的符号!\n");
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
			postfixexp[posj++]=' ';//每个数字后面放个空格
		}
	}
	//infixexp遍历完毕
	//把暂存于栈中的运算符依次退栈并写入postfixexp
	charnow=charstack[posk--];
	while(charnow!='@')
	{
		if(charnow=='(')
		{
			printf("\n表达式错误: 括号不匹配 !\n");
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
int compute()//计算后缀表达式postfixexp的值
{
	double partinteger,partdecimal;  //用于保存浮点数，partinteger为整数部分，partdecimal为小数部分
	double topX,topY;          //保存每个操作符的两个操作数
	int posi=0;  //用于遍历后缀表达式
	int posj=-1;
	double tentimes=10.0;
	while(postfixexp[posi])
	{
		if(postfixexp[posi]==' ')//遇到空格不做处理
		{
			posi++;
			continue;
		}
		switch(postfixexp[posi])
		{
	       case '+'://做栈顶两个元素的加法，和赋给partinteger
			   if(posi<1)
			   {
				   printf("\n表达式错误1 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topX+topY;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '-'://做栈顶两个元素的减法，差赋给partinteger
			   if(posi<1)
			   {
				   printf("\n表达式错误 2!\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topY-topX;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '*'://做栈顶两个元素的乘法，积赋给partinteger
			   if(posi<1)
			   {
				   printf("\n表达式错误3 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   partinteger=topX*topY;
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   case '/'://做栈顶两个元素的除法，商赋给partinteger
			   if(posi<1)
			   {
				   printf("\n表达式错误4 !\n");
				   return fail;
			   }
			   topX=doublestack[posj--];
			   topY=doublestack[posj--];
			   if(topX!=0.0)
				   partinteger=topY/topX;
			   else
			   {
				   printf("\n表达式错误 : 除数为0 !\n");
				   return fail;
			   }
			   posi++;
			   doublestack[++posj]=partinteger;
			   break;
		   default:
			   //利用partinteger保存扫描到的整数部分的值
			   partinteger=0;										//基准为0
			   while(postfixexp[posi]>=48 && postfixexp[posi]<=57)	//测试字符是否为字符数字
			   {
				   partinteger=partinteger*10+postfixexp[posi]-48;  //字符数字转换成真正数字，并实现多位数
				   posi++;											//循环移动到下一个字符
			   }
			   //利用partdecimal保存扫描到的小数部分的值
			   if(postfixexp[posi]=='.')							//一旦遇到小数点，后面就是小数部分
			   {
				   partdecimal=0;									//基准为0
				   posi++;											//小数点后第一位
				   while(postfixexp[posi]>=48 && postfixexp[posi]<=57)
				   {
					   partdecimal=partdecimal+(postfixexp[posi]-48)/tentimes;
					   posi++;
					   tentimes*=10;
				   }
				   partinteger+=partdecimal;	//把整数部分和小数部分合在一起			   			   
			   }
			   doublestack[++posj]=partinteger;
		}
	}
	if(posj<0)
	{
		printf("\n表达式错误 6!\n");
		return fail;
	}
	partinteger=doublestack[posj--];
	if(posj<0)
	{
		if(partinteger-(int)partinteger!=0)
			printf("\n计算结果是：\n%f\n",partinteger);
		else
			printf("\n计算结果是：\n%.0f\n",partinteger);
		return success;
	}
	else
	{
		printf("\n表达式错误 7!\n");
		return fail;
	}
}
void showmenu()
{
    printf("        计算表达式功能演示        \n");
    printf("==================================\n");
    printf("1.启用默认表达式                  \n");
    printf("2.键盘输入                        \n");
    printf("3.计算表达式                      \n");
    printf("0.退出							 \n");
    printf("==================================\n");
}
void processmenu()
{
    char choice;				//用于用户选择菜单选项
    int  returnvalue;			//返回信息代码
    printf("请输入选项：");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice)
    {
    case '1'://1.启用默认数据
        printf("================\n");
        returnvalue=inputexp(1);
        if(returnvalue==fail)
            printf("已经取消建立表达式!\n");
        else if(returnvalue==success)
        {
            printf("当前表达式字符串为: \n");
            showinfixexp();
            printf("\n表达式建立成功!\n");
        }
        printf("================\n");
        break;
    case '2'://2.启用键盘输入
        printf("================\n");
        returnvalue=inputexp(2);
        if(returnvalue==fail)
            printf("已经取消建立表达式!\n");
        else if(returnvalue==success)
        {
            printf("当前表达式字符串为: \n");
            showinfixexp();
            printf("\n表达式建立成功!\n");
        }
        printf("================\n");
        break;
	case '3'://3.计算表达式
        printf("================\n");
		printf("当前表达式字符串为: \n");
		showinfixexp();
		if(change()==success)
		{
			printf("\n对应的后缀表达式：\n");
			showpostfixexp();
			printf("\n计算表达式开始... \n");
			compute();
		}
		printf("================\n");
        break;
    case '0':
        printf("您选择了退出，谢谢使用...\n");
        system("pause");
        exit(1);
    default:
        printf("输入有错，请重新输入...\n");
    }
}
//程序主入口
int main(void) 
{
	SetConsoleTitle("计算表达式（C版）");
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
}//主函数结束