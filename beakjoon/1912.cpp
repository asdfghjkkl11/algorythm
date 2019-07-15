#include <iostream>
#include <algorithm>
using namespace std;
int n, result = -1001;
int sum = -1001, num = -1001;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum = max(num, sum + num);
		result = max(result, sum);
	}
	cout << result << endl;
	return 0;
}
