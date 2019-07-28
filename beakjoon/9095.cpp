#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, t;
int cathe[12] = { 0,1,2,4,7,-1,-1,-1,-1,-1,-1,-1 };
int dp(int num) {
	if (cathe[num] != -1)
		return cathe[num];
	int result = 0;
	for (int i = 1; i < 4;i++) {
		if (num - i >= 0)
			result += dp(num - i);
	}
	return result;
}
int main()
{
	for (cin >> t;t; t--) {
		cin >> n;
		int result = dp(n);
		cout << result << endl;
	}
	return 0;
}
