#include<iostream>
#include<vector>
using namespace std;
int n, a, b;
vector<int>cache[10];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a %= 10;
		if (cache[a].size() == 0) {
			int t = a;
			do {
				cache[a].push_back(t);
				t *= a;
				t %= 10;
			} while (t != a);
		}
		int result = cache[a][(b - 1) % cache[a].size()];
		if(result==0)
			cout << 10 << endl;
		else
			cout << result << endl;
	}
	return 0;
}
