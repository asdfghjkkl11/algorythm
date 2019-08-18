#include <iostream>
using namespace std;
int A, MAX = -1000000, MIN = 1000000, T;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A;
		MAX = (A > MAX) ? A : MAX;
		MIN = (A < MIN) ? A : MIN;
	}
	cout << MIN << ' ' << MAX << endl;
	return 0;
}
