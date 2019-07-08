#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int num[10] = {0};
	if (t == 0)
		num[0]++;
	while (t != 0) {
		int n = t % 10;
		num[n]++;
		t /= 10;
	}
	for (int i = 9; i >=0;i--) {
		while (num[i] != 0) {
			cout << i;
			num[i]--;
		}
	}
	cout << '\n';
}
