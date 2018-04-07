#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a,b) (((a)<(b)) ? (a) : (b))
int Answer;
int s[32];
int c;
void sys(int num, int count) {
	int x, y,r;
	x = num % count;
	y = num / count;
	s[c] = x;
	c++;
	if (y == 0)
		return;
	if (y < count) {
		s[c] = y;
		c++;
		return;
	}
	sys(y,count);
}
int equl(int num,int count){
	int i;
	sys(num, count);
	if (c == 1)
		return 1;
	for (i = 0; i < c-1;i++) {
		if (s[i] != s[i + 1])
			return 0;
	}
	return 1;
}
int main(void)
{
	int n1, n2;
	int num,i,x;
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &num);
		c = 0;
		n1 = 0;
		n2 = 0;
		for (i = sqrt(num); i >= 1; i--) {
			
			x = (num - i) / i;
			if (num==(x*i)+i&&x>i) {
				n1 = x;
				break;
			}
		}
		for (i = 2;i<sqrt(num); i++){
			if (equl(num, i) == 1) {
				n2 = i;
				break;
			}
			c = 0;
		}
		if (n1 == 0)
			Answer = n2;
		else if (n2 == 0)
			Answer = n1;
		else
			Answer = min(n1,n2);
		if (n1 == 0 && n2 == 0) {
			if (num <10)
				Answer = num + 1;
			else
				Answer = num - 1;
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;
}