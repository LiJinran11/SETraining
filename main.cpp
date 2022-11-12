#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <iomanip>
using namespace std;
struct StuInfo
{
	char name[15]; //姓名          lzh
	char sno[5];  //学号           1001
	char contact[12]; //联系方式   18888888888
	char rnum[10]; //寝室号        room_1
	char date[10];  //返校日期     8.28
	char wayside[50]; //途径地     baoding
	char YNvacc; //是否打疫苗    y
	int temp1;   //体温            36
	int temp2;   //体温            36                
	int temp3;//三日体温           36
};
struct StuNode
{
	StuInfo student;
	StuNode* next;
};
typedef StuNode* StuLinkList;
void DestroyList(StuLinkList* L);
void travel(StuLinkList head);
void input(StuInfo* ep);
void output(StuInfo* ep);
void header();
void ReadFile(StuLinkList* head);
void InputData(int n);
void FMData(StuLinkList* head);
void ScreenRisk(StuLinkList* head);
//销毁链表
void DestroyList(StuLinkList* L)
{
	StuLinkList q, p = *L;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	*L = NULL;
}
//遍历链表(shuchu)
void travel(StuLinkList head)
{
	StuLinkList p = head->next;
	while (p)
	{
		output(&(*p).student);
		p = p->next;
	}
}
//输入信息
void input(StuInfo* ep)
{
	cout << "请输入姓名:";
	cin >> ep->name;
	cout << endl << "请输入学号:";
	cin >> ep->sno;
	cout << endl << "请输入如联系方式:";
	cin >> ep->contact;
	cout << endl << "请输入寝室号:";
	cin >> ep->rnum;
	cout << endl << "请输入入校日期:";
	cin >> ep->date;
	cout << endl << "请输入14日途径地:";
	cin >> ep->wayside;
	cout << endl << "疫苗接种情况:";
	cin >> ep->YNvacc;
	cout << endl << "三日内体温,第一天:";
	cin >> ep->temp1;
	cout << endl << "三日内体温,第二天:";
	cin >> ep->temp2;
	cout << endl << "三日内体温,第三天:";
	cin >> ep->temp3;
	cout << endl;
}
//输出信息
void output(StuInfo* ep)
{
	printf("%-7s%-7s%-14s%-10s%-10s%-12s%-7c%-8d%-8d%-5d\n", ep->name,
		ep->sno,
		ep->contact,
		ep->rnum,
		ep->date,
		ep->wayside,
		ep->YNvacc,
		ep->temp1,
		ep->temp2,
		ep->temp3);
}
//表头
void header()
{
	printf("姓名   学号    联系方式     寝室号   返校日期   途径地     疫苗   体温1   体温2   体温3\n");
	cout << "----------------------------------------------------------------------------------------" << endl;
}
//文件读入功能
void ReadFile(StuLinkList* head)
{
	FILE* fp1;
	FILE* fp2;
	StuLinkList tail, s;

	//打开文件jichu1.dat和student.dat
	if ((fp1 = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\jichu.dat", "rb")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}
	if ((fp2 = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "wb")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}

	//读取jichu.dat并写入文件student.dat
	tail = (*head) = new StuNode;
	for (int i = 0; i < 2; i++)
	{
		s = new StuNode;
		fread(&s->student, sizeof(StuInfo), 1, fp1);
		tail->next = s;
		tail = s;
		fwrite(&s->student, sizeof(StuInfo), 1, fp2);
	}
	tail->next = NULL;

	fclose(fp1);
	fclose(fp2);
	cout << "数据初始化成功！请您继续!" << endl;

	//++++销毁链表
	DestroyList(head);
}
//数据输入存储功能
void InputData(int n)
{
	FILE* fp;
	int i = 1;
	StuInfo stu;

	//打开student.dat
	if ((fp = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "ab")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}

	//输入学生信息并直接存入到文件中
	for (; n > 0; n--, i++)
	{
		cout << "请输入第" << i << "位同学的信息：" << endl << endl;
		input(&stu);
		if (fwrite(&stu, sizeof(StuInfo), 1, fp) != 1)
		{
			printf("file write error");
		}
	}
	fclose(fp);
	cout << "录入信息完成！";
}
//查找,修改数据功能
void FMData(StuLinkList* head)
{
	StuLinkList tail, s;
	int count = 0; //用来辅助判断

	//打开文件student.dat
	FILE* fp;
	if ((fp = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "rb")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}

	//查找内容以及输出格式
	char a[15];
	cout << "请输入您想要查找的学号或者名字:";
	cin >> a;
	header();

	//从student.dat生成链表
	tail = (*head) = new StuNode;
	while (!feof(fp))
	{
		s = new StuNode;
		fread(&s->student, sizeof(StuInfo), 1, fp);
		tail->next = s;
		tail = s;
	}
	tail->next = NULL;
	fclose(fp);

	//遍历链表并查找和输出信息
	tail = (*head);  //自由指针指向头结点
	while (tail->next)
	{
		tail = tail->next;
		if (!strcmp(a, (*tail).student.name) || !strcmp(a, (*tail).student.sno))
		{
			output(&(*tail).student);
			count++;
			break;
		}
	}
	if ((tail->next == NULL) && (count == 0))
	{
		cout << "查无此人！";
		exit(0);
	}
	//修改数据！！
	char judge;	 //判断是不是要需要修改
	int m; 	//选择修改哪个属性
	cout << endl << "是否需要修改数据(y/n):";
	cin >> judge;
	cout << endl;

	if (judge == 'y')
	{
		cout << "选择您需要修改的属性:1.联系方式 2.寝室号 任意键退出程序" << endl << endl;
		cin >> m;
		cout << endl;

		//修改
		if (m == 1)
		{
			cout << "请输入新的联系方式:";
			cin >> (*tail).student.contact;
			cout << endl << "修改完成！";
		}
		else if (m == 2)
		{
			cout << "请输入新的寝室号方式:";
			cin >> (*tail).student.rnum;
			cout << endl << "修改完成！";
		}
		else
			exit(0);

		//修改完成后要重新写入数据
		tail = (*head);
		if ((fp = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "wb")) == NULL)
		{
			printf("faild\n");
			exit(0);
		}
		while (tail->next)
		{
			tail = tail->next;
			if (fwrite(&tail->student, sizeof(StuInfo), 1, fp) != 1)
			{
				cout << "file write error";
			}
		}
	}
	//销毁链表
	travel(*head);
	fclose(fp);
	DestroyList(head);
}
//筛选功能
void ScreenRisk(StuLinkList* head)
{
	FILE* fp1, * fp2;
	StuLinkList tail, s;
	tail = (*head) = new StuNode;
	int count = 0;
	int i = 0;
	struct {
		char name[10];
	}RiskRoom[5];  //风险寝室  
	char RiskArea[10];
	//打开文件
	if ((fp1 = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "rb")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}
	if ((fp2 = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\guanzhu.dat", "ab")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}
	// 从student.dat生成链表
	tail = (*head) = new StuNode;
	while (!feof(fp1))
	{
		s = new StuNode;
		fread(&s->student, sizeof(StuInfo), 1, fp1);
		tail->next = s;
		tail = s;
	}
	tail->next = NULL;
	//遍历链表并且根据风险地区找出风险寝室
	cout << "请输入风险地区:";
	cin >> RiskArea;
	tail = (*head);
	while (tail->next)
	{
		tail = tail->next;
		if (!strcmp(RiskArea, (*tail).student.wayside))
		{
			strcpy(RiskRoom[i].name, (*tail).student.rnum);
			count++;
			i++;
		}
	}
	//根据风险寝室找出风险人员并且写入guanzhu.dat +输出（ab方式）
	header();
	tail = (*head);
	for (i = 0; i < count; i++)
	{
		while (tail->next)
		{
			tail = tail->next;
			if (!strcmp(RiskRoom[i].name, (*tail).student.rnum))
			{
				output(&(*tail).student);
				cout << "----------------------------------------------------------------------------------------" << endl;
				fwrite(&tail->student, sizeof(StuInfo), 1, fp2);
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	DestroyList(head);
}
int main()
{
	int option; //选择功能
	int n; //插入几条
	char judge; //判断是否导入数据
	StuLinkList head; //头结点
	cout << endl << "是否需要导入默认信息(如果原来有信息会覆盖 y/n):";
	cin >> judge;
	if (judge == 'y')
	{
		ReadFile(&head);
		cout << "导入信息完成!" << endl;
	}
	do
	{
		cout << endl << "1.录入信息功能\t2.查找、修改信息功能\t3.筛选信息功能\t0.退出" << endl << endl;
		cout << "请选择你需要的功能:";
		scanf_s("%d", &option);
		printf("\n\n");
		switch (option)
		{
		case 1:
			cout << "您需要录入多少信息？" << endl;
			cin >> n;
			InputData(n);
			printf("\n\n\n");
			break;
		case 2:
			FMData(&head);
			printf("\n\n\n");
			break;
		case 3:
			ScreenRisk(&head);
			printf("\n\n\n");
			break;
		case 0:break;
		}

	} while (option);
	return 0;
}