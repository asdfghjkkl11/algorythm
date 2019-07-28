#include<iostream>
using namespace std;
int i,n;
int main() {
	cin >> n;
	for (i = 0; i < n; i++)
		cout << 1;
	for (i = 0; i < n - 1; i++)
		cout << 0;
	return 0;
}
