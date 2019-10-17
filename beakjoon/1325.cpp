#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M,A,B,index=0;
vector<int>V[10000], result;
bool visit[10000];
int dfs(int a) {
	visit[a] = false;
	if (V[a].size() == 0)
		return 1;
	int ret = 1;
	for (int i = 0; i < V[a].size(); i++) {
		if(visit[V[a][i]])
			ret += dfs(V[a][i]);
	}
	return ret;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M;i++) {
		cin >> A >> B;
		V[B - 1].push_back(A - 1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit[j] = true;
		int t = dfs(i);
		if (index < t) {
			index = t;
			result.clear();
			result.push_back(i);
		}
		else if (index == t){
			result.push_back(i);
		}
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i]+1 << ' ';
	cout << endl;
	return 0;
}
