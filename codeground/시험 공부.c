#include <stdio.h>
#include <string.h>
int Answer;
int score[200000];
void quick(int l, int r) {
	int i, j, key, temp;
	if (l<r) {
		i = l - 1;
		j = r + 1;
		key = score[(l + r) / 2];
		do {
			do {
				i++;
			} while (score[i] < key&&i<r);
			do {
				j--;
			} while (score[j] > key&&j>l);
			if (i < j) {
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		} while (i < j);
		temp = score[l];
		score[l] = score[j];
		score[j] = temp;
		quick(l, j);
		quick(j + 1, r);
	}
}
int main(void)
{
	int T, Test_case, test_case;
	int max,choice,i;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (Test_case = 0; Test_case < T; Test_case++)
	{
		scanf("%d %d", &max,&choice);
		Answer = 0;
		for (test_case = 0; test_case < max; test_case++)
		{
			scanf("%d ", &score[test_case]);
		}
		quick(0,max-1);
		for (i = max - 1; i > max - 1 - choice;i--) {
			Answer += score[i];
		}
		printf("Case #%d\n", Test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;
}
//시험기간에는 역시 시험공부지
