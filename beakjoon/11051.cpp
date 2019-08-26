#include <iostream>
using namespace std;
int cathe[1000][1001] = { 0 };
int n, k;
int bin(int a, int b) {
	if (cathe[a][b] != 0)
		return cathe[a][b];
	if (b == 0 || b == a)
		return 1;
	return cathe[a][b] = (bin(a - 1, b - 1) + bin(a - 1, b)) % 10007;
}
int main()
{
	cin >> n >> k;
	cout << bin(n, k) << endl;
	return 0;
}
