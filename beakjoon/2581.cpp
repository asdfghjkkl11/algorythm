#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int num[10001];
int main()
{
	for (int i = 0; i < 10001; i++) {
		num[i] = 1;
	}
	num[0] = 0, num[1] = 0;
	for (int i = 2; i < 10001; i++) {
		if (num[i] == 1) {
			for (int j = i * 2; j < 10001; j += i) {
				num[j] = 0;
			}
		}
	}
	int count = 0;
	int min = 0;
	cin >> n >> m;
	for (int i = n; i <= m;i++) {
		if (num[i] == 1) {
			if (min == 0)
				min = i;
			count += i;
		}
	}
	if (min == 0)
		cout << -1 << endl;
	else
		cout << count<<endl<< min << endl;
	return 0;
}
