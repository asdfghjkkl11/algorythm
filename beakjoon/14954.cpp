#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,Count=0;
int cathe[1000];
int makenum(int n) {
	int sum = 0;
	while (n != 0) {
		int a = n % 10;
		n /= 10;
		a *= a;
		sum += a;
	}
	return sum;
}
int main() {
	cin >> n;
	for (int i = 0; i < 1000;i++) {
		cathe[i] = -1;
	}
	if (n < 1000)
		cathe[n] = Count;
	Count++;
	int result = -1;
	int b = n;
	while (true) {
		int a = makenum(b);
		if (a == 1)
			break;
		if (cathe[a] == -1)
			cathe[a] = Count;
		else {
			result = Count - cathe[a];
			break;
		}
		
		Count++;
		b = a;
	}
	if (result == -1)
		cout << "HAPPY" << endl;
	else
		cout << "UNHAPPY" << endl;
	return 0;
}
