#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct shark {
	int s, d, z;
}mat[100][100] = { 0 };
int R, C, M, result = 0, dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
int r, c, s, d, z, Ri, Ci;
void del(int a, int b) {
	mat[a][b].s = 0;
	mat[a][b].d = 0;
	mat[a][b].z = 0;
}
void move() {
	shark temp[100][100] = { 0 };
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (mat[i][j].z != 0) {
				int x, y;
				x = (i + (mat[i][j].s*dir[mat[i][j].d][0]) + (Ri*1000)) % Ri;
				y = (j + (mat[i][j].s*dir[mat[i][j].d][1]) + (Ci*1000)) % Ci;
				if (x >= R) {
					x = Ri - x;
					mat[i][j].d = (mat[i][j].d % 2 == 0) ? mat[i][j].d + 1 : mat[i][j].d - 1;
				}
				else if (y >= C) {
					y = Ci - y;
					mat[i][j].d = (mat[i][j].d % 2 == 0) ? mat[i][j].d + 1 : mat[i][j].d - 1;
				}
				temp[x][y] = (temp[x][y].z < mat[i][j].z) ? mat[i][j] : temp[x][y];
			}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			mat[i][j] = temp[i][j];
}
int main() {
	cin >> R >> C >> M;
	Ri = (2 * R) - 2, Ci = (2 * C) - 2;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		mat[r - 1][c - 1].s = s;
		mat[r - 1][c - 1].d = d - 1;
		mat[r - 1][c - 1].z = z;
	}
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++)
			if (mat[j][i].z != 0) {
				result += mat[j][i].z;
				del(j, i);
				break;
			}
		move();
	}
	cout << result << endl;
	return 0;
}
