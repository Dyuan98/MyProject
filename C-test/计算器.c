#include <windows.h>
#include<math.h>
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);//��������
HDC hDC;
PAINTSTRUCT paint;
RECT rect1;
RECT rect2;
RECT rect3;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    char *cName = "myWindow";//������ַ�ָ���ʾ�����������
    WNDCLASS wc;//�������
    HWND hWnd;
    MSG Msg;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);;//���ô��ڱ���Ϊ��ɫ
    wc.hCursor = NULL;//���ڵĹ�겻����
    wc.hIcon = NULL;//����ͼ������
    wc.hInstance = hInstance;//��ǰ����ľ����hInstance��������������
    wc.lpfnWndProc = WinProc;//���ڴ�����̵Ĵ��ں�����
    wc.lpszClassName =(LPSTR)cName;//����������֡�
    wc.lpszMenuName = NULL;//Ŀ¼����������
    wc.style = CS_HREDRAW | CS_VREDRAW; //������ķ��
    RegisterClass(&wc);//��ϵͳ��ע�ᴰ��
    hWnd = CreateWindow(cName,TEXT("������"),WS_OVERLAPPEDWINDOW,10, 20, 210, 300,             
		NULL, NULL, hInstance, NULL) ;
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
	static HWND btnHwnd ;
	static HWND inputHwnd ;
	static HWND	a ;
	static HWND b;
	static HWND c;
	static HWND d;
	static HWND e;
	static HWND f;
	static HWND g;
	static HWND h;
	static HWND i;
	static HWND j;
	static HWND k;
	static HWND l;
	static HWND m;
	static HWND n;
	static HWND o;
	static HWND p;
	static HWND Q;
	static HWND R;
	static HWND S;
	static HWND T;
	static HWND U;
	static HWND V;
	static HWND W;
	static HWND X;
	static HWND Y;
	static HWND Z;
	static HWND ZZ;
	static char str1[10],str3[10];
	static int d1,d2,s,flag;
	static int t;
	static float pf,fs,d3;
    switch(Msg)//����Ϣ�����ж�
    {
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&paint);//��ȡ�豸������
		rect1.right=50;
		rect1.top=5;
		rect1.bottom=30;
		rect1.left=0;
		
		rect2.right=180;
		rect2.top=5;
		rect2.bottom=30;
		rect2.left=0;
		
		rect3.right=310;
		rect3.top=5;
		rect3.bottom=30;
		rect3.left=0;
		
		
		DrawText(hDC,"�鿴(v)",-1, &rect1,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"�༭(E)",-1, &rect2,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		DrawText(hDC,"����(H)",-1, &rect3,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hWnd,&paint);
		
		return 0;
		
	case WM_CREATE:	//��Ӧ���ڵĴ����¼�
		//������ť
		btnHwnd = CreateWindow( TEXT("button"), TEXT("MC"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 80, 37.5, 27.5, hWnd, (HMENU)1, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		a= CreateWindow( TEXT("button"), TEXT("<-"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 110, 37.5, 27.5, hWnd, (HMENU)2, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		b = CreateWindow( TEXT("button"), TEXT("7"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 140, 37.5, 27.5, hWnd, (HMENU)3, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		c = CreateWindow( TEXT("button"), TEXT("4"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 170, 37.5, 27.5, hWnd, (HMENU)4, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		d = CreateWindow( TEXT("button"), TEXT("1"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 200, 37.5, 27.5, hWnd, (HMENU)5, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		e = CreateWindow( TEXT("button"), TEXT("0"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   0, 230, 80, 27.5, hWnd, (HMENU)6, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		f = CreateWindow( TEXT("button"), TEXT("MR"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   40, 80, 37.5, 27.5, hWnd, (HMENU)7, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		g = CreateWindow( TEXT("button"), TEXT("CE"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   40, 110, 37.5, 27.5, hWnd, (HMENU)8, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		h = CreateWindow( TEXT("button"), TEXT("8"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   40, 140, 37.5, 27.5, hWnd, (HMENU)9, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		i = CreateWindow( TEXT("button"), TEXT("5"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   40, 170, 37.5, 27.5, hWnd, (HMENU)10, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		j = CreateWindow( TEXT("button"), TEXT("2"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   40, 200, 37.5, 27.5, hWnd, (HMENU)11, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		k = CreateWindow( TEXT("button"), TEXT("MS"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 80, 37.5, 27.5, hWnd, (HMENU)12, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		l = CreateWindow( TEXT("button"), TEXT("C"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 110, 37.5, 27.5, hWnd, (HMENU)13, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		m = CreateWindow( TEXT("button"), TEXT("9"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 140, 37.5, 27.5, hWnd, (HMENU)14, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		n = CreateWindow( TEXT("button"), TEXT("6"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 170, 37.5, 27.5, hWnd, (HMENU)15, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		o = CreateWindow( TEXT("button"), TEXT("3"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 200, 37.5, 27.5, hWnd, (HMENU)16, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		p = CreateWindow( TEXT("button"), TEXT("."),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   80, 230, 37.5, 27.5, hWnd, (HMENU)17, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		Q = CreateWindow( TEXT("button"), TEXT("M+"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 80, 37.5, 27.5, hWnd, (HMENU)18, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		R = CreateWindow( TEXT("button"), TEXT("��"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 110, 37.5, 27.5, hWnd, (HMENU)19, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		S = CreateWindow( TEXT("button"), TEXT("/"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 140, 37.5, 27.5, hWnd, (HMENU)20, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		T = CreateWindow( TEXT("button"), TEXT("*"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 170, 37.5, 27.5, hWnd, (HMENU)21, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		U = CreateWindow( TEXT("button"), TEXT("-"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 200, 37.5, 27.5, hWnd, (HMENU)22, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		V = CreateWindow( TEXT("button"), TEXT("+"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   120, 230, 37.5, 27.5, hWnd, (HMENU)23, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		W = CreateWindow( TEXT("button"), TEXT("M-"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   160, 80, 37.5, 27.5, hWnd, (HMENU)24, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		X = CreateWindow( TEXT("button"), TEXT("��"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   160, 110, 37.5, 27.5, hWnd, (HMENU)25, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		Y = CreateWindow( TEXT("button"), TEXT("%"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   160, 140, 37.5, 27.5, hWnd, (HMENU)26, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		Z = CreateWindow( TEXT("button"), TEXT("1/x"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   160, 170, 37.5, 27.5, hWnd, (HMENU)27, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		ZZ = CreateWindow( TEXT("button"), TEXT("="),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   160, 200, 37.5, 60, hWnd, (HMENU)28, (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ), NULL ) ;
		//�����ı���
		inputHwnd = CreateWindow( TEXT("edit"), NULL,WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE , 5, 30, 185, 50, hWnd, (HMENU)0, ((LPCREATESTRUCT) lParam) -> hInstance,NULL ) ;
		return 0 ;
	case WM_COMMAND://��Ӧ����
		{
			switch(LOWORD(wParam))
			{
			case 23://��ID��Ϊ1�İ�ť���,"���"��ť
				{
					//��ȡ�ı���������
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d1=atoi(str1); 
					ZeroMemory(str1,sizeof(str1));
					SetDlgItemText(hWnd,0,str1);
					flag=1;
					return 0;
				}
			case 22:
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d1=atoi(str1); 
					ZeroMemory(str1,sizeof(str1));
					SetDlgItemText(hWnd,0,str1);
					flag=2;
					return 0;
				}
			case 21:
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d1=atoi(str1); 
					ZeroMemory(str1,sizeof(str1));
					SetDlgItemText(hWnd,0,str1);
					flag=3;
					return 0;
				}
			case 20:
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d1=atoi(str1); 
					ZeroMemory(str1,sizeof(str1));
					SetDlgItemText(hWnd,0,str1);
					flag=4;
					return 0;
				}
			case 28:
				{
					if(flag==1)
					{
						d2=atoi(str1);
					    s=d1+d2;
                        ltoa(s,str3,10);
                        SetDlgItemText(hWnd,0,str3); 
					}
					if(flag==2)
					{
						d2=atoi(str1);
					    s=d1-d2;
                        ltoa(s,str3,10);
                        SetDlgItemText(hWnd,0,str3); 
					}
					if(flag==3)
					{
						d2=atoi(str1);
					    s=d1*d2;
                        ltoa(s,str3,10);
                        SetDlgItemText(hWnd,0,str3); 
					}
					if(flag==4)
					{
						d2=atoi(str1);
					    s=d1/d2;
                        ltoa(s,str3,10);
                        SetDlgItemText(hWnd,0,str3); 
					}
					return 0;	
				}

			case 3:
				{  
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"7");
					SetDlgItemText(hWnd,0,str1);
					//���ı�������ʾ
					
					return 0;
				}
			case 4:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"4");
					SetDlgItemText(hWnd,0,str1);
					
					return 0;
				}
			case 5:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"1");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 6:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"0");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 9:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"8");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 10:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"5");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 11:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"2");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 14:
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"9");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 15:
				{ 
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
				    strcat(str1,"6");
				    SetDlgItemText(hWnd,0,str1);
				    return 0;
				}
			case 16:
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					strcat(str1,"3");
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 8://����
				{
					ZeroMemory(str3,sizeof(str3));
					SetDlgItemText(hWnd,0,str3);
					return 0;
				}
			case 2://ɾ��
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					t=strlen(str1);
					str1[t-1]=NULL;
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 25://ƽ����
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d3=atof(str1);
					pf=sqrt(d3);
					sprintf(str1,"%.9f",pf);
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 27://  1/X
				{
					GetDlgItemText(hWnd,0,str1,sizeof(str1)/sizeof(char));
					d3=atof(str1);
					fs=1/d3;
					sprintf(str1,"%.9f",fs);
					SetDlgItemText(hWnd,0,str1);
					return 0;
				}
			case 19:
				{
					d1=atoi(str1);
					d1=-d1;
					ltoa(d1,str1,10);
					SetDlgItemText(hWnd,0,str1);
					return 0;
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
