#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char str1[1001], str2[1001];
int mat[1000][1000];
int cathe[1000][1000];
int DP(int a, int b) {
	if (a > strlen(str1) - 1 || b > strlen(str2) - 1)
		return 0;
	if (cathe[a][b] != -1)
		return cathe[a][b];
	if (mat[a][b] == 0)
		return cathe[a][b] = max(DP(a + 1, b), DP(a, b + 1));
	else
		return cathe[a][b] = mat[a][b] + DP(a + 1, b + 1);
}
int main()
{
	cin >> str1 >> str2;
	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			cathe[i][j] = -1;
			if (str1[i] == str2[j])
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
	int result = DP(0, 0);
	cout << result << endl;
	return 0;
}
