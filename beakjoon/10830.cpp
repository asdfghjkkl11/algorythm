#include <iostream>
using namespace std;
unsigned long long B;
long long A, arr[2][5][5] = { 0 };
void matrix(int a, int b) {
	long long result[5][5] = { 0 };
	for (int i = 0; i < A; i++)
		for (int j = 0; j < A; j++) {
			for (int k = 0; k < A; k++)
				result[i][j] += arr[a][i][k] * arr[b][k][j];
			result[i][j] %= 1000;
		}
	for (int i = 0; i < A; i++)
		for (int j = 0; j < A; j++)
			arr[a][i][j] = result[i][j];
}
int main() {
	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++)
			cin >> arr[1][i][j];
		arr[0][i][i] = 1;
	}
	while (B > 0) {
		if (B % 2)
			matrix(0,1);
		matrix(1, 1);
		B /= 2;
	}
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++)
			cout << arr[0][i][j] << ' ';
		cout << endl;
	}
	return 0;
}
