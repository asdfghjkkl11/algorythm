#include <iostream>
using namespace std;
bool* str1;
bool* str2;
int a, b;
void star(int c) {
	str2 = new bool[b];
	if (c == 0)
		for (int i = 0; i < b; i++)
			if (i == a - 1)
				str2[i] = true;
			else
				str2[i] = false;
	else if (c == a)
		return;
	else {
		for (int i = 0; i < b; i++)
			str2[i] = false;
		for (int i = 0; i < b; i++) {
			if (i >= a - 1 - c&&i <= a - 1 + c) {
				if (c % 3 == 0)
					if (str1[i] == false && (str1[i - 1] ^ str1[i + 1]))
						str2[i] = true;
				if (c % 3 == 1)
					if (str1[i] == true)
						str2[i - 1] = str2[i + 1] = true;
				if (c % 3 == 2)
					if (str1[i] == true)
						str2[i - 1] = str2[i] = str2[i + 1] = true;
			}
		}
	}
	for (int i = 0; i < b;i++) {
		if (str2[i] == true)
			cout << '*';
		else
			cout << ' ';
		str1[i] = str2[i];
	}
	cout << '\n';
	star(++c);
}
int main() {
	cin >> a;
	b = (a * 2) - 1;
	str1 = new bool[b];
	star(0);
	return 0;
}
