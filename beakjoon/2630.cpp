#include <iostream>
using namespace std;
int N, mat[128][128], B = 0, W = 0;
int paper(int x, int y, int s) {
	if (s == 1)
		return mat[x][y];
	int P[4];
	P[0] = paper(x, y, s / 2);
	P[1] = paper(x, y + s / 2, s / 2);
	P[2] = paper(x + s / 2, y, s / 2);
	P[3] = paper(x + s / 2, y + s / 2, s / 2);
	if (P[0] == P[1] && P[0] == P[2] && P[0] == P[3])
		return P[0];
	else {
		for (int i = 0; i < 4; i++)
			if (P[i] == 0)
				W++;
			else if (P[i] == 1)
				B++;
		return -1;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	int R = paper(0, 0, N);
	if (R == 0)
		W++;
	else if (R == 1)
		B++;
	cout << W << endl;
	cout << B << endl;
	return 0;
}
