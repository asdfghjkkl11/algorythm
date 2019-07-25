#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;
deque<int> que;
string str;
int n, t,toggle;
int main()
{
	for (cin >> t; t--;) {
		toggle = 1;
		que.clear();
		cin.ignore();
		cin >> str;
		cin >> n;
		char c=' ';
		for (int i = 0; i < n; i++) {
			int a;
			cin >> c >> a;
			que.push_back(a);
		}
		cin >> c;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'R') {
				if (toggle == 1)
					toggle = 2;
				else if (toggle == 2)
					toggle = 1;
			}
			else if (str[i] == 'D') {
				if (que.size() == 0)
					toggle = 0;
				else if(toggle==1)
					que.pop_front();
				else if (toggle == 2)
					que.pop_back();
			}
		}
		if (toggle == 1) {
			cout << '[';
			for (int i = 0; i < que.size(); i++) {
				cout << que[i];
				if (i != que.size() - 1)
					cout << ',';
			}
			cout << ']';
		}
		else if (toggle == 2) {
			cout << '[';
			for (int i = que.size()-1; i >=0; i--) {
				cout << que[i];
				if (i != 0)
					cout << ',';
			}
			cout << ']';
		}
		else
			cout << "error";
		cout << endl;
	}
	return 0;
}
