#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int i=0;
	while (a > i) {
		a -= i;
		i++;
	}
	if (i % 2 == 0)
		cout << a << '/' << i + 1 - a << "\n";
	else
		cout << i + 1 - a << '/' << a << "\n";
}
