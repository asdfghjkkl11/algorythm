#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
struct comp {
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<2>(a)>get<2>(b);
	}
};
vector<pair<int, int>> v[10000];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> pq;
int check[10000] = { 0 };
int N, M, A, B, C,result=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A-1].push_back({ B-1,C });
		v[B-1].push_back({ A-1,C });
	}
	int start = 0;
	for (int i = 1; i < N; i++) {
		int leng = v[start].size();
		for (int j = 0; j < leng; j++) {
			pq.push({ start,v[start][j].first,v[start][j].second });
		}
		while (check[get<0>(pq.top())] * check[get<1>(pq.top())]) {
			pq.pop();
		}
		check[get<0>(pq.top())] = check[get<1>(pq.top())] = 1;
		result += get<2>(pq.top());
		start = get<1>(pq.top());
		pq.pop();
	}
	cout << result << endl;
	return 0;
}
