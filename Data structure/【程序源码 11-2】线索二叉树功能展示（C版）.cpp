//线索二叉树的功能展示
#include<windows.h>
#include<stdio.h>
#include<iomanip.h>
#include<sstream>							//提供stringstream的功能
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
haveason,havetwosons,range_error,quit
};					//定义返回信息清单
#define Maxsize 100									//定义的长度
#define len sizeof(threadnode)                      //宏定义开辟空间长度
char defaultbtree[]="ab#d##ce#f###";				//默认先根遍历的输入数据
bool startbuild;									//标记是否是新建二叉树，为0时是新建，为1则已经建立
bool threaded;                                      //标记是否已经线索化，防止重复线索化
struct threadnode//定义结点结构体
{
    char data;
    int ltag,rtag;
    threadnode *lchild, *rchild;
    
};
char btreedata[Maxsize];						//存储先根遍历下约定的字符串形式用于构建二叉树
char answer;
stringstream buff;								//用于输入字符串
threadnode *root;//根
void showmenu(void);//显示菜单
void processmenu(void);//执行功能
void creatbtree(threadnode *&nodenow);			//递归建立二叉树	
void buildinorderthread(threadnode *current,threadnode *&pre);//建立中根线索
threadnode *parent(threadnode *nodenow);		//查找父亲结点
returninfo inputbtree(int choice);				//输入数据：两种 1：默认 2：键盘输入
void showbtreedata();							//在主界面中显示当前工作数组
threadnode *first(threadnode *current);			//找中根序列下的第一个
threadnode *last(threadnode  *current);			//找中根序列下的最后一个
threadnode *prior(threadnode *current);			//找中根序列下的上一个
threadnode *next(threadnode  *current);			//找中根序列下的下一个
returninfo  buildinorderthread();				//构建中根线索二叉树的入口
void preorder(void (*visit)(threadnode *searchp));  //线索二叉树下的先根遍历
void inorder (void  (*visit)(threadnode *searchp)); //线索二叉树下的中根遍历
void postorder(void (*visit)(threadnode *searchp)); //线索二叉树下的后根遍历

returninfo inputbtree(int choice)  //广义表字符串生成链接存储二叉树
{
	if(startbuild==0)
        startbuild=1;
    else
    {
		printf("安全提示： 原二叉树已经建立，操作将会将其中数据全部破坏!\n");
        printf("您确认继续进行此操作  (Y|N):");
		fflush(stdin);
		scanf("%c",&answer);
        if(answer=='Y'||answer=='y')
        {
            //此处应该把原二叉树的所有结点空间释放空间，此处没有处理
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
            printf("下面用键盘输入二叉树先序遍历的字符串形式 (注意用英文输入法)：\n");
            printf("范例：abc##de#g##f###\n");
            printf("请输入合法的二叉树先序遍历的字符串形式：\n");
			scanf("%s",btreedata);//输入字符数组
        }
    }
    buff << btreedata;					//输出字符数组
    creatbtree(root);					//构建二叉树
	return success;
}
//显示字符数组
void showbtreedata()
{
	printf("%s\n",btreedata);
}
//返回以*current为根的中根线索二叉树中中根序列下的第一个结点
threadnode *first(threadnode  *current)
{
    threadnode *searchp = current;
    while(searchp->ltag == 0)
        searchp = searchp->lchild;  //最左下结点（不一定是叶结点）
    return searchp;
}
//返回以*current为根的中根线索二叉树中中根序列下的最后一个结点
threadnode *last(threadnode *current)
{
    threadnode *searchp = current;
    while(searchp->rtag == 0)
        searchp = searchp->rchild;  //最右下结点（不一定是叶结点）
    return searchp;
}
//返回在中根线索二叉树中结点current在中根下的先驱结点
threadnode *prior(threadnode *current)
{
    threadnode *searchp = current->lchild;
    if(current->ltag == 0)
        return last(searchp);
    else
        return searchp;
}
//返回在中根线索二叉树中结点current在中根下的后继结点
threadnode *next(threadnode *current)
{
    threadnode *searchp = current->rchild;
    if(current->rtag == 0)
        return first(searchp);	//在右子树中找中根下第一个结点
    else
        return searchp;			// rtag=1，searchp指向结点就是它的后继结点，直接返回
}

