#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M,result=100000000,t;
vector<pair<int, int>>C, H;
int distance(pair<int,int> a, pair<int,int> b) {
	return abs(a.first-b.first) + abs(a.second-b.second);
}
void dfs(int a,vector<int>&v) {
	if (v.size() == M) {
		int c = 0;
		vector<int>R(H.size(),100);
		for (int i = 0; i < v.size();i++)
			for (int j = 0; j < H.size();j++)
				R[j] = min(R[j], distance(C[v[i]],H[j]));
		for (int j = 0; j < H.size(); j++)
			c += R[j];
		if (c < result)
			result = c;
		return;
	}
	if (a == C.size())
		return;
	for (int i = a; i < C.size();i++) {
		v.push_back(i);
		dfs(i+1,v);
		v.pop_back();
	}
}
int main() {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> t;
				if (t == 1)
					H.push_back({i,j});
				if (t == 2)
					C.push_back({i,j});
			}
		vector<int>v;
		dfs(0,v);
		cout << result << endl;
	return 0;
}
