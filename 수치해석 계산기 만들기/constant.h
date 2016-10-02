#ifndef CONSTANT_H
#define CONSTANT_H

static double PI = 4.0 * atan(1.0);
static double halfPI = PI/2.0;
static double twoPI = 2 * PI;
static double PI_over_four = halfPI / 2.0;
static double SQRT_2 = 1.4142135;
static double EXP = 2.71828182846;
static double ln2 = 0.693147180559;

double mod(double x, double y) //modulo 연산 함수 
{
	if(y == 0)
		return x;
	long i = (long)(x/y);
	if(x*y < 0)
		--i;
	x = x - ((double)i) * y;
	if(x == y)
		x -= y;
	return x;
}
#endif