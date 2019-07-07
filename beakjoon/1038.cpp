#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<long long int>v;
void dp(long long int n) {
	int a = n % 10;
	for (int i = 0; i < a;i++) {
		long long int b = n * 10;
		b += i;
		v.push_back(b);
		dp(b);
	}
}
int main()
{
	cin >> n;
	n;
	for (int i = 0; i < 10;i++) {
		v.push_back(i);
		dp(i);
	}
	sort(v.begin(), v.end());
	if (n >= v.size())
		cout << -1 << endl;
	else
		cout << v[n] << endl;
	return 0;
}
