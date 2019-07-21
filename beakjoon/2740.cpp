#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n1, m1, n2, m2, a;
int mat1[100][100], mat2[100][100], mat3[100][100] = {};
int main()
{
	ios::sync_with_stdio(false);
	cin >> n1 >> m1;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++) {
			cin >> a;
			mat1[i][j] = a;
		}
	cin >> n2 >> m2;
	for (int i = 0; i < n2; i++)
		for (int j = 0; j < m2; j++) {
			cin >> a;
			mat2[i][j] = a;
		}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < n2; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			cout << mat3[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
