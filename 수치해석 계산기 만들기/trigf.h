#ifndef TRIGF_H
#define TRIGF_H

double _sine(double ); // sin�� ���� �Լ�
double _cosine(double ); // cos�� ���� �Լ�
double sine(double ); // ������ ���̰� sin���� �����ϴ� �Լ�


double _sine(double x)
{
	double s1 = 1.0/(2.0*3.0);
	double s2 = 1.0/(4.0*5.0);
	double s3 = 1.0/(6.0*7.0);
	double s4 = 1.0/(8.0*9.0);
	double z = x * x;

	return ((((s4*z - 1.0) * s3 * z + 1.0) * s2 * z - 1.0) * s1 * z +1.0) * x;
}

double _cosine(double x)
{
	double c1 = 1.0/(1.0 * 2.0);
	double c2 = 1.0/(3.0 * 4.0);
	double c3 = 1.0/(5.0 * 6.0);
	double c4 = 1.0/(7.0 * 8.0);
	double z = x * x;

	return (((c4 * z - 1.0) * c3 * + 1.0) * c2 * z -1.0) * c1 * z + 1.0;
}

double sine(double x)
{
	long n = (long)(x/halfPI + 0.5);
	x -= n * halfPI;
	n = mod(n, (long)4);

	switch(n)
	{
	case 0:
		return _sine(x);
	case 1:
		return _cosine(x);
	case 2:
		return -_sine(x);
	case 3:
		return -_cosine(x);
	}
}
#endif