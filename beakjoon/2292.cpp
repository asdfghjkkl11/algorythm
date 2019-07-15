#include <iostream>
using namespace std;
int main()
{
	int a, sum =1, i = 0;
	cin >> a;
	while (sum < a) {
		sum += 6 * i;
		i++;
	}
	if (a == 1)
		i=1;
	cout << i << "\n";
}
