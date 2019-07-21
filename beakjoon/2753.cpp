#include <iostream>
using namespace std;
int A, B;
int main() {
	cin >> A;
	if (A % 4 == 0)
		if (A % 100 == 0)
			if (A % 400 == 0)
				B = 1;
			else
				B = 0;
		else
			B = 1;
	else
		B = 0;
	cout << B << endl;
	return 0;
}
