#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> V;
int N, n1,n2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		V.push_back(make_pair(n1,n2));
	}
	sort(V.begin(),V.end());
	for (int i = 0; i < N; i++)
		cout << V[i].first << ' ' << V[i].second << '\n';
	return 0;
}
