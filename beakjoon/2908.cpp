#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	int c[3], d[3];
	for (int i = 0; i < 3;i++) {
		c[i] = a % 10;
		d[i] = b % 10;
		a /= 10;
		b /= 10;
	}
	for (int i = 0; i < 3; i++) {
		if (c[i] > d[i]) {
			cout << c[0]<<c[1]<<c[2] << "\n";
			break;
		}
		else if (d[i]>c[i]) {
			cout << d[0]<<d[1]<<d[2] << "\n";
			break;
		}
	}
  return 0;
}
