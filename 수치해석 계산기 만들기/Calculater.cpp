#include <iostream>
#include <string>
#include <stdlib.h>
#include "constant.h"
#include "sqrt.h"
#include "trigf.h"
#include "arct.h"
#include "ln.h"
#include "power.h"
using namespace std;

int main()
{
	char str[50];
	char *command;
	double num;
	double exp;
	bool flag;

	cout << "sqrt(double x) / sin(double x) / cos(double x) / tan(double x) /" << endl
		<< "arcsin(double x) / arccos(double x) / arctan(double x) /" << endl
		<< "ln(double x) / power(double x, double y) / quit" << endl << endl;

	while(1)
	{

		cout << "> ";
		cin >> str;

		command = strtok(str, "("); // ��ɾ�κ��� command�� ����
		if(strncmp(command,"quit", 4) == 0) // quit��ɾ ������ ���α׷� ����
		{
			cout << "Bye." << endl;
			return 0;
		}
		num = atof(strtok(NULL, ",)")); // ���ںκ��� double������ ����
	

		if(strncmp(command,"sqrt", 4) == 0) // square root ���ϱ�
		{
			if(num<0) // 0���� ������ ���� ���
				cout << "0���� ū ���� �Է��ϼ���." << endl;
			else
				cout << _sqrt(num) << endl;
		}
		else if(strncmp(command,"sin", 3) == 0) // sin �� ���ϱ�
			cout << sine(num) << endl;
		else if(strncmp(command,"cos", 3) == 0) // cos �� ���ϱ�
			cout << sine(num+halfPI) << endl; // cos(x) = sin(pi/2 + x)
		else if(strncmp(command,"tan", 3) == 0) // tan �� ���ϱ�
		{
			if(sine(num+halfPI)==0) // cos�� 0�϶� tan�� �������� �ʴ´�
				cout << "tan���� �������� �ʽ��ϴ�" << endl;
			else
				cout << sine(num)/sine(num+halfPI) << endl; // tan = sin/cos
		}
		else if(strncmp(command,"arcsin", 6) == 0) // arcsin �� ���ϱ�
		{
			if(num > 1 || num < -1)
				cout << "sin���� ������ ������ϴ�." << endl;
			else
			{
				num = num/(sqrt(1-num*num));

				if(num < -1.0 || num > 1.0)
					cout << halfPI - arct(1/num);
				else
					cout << arct(num) << endl;
			}
		}
		else if(strncmp(command,"arccos", 6) == 0)
		{
			if(num > 1 || num < -1)
				cout << "cos���� ������ ������ϴ�." << endl;
			else
			{
				if(num > 0)
					flag = true;
				else
					flag = false;

				num = (sqrt(1-num*num))/num;

				if(num < -1.0 || num > 1.0)
					num = halfPI - arct(1/num);
				else
					num = arct(1/num);

				if(flag = true)
					cout << num << endl;
				else
					cout << halfPI + num << endl;
			}
		}
		else if(strncmp(command,"arctan", 6) == 0)
		{
			if(num < -1.0 || num > 1.0)
				cout << halfPI - arct(1/num);
			else
				cout << arct(num) << endl;
		}
		else if(strncmp(command,"ln", 2) == 0)
		{
			if(num <= 0)
				cout << "0���� ū ���̿��� �մϴ�." << endl;
			else
				cout << ln(num) << endl;
		}
		else if(strncmp(command,"power", 5) == 0)
		{
			exp = atof(strtok(NULL, ")"));

			if(num <= 0)
				cout << "���� 0���� ū ���̿��� �մϴ�." << endl;
			else if(exp < 0)
				cout << "������ 0���� ū ���̿��� �մϴ�." << endl;
			else
				cout << _power(num, exp) << endl;
		}
	}
} 