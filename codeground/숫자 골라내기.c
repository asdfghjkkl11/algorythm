#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Answer;
int bi[32];
int xor[32] = {0};
int num;
int count;
void sys() {
	while (num>1) {
		bi[count] = num % 2;
		num /= 2;
		count++;
	}
	if (num == 1) {
		bi[count] = num;
		count++;
	}
}
void XOR() {
	int i;
	for (i = 0; i < count;i++) {
		if (xor[i] == bi[i])
			xor[i] = 0;
		else
			xor[i] = 1;
	}
}
int back() {
	int b = 1;
	int a = 0;
	int i;
	for (i = 0; i < 32;i++) {
		a += b*xor[i];
		b *= 2;
	}
	return a;
}
int main(void)
{
	int i;
	int T, t, Test_case, test_case;
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (test_case = 0; test_case < t; test_case++)
	{
		scanf("%d", &T);
		for (i = 0; i < 32;i++) {
			xor[i] = 0;
		}
		for (Test_case = 0; Test_case < T; Test_case++)
		{
			count = 0;
			scanf("%d ", &num);
			sys();
			XOR();
		}
		Answer = back();
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;
}
