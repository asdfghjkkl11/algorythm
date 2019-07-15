#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	char day[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT","SUN" };
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int a,b;
	cin >> a>>b;
	int c = 0;
	for (int i = 1; i < a;i++)
		c = c + month[i-1];
	c = c + b - 1;
	cout << day[c % 7] << endl;
	return 0;
}
