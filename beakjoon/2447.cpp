#include <iostream>
using namespace std;
char mat[6561][6561];
int n;
void draw(int x, int y) {
	for (int i = x - 1; i < x + 2; i++)
		for (int j = y - 1; j < y + 2; j++)
			mat[i][j] = '*';
	mat[x][y] = ' ';
}
void dp(int x,int y,int m) {
	if (m == 3)
		draw(x, y);
	else {
		m /= 3;
		dp(x-m, y-m, m);
		dp(x-m, y, m);
		dp(x-m, y+m, m);
		dp(x, y-m, m);
		dp(x, y+m, m);
		dp(x+m, y-m, m);
		dp(x+m, y, m);
		dp(x+m, y+m, m);
	}
}
int main()
{
	cin >> n;
	if (n == 1) {
		cout << '*' << endl;
		return 0;
	}
	for (int i = 0; i < n;i++)
		for (int j = 0; j < n;j++)
			mat[i][j] = ' ';
	int p = (n / 2);
	dp(p, p, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j];
		cout << endl;
	}
	return 0;
}
