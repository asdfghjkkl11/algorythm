#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> cost, sec;
vector<int> MAX;
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n;
		MAX.clear();
		int c = cost.size();
		if (c>0)
			for (int j = 0; j < c; j++) {
				cost.pop();
				sec.pop();
			}
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			cost.push(a);
			sec.push(j);
			MAX.push_back(a);
		}
		sort(MAX.begin(), MAX.end());
		int count = 0;
		while (MAX.size() != 0) {
			int a = cost.front();
			int s = sec.front();
			if (a != MAX[MAX.size() - 1]) {
				cost.pop();
				sec.pop();
				cost.push(a);
				sec.push(s);
			}
			else {
				if (s == m) {
					cost.pop();
					sec.pop();
					MAX.pop_back();
					count++;
					break;
				}
				else {
					cost.pop();
					sec.pop();
					MAX.pop_back();
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
