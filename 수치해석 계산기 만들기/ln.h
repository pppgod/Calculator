#ifndef LN_H
#define LN_H

double ln(double ); // 범위를 줄이는 함수
double _ln(double ); // 자연로그값을 리턴하는 함수

typedef union
{
	double fp;
	struct
	{
		unsigned long lo;
		unsigned long hi;
	};
}hack_structure;

double ln(double X)
{
	hack_structure x;
	short expo;
	x.fp = X;
	// grab the exponent
	expo = (short)(x.hi >> 20);
	expo -= 0x3ff;
	// normalize the number
	x.hi &= 0x000fffff;
	x.hi += 0x3ff00000;
	return (ln2 * expo + _ln(x.fp));
}

double _ln(double x)
{
	double z = (x-1)/(x+1);
	double y = z*z;
	double up = (2*z)*(225225 - (345345*y) + (147455*y*y) - (15159*y*y*y));
	double down = 225225 - (420420*y) + (242550*y*y) - (44100*y*y*y) + (1225*y*y*y*y);

	return up/down;
}
#endif LN_H