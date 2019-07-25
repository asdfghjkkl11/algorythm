#include<stdio.h>
#define pi 3.1415926535897932384626433832795
int main()
{
	double r;
	scanf("%lf", &r);
	printf("%.6lf\n%.6lf\n", pi*r*r, r*r * 2);
	return 0;
}
