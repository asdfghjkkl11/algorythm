#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int N[10] = {0};
	cin >> a;
	cin >> b;
	cin >> c;
	int sum = a*b*c;
	while (sum != 0) {
		N[sum % 10]++;
		sum /= 10;
	}
	for (int i = 0; i < 10;i++) {
		cout << N[i]<<"\n";
	}
	return 0;
}
