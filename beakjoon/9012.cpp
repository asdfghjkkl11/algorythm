#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	char str[10001];
	vector<char> v;
	for (int i = 0; i < t; i++) {
		cin >> str;
		bool answer = true;
		v.clear();
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '(') {
				v.push_back(str[j]);
			}
			else {
				if (str[j] == ')') {
					int size = v.size() - 1;
					if (size<0) {
						answer = false;
						break;
					}
					if (v[size] == '(')
						v.pop_back();
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
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
