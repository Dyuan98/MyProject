//�����������Ĺ���չʾ
#include<windows.h>
#include<stdio.h>
#include<iomanip.h>
#include<sstream>							//�ṩstringstream�Ĺ���
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
haveason,havetwosons,range_error,quit
};					//���巵����Ϣ�嵥
#define Maxsize 100									//����ĳ���
#define len sizeof(threadnode)                      //�궨�忪�ٿռ䳤��
char defaultbtree[]="ab#d##ce#f###";				//Ĭ���ȸ���������������
bool startbuild;									//����Ƿ����½���������Ϊ0ʱ���½���Ϊ1���Ѿ�����
bool threaded;                                      //����Ƿ��Ѿ�����������ֹ�ظ�������
struct threadnode//������ṹ��
{
    char data;
    int ltag,rtag;
    threadnode *lchild, *rchild;
    
};
char btreedata[Maxsize];						//�洢�ȸ�������Լ�����ַ�����ʽ���ڹ���������
char answer;
stringstream buff;								//���������ַ���
threadnode *root;//��
void showmenu(void);//��ʾ�˵�
void processmenu(void);//ִ�й���
void creatbtree(threadnode *&nodenow);			//�ݹ齨��������	
void buildinorderthread(threadnode *current,threadnode *&pre);//�����и�����
threadnode *parent(threadnode *nodenow);		//���Ҹ��׽��
returninfo inputbtree(int choice);				//�������ݣ����� 1��Ĭ�� 2����������
void showbtreedata();							//������������ʾ��ǰ��������
threadnode *first(threadnode *current);			//���и������µĵ�һ��
threadnode *last(threadnode  *current);			//���и������µ����һ��
threadnode *prior(threadnode *current);			//���и������µ���һ��
threadnode *next(threadnode  *current);			//���и������µ���һ��
returninfo  buildinorderthread();				//�����и����������������
void preorder(void (*visit)(threadnode *searchp));  //�����������µ��ȸ�����
void inorder (void  (*visit)(threadnode *searchp)); //�����������µ��и�����
void postorder(void (*visit)(threadnode *searchp)); //�����������µĺ������

returninfo inputbtree(int choice)  //������ַ����������Ӵ洢������
{
	if(startbuild==0)
        startbuild=1;
    else
    {
		printf("��ȫ��ʾ�� ԭ�������Ѿ��������������Ὣ��������ȫ���ƻ�!\n");
        printf("��ȷ�ϼ������д˲���  (Y|N):");
		fflush(stdin);
		scanf("%c",&answer);
        if(answer=='Y'||answer=='y')
        {
            //�˴�Ӧ�ð�ԭ�����������н��ռ��ͷſռ䣬�˴�û�д���
            startbuild=1;
        }
        else
        {
            return fail;
        }
    }
    if(startbuild==1)
    {
		threaded = true;
        if(choice==1)
        {
            strcpy(btreedata,defaultbtree);
        }
        else
        {
            printf("�����ü����������������������ַ�����ʽ (ע����Ӣ�����뷨)��\n");
            printf("������abc##de#g##f###\n");
            printf("������Ϸ��Ķ���������������ַ�����ʽ��\n");
			scanf("%s",btreedata);//�����ַ�����
        }
    }
    buff << btreedata;					//����ַ�����
    creatbtree(root);					//����������
	return success;
}
//��ʾ�ַ�����
void showbtreedata()
{
	printf("%s\n",btreedata);
}
//������*currentΪ�����и��������������и������µĵ�һ�����
threadnode *first(threadnode  *current)
{
    threadnode *searchp = current;
    while(searchp->ltag == 0)
        searchp = searchp->lchild;  //�����½�㣨��һ����Ҷ��㣩
    return searchp;
}
//������*currentΪ�����и��������������и������µ����һ�����
threadnode *last(threadnode *current)
{
    threadnode *searchp = current;
    while(searchp->rtag == 0)
        searchp = searchp->rchild;  //�����½�㣨��һ����Ҷ��㣩
    return searchp;
}
//�������и������������н��current���и��µ��������
threadnode *prior(threadnode *current)
{
    threadnode *searchp = current->lchild;
    if(current->ltag == 0)
        return last(searchp);
    else
        return searchp;
}
//�������и������������н��current���и��µĺ�̽��
threadnode *next(threadnode *current)
{
    threadnode *searchp = current->rchild;
    if(current->rtag == 0)
        return first(searchp);	//�������������и��µ�һ�����
    else
        return searchp;			// rtag=1��searchpָ����������ĺ�̽�㣬ֱ�ӷ���
}

