#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, Count = 0;
vector<int>v;
void dfs(int m) {
	for (int i = 0; m > 1 && i < m - 1; i++) {
		if (v[i] == v[m - 1])
			return;
		if (abs(i - m + 1) == abs(v[i] - v[m - 1]))
			return;
	}
	if (m == n) {
		Count++;
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		dfs(m + 1);
		v.pop_back();
	}
}
int main()
{
	cin >> n;
	dfs(0);
	cout << Count;
	return 0;
}
