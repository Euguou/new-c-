#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	double D,sum,one,twe;
	scanf_s("%lf", &D);
	one = 150 * 0.4463;
	twe = (400 - 150)*0.4663 + one;
	if (D < 150)
	{
		sum = D * 0.4463;
	}
	if (D > 151 )
	{
		if (D < 400)
		{
			sum = (D - 150)*0.4663 + one;
		}
		else
			sum = (D - 400)*0.5663 + twe;
	}
	printf("%.1f", sum);
	return 0;
}