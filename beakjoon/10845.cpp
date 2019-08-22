#include <iostream>
#include <vector>
#include <string>
using namespace std
int main()
{
	vector<int> queue;
	string str;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			queue.push_back(n);
		}
		else if (str == "pop")
			if (queue.size() > 0) {
				cout << queue[0] << '\n';
				queue.erase(queue.begin());
			}
			else
				cout << -1 << '\n';
		else if (str == "size")
			cout << queue.size() << '\n';
		else if (str == "empty")
			if (queue.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (str == "front")
			if (queue.size() > 0)
				cout << queue[0] << '\n';
			else
				cout << -1 << '\n';
		else if (str == "back")
			if (queue.size() > 0)
				cout << queue[queue.size() - 1] << '\n';
			else
				cout << -1 << '\n';
	}
}
