#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, a[50], b[50];
	cin >> n;
	for (int i = 0; i<n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	for (int i = 0; i<n; i++) {
		int x;
		cin >> x;
		b[i] = x;
	}
	sort(a, a + n);
	sort(b, b + n);
	int sum = 0;
	for (int i = 0; i<n; i++) {	
		sum += a[i] * b[n - 1 - i];
	}
	cout << sum << endl;
}
