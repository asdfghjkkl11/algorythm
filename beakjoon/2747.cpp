#include <iostream>
using namespace std;
int n;
int fiv[3];
int main()
{
	int count = 3;
	fiv[0] = 0;
	fiv[1] = 1;
	fiv[2] = 1;
	cin >> n;
	if (n <= 2)
		cout << fiv[n] << endl;
	else {
		while (count <= n) {
			fiv[0] = fiv[1];
			fiv[1] = fiv[2];
			fiv[2] = fiv[0] + fiv[1];
			count++;
		}
		cout << fiv[2] << endl;
	}
	return 0;
}
