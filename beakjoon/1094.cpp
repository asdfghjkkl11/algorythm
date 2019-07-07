#include <iostream>
#include <algorithm>
using namespace std;
int m;
int main()
{
	cin >> m;
	int count = 0;
	while (m != 0) {
		count += m % 2;
		m /= 2;
	}
	cout << count << endl;
	return 0;
}
