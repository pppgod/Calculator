#ifndef POWER_H
#define POWER_H

double _power(double, double ); // e^ln(x) = x���� �̿��Ͽ� ��� ����
double power(double, int ); // ������ �����϶� e^x���� ���ϴ� �Լ�
double exp1(double ); // ������ �Ҽ��κа� �����κ����� ������ e^x�� ���ϴ� �Լ�

double _power(double x, double y)
{
	return exp1(y*ln(x));
}
double power(double x, int n)
{
	double retval = 1;
	double factor = x;
	while(n != 0)
	{
		if((n&1) != 0)
			retval *= factor;
		factor *= factor;
		n >>= 1;
	}
	return retval;
}

double exp1(double x)
{
	const double root_e = sqrt(sqrt(2.71828182846));
	double retval;
	double intpart;
	int n;
	x *= 4;
	n = (int)x;
	x -= n;
	x /= 4;
	retval = (((((x/6+1)*x/5+1)*x/4+1)*x/3+1)*x/2+1)*x+1;
	intpart = power(root_e, n);

	return intpart*retval;
}
#endif