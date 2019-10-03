#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N, po[10] = { 0 }, mat[10] = { 0 }, M = 0, result = 10000;
vector<int>cache(1050, -1);
bool check(int a, vector<int> &v) {
	int b = 0, visit[10] = {0};
	queue<int>que;
	que.push(v[0]);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		visit[f] = 1;
		b |= (1<<f);
		for (int i = 0; i < v.size();i++) {
			if (visit[v[i]] == 0 && mat[f] & (1 << v[i]))
				que.push(v[i]);
		}
	}
	return ((b&a) == a) ? true : false;
}
void link(int a) {
	vector<int> v;
	int res = 0;
	for (int i = 0; i < N; i++)
		if (a&(1 << i)) {
			v.push_back(i);
			res += po[i];
		}
	cache[a] = (check(a, v)) ? res : -1;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> po[i];
		M = M | (1 << i);
	}
	for (int i = 0; i < N; i++) {
		int t, s;
		cin >> t;
		mat[i] |= (1 << i);
		for (int j = 0; j < t; j++) {
			cin >> s;
			mat[i] |= (1 << (s - 1));
		}
	}
	for (int i = 1; i < M; i++)
		link(i);
	for (int i = 0; i <= M / 2; i++) {
		if (cache[i] == -1 || cache[M - i] == -1)
			continue;
		result = min(result, abs(cache[i] - cache[M - i]));
	}
	result = (result == 10000) ? -1 : result;
	cout << result << endl;
	return 0;
}
