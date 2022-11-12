#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

#define FILE_PATH "Demo.txt"

char Arithmetic_brackets[4] = { '(', ' ',')',' ' }; //括号
char Arithmetic_operators[4] = { '+','-','*','/' }; //运算符
const int Arithmetic_operation = 4; //生成随机运算符
const int Arithmetic_bracket = 2; //生成随机括号
int Arithmetic_number; //题目数目
int Arithmetic_max;	//最大数
int Arithmetic_iffile;   //确定是否打印
int Arithmetic_ifdecimal;  //确定是否有小数
int Arithmetic_ifbrackets;  //确定是否有括号
int Arithmetic_operand; //选择几个操作数
FILE* fp;   //文件地址
int judge;

void menu1()
{
	cout << "第1步：请设置题目数量 <1-100> ：" << endl;
	cin >> Arithmetic_number;
	while ((Arithmetic_number > 100) || (Arithmetic_number < 1))
	{
		cout << "您设置的题目数目不符合要求(太多/太少)。 < 1 - 100 > " << endl;
		cout << endl;
		cout << "请按确认键重新输入，谢谢！" << endl;
		cin >> Arithmetic_number;
	}
}

void menu2()
{
	cout << "第2步：请设置最大数 <1-1000> ：" << endl;
	cin >> Arithmetic_max;
	while ((Arithmetic_max > 1000) || (Arithmetic_max < 1))
	{
		cout << "您设置的最大数不符合要求(太大/太小)。 < 1 - 1000 > " << endl;
		cout << endl;
		cout << "请按确认键重新输入，谢谢！" << endl;
		cin >> Arithmetic_max;
	}
}

void menu3()
{
	cout << "第3步：请选择是否有小数：(输入 <0> 生成整数 , 输入 <1> 生成小数) " << endl;
	cin >> Arithmetic_ifdecimal;
	while ((Arithmetic_ifdecimal != 0) && (Arithmetic_ifdecimal != 1))
	{
		cout << "您输入的数不符合要求。(输入 <0> 生成整数 , 输入 <1> 生成小数) " << endl;
		cout << endl;
		cout << "请按确认键重新输入！" << endl;
		cin >> Arithmetic_ifdecimal;
	}
}

int menu4()
{
	cout << "第4步：请选择几个操作数：(输入 <2> 两个操作数 , 输入 <3> 三个操作数 , 输入 <4> 四个操作数 . 注：只有两个操作数以上才能生成括号 )" << endl;
	cin >> Arithmetic_operand;
	return Arithmetic_operand;
}

void menu5()
{
	cout << "第4步：请选择是否有括号：(输入 <0> 无括号 , 输入 <1> 有括号)" << endl;
	cin >> Arithmetic_ifbrackets;
	while ((Arithmetic_ifbrackets != 0) && (Arithmetic_ifbrackets != 1))
	{
		cout << "您输入的数不符合要求。(输入 <0> 无括号 , 输入 <1> 有括号) " << endl;
		cout << endl;
		cout << "请按确认键重新输入！" << endl;
		cin >> Arithmetic_ifbrackets;
	}
}



void menu()
{
	menu1();
	menu2();
	menu3();
	judge = menu4();
	if (judge == 3 || judge == 4)
	{
		menu5();
	}
}

