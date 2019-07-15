#include <iostream>
#include <algorithm>
using namespace std;
int num[9], a, sum = 0;
bool tf[9] = { 0 },t=false;
int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> a;
		num[i] = a;
		sum += a;
	}
	sort(num, num + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) {}
			else {
				if (sum - (num[i] + num[j]) == 100) {
					tf[i] = true;
					tf[j] = true;
					t = true;
				}
			}
			if (t)
				break;
		}
		if (t)
			break;
	}
	for (int i = 0; i < 9; i++)
		if (tf[i] == false)
			cout << num[i] << endl;
	return 0;
}
