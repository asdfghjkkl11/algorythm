#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int num[100];
vector<int> find(int a) {
	vector<int>v;
	int i;
	for (i = 1; i*i < a; i++)
		if (a%i == 0) {
			if (i != 1)
				v.push_back(i);
			v.push_back(a / i);
		}
	if(i*i==a)
		v.push_back(i);
	sort(v.begin(), v.end());
	return v;
}
int main()
{
	cin >> n;
	int mi = 1000000001, ma = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[i] = a;
		mi = min(mi, a);
		ma = max(ma, a);
	}
	vector<int> v = find(ma - mi);
	for (int i = 0; i < v.size();i++) {
		int mod = num[0] % v[i];
		bool tf = true;
		for (int j = 1; j < n; j++)
			if (mod != num[j] % v[i]) {
				tf = false;
				break;
			}
		if(tf)
			cout << v[i] << ' ';
	}
	cout << endl;
	return 0;
}
