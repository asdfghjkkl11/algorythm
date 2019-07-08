#include <iostream>
#include <algorithm>
using namespace std;
int mat[1001][1001], N, M, X, a, b, c;
int main() {
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = 1000000000;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		mat[a][b] = c;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(mat[i][k]!= 1000000000)
					if (mat[i][j] > mat[i][k] + mat[k][j])
						mat[i][j] = mat[i][k] + mat[k][j];
	int res = mat[1][X]+mat[X][1];
	for (int i = 2; i <= N; i++)
		res = max(res, mat[i][X] + mat[X][i]);
	cout << res << endl;
	return 0;
}
