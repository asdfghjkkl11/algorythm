#include <iostream>
#include <algorithm>
using namespace std;
int n;
int num[100];
int gcd(int a,int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;
		num[i] = a;
	}
	for (int i = 1; i < n;i++) {
		int g = gcd(max(num[0], num[i]), min(num[0], num[i]));
		cout << num[0] / g;
		cout << '/';
		cout <<num[i] / g << endl;
	}
	return 0;
}
