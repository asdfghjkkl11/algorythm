#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int A, B, C;
int main() {
	while (1) {
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0)
			break;
		int M = max(max(A, B), C);
		if (pow(M, 2) * 2 == pow(A, 2) + pow(B, 2) + pow(C, 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}
