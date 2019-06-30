#include <iostream>
using namespace std;
int n, l;
int main()
{
	cin >> n >> l;
	int sum = 0;
	int i;
	for (i = 0; i < l; i++)
		sum += i;
	int start = -1;
	for (i = l; i < 101;i++) {
		int a = n - sum;
		if (a%i == 0) {
			start = a / i;
			break;
		}
		sum += i;
	}
	if (start <0 || i == 101)
		cout << -1 << endl;
	else {
		for (int j = 0; j < i;j++)
			cout << start+j << ' ';
		cout << endl;
	}
	return 0;
}
