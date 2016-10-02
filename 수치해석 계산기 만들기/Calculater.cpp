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

		command = strtok(str, "("); // 명령어부분을 command에 저장
		if(strncmp(command,"quit", 4) == 0) // quit명령어가 들어오면 프로그램 종료
		{
			cout << "Bye." << endl;
			return 0;
		}
		num = atof(strtok(NULL, ",)")); // 숫자부분을 double형으로 변형
	

		if(strncmp(command,"sqrt", 4) == 0) // square root 구하기
		{
			if(num<0) // 0보다 작으면 오류 출력
				cout << "0보다 큰 수를 입력하세요." << endl;
			else
				cout << _sqrt(num) << endl;
		}
		else if(strncmp(command,"sin", 3) == 0) // sin 값 구하기
			cout << sine(num) << endl;
		else if(strncmp(command,"cos", 3) == 0) // cos 값 구하기
			cout << sine(num+halfPI) << endl; // cos(x) = sin(pi/2 + x)
		else if(strncmp(command,"tan", 3) == 0) // tan 값 구하기
		{
			if(sine(num+halfPI)==0) // cos이 0일때 tan값 존재하지 않는다
				cout << "tan값이 존재하지 않습니다" << endl;
			else
				cout << sine(num)/sine(num+halfPI) << endl; // tan = sin/cos
		}
		else if(strncmp(command,"arcsin", 6) == 0) // arcsin 값 구하기
		{
			if(num > 1 || num < -1)
				cout << "sin값의 범위를 벗어났습니다." << endl;
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
				cout << "cos값의 범위를 벗어났습니다." << endl;
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
				cout << "0보다 큰 수이여야 합니다." << endl;
			else
				cout << ln(num) << endl;
		}
		else if(strncmp(command,"power", 5) == 0)
		{
			exp = atof(strtok(NULL, ")"));

			if(num <= 0)
				cout << "밑이 0보다 큰 수이여야 합니다." << endl;
			else if(exp < 0)
				cout << "지수가 0보다 큰 수이여야 합니다." << endl;
			else
				cout << _power(num, exp) << endl;
		}
	}
} 