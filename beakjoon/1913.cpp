#include <iostream>
#include <algorithm>
using namespace std;
int N, M, s, t, a, b;
int mat[1000][1000];
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int main() {
	cin >> N >> M;
	s = N*N;
	t = N;
	int x = -1, y = 0;
	while (s != 0) {
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 1)
				t--;
			for (int j = 0; j < t; j++) {
				x += dir[i][1];
				y += dir[i][0];
				mat[x][y] = s;
				if (s == M) {
					a = x+1;
					b = y+1;
				}
				s--;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
	cout << a << ' ' << b << endl;
	return 0;
}
