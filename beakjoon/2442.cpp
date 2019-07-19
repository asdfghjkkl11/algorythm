#include<iostream>
#include<deque>
using namespace std;
int n;
deque<char> q;
int main()
{
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		q.push_back(' ');
	}
	q.push_back('*');
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < q.size(); j++) {
			cout << q[j];
		}
		cout << endl;
		q.pop_front();
		q.push_back('*');
		q.push_back('*');
	}
	return 0;
}
