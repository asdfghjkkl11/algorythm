#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t,n,k,goal;
int cost[1001];
int MAX[1001];
int ten[1001];
int index;
queue<int> list;
vector<int> mat[1001];
void find() {
	if (list.size() == 0)
		return;
	for (int i = 0; i < list.size();i++) {
		int a = list.front();
		list.pop();
		for (int j = 0; j < mat[a].size();j++) {
			if (MAX[mat[a][j]] < MAX[a] + cost[a]) {
				MAX[mat[a][j]] = MAX[a] + cost[a];
				list.push(mat[a][j]);
			}
		}
	}
	find();
}
int main() {
	cin >> t;
	for (int c = 0; c < t; c++) {
		cin >> n >> k;
		for (int i = 0; i <= n; i++) {
			mat[i].clear();
			ten[i] = 0;
			MAX[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			cin >> cost[i];
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			mat[x].push_back(y);
			ten[y]++;
		}
		cin >> goal;
		for (int i = 1; i <= n; i++) {
			if (ten[i] == 0) {
				list.push(i);
			}
		}
		find();
		cout << MAX[goal] + cost[goal] << endl;
	}
	return 0;
}
