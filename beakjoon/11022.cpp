#include <iostream>
using namespace std;
int A, B, T;
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B;
		cout <<"Case #"<<i<<": " << A << " + " << B << " = " << A+B << endl;
	}
	return 0;
}