void Arithmetic_Output_Screen2()
{
	cout << "+----------------以下为*小学四则运算自动生成程序*所生成的四则运算练习题----------------+" << endl;
	fopen_s(&fp, FILE_PATH, "w");
	for (int i = 1; i < Arithmetic_number+1; ++i)
	{

		/*随机生成四个整数*/
		int number1 = rand() % Arithmetic_max;
		int number2 = rand() % Arithmetic_max;

		/*随机生成四个小数*/
		float number5 = (float)rand() / Arithmetic_max;
		float number6 = (float)rand() / Arithmetic_max;

		/*随机生成三个运算符*/
		int operation1 = rand() % Arithmetic_operation;
		char cur_operation1 = Arithmetic_operators[operation1];

		if (Arithmetic_ifdecimal)
		{
			if (Arithmetic_ifbrackets)
			{

				cout << "NO." << i << " : " << number5 << " " << cur_operation1 << " " << number6 << "=" << endl;
				fprintf(fp, "NO. %2d : %.2f %c %.2f = \n", i, number5, cur_operation1, number6);

			}
			else
			{

				cout << "NO." << i << " : " << number5 << " " << cur_operation1 << " " << number6 << "=" << endl;
				fprintf(fp, "NO. %2d : %.2f %c %.2f = \n", i, number5, cur_operation1, number6);

			}
		}
		else
		{
			if (Arithmetic_ifbrackets)
			{

				cout << "NO." << i << " : " << number1 << " " << cur_operation1 << " " << number2 << endl;
				fprintf(fp, "NO. %2d : %c %d %c = \n", i, number1, cur_operation1, number2);

			}
			else
			{

				cout << "NO." << i << " : " << number1 << " " << cur_operation1 << " " << number2 << " " << "=" << endl;
				fprintf(fp, "NO. %2d : %d %c %d = \n", i, number1, cur_operation1, number2);

			}
		}
	}
	fclose(fp);
	cout << "+------------------------------------已成功写入文件demo.txt--------------------------------------------------+" << endl;

}

void Arithmetic_Output_Screen3()
{
	cout << "+----------------以下为*小学四则运算自动生成程序*所生成的四则运算练习题----------------+" << endl;
	fopen_s(&fp, FILE_PATH, "w");
	for (int i = 1; i < Arithmetic_number+1; ++i)
	{

		/*随机生成四个整数*/
		int number1 = rand() % Arithmetic_max;
		int number2 = rand() % Arithmetic_max;
		int number3 = rand() % Arithmetic_max;

		/*随机生成四个小数*/
		float number5 = (float)rand() / Arithmetic_max;
		float number6 = (float)rand() / Arithmetic_max;
		float number7 = (float)rand() / Arithmetic_max;

		/*随机生成三个运算符*/
		int operation1 = rand() % Arithmetic_operation;
		int operation2 = rand() % Arithmetic_operation;
		char cur_operation1 = Arithmetic_operators[operation1];
		char cur_operation2 = Arithmetic_operators[operation2];

		/*随机产生括号()*/
		int barcket1 = rand() % Arithmetic_bracket;
		char cur_barckets1 = Arithmetic_brackets[barcket1];
		char cur_barckets2 = Arithmetic_brackets[barcket1 + 2];

		if (Arithmetic_ifdecimal)
		{
			if (Arithmetic_ifbrackets)
			{

				cout << "NO." << i << " : " << cur_barckets1 << number5 << " " << cur_operation1 << " " << number6 << cur_barckets2 << " " << cur_operation2 << " " << number7 << " " << "=" << endl;
				fprintf(fp, "NO. %2d : %c %.2f %c %.2f %c %c %.2f = \n", i, cur_barckets1, number5, cur_operation1, number6, cur_barckets2, cur_operation2, number7);

			}
			else
			{

				cout << "NO." << i << " : " << number5 << " " << cur_operation1 << " " << number6 << " " << cur_operation2 << " " << number7 << " " "=" << endl;
				fprintf(fp, "NO. %2d : %.2f %c %.2f %c %.2f = \n", i, number5, cur_operation1, number6, cur_operation2, number7);

			}
		}
		else
		{
			if (Arithmetic_ifbrackets)
			{

				cout << "NO." << i << " : " << cur_barckets1 << number1 << " " << cur_operation1 << " " << number2 << cur_barckets2 << " " << cur_operation2 << " " << number3 << " " "=" << endl;
				fprintf(fp, "NO. %2d : %c %d %c %d %c %c %d = \n", i, cur_barckets1, number1, cur_operation1, number2, cur_barckets2, cur_operation2, number3);

			}
			else
			{

				cout << "NO." << i << " : " << number1 << " " << cur_operation1 << " " << number2 << " " << cur_operation2 << " " << number3 << " " << "=" << endl;
				fprintf(fp, "NO. %2d : %d %c %d %c %d = \n", i, number1, cur_operation1, number2, cur_operation2, number3);

			}
		}
	}
	fclose(fp);
	cout << "+------------------------------------已成功写入文件demo.txt--------------------------------------------------+" << endl;

}

