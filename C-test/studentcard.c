#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);//函数声明
RECT rect1;
RECT rect2;
RECT rect3;
RECT rect4;
RECT rect5;
RECT rect6;
RECT rect7;
RECT rect8;
RECT rect9;
RECT rect10;
RECT rect11;
RECT rect12;
RECT rect13;
RECT rect14;
HDC hDC;
PAINTSTRUCT paint;
HWND hWnd;
typedef struct student
{
	char xuehao[20];
	char name[12];
	char xinbie[20];
	char banji[20];
	char shijian[20];
	char xueyuan[20];
	struct student* next;
}STU;
STU head;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    char *cName = "myWindow";//定义个字符指针表示窗口类的名字
    WNDCLASS wc;//定义变量
    HWND hWnd;
    MSG Msg;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//设置窗口背景为白色
    wc.hCursor = NULL;//窗口的光标不设置
    wc.hIcon = NULL;//窗口图标设置
    wc.hInstance = hInstance;//当前程序的句柄，hInstance是由主函数传递
    wc.lpfnWndProc = WinProc;//窗口处理过程的窗口函数。
    wc.lpszClassName =(LPSTR)cName;//窗口类的名字。
    wc.lpszMenuName = NULL;//目录名，不设置
    wc.style = CS_HREDRAW | CS_VREDRAW; //窗口类的风格
    RegisterClass(&wc);//在系统中注册窗口
    hWnd = CreateWindow(cName, TEXT("学生证管理系统"),WS_OVERLAPPEDWINDOW, 10, 30, 800, 600, NULL,            NULL, hInstance, NULL) ;
	ShowWindow(hWnd,nShowCmd);//显示窗口
	UpdateWindow(hWnd);//更新窗口
	while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);//翻译消息
        DispatchMessage(&Msg);//分派消息
    }
    return Msg.message;//程序结束后返回消息
}
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{//处理消息过程
	static HWND hwndInput1 ;
	static HWND hwndInput2 ;
	static HWND hwndInput3 ;
	static HWND hwndInput4 ;
	static HWND hwndInput5 ;
	static HWND hwndInput6 ;
	static HWND hwndInput7 ;
	static HWND hwndInput8 ;
    static HWND hwndInput9 ;
    static HWND hwndbutton1;
	static HWND hwndbutton2;
	static HWND hwndbutton3;
	static HWND hwndbutton4;
	static HWND hwndbutton5;
	static HWND hwndbutton6;
	static HWND hwndbutton7;
    static char filename[20];
    static char str1[100];
    static char str2[10000];
    static char str3[100];
	switch(Msg)//对消息进行判断
    {
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&paint);//获取设备上下文
		
		rect1.top=50;
		rect1.right=20;
		rect1.bottom=70;
		rect1.left=250;
		
		rect2.top=90;
		rect2.right=20;
		rect2.bottom=110;
		rect2.left=250;
		
        rect3.top=130;
		rect3.right=20;
		rect3.bottom=150;
		rect3.left=250;
		
        rect4.top=170;
		rect4.right=20;
		rect4.bottom=190;
		rect4.left=250;
		
		rect5.top=210;
		rect5.right=20;
		rect5.bottom=230;
		rect5.left=250;
		
		rect6.top=50;
		rect6.right=440;
		rect6.bottom=70;
		rect6.left=390;
		
		rect7.top=90;
		rect7.right=440;
		rect7.bottom=110;
		rect7.left=390;
		
		rect8.top=130;
		rect8.right=440;
		rect8.bottom=150;
		rect8.left=390;
		
		rect9.top=170;
		rect9.right=440;
		rect9.bottom=190;
		rect9.left=390;
		
		rect10.top=210;
		rect10.right=450;
		rect10.bottom=230;
		rect10.left=350;
		
		rect11.top=250;
		rect11.right=450;
		rect11.bottom=270;
		rect11.left=350;
		
		rect12.top=320;
		rect12.right=90;
		rect12.bottom=340;
		rect12.left=50;
			
		rect14.top=10;
		rect14.right=350;
		rect14.bottom=30;
		rect14.left=50;
		
		
		//在窗口中输出文本
		DrawText(hDC,"添加学生证信息:",-1, &rect1,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"查询学生证信息:",-1,&rect2,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"删除学生证信息:",-1,&rect3,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"修改学生证信息:",-1,&rect4,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"班级学生证信息:",-1,&rect5,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"学号:",-1,&rect6,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"姓名:",-1,&rect7,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"性别:",-1,&rect8,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"班级:",-1,&rect9,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"入学时间:",-1,&rect10,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"所属院系:",-1,&rect11,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"文件:",-1,&rect12,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"软件152刘帅201500781",-1,&rect14,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hWnd,&paint);
		return 0;
	case WM_CREATE:
		//创建按钮和文本框
		hwndInput1=CreateWindow(TEXT("BUTTON"),TEXT("添加"),WS_CHILD|WS_VISIBLE,270,40,40,30,
			hWnd,(HMENU)11,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput2=CreateWindow(TEXT("BUTTON"),TEXT("查询"),WS_CHILD|WS_VISIBLE,270,80,40,30,
			hWnd,(HMENU)12,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput3=CreateWindow(TEXT("BUTTON"),TEXT("删除"),WS_CHILD|WS_VISIBLE,270,120,40,30,
			hWnd,(HMENU)13,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput4=CreateWindow(TEXT("BUTTON"),TEXT("修改"),WS_CHILD|WS_VISIBLE,270,160,40,30,
			hWnd,(HMENU)14,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput5=CreateWindow(TEXT("BUTTON"),TEXT("查询"),WS_CHILD|WS_VISIBLE,270,200,40,30,
			hWnd,(HMENU)15,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput7=CreateWindow(TEXT("BUTTON"),TEXT("导入"),WS_CHILD|WS_VISIBLE,70,260,40,30,
			hWnd,(HMENU)17,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput8=CreateWindow(TEXT("BUTTON"),TEXT("保存"),WS_CHILD|WS_VISIBLE,150,260,40,30,
			hWnd,(HMENU)18,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput6=CreateWindow(TEXT("BUTTON"),TEXT("初始化"),WS_CHILD|WS_VISIBLE,230,260,50,30,
			hWnd,(HMENU)16,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput1=CreateWindow(TEXT("BUTTON"),TEXT("统计"),WS_CHILD|WS_VISIBLE,310,260,40,30,
			hWnd,(HMENU)19,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput1 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 50, 150, 20,	hWnd, (HMENU)21, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput2 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 90, 150, 20,	hWnd, (HMENU)22, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput3 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 130, 150, 20,	hWnd, (HMENU)23, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput4 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 170, 150, 20,	hWnd, (HMENU)24, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput5 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 210, 150, 20,	hWnd, (HMENU)25, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput6 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,460, 250, 150, 20,	hWnd, (HMENU)26, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput7 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,100, 320, 200, 20,	hWnd, (HMENU)27, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		hwndInput9 = CreateWindow( TEXT("edit"), NULL,	WS_CHILD | WS_VISIBLE  | WS_BORDER |	
			ES_LEFT | ES_MULTILINE ,50, 370, 600, 150,	hWnd, (HMENU)29, ((LPCREATESTRUCT) lParam) -> hInstance, NULL ) ;		
		
		return 0 ;
		
	case WM_COMMAND://响应命令
		{
			switch(LOWORD(wParam))
			{
			case 17:
				{FILE *fp;
				STU *p,*tail;
				head.next=NULL;
				GetDlgItemText(hWnd,27,filename,sizeof(filename)/sizeof(char));
				fp=fopen(filename,"r");
				tail=&head;
				while(!feof(fp))
				{
					p=(STU*)malloc(sizeof(STU));
					fscanf(fp,"%s%s%s%s%s%s",p->xuehao,p->name,p->xinbie,p->banji,p->shijian,p->xueyuan);		
					tail->next=p;
					p->next=NULL;
					tail=p;
					if(feof(fp))
					{
						MessageBox(NULL,TEXT("导入成功"),TEXT("提示"),MB_OK);
						return 0;
					}
				}
				fclose(fp);
				return 0;}
			case 12://查询
				{
					STU *p;
					char xuehao[10];
					long j;
					GetDlgItemText(hWnd,21,xuehao,sizeof(xuehao)/sizeof(char));
					j=atol(xuehao);//字符串转化成长整型数
					if(j==0)
					{
						MessageBox(NULL,TEXT("请输入要查询的学号"),TEXT("提示！"),MB_OK);
						return 0;
					}
					p=head.next;//p指向头结点
					while(p!=NULL)   //查找所在结点
					{
						if(strcmp(p->xuehao,xuehao)==0)//比较
							break; //已经找到 跳出循环
						p=p->next;   //p指向下一个结点
					}
					if(p==NULL)  
					{ 
						MessageBox(NULL,TEXT("不存在该学号"),TEXT("提示"),MB_OK);
						SetDlgItemText(hWnd,22,NULL);
						return 0;
					}
					SetDlgItemText(hWnd,21,p->xuehao);//设置文本
					SetDlgItemText(hWnd,22,p->name);
					SetDlgItemText(hWnd,23,p->xinbie);
					SetDlgItemText(hWnd,24,p->banji);
					SetDlgItemText(hWnd,25,p->shijian);
					SetDlgItemText(hWnd,26,p->xueyuan);
					return 0;
				}
			case 11://添加
				{ 
					int year,month,day;
					STU *p,*tail,*pre;
					pre=&head;
					p=(STU *)malloc(sizeof(STU));
					GetDlgItemText(hWnd,21,p->xuehao,sizeof(p->xuehao)/sizeof(char));
					GetDlgItemText(hWnd,22,p->name,sizeof(p->name)/sizeof(char));
					GetDlgItemText(hWnd,23,p->xinbie,sizeof(p->xinbie)/sizeof(char));
					GetDlgItemText(hWnd,24,p->banji,sizeof(p->banji)/sizeof(char));
					GetDlgItemText(hWnd,25,p->shijian,sizeof(p->shijian)/sizeof(char));
					GetDlgItemText(hWnd,26,p->xueyuan,sizeof(p->xueyuan)/sizeof(char));
					//学号重复判断
					while(pre!=NULL)//查找所在结点
					{
						if(strcmp(pre->xuehao,p->xuehao)==0)break;//比较
						pre=pre->next;   //p指向下一个结点
					}
					if(pre)
					{
						MessageBox(NULL,TEXT("学号重复"),TEXT("提示"),MB_OK);
						return 0;
					}
					//性别判断
					if(strcmp(p->xinbie,"男")!=0&&strcmp(p->xinbie,"女")!=0)
					{
						MessageBox(NULL,TEXT("性别错误"),TEXT("提示"),MB_OK);
						return 0;
					}
					//日期判断
					sscanf(p->shijian,"%d.%d.%d",&year,&month,&day);//字符串输入
					if(year<2014||year>2018||month<1||month>12||day<1||day>31)
					{
						MessageBox(NULL,TEXT("日期格式错误(请用.号分开年月日)"),TEXT("提示"),MB_OK);
						return 0;
					}
					
					tail=head.next;
					while(tail->next!=NULL)    
					{
						tail=tail->next;  	
					}
					tail->next=p;
					p->next=NULL;//将p结点添加到链表的尾部
					return 0;
				}
			case 18://保存
				{
					FILE *fp;
					STU *p;
					GetDlgItemText(hWnd,27,filename,sizeof(filename)/sizeof(char));
					fp=fopen(filename,"w");//写文件
					p=head.next;/*p指向第一个结点*/
					while(p!=NULL)
					{
						fprintf(fp,"%s %s %s %s %s %s\n",p->xuehao,p->name,p->xinbie,p->banji,p->shijian,p->xueyuan);
						p=p->next;
					}
					fclose(fp);
					MessageBox(NULL,TEXT("保存成功"),TEXT("提示"),MB_OK);
					return 0;
					
				}
			case 13://删除
				{
					STU *p,*pre;		
					char xuehao[20];
					long z;
					GetDlgItemText(hWnd,21, xuehao,sizeof( xuehao)/sizeof(char));
					z=atol(xuehao);
					pre=&head;     
					p=head.next;  
					if(z==0)
					{
						MessageBox(NULL,TEXT("请输入要删除的学号"),TEXT("提示"),MB_OK);
						return 0;
					}
					while(p!=NULL)
					{
						if(strcmp(p->xuehao,xuehao)==0) break;
						pre=pre->next;  
						p=p->next;
					}
					if(p!=NULL)   
					{
						pre->next=p->next;  
						free(p);
						MessageBox(NULL,TEXT("删除成功"),TEXT("提示"),MB_OK);
						return ;
					}
					if(p==NULL)
					{
						MessageBox(NULL,TEXT("不存在该学号"),TEXT("提示"),MB_OK);
						return ;
					}
					return 0;
				}
			case 14://修改
				{
					STU *p,temp;//temp暂时存放信息
					
					char xuehao[10];
					long k;
					GetDlgItemText(hWnd,21,xuehao,sizeof(xuehao)/sizeof(char));
					k=atol(xuehao);
					p=head.next;      //p指向第一个结点
					if(k==0)
					{
						MessageBox(NULL,TEXT("请输入要修改的学号"),TEXT("提示"),MB_OK);
						return 0;
					}
					while(p!=NULL)   
					{
						if(strcmp(p->xuehao,xuehao)==0)break; 
						p=p->next;   //p指向下一个结点
					}
					if(p==NULL)  //如果没有找到
					{
						MessageBox(NULL,TEXT("不存在该学号"),TEXT("提示"),MB_OK);
						return 0;
					}
					GetDlgItemText(hWnd,21,temp.xuehao,sizeof(temp.xuehao)/sizeof(char));
					GetDlgItemText(hWnd,22,temp.name,sizeof(temp.name)/sizeof(char));
					GetDlgItemText(hWnd,23,temp.xinbie,sizeof(temp.xinbie)/sizeof(char));
					GetDlgItemText(hWnd,24,temp.banji,sizeof(temp.banji)/sizeof(char));
					GetDlgItemText(hWnd,25,temp.shijian,sizeof(temp.shijian)/sizeof(char));
					GetDlgItemText(hWnd,26,temp.xueyuan,sizeof(temp.xueyuan)/sizeof(char));
					strcpy(p->xuehao,temp.xuehao);//覆盖
					strcpy(p->name,temp.name);
					strcpy(p->xinbie,temp.xinbie);
					strcpy(p->banji,temp.banji);
					strcpy(p->shijian,temp.shijian);
					strcpy(p->xueyuan,temp.xueyuan);
					MessageBox(NULL,TEXT("修改成功"),TEXT("提示"),MB_OK);
					return 0;
				}
			case 15://查询全班
				{
					long b;
					STU *p;
					char banji[10];
					GetDlgItemText(hWnd,24,banji,sizeof(banji)/sizeof(char));
					p=head.next; 
					b=atol(banji);
					if(b==0)
					{
						MessageBox(NULL,TEXT("请输入班号"),TEXT("提示"),MB_OK);
						return 0;
					}
					while(p!=NULL)   
					{
						if(strcmp(p->banji,banji)==0) //比较
						{
							sprintf(str1,"学号：%s 姓名：%s 性别：%s 班级：%s 入学时间：%s 院系：%s\r\n",p->xuehao,p->name,p->xinbie,p->banji,p->shijian,p->xueyuan);
							strcat(str2,str1);//连接字符串
						}
						p=p->next;   /*p指向下一个结点*/
					}
					SetDlgItemText(hWnd,29,str2);
					sprintf(str2,"");
					return 0;
			case 19://统计
				{
					char xinbie[10];
					char banji[10];
					int count1=0,count2=0;
					STU *p;
					GetDlgItemText(hWnd,24,banji,sizeof(banji)/sizeof(char));
					GetDlgItemText(hWnd,23,xinbie,sizeof(banji)/sizeof(char));
					p=head.next;
					while(p!=NULL)
					{
						if(strcmp(p->banji,banji)==0)
						{
							if(strcmp(p->xinbie,"男")==0)
								count1++;
							else if(strcmp(p->xinbie,"女")==0)
								count2++;
						}
						p=p->next;
					}
					if(count1==0&&count2==0)
					{
						MessageBox(NULL,TEXT("检查是否输入班级或者不存在此班级"),TEXT("提示"),MB_OK);
						return 0;
					}
					ltoa(count1,str1,10);
					ltoa(count2,str2,10);
					sprintf(str3,"男生人数：%s  女生人数：%s",str1,str2);
					SetDlgItemText(hWnd,29,str3);
					return 0;
				}
			case 16:
				{
					SetDlgItemText(hWnd,21,"");//设置文本
					SetDlgItemText(hWnd,22,"");
					SetDlgItemText(hWnd,23,"");
					SetDlgItemText(hWnd,24,"");
					SetDlgItemText(hWnd,25,"");
					SetDlgItemText(hWnd,26,"");
					SetDlgItemText(hWnd,29,"");
				}
			}
}
return 0;
	  }
    case WM_DESTROY://如果是点击关闭窗口时的消息
        PostQuitMessage(0);//退出消息队列
        return 0;//返回0，结束函数
    }
	//如果是其余的消息，调用默认消息处理函数，将消息该函数处理并将返回值返回
    return DefWindowProc(hWnd,Msg,wParam,lParam);
}
