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
	for (int i = 0; i < N; i++) {
		if ((a&(1 << i)) == 0) {
			v.push_back(arr[i]);
			dfs(a | (1 << i));
			v.pop_back();
		}
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
