#include <iostream>
#include <algorithm>
using namespace std;
int N, M, r = 5000, r1, r2;
char arr[50][50], BW[8][8], WB[8][8], A = 'B', B = 'W', C;
int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			BW[i][j] = A;
			WB[i][j] = B;
			swap(A, B);
		}
		swap(A, B);
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N-7; i++)
		for (int j = 0; j < M-7; j++) {
			r1 = 0, r2 = 0;
			for (int k = 0; k < 8; k++)
				for (int l = 0; l < 8; l++) {
					if (arr[i+k][j+l] != BW[k][l])
						r1++;
					if (arr[i+k][j+l] != WB[k][l])
						r2++;
				}
			r = min(r, min(r1, r2));
		}
	cout << r << endl;
	return 0;
}
