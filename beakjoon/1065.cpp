#include <iostream>
using namespace std;
int d(int a) {
	int b[4],i=0;
	int c = a;
	while (c!=0) {
		b[i] = c % 10;
		c /= 10;
		i++;
	}
	for (int j = 0; j < i - 2;j++)
		if (b[j + 1] - b[j] != b[j + 2] - b[j + 1])
			return 0;
	return 1;
}
int main() {
	int a,c=0;
	cin >> a;
	for (int i = 1; i <= a;i++)
		if (i < 100)
			c++;
		else
			c = c + d(i);
	cout << c << "\n";
	return 0;
}
