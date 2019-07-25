#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int C[8];
	int d;
	for (int i = 0; i < 8;i++) {
		cin >> C[i];
	}
	d = C[1] - C[0];
	bool c = true;
	for (int i = 2; i < 8;i++) {
		if (C[i] - C[i - 1] != d) {
			c = false;
			break;
		}
	}
	if (c == false)
		cout << "mixed\n";
	else {
		if (d == 1)
			cout << "ascending\n";
		else
			cout << "descending\n";
	}
	return 0;
}