//�����и������Զ����������и�������
returninfo buildinorderthread()
{
	
    threadnode *pre = NULL;
    if(root!=NULL)
    {
        buildinorderthread(root,pre);
        pre->rchild= NULL;
        pre->rtag = 1;
    }
    return success;
}
//���и��������������󸸽��
threadnode *parent(threadnode *nodenow)
{
    threadnode* searchp;
    if(nodenow == root) 
		return NULL;
    for(searchp = nodenow; searchp->ltag==0; searchp = searchp->lchild);
    if(searchp->lchild!=NULL)
    {
        for(searchp = searchp->lchild; searchp->lchild!=nodenow && searchp->rchild!=nodenow; 
		searchp=searchp->rchild);
    }
    else
    {
        for(searchp = nodenow; searchp->rtag==0; searchp=searchp->rchild);
        for(searchp=searchp->rchild; searchp->lchild!=nodenow && searchp->rchild!=nodenow; 
		searchp=searchp->lchild);
    }
    return searchp;
}
//ͨ���ȸ��ݹ����������������
void creatbtree(threadnode *&nodenow)
{
    char charnow;							//���嵱ǰ�ַ�
    if(buff>>charnow)						//���뵱ǰ�ַ�
    {
        if(charnow!='#')					//������ǿն��ӷ��ţ���ʼ�������
        {
			nodenow=(threadnode *)malloc(len);//���ٿռ�
            nodenow->data=charnow;			//�ַ�������������
			nodenow->ltag=0;
			nodenow->rtag=0;
			nodenow->lchild=NULL;
			nodenow->rchild=NULL;
            creatbtree(nodenow->lchild);	//�ݹ齨����������
            creatbtree(nodenow->rchild);	//�ݹ齨����������
        }
        else
            nodenow = NULL;
    }
}
//ͨ���и��ݹ�������Զ���������������
void buildinorderthread(threadnode *current,threadnode *&pre)
{
    if(current == NULL) return;
    buildinorderthread(current->lchild,pre);				//�ݹ����������
    if(current->lchild == NULL)								//û���������ʼ��������
    {
        current->lchild = pre;
        current->ltag = 1;
    }
    if(pre!=NULL && pre->rchild == NULL)					//û���Ҷ�����ʼ��������
    {
        pre->rchild = current;
        pre->rtag = 1;
    }
    pre = current;
    buildinorderthread(current->rchild,pre);				//�ݹ����������
}
//��ʾ��ǰ�������
void print(threadnode* nodenow)
{
	printf("%c  ",nodenow->data);
}
//���и�������������ʵ���ȸ�����
void preorder(void(*visit)(threadnode *searchp))
{
    threadnode *searchp=root;
    while(searchp!= NULL)
    {
        visit(searchp);									//���ʸ����
        if(searchp->ltag == 0)							//������Ů����Ϊ���
            searchp = searchp->lchild;
        else if(searchp->rtag == 0)						//������Ů����Ϊ���
            searchp = searchp ->rchild;
        else
        {
            while (searchp!=NULL && searchp->rtag == 1)	// �غ���������
                searchp = searchp->rchild;			// ֱ��������Ů�Ľ��
            if (searchp!=NULL)							//��ʱ����rtag=0
                searchp = searchp->rchild;			//����Ů��Ϊ���
        }
    }
}
//���и�������������ʵ���и�����
void inorder(void(*visit)(threadnode *searchp))
{
    threadnode *searchp;
    for(searchp = first(root); searchp != NULL; searchp = next(searchp))
        visit(searchp);									//����������Ϊ�и��������и������ͺܼ�
}
//���и�������������ʵ�ֺ��������
void postorder(void(*visit)(threadnode *searchp))
{
    threadnode *workingp,*searchp;						
    workingp = root;									//���ù���ָ��workingp���Ӹ���㿪ʼ
	while(workingp->ltag == 0 || workingp ->rtag ==0)	//�����Ҷ���ʱ�������ӽ�����ƶ�
    {
        if(workingp->ltag == 0) 
			workingp = workingp->lchild;
        else 
			if(workingp->rtag == 0) 
				workingp = workingp->rchild;
    }
    visit(workingp);									//���ʵ�ǰ����ָ����ָ���
	while((searchp=parent(workingp)) != NULL)			//��������ָ��searchpÿ�δӹ���ָ�븸��㿪ʼ			
    {
        if(searchp->rchild == workingp || searchp->rtag == 1)
            workingp = searchp;
        else
        {
            workingp = searchp->rchild;
            while(workingp->ltag == 0 || workingp->rtag == 0)
            {
                if(workingp->ltag ==0) workingp = workingp->lchild;
                else if(workingp->rtag ==0) workingp = workingp->rchild;
            }
        }
        visit(workingp);								//���ʵ�ǰ����ָ����ָ���
    }
}

