#ifndef ARCT_H
#define ARCT_H

double arct(double x) // ��ũź��Ʈ�� �����ϴ� �Լ�
{
	double y = x * x;
	x = x*((1155 + 1190*y + 231*y*y)/(1155 + 1575*y + 525*y*y + 25*y*y*y));
	return x;
}
#endif