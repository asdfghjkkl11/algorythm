#include <iostream>
using namespace std;
int n, k;
int bin(int a,int b) {
	if (b == 0 || b == a)
		return 1;
	return bin(a - 1, b - 1) + bin(a - 1, b);
}
int main()
{
	cin >> n >> k;
	cout << bin(n, k)<<endl;
	return 0;
}
