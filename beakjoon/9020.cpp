#include <iostream>
using namespace std;
int n, t;
int num[10001];
int main()
{
	for (int i = 0; i < 10001; i++)
		num[i] = 1;
	num[0] = 0, num[1] = 0;
	for (int i = 2; i < 10001; i++)
		if (num[i] == 1)
			for (int j = i * 2; j < 10001; j += i)
				num[j] = 0;
	for (cin >> t; t--;) {
		cin >> n;
		int a = n / 2;
		int b = n - a;
		while (num[a]!=1||num[b]!=1) {
			b++;
			a--;
		}
		cout << a << ' ' << b << endl;
	}
	return 0;
}
