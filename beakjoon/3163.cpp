#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int t, n, m, s;
deque<pair<int, int>> que;
deque<int> que2;
int main() {
	for (cin >> t; t--;) {
		que.clear();
		que2.clear();
		cin >> n >> m >> s;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (b > 0)
				a = m - a;
			que.push_back(make_pair(a, b));
		}
		for (int i = 0; i < n; i++)
			if (que[i].second < 0)
				que2.push_back(que[i].first);
		for (int i = 0; i < n; i++)
			if (que[i].second > 0)
				que2.push_back(que[i].first);
		for (int i = 0; i < n; i++)
			que[i].first = que2[i];
		sort(que.begin(),que.end());
		cout << que[s - 1].second << endl;
	}
	return 0;
}
