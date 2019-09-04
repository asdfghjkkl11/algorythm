#include <iostream>
using namespace std;
int main() {
	char c[101];
	cin >> c;
	int i = 0;
	while (c[i]!=0) {
		cout << c[i];
		i++;
		if(i%10==0)
		cout << endl;
	}
	return 0;
}
