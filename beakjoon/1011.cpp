#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t;i++) {
		int a, b;
		cin >> a >> b;
		int distance = b - a;
		int count = 0;
		while (distance>0) {
			int k = (count / 2) + 1;
			distance -= k;
			count++;
		}
		cout << count << "\n";
	}
}