//利用中根遍历对二叉树进行中根线索化
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
//在中根线索二叉树中求父结点
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
//通过先根递归遍历，建立二叉树
void creatbtree(threadnode *&nodenow)
{
    char charnow;							//定义当前字符
    if(buff>>charnow)						//输入当前字符
    {
        if(charnow!='#')					//如果不是空儿子符号，则开始建立结点
        {
			nodenow=(threadnode *)malloc(len);//开辟空间
            nodenow->data=charnow;			//字符存入结点数据域
			nodenow->ltag=0;
			nodenow->rtag=0;
			nodenow->lchild=NULL;
			nodenow->rchild=NULL;
            creatbtree(nodenow->lchild);	//递归建立其左子树
            creatbtree(nodenow->rchild);	//递归建立其右子树
        }
        else
            nodenow = NULL;
    }
}
//通过中根递归遍历，对二叉树进行线索化
void buildinorderthread(threadnode *current,threadnode *&pre)
{
    if(current == NULL) return;
    buildinorderthread(current->lchild,pre);				//递归访问左子树
    if(current->lchild == NULL)								//没有左儿子则开始做左线索
    {
        current->lchild = pre;
        current->ltag = 1;
    }
    if(pre!=NULL && pre->rchild == NULL)					//没有右儿子则开始做右线索
    {
        pre->rchild = current;
        pre->rtag = 1;
    }
    pre = current;
    buildinorderthread(current->rchild,pre);				//递归访问右子树
}
//显示当前结点数据
void print(threadnode* nodenow)
{
	printf("%c  ",nodenow->data);
}
//在中根线索二叉树上实现先根遍历
void preorder(void(*visit)(threadnode *searchp))
{
    threadnode *searchp=root;
    while(searchp!= NULL)
    {
        visit(searchp);									//访问根结点
        if(searchp->ltag == 0)							//有左子女，即为后继
            searchp = searchp->lchild;
        else if(searchp->rtag == 0)						//有右子女，即为后继
            searchp = searchp ->rchild;
        else
        {
            while (searchp!=NULL && searchp->rtag == 1)	// 沿后继线索检测
                searchp = searchp->rchild;			// 直到有右子女的结点
            if (searchp!=NULL)							//此时必有rtag=0
                searchp = searchp->rchild;			//右子女即为后继
        }
    }
}
//在中根线索二叉树上实现中根遍历
void inorder(void(*visit)(threadnode *searchp))
{
    threadnode *searchp;
    for(searchp = first(root); searchp != NULL; searchp = next(searchp))
        visit(searchp);									//由于线索树为中根，所以中根遍历就很简单
}
//在中根线索二叉树上实现后根遍历法
void postorder(void(*visit)(threadnode *searchp))
{
    threadnode *workingp,*searchp;						
    workingp = root;									//启用工作指针workingp，从根结点开始
	while(workingp->ltag == 0 || workingp ->rtag ==0)	//有左右儿子时，往儿子结点上移动
    {
        if(workingp->ltag == 0) 
			workingp = workingp->lchild;
        else 
			if(workingp->rtag == 0) 
				workingp = workingp->rchild;
    }
    visit(workingp);									//访问当前工作指针所指结点
	while((searchp=parent(workingp)) != NULL)			//启用搜索指针searchp每次从工作指针父结点开始			
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
        visit(workingp);								//访问当前工作指针所指结点
    }
}

void showmenu(void)
{
    printf("        线索二叉树功能演示        \n");
    printf("==================================\n");
    printf("1.第一种输入法：默认先根字符串    \n");
    printf("2.第二种输入法：输入先根字符串    \n");
    printf("3.中根线索化并且做三种遍历        \n");
    printf("0.退出							 \n");
    printf("==================================\n");
}
void processmenu()
{
    char choice;				//用于用户选择菜单选项
    int  returnvalue;			//返回信息代码
    printf("请输入选项：");
	fflush(stdin);//消除回车影响
	scanf("%c",&choice);
    switch(choice)
    {
    case '1'://1.启用默认数据
        printf("================\n");
        returnvalue=inputbtree(1);
        if(returnvalue==fail)
            printf("已经取消建立二叉树!\n");
        else if(returnvalue==success)
        {
            printf("当前二叉树的先序遍历字符串为: \n");
            showbtreedata();
            printf("二叉树建立成功!\n");
        }
        printf("================\n");
        break;
    case '2'://2.启用键盘输入
        printf("================\n");
        returnvalue=inputbtree(2);
        if(returnvalue==fail)
            printf("已经取消建立二叉树!\n");
        else if(returnvalue==success)
        {
            printf("当前二叉树的先序遍历字符串为: \n");
            showbtreedata();
            printf("二叉树建立成功!\n");
        }
        printf("================\n");
        break;
	case '3'://3.在中根线索化二叉树上遍历
		if(!threaded)
		{
			printf("当前二叉树已线索化，请勿重复线索化!\n");
			break;
		}
        printf("================\n");
		printf("当前二叉树的先序遍历字符串为: \n");
		showbtreedata();
        printf("================\n");
		printf("开始线索化……\n");
        returnvalue=buildinorderthread();
        
		if(returnvalue==fail)
            printf("中根线索化失败!\n");
        else if(returnvalue==success)
		{	
			threaded=false;
            printf("中根线索化成功!\n");
			printf("================\n");
			printf("先根遍历结果：");
			preorder(print);
			printf("\n");
			printf("中根遍历结果：");
			inorder(print);
			printf("\n");
			printf("后根遍历结果：");
			postorder(print);
			printf("\n");
			
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
    system("color f0");
	SetConsoleTitle("线索二叉树功能演示（C版）");
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

