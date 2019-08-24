#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << v[m - 1] << endl;
	return 0;
}
