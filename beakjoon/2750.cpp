#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int num[2001] = {0};
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		num[1000+a]++;
	}
	for (int i = 0; i < 2001;i++) {
		if (num[i] != 0)
			cout << i-1000 << "\n";
	}
}
