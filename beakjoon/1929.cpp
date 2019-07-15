#include <iostream>
using namespace std;
int n,m;
int num[1000001];
int main()
{
	for (int i = 0; i < 1000001; i++)
		num[i] = 1;
	num[0] = 0, num[1] = 0;
	for (int i = 2; i < 1000001; i++)
		if (num[i] == 1)
			for (int j = i * 2; j < 1000001; j += i)
				num[j] = 0;
	scanf("%d %d",&n,&m);
	for (int i = n; i <= m; i++)
		if (num[i] == 1)
			printf("%d\n",i);
	return 0;
}
