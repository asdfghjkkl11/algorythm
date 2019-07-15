#include <iostream>
#include <algorithm>
using namespace std;
int n;
int num[1001];
int main()
{
	for (int i = 0; i < 1001; i++)
		num[i] = 1;
	num[0] = 0, num[1] = 0;
	for (int i = 2; i < 1001; i++)
		if (num[i] == 1)
			for (int j = i * 2; j < 1001; j += i)
				num[j] = 0;
	int count = 0;
	for (cin >> n; n--;) {
		int a;
		cin >> a;
		if (num[a] == 1)
			count++;
	}
	cout << count << endl;
	return 0;
}
