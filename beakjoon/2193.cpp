#include<iostream>
using namespace std;
int n;
long long cathe[91];
long long dp(long long num) {
	if (cathe[num] != -1)
		return cathe[num];
	long long result = 0;
	for (int i = num-2; i>=0; i--)
		result += dp(i);
	return cathe[num] = result;
}
int main()
{
	fill_n(cathe, 91, -1);
	cathe[0] = cathe[1] = cathe[2] = 1;
	cin >> n;
	long long result = dp(n);
	cout << result << endl;
	return 0;
}
