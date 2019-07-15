#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, A, B;
pair<int, int>task[100000];
vector<pair<int, int>>V;
bool compare(pair<int, int>a, pair<int, int>b) {
	return (a.first == b.first) ? (a.second < b.second) ? true : false : (a.first < b.first) ? true : false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		task[i] = make_pair(A,B);
	}
	stable_sort(task,task+N,compare);
	V.push_back(task[0]);
	for (int i = 1; i < N;i++) {
		pair<int, int>back = V.back();
		if (back.second <= task[i].first)
			V.push_back(task[i]);
		else if (back.second > task[i].second) {
			V.pop_back();
			V.push_back(task[i]);
		}
	}
	cout << V.size() << endl;
	return 0;
}
