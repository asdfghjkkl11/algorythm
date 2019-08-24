#include<iostream>
using namespace std;
int n, a, b;
int main()
{
	do{
		cin >> a >> b;
		if (a != 0 || b != 0)
			cout << a + b << endl;
	} while (a!=0||b!=0);
	return 0;
}
