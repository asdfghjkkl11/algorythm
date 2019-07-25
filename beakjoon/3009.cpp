#include <iostream>
using namespace std;
int A, B, C=0, D=0;
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> A >> B;
		C = C ^ A;
		D = D ^ B;
	}
	cout << C << ' ' << D << endl;
	return 0;
}