void showmenu(void)
{
    printf("        ����������������ʾ        \n");
    printf("==================================\n");
    printf("1.��һ�����뷨��Ĭ���ȸ��ַ���    \n");
    printf("2.�ڶ������뷨�������ȸ��ַ���    \n");
    printf("3.�и����������������ֱ���        \n");
    printf("0.�˳�							 \n");
    printf("==================================\n");
}
void processmenu()
{
    char choice;				//�����û�ѡ��˵�ѡ��
    int  returnvalue;			//������Ϣ����
    printf("������ѡ�");
	fflush(stdin);//�����س�Ӱ��
	scanf("%c",&choice);
    switch(choice)
    {
    case '1'://1.����Ĭ������
        printf("================\n");
        returnvalue=inputbtree(1);
        if(returnvalue==fail)
            printf("�Ѿ�ȡ������������!\n");
        else if(returnvalue==success)
        {
            printf("��ǰ����������������ַ���Ϊ: \n");
            showbtreedata();
            printf("�����������ɹ�!\n");
        }
        printf("================\n");
        break;
    case '2'://2.���ü�������
        printf("================\n");
        returnvalue=inputbtree(2);
        if(returnvalue==fail)
            printf("�Ѿ�ȡ������������!\n");
        else if(returnvalue==success)
        {
            printf("��ǰ����������������ַ���Ϊ: \n");
            showbtreedata();
            printf("�����������ɹ�!\n");
        }
        printf("================\n");
        break;
	case '3'://3.���и��������������ϱ���
		if(!threaded)
		{
			printf("��ǰ���������������������ظ�������!\n");
			break;
		}
        printf("================\n");
		printf("��ǰ����������������ַ���Ϊ: \n");
		showbtreedata();
        printf("================\n");
		printf("��ʼ����������\n");
        returnvalue=buildinorderthread();
        
		if(returnvalue==fail)
            printf("�и�������ʧ��!\n");
        else if(returnvalue==success)
		{	
			threaded=false;
            printf("�и��������ɹ�!\n");
			printf("================\n");
			printf("�ȸ����������");
			preorder(print);
			printf("\n");
			printf("�и����������");
			inorder(print);
			printf("\n");
			printf("������������");
			postorder(print);
			printf("\n");
			
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
    system("color f0");
	SetConsoleTitle("����������������ʾ��C�棩");
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