void Arithmetic_Output_Screen4()
{
	cout << "+----------------以下为*小学四则运算自动生成程序*所生成的四则运算练习题----------------+" << endl;
	fopen_s(&fp, FILE_PATH, "w");
	for (int i = 1; i < Arithmetic_number+1; ++i)
	{
		
		/*随机生成四个整数*/
		int number1 = rand() % Arithmetic_max;
		int number2 = rand() % Arithmetic_max;
		int number3 = rand() % Arithmetic_max;
		int number4 = rand() % Arithmetic_max;

		/*随机生成四个小数*/
		float number5 = (float)rand() / Arithmetic_max;
		float number6 = (float)rand() / Arithmetic_max;
		float number7 = (float)rand() / Arithmetic_max;
		float number8 = (float)rand() / Arithmetic_max;

		/*随机生成三个运算符*/
		int operation1 = rand() % Arithmetic_operation;
		int operation2 = rand() % Arithmetic_operation;
		int operation3 = rand() % Arithmetic_operation;
		char cur_operation1 = Arithmetic_operators[operation1];
		char cur_operation2 = Arithmetic_operators[operation2];
		char cur_operation3 = Arithmetic_operators[operation3];

		/*随机产生括号()*/
		int barcket1 = rand() % Arithmetic_bracket;
		char cur_barckets1 = Arithmetic_brackets[barcket1];
		char cur_barckets2 = Arithmetic_brackets[barcket1 + 2];

		if (Arithmetic_ifdecimal)
		{
			if (Arithmetic_ifbrackets)
			{
				
				cout << "NO." << i << " : " << cur_barckets1 << number5 << " " << cur_operation1 << " " << number6 << cur_barckets2 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
				fprintf(fp, "NO. %2d : %c %.2f %c %.2f %c %c %.2f %c %.2f = \n", i, cur_barckets1, number5, cur_operation1, number6, cur_barckets2, cur_operation2, number7, cur_operation3, number8);
				
			}
			else
			{
				
				cout << "NO." << i << " : " << number5 << " " << cur_operation1 << " " << number6 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
				fprintf(fp, "NO. %2d : %.2f %c %.2f %c %.2f %c %.2f = \n", i, number5, cur_operation1, number6, cur_operation2, number7, cur_operation3, number8);
				
			}
		}
		else
		{
			if (Arithmetic_ifbrackets)
			{
				
				cout << "NO." << i << " : " << cur_barckets1 << number1 << " " << cur_operation1 << " " << number2 << cur_barckets2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
				fprintf(fp, "NO. %2d : %c %d %c %d %c %c %d %c %d = \n", i, cur_barckets1, number1, cur_operation1, number2, cur_barckets2, cur_operation2, number3, cur_operation3, number4);
				
			}
			else
			{
				
				cout << "NO." << i << " : " << number1 << " " << cur_operation1 << " " << number2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
				fprintf(fp, "NO. %2d : %d %c %d %c %d %c %d = \n", i, number1, cur_operation1, number2, cur_operation2, number3, cur_operation3, number4);
				
			}
		}
	}
	fclose(fp);
	cout << "+------------------------------------已成功写入文件demo.txt--------------------------------------------------+" << endl;

}

int main()
{
	menu();
	if (judge == 2)
	{
		Arithmetic_Output_Screen2();
	}
	else if (judge == 3)
	{
		Arithmetic_Output_Screen3();
	}
	else if(judge == 4)
	{
		Arithmetic_Output_Screen4();
	}
	return 0;
}