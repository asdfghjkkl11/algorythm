#include<iostream>
#include<string>
using namespace std;
string s,t="";
int main()
{
	cin >> s;
	t += s[0];
	for (int i = 0; i < s.length();i++) {
		if (s[i] == '-')
			t += s[i + 1];
	}
	cout << t << endl;
	return 0;
}
