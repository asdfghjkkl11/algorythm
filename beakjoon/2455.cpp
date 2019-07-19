#include <iostream>
#include <algorithm>
using namespace std;
int n[4], m[4], r[4];
int main()
{
	for (int i = 0; i < 4;i++) {
		cin >> n[i] >> m[i];
		r[i] = m[i] - n[i];
		if (i != 0)
			r[i] += r[i - 1];
	}
	cout << max(max(r[0],r[1]),max(r[2],r[3])) << endl;
	return 0;
}
