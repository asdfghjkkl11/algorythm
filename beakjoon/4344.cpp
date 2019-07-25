#include <iostream>
using namespace std;
int main() {
	int n,a,c;
	float b[1000];
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> a;
		float sum = 0;
		for (int j = 0; j< a; j++) {
			cin >> b[j];
			sum += b[j];
		}
		sum /= a;
		c = 0;
		for (int j = 0; j< a; j++) {
			if (b[j] > sum)
				c++;
		}
		float result = (float)c / a*100;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << result << "%\n";
	}
	return 0;
}
