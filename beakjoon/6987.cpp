#include <iostream>
using namespace std;
int N, score[6][3];
int dfs(int a,int b) {
	if (a == 6)
		return 1;
	if (b == 6)
		return dfs(a + 1, a + 2);
	int result = 0;
	for (int i = 0; i < 3; i++)
		if (score[a][i] > 0 && score[b][2-i] > 0) {
			score[a][i]--; score[b][2-i]--;
			result |= dfs(a, b + 1);
			score[a][i]++; score[b][2-i]++;
		}
	return result;
}
int main() {
	for (int i = 0; i < 4; i++) {
		N = 0;
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 3; k++) {
				cin >> score[j][k];
				N += score[j][k];
			}
		if (N != 30)
			cout << 0 << endl;
		else
			cout << dfs(0,1) << endl;
	}
	return 0;
}
