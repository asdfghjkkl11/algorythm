#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
vector<int> v[5];
deque<pair<int, int>>deq;
int N,a,b;
int main() {
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> a>>b;
		deq.push_back(make_pair(a, b));
	}
	while (deq[0].first != deq[2].first || deq[1].first != deq[3].first) {
		deq.push_back(deq.front());
		deq.pop_front();
	}
	for (int i = 0; i < 6; i++)
		v[deq[i].first].push_back(deq[i].second);
	int area = 1;
	int index = 0;
	for (int i = 1; i < 5; i++)
		if (v[i].size() == 1)
			area *= v[i][0];
		else
			index += i*i;
	switch (index) {
	case 10:
		area -= v[1][0] * v[3][1];
		break;
	case 13:
		area -= v[2][1] * v[3][0];
		break;
	case 17:
		area -= v[1][1] * v[4][0];
		break;
	case 20:
		area -= v[2][0] * v[4][1];
		break;
	}
	cout << area*N << endl;
	return 0;
}
