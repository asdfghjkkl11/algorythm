#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> stack;
	string str;
	int t;
	cin >> t;
	for (int i = 0; i < t;i++) {
		cin >>str;
		if (str == "push") {
			int n;
			cin >> n;
			stack.push_back(n);
		}
		else if (str == "pop")
			if (stack.size() > 0) {
				cout << stack[stack.size()-1] << '\n';
				stack.pop_back();
			}
			else
				cout <<-1 << '\n';
		else if (str =="size")
			cout << stack.size() << '\n';
		else if (str=="empty")
			if (stack.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (str == "top")
			if (stack.size() > 0)
				cout << stack[stack.size() - 1] << '\n';
			else
				cout << -1 << '\n';
	}
}
