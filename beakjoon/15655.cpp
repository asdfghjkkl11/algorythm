#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[8];
vector<int>v;
void dfs(int a) {
	if (v.size() == M) {
		for (int i : v)
			printf("%d ", i);
		printf("\n");
		return;
	}
	if (a == N)
		return;
	for (int i = a; i < N; i++) {
		v.push_back(arr[i]);
		dfs(i + 1);
		v.pop_back();
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	dfs(0);
	return 0;
}
