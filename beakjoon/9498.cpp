#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a > 89) {
		cout << "A\n";
		return 0;
	}
	if (a>79) {
		cout << "B\n";
		return 0;
	}
	if (a>69) {
		cout << "C\n";
		return 0;
	}
	if (a>59) {
		cout << "D\n";
		return 0;
	}
	cout << "F\n";
	return 0;
}
