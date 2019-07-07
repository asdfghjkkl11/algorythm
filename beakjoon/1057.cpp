#include <iostream>
#include <algorithm>
using namespace std;
int t,n,m;
int main()
{
	cin >> t>>n>>m;
	int count = 0;
	while (n!=m) {
		if (n % 2 == 1)
			n++;
		if (m % 2 == 1)
			m++;
		n /= 2;
		m /= 2;
		count++;
	}
	cout << count << endl;
	return 0;
}
