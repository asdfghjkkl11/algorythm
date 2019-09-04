#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int cathe[15];
int t[15], p[15];
int dp(int num) {
	if (num > n - 1)
		return 0;
	if (cathe[num] != -1)
		return cathe[num];
	int result = 0;
	int sum;
	if(num+t[num]>n)
		sum = dp(num + t[num]);
	else
		sum = p[num] + dp(num + t[num]);
	result = max(dp(num+1),sum);
	return cathe[num] = result;
}
int main()
{
	fill_n(cathe, 15, -1);
	cin >> n;
	for (int i = 0; i < n;  i++) {
		int a, b;
		cin >> t[i] >> p[i];
	}
	int result = dp(0);
	cout << result << endl;
	return 0;
}
