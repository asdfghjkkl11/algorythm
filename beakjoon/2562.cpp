#include <iostream>
using namespace std;
int A, MAX = -1, MIN = 0;
int main() {
	for (int i = 1; i <= 9; i++) {
		cin >> A;
		if (A > MAX) {
			MAX = A;
			MIN = i;
		}
	}
	cout << MAX << endl << MIN << endl;
	return 0;
}
