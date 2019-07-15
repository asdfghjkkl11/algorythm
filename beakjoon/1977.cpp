#include <iostream>
#include <vector>
using namespace std;
int n,m;
int num[101];
vector<int> v;
int main()
{
	for (int i = 0; i < 101;i++)
		num[i] = i*i;
	cin >> n >> m;
	for (int i = 0; i < 101; i++)
		if (num[i] >= n&&num[i] <= m)
			v.push_back(num[i]);
	if (v.size() == 0)
		cout << -1 << endl;
	else {
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
			sum += v[i];
		cout << sum << endl;
		cout << v[0] << endl;
	}
	return 0;
}
