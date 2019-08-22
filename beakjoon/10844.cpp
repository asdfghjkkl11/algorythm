#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long cathe[100][10] = {0};
int main()
{
	cin >> n;
	cathe[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		cathe[0][i] = 1;
	}
	for (int i = 1; i < n;i++) {
		for (int j = 0; j < 10;j++) {
			if(j-1>=0)
				cathe[i][j] += cathe[i - 1][j - 1] % 1000000000;
			if(j+1<10)
				cathe[i][j] += cathe[i - 1][j + 1] % 1000000000;
		}
	}
	long long result=0;
	for (int i = 0; i < 10;i++) {
		result += cathe[n - 1][i] % 1000000000;
		result %= 1000000000;
	}
	cout << result << "\n";
	return 0;
}
