#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int r1, r2, c1, c2;
int mat[50][5];
int dir[4][2] = { { 0,1 },{ -1,0 },{ 0,-1 },{ 1,0 } };
int max(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	cin >> r1 >> c1 >> r2 >> c2;
	int R = max(max(r1, r2), max(c1, c2));
	int count = 1;
	int m = (R * 2 + 1)*(R * 2 + 1) + 1;
	int i = 0, j = 0;
	int c = 0, d = 1, e = 0, f = 0;
	int max = 0;
	while (count<m) {
		if ((i - r1) <= r2 - r1 && (j - c1) <= c2 - c1 && (i - r1) >= 0 && (j - c1) >= 0) {
			mat[i - r1][j - c1] = count;
			if (count > max)
				max = count;
		}
		i += dir[f][0];
		j += dir[f][1];
		e++;
		if (e == d) {
			f++;
			f %= 4;
			e = 0;
			if (c == 1) {
				c = 0;
				d++;
			}
			else
				c++;
		}
		count++;
	}
	int lo = (int)log10(max)+1;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			printf("%*d",lo,mat[i][j]);
			if(j==c2-c1)
				cout << '\n';
			else
				cout << ' ';
		}
	}
	return 0;
}
