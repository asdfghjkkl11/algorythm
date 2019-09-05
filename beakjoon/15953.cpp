#include<iostream>
using namespace std;
int n, a, b;
int A(int a) {
	if (a == 0)
		return 0;
	if (a < 2)
		return 5000000;
	if (a < 4)
		return 3000000;
	if (a < 7)
		return 2000000;
	if (a < 11)
		return 500000;
	if (a < 16)
		return 300000;
	if (a < 22)
		return 100000;
	return 0;
}
int B(int b) {
	if (b == 0)
		return 0;
	if (b < 2)
		return 5120000;
	if (b < 4)
		return 2560000;
	if (b < 8)
		return 1280000;
	if (b < 16)
		return 640000;
	if (b < 32)
		return 320000;
	return 0;
}
int main()
{
	for (cin >> n; n--;) {
		cin >> a >> b;
		cout << A(a) + B(b) << endl;
	}
	return 0;
}
