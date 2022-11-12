#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <iomanip>
using namespace std;
struct StuInfo
{
	char name[15]; //����          lzh
	char sno[5];  //ѧ��           1001
	char contact[12]; //��ϵ��ʽ   18888888888
	char rnum[10]; //���Һ�        room_1
	char date[10];  //��У����     8.28
	char wayside[50]; //;����     baoding
	char YNvacc; //�Ƿ������    y
	int temp1;   //����            36
	int temp2;   //����            36                
	int temp3;//��������           36
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
//��������
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
//��������(shuchu)
void travel(StuLinkList head)
{
	StuLinkList p = head->next;
	while (p)
	{
		output(&(*p).student);
		p = p->next;
	}
}
//������Ϣ
void input(StuInfo* ep)
{
	cout << "����������:";
	cin >> ep->name;
	cout << endl << "������ѧ��:";
	cin >> ep->sno;
	cout << endl << "����������ϵ��ʽ:";
	cin >> ep->contact;
	cout << endl << "���������Һ�:";
	cin >> ep->rnum;
	cout << endl << "��������У����:";
	cin >> ep->date;
	cout << endl << "������14��;����:";
	cin >> ep->wayside;
	cout << endl << "����������:";
	cin >> ep->YNvacc;
	cout << endl << "����������,��һ��:";
	cin >> ep->temp1;
	cout << endl << "����������,�ڶ���:";
	cin >> ep->temp2;
	cout << endl << "����������,������:";
	cin >> ep->temp3;
	cout << endl;
}
//�����Ϣ
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
//��ͷ
void header()
{
	printf("����   ѧ��    ��ϵ��ʽ     ���Һ�   ��У����   ;����     ����   ����1   ����2   ����3\n");
	cout << "----------------------------------------------------------------------------------------" << endl;
}
//�ļ����빦��
void ReadFile(StuLinkList* head)
{
	FILE* fp1;
	FILE* fp2;
	StuLinkList tail, s;

	//���ļ�jichu1.dat��student.dat
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

	//��ȡjichu.dat��д���ļ�student.dat
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
	cout << "���ݳ�ʼ���ɹ�����������!" << endl;

	//++++��������
	DestroyList(head);
}
//��������洢����
void InputData(int n)
{
	FILE* fp;
	int i = 1;
	StuInfo stu;

	//��student.dat
	if ((fp = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "ab")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}

	//����ѧ����Ϣ��ֱ�Ӵ��뵽�ļ���
	for (; n > 0; n--, i++)
	{
		cout << "�������" << i << "λͬѧ����Ϣ��" << endl << endl;
		input(&stu);
		if (fwrite(&stu, sizeof(StuInfo), 1, fp) != 1)
		{
			printf("file write error");
		}
	}
	fclose(fp);
	cout << "¼����Ϣ��ɣ�";
}
//����,�޸����ݹ���
void FMData(StuLinkList* head)
{
	StuLinkList tail, s;
	int count = 0; //���������ж�

	//���ļ�student.dat
	FILE* fp;
	if ((fp = fopen("E:\\Project\\CPlus\\experiment_3\\experiment_3\\student.dat", "rb")) == NULL)
	{
		printf("faild\n");
		exit(0);
	}

	//���������Լ������ʽ
	char a[15];
	cout << "����������Ҫ���ҵ�ѧ�Ż�������:";
	cin >> a;
	header();

	//��student.dat��������
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

	//�����������Һ������Ϣ
	tail = (*head);  //����ָ��ָ��ͷ���
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
		cout << "���޴��ˣ�";
		exit(0);
	}
	//�޸����ݣ���
	char judge;	 //�ж��ǲ���Ҫ��Ҫ�޸�
	int m; 	//ѡ���޸��ĸ�����
	cout << endl << "�Ƿ���Ҫ�޸�����(y/n):";
	cin >> judge;
	cout << endl;

	if (judge == 'y')
	{
		cout << "ѡ������Ҫ�޸ĵ�����:1.��ϵ��ʽ 2.���Һ� ������˳�����" << endl << endl;
		cin >> m;
		cout << endl;

		//�޸�
		if (m == 1)
		{
			cout << "�������µ���ϵ��ʽ:";
			cin >> (*tail).student.contact;
			cout << endl << "�޸���ɣ�";
		}
		else if (m == 2)
		{
			cout << "�������µ����Һŷ�ʽ:";
			cin >> (*tail).student.rnum;
			cout << endl << "�޸���ɣ�";
		}
		else
			exit(0);

		//�޸���ɺ�Ҫ����д������
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
	//��������
	travel(*head);
	fclose(fp);
	DestroyList(head);
}
//ɸѡ����
void ScreenRisk(StuLinkList* head)
{
	FILE* fp1, * fp2;
	StuLinkList tail, s;
	tail = (*head) = new StuNode;
	int count = 0;
	int i = 0;
	struct {
		char name[10];
	}RiskRoom[5];  //��������  
	char RiskArea[10];
	//���ļ�
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
	// ��student.dat��������
	tail = (*head) = new StuNode;
	while (!feof(fp1))
	{
		s = new StuNode;
		fread(&s->student, sizeof(StuInfo), 1, fp1);
		tail->next = s;
		tail = s;
	}
	tail->next = NULL;
	//���������Ҹ��ݷ��յ����ҳ���������
	cout << "��������յ���:";
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
	//���ݷ��������ҳ�������Ա����д��guanzhu.dat +�����ab��ʽ��
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
	int option; //ѡ����
	int n; //���뼸��
	char judge; //�ж��Ƿ�������
	StuLinkList head; //ͷ���
	cout << endl << "�Ƿ���Ҫ����Ĭ����Ϣ(���ԭ������Ϣ�Ḳ�� y/n):";
	cin >> judge;
	if (judge == 'y')
	{
		ReadFile(&head);
		cout << "������Ϣ���!" << endl;
	}
	do
	{
		cout << endl << "1.¼����Ϣ����\t2.���ҡ��޸���Ϣ����\t3.ɸѡ��Ϣ����\t0.�˳�" << endl << endl;
		cout << "��ѡ������Ҫ�Ĺ���:";
		scanf_s("%d", &option);
		printf("\n\n");
		switch (option)
		{
		case 1:
			cout << "����Ҫ¼�������Ϣ��" << endl;
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