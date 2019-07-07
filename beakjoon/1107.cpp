#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n;
int index[10] = { 0 };
int check(int a) {
	int result;
	int b = a;
	do{
		if (index[a % 10] == 1) {
			result = 500001;
			return result;
		}
		a /= 10;
	} while (a != 0);
	a = b;
	if (b == 0)
		a = 1;
	result = (int)log10(a) + (int)abs(b - m)+1;
	return result;
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		index[a] = 1;
	}
	int move = abs(m - 100);
	for (int i = 0; i < 1000001;i++)
		move = min(move,check(i));
	cout << move << endl;
	return 0;
}
