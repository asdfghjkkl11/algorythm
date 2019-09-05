#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int N, mat[20][20], cache[1048576];
bool check[20] = { 0 };
int calculate() {
	vector<int> r, l;
	for (int i = 0; i < N; i++) {
		if (check[i])
			r.push_back(i);
		else
			l.push_back(i);
	}
	int R = 0, L = 0;
	for (int i = 0; i < r.size() - 1; i++) {
		for (int j = i + 1; j < r.size(); j++) {
			R += mat[r[i]][r[j]];
			R += mat[r[j]][r[i]];
			L += mat[l[i]][l[j]];
			L += mat[l[j]][l[i]];
		}
	}
	return abs(R - L);
}
int DFS(int a, int C) {
	if (cache[C] != -1)
		return cache[C];
	if (a == N / 2)
		return calculate();
	int m = 1000000001;
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = !check[i];
			m = min(m, DFS(a + 1, C ^ (1 << i)));
			check[i] = !check[i];
		}
	}
	return cache[C] = m;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	cout << DFS(0, 0) << endl;
	return 0;
}
