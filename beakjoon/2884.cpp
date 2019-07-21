#include <iostream>
using namespace std;
int A, B;
int main() {
	cin >> A >> B;
	A += 24;
	B += 15;
	if (B < 60)
		A--;
	A %= 24;
	B %= 60;
	cout << A << ' ' << B << endl;
	return 0;
}
