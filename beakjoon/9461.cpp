#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t;
long long tri[100] = {1,1,1,2,2,3,4,5,7,9,12};
int main()
{
	for (int i = 11; i < 100;i++) {
		tri[i] = tri[i - 2] + tri[i - 3];
	}
	for (cin >> t; t--;) {
		cin >> n;
		cout << tri[n-1]<< endl;
	}
	return 0;
}
