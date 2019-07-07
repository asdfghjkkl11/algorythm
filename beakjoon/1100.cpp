#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int sum = 0;
	char c;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			if ((i % 2) ^ (j % 2) == 0 && c == 'F')
				sum++;
		}
	}
	cout << sum << endl;
}
