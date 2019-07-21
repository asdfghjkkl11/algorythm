#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	char str[10001];
	vector<char> v;
	cin >> str;
	bool answer = true;
	int c = 0;
	int axis = 1;
	int toggle = 0;
	v.clear();
	for (int j = 0; j < strlen(str); j++) {
		if (str[j] == '(' || str[j] == '[') {
			v.push_back(str[j]);
			if (toggle == 0)
				toggle = 1;
			if (str[j] == '(')
				axis *= 2;
			else
				axis *= 3;
		}
		else {
			if (str[j] == ')' || str[j] == ']') {
				int size = v.size() - 1;
				if (size<0) {
					answer = false;
					break;
				}
				if (str[j] - v[size] == 2 || str[j] - v[size] == 1) {
					v.pop_back();
					if (toggle == 1) {
						c += toggle*axis;
						toggle = 0;
					}
					if (str[j] == ')')
						axis /= 2;
					else
						axis /= 3;
				}
				else {
					answer = false;
					break;
				}
			}
		}
	}
	if (v.size() > 0)
		answer = false;
	if (answer == true)
		cout << c << "\n";
	else
		cout << 0 << "\n";
}
