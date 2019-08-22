#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int> stack;
int n;
int main()
{
	for (cin >> n; n--;) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int a;
			cin >> a;
			stack.push_front(a);
		}
		else if (str == "push_back") {
			int a;
			cin >> a;
			stack.push_back(a);
		}
		else if (str == "pop_front")
			if (stack.size() == 0)
				cout << -1 << endl;
			else {
				int a = stack.front();
				cout << a << endl;
				stack.pop_front();
			}
		else if (str == "pop_back")
			if (stack.size() == 0)
				cout << -1 << endl;
			else {
				int a = stack.back();
				cout << a << endl;
				stack.pop_back();
			}
		else if (str == "size")
			cout << stack.size() << endl;
		else if (str == "empty")
			if(stack.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		else if (str == "front")
			if (stack.size() == 0)
				cout << -1 << endl;
			else
				cout << stack.front() << endl;
		else if (str == "back")
			if (stack.size() == 0)
				cout << -1 << endl;
			else
				cout << stack.back() << endl;
	}
	return 0;
}
