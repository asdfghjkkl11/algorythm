#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (((a)<(b)) ? (a) : (b))
#define max(a,b) (((a)>(b)) ? (a) : (b))
int Answer;
int num[10000];
void quick(int l,int r) {
	int i, j, key, temp;
	if (l<r) {
		i = l-1;
		j = r + 1;
		key = num[(l+r)/2];
		do {
			do {
				i++;
			} while (num[i] < key&&i<r);
			do {
				j--;
			} while (num[j] > key&&j>l);
			if (i < j) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		} while (i < j);
		temp = num[l];
		num[l] = num[j];
		num[j] = temp;
		quick(l,j);
		quick(j+1,r);
	}
}
int main(void)
{
	int T,t,Test_case, test_case;
	int i;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (test_case = 0; test_case < t; test_case++)
	{
		scanf("%d", &T);
		Answer = 0;
		for (Test_case = 0; Test_case < T; Test_case++)
		{
			scanf("%d",&num[Test_case]);
		}
		quick(0,T-1);
		for (i = 0; i < T; i++)
		{
			if (i % 2 == 1)
				Answer -= num[i];
			else
				Answer += num[i];
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;
}ㅍ
