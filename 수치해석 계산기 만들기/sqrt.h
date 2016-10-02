#ifndef SQRT_H
#define SQRT_H

double my_sqrt(double , int ); // sqrt값 리턴함수
double _sqrt(double ); // 오차를 줄이기위해 형태를 바꾸어 sqrt값 리턴함수

double my_sqrt(double a, int n)
{
	double x;
	int i;
	if(1 <= 0.0)
		return a;

	x = a;
	for(i = 0; i < n; i++)
		x = 0.5 * (a/x + x);
	return x;
}

double _sqrt(double f)
{
	typedef union
	{
		double fp;
		struct
		{
			unsigned long lo;
			unsigned long hi;
		};
	}hack_structure;

	hack_structure x;
	short expo;
	// unsigned short sign;
	char odd = 0;

	x.fp = f;
	expo = (short)(x.hi >> 20);
	expo -= 0x3ff;

	x.hi &= 0x000fffff;
	x.hi += 0x3ff00000;

	x.fp = my_sqrt(x.fp, 10);

	if(expo & 1)
	{
		++expo;
		odd = 1;
	}

	expo /= 2;

	expo += 0x3ff;
	x.hi &= 0x000fffff;
	x.hi += ((unsigned long)expo << 20);

	if(odd)
		x.fp /= SQRT_2;

	return x.fp;
}
#endif