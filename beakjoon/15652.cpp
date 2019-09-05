#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v;
unordered_map<int, int>um;
int N, M;
void DFS(int b) {
	if (b == M) {
		for (int i = 0; i<v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!v.empty()&&v.back()>i)
			continue;
		um[i]++;
		v.push_back(i);
		DFS(b + 1);
		v.pop_back();
		um[i]--;
	}
}
int main() {
	cin >> N >> M;
	DFS(0);
	return 0;
}
