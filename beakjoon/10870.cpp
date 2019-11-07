#include <iostream>
using namespace std;
long long arr[21] = {0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
long long dp(int a) {
	if (arr[a] != -1)
		return arr[a];
	return dp(a - 1) + dp(a - 2);
}
int main()
{
	int N;
	cin >> N;
	cout << dp(N) << endl;
	return 0;
}
