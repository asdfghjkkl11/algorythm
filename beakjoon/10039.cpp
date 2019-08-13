#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int C[5];
	int sum = 0;
	for (int i = 0; i < 5;i++) {
		cin >> C[i];
		if (C[i] < 40)
			C[i] = 40;
		sum += C[i];
	}
	sum /= 5;
	cout << sum << "\n";
	return 0;
}
