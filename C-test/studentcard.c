#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);//��������
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
    char *cName = "myWindow";//������ַ�ָ���ʾ�����������
    WNDCLASS wc;//�������
    HWND hWnd;
    MSG Msg;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ô��ڱ���Ϊ��ɫ
    wc.hCursor = NULL;//���ڵĹ�겻����
    wc.hIcon = NULL;//����ͼ������
    wc.hInstance = hInstance;//��ǰ����ľ����hInstance��������������
    wc.lpfnWndProc = WinProc;//���ڴ�����̵Ĵ��ں�����
    wc.lpszClassName =(LPSTR)cName;//����������֡�
    wc.lpszMenuName = NULL;//Ŀ¼����������
    wc.style = CS_HREDRAW | CS_VREDRAW; //������ķ��
    RegisterClass(&wc);//��ϵͳ��ע�ᴰ��
    hWnd = CreateWindow(cName, TEXT("ѧ��֤����ϵͳ"),WS_OVERLAPPEDWINDOW, 10, 30, 800, 600, NULL,            NULL, hInstance, NULL) ;
	ShowWindow(hWnd,nShowCmd);//��ʾ����
	UpdateWindow(hWnd);//���´���
	while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);//������Ϣ
        DispatchMessage(&Msg);//������Ϣ
    }
    return Msg.message;//��������󷵻���Ϣ
}
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{//������Ϣ����
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
	switch(Msg)//����Ϣ�����ж�
    {
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&paint);//��ȡ�豸������
		
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
		
		
		//�ڴ���������ı�
		DrawText(hDC,"���ѧ��֤��Ϣ:",-1, &rect1,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"��ѯѧ��֤��Ϣ:",-1,&rect2,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"ɾ��ѧ��֤��Ϣ:",-1,&rect3,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�޸�ѧ��֤��Ϣ:",-1,&rect4,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�༶ѧ��֤��Ϣ:",-1,&rect5,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"ѧ��:",-1,&rect6,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"����:",-1,&rect7,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�Ա�:",-1,&rect8,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�༶:",-1,&rect9,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"��ѧʱ��:",-1,&rect10,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"����Ժϵ:",-1,&rect11,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�ļ�:",-1,&rect12,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"���152��˧201500781",-1,&rect14,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hWnd,&paint);
		return 0;
	case WM_CREATE:
		//������ť���ı���
		hwndInput1=CreateWindow(TEXT("BUTTON"),TEXT("���"),WS_CHILD|WS_VISIBLE,270,40,40,30,
			hWnd,(HMENU)11,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput2=CreateWindow(TEXT("BUTTON"),TEXT("��ѯ"),WS_CHILD|WS_VISIBLE,270,80,40,30,
			hWnd,(HMENU)12,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput3=CreateWindow(TEXT("BUTTON"),TEXT("ɾ��"),WS_CHILD|WS_VISIBLE,270,120,40,30,
			hWnd,(HMENU)13,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput4=CreateWindow(TEXT("BUTTON"),TEXT("�޸�"),WS_CHILD|WS_VISIBLE,270,160,40,30,
			hWnd,(HMENU)14,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput5=CreateWindow(TEXT("BUTTON"),TEXT("��ѯ"),WS_CHILD|WS_VISIBLE,270,200,40,30,
			hWnd,(HMENU)15,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput7=CreateWindow(TEXT("BUTTON"),TEXT("����"),WS_CHILD|WS_VISIBLE,70,260,40,30,
			hWnd,(HMENU)17,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput8=CreateWindow(TEXT("BUTTON"),TEXT("����"),WS_CHILD|WS_VISIBLE,150,260,40,30,
			hWnd,(HMENU)18,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput6=CreateWindow(TEXT("BUTTON"),TEXT("��ʼ��"),WS_CHILD|WS_VISIBLE,230,260,50,30,
			hWnd,(HMENU)16,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
		hwndInput1=CreateWindow(TEXT("BUTTON"),TEXT("ͳ��"),WS_CHILD|WS_VISIBLE,310,260,40,30,
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
		
	case WM_COMMAND://��Ӧ����
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
						MessageBox(NULL,TEXT("����ɹ�"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
				}
				fclose(fp);
				return 0;}
			case 12://��ѯ
				{
					STU *p;
					char xuehao[10];
					long j;
					GetDlgItemText(hWnd,21,xuehao,sizeof(xuehao)/sizeof(char));
					j=atol(xuehao);//�ַ���ת���ɳ�������
					if(j==0)
					{
						MessageBox(NULL,TEXT("������Ҫ��ѯ��ѧ��"),TEXT("��ʾ��"),MB_OK);
						return 0;
					}
					p=head.next;//pָ��ͷ���
					while(p!=NULL)   //�������ڽ��
					{
						if(strcmp(p->xuehao,xuehao)==0)//�Ƚ�
							break; //�Ѿ��ҵ� ����ѭ��
						p=p->next;   //pָ����һ�����
					}
					if(p==NULL)  
					{ 
						MessageBox(NULL,TEXT("�����ڸ�ѧ��"),TEXT("��ʾ"),MB_OK);
						SetDlgItemText(hWnd,22,NULL);
						return 0;
					}
					SetDlgItemText(hWnd,21,p->xuehao);//�����ı�
					SetDlgItemText(hWnd,22,p->name);
					SetDlgItemText(hWnd,23,p->xinbie);
					SetDlgItemText(hWnd,24,p->banji);
					SetDlgItemText(hWnd,25,p->shijian);
					SetDlgItemText(hWnd,26,p->xueyuan);
					return 0;
				}
			case 11://���
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
					//ѧ���ظ��ж�
					while(pre!=NULL)//�������ڽ��
					{
						if(strcmp(pre->xuehao,p->xuehao)==0)break;//�Ƚ�
						pre=pre->next;   //pָ����һ�����
					}
					if(pre)
					{
						MessageBox(NULL,TEXT("ѧ���ظ�"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					//�Ա��ж�
					if(strcmp(p->xinbie,"��")!=0&&strcmp(p->xinbie,"Ů")!=0)
					{
						MessageBox(NULL,TEXT("�Ա����"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					//�����ж�
					sscanf(p->shijian,"%d.%d.%d",&year,&month,&day);//�ַ�������
					if(year<2014||year>2018||month<1||month>12||day<1||day>31)
					{
						MessageBox(NULL,TEXT("���ڸ�ʽ����(����.�ŷֿ�������)"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					
					tail=head.next;
					while(tail->next!=NULL)    
					{
						tail=tail->next;  	
					}
					tail->next=p;
					p->next=NULL;//��p�����ӵ������β��
					return 0;
				}
			case 18://����
				{
					FILE *fp;
					STU *p;
					GetDlgItemText(hWnd,27,filename,sizeof(filename)/sizeof(char));
					fp=fopen(filename,"w");//д�ļ�
					p=head.next;/*pָ���һ�����*/
					while(p!=NULL)
					{
						fprintf(fp,"%s %s %s %s %s %s\n",p->xuehao,p->name,p->xinbie,p->banji,p->shijian,p->xueyuan);
						p=p->next;
					}
					fclose(fp);
					MessageBox(NULL,TEXT("����ɹ�"),TEXT("��ʾ"),MB_OK);
					return 0;
					
				}
			case 13://ɾ��
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
						MessageBox(NULL,TEXT("������Ҫɾ����ѧ��"),TEXT("��ʾ"),MB_OK);
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
						MessageBox(NULL,TEXT("ɾ���ɹ�"),TEXT("��ʾ"),MB_OK);
						return ;
					}
					if(p==NULL)
					{
						MessageBox(NULL,TEXT("�����ڸ�ѧ��"),TEXT("��ʾ"),MB_OK);
						return ;
					}
					return 0;
				}
			case 14://�޸�
				{
					STU *p,temp;//temp��ʱ�����Ϣ
					
					char xuehao[10];
					long k;
					GetDlgItemText(hWnd,21,xuehao,sizeof(xuehao)/sizeof(char));
					k=atol(xuehao);
					p=head.next;      //pָ���һ�����
					if(k==0)
					{
						MessageBox(NULL,TEXT("������Ҫ�޸ĵ�ѧ��"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					while(p!=NULL)   
					{
						if(strcmp(p->xuehao,xuehao)==0)break; 
						p=p->next;   //pָ����һ�����
					}
					if(p==NULL)  //���û���ҵ�
					{
						MessageBox(NULL,TEXT("�����ڸ�ѧ��"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					GetDlgItemText(hWnd,21,temp.xuehao,sizeof(temp.xuehao)/sizeof(char));
					GetDlgItemText(hWnd,22,temp.name,sizeof(temp.name)/sizeof(char));
					GetDlgItemText(hWnd,23,temp.xinbie,sizeof(temp.xinbie)/sizeof(char));
					GetDlgItemText(hWnd,24,temp.banji,sizeof(temp.banji)/sizeof(char));
					GetDlgItemText(hWnd,25,temp.shijian,sizeof(temp.shijian)/sizeof(char));
					GetDlgItemText(hWnd,26,temp.xueyuan,sizeof(temp.xueyuan)/sizeof(char));
					strcpy(p->xuehao,temp.xuehao);//����
					strcpy(p->name,temp.name);
					strcpy(p->xinbie,temp.xinbie);
					strcpy(p->banji,temp.banji);
					strcpy(p->shijian,temp.shijian);
					strcpy(p->xueyuan,temp.xueyuan);
					MessageBox(NULL,TEXT("�޸ĳɹ�"),TEXT("��ʾ"),MB_OK);
					return 0;
				}
			case 15://��ѯȫ��
				{
					long b;
					STU *p;
					char banji[10];
					GetDlgItemText(hWnd,24,banji,sizeof(banji)/sizeof(char));
					p=head.next; 
					b=atol(banji);
					if(b==0)
					{
						MessageBox(NULL,TEXT("��������"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					while(p!=NULL)   
					{
						if(strcmp(p->banji,banji)==0) //�Ƚ�
						{
							sprintf(str1,"ѧ�ţ�%s ������%s �Ա�%s �༶��%s ��ѧʱ�䣺%s Ժϵ��%s\r\n",p->xuehao,p->name,p->xinbie,p->banji,p->shijian,p->xueyuan);
							strcat(str2,str1);//�����ַ���
						}
						p=p->next;   /*pָ����һ�����*/
					}
					SetDlgItemText(hWnd,29,str2);
					sprintf(str2,"");
					return 0;
			case 19://ͳ��
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
							if(strcmp(p->xinbie,"��")==0)
								count1++;
							else if(strcmp(p->xinbie,"Ů")==0)
								count2++;
						}
						p=p->next;
					}
					if(count1==0&&count2==0)
					{
						MessageBox(NULL,TEXT("����Ƿ�����༶���߲����ڴ˰༶"),TEXT("��ʾ"),MB_OK);
						return 0;
					}
					ltoa(count1,str1,10);
					ltoa(count2,str2,10);
					sprintf(str3,"����������%s  Ů��������%s",str1,str2);
					SetDlgItemText(hWnd,29,str3);
					return 0;
				}
			case 16:
				{
					SetDlgItemText(hWnd,21,"");//�����ı�
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
    case WM_DESTROY://����ǵ���رմ���ʱ����Ϣ
        PostQuitMessage(0);//�˳���Ϣ����
        return 0;//����0����������
    }
	//������������Ϣ������Ĭ����Ϣ������������Ϣ�ú�������������ֵ����
    return DefWindowProc(hWnd,Msg,wParam,lParam);
}
