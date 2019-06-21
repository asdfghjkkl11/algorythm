#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;
deque<int> stack;
queue<int> que;
int n,m;
int main()
{
	cin >> n>>m;
	for (int i = 1; i <= n;i++)
		stack.push_back(i);
	for (int i = 0; i < m;i++) {
		int a;
		cin >> a;
		que.push(a);
	}
	int count = 0;
	while (que.size()!=0) {
		int left=0,right=0;
		int len = stack.size();
		for (int i = 0; i < len;i++) {
			if (stack[i] == que.front()) {
				left = i;
				right = len - i;
			}
		}
		if (left < right) {
			while (stack.front()!=que.front()) {
				int a = stack.front();
				stack.pop_front();
				stack.push_back(a);
				count++;
			}
		}
		else {
			while (stack.front() != que.front()) {
				int a = stack.back();
				stack.pop_back();
				stack.push_front(a);
				count++;
			}
		}
		stack.pop_front();
		que.pop();
	}
	cout << count << endl;
	return 0;
}
