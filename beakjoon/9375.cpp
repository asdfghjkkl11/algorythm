#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int t;
string kinds[30];
int n;
int main()
{
	string s;
	for (cin >> t; t--;) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> kinds[i];
		}
		sort(kinds, kinds + n);
		int kind = 1;
		int count = 0;
		vector<int> v;
		if (n != 0)
			count = 1;
		for (int i = 1; i < n; i++) {
			if (kinds[i] != kinds[i - 1]) {
				kind++;
				v.push_back(count);
				count = 1;
			}
			else
				count++;
		}
		v.push_back(count);
		int result = 1;
		for (int i = 0; i < v.size(); i++) {
			result *= v[i] + 1;
		}
		cout << result - 1 << endl;
	}
	return 0;
}
