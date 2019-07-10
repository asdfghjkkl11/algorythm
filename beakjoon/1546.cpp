#include <iostream>
using namespace std;
int main() {
	int n;
	float sum = 0, a[1000], max = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i] * 100 / max ;
		sum += a[i];
	}
	sum /= n;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << sum << "\n";
	return 0;
}
