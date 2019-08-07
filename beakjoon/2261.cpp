#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
vector<pair<int, int>>V;
set<pair<int, int>>S;
int N, x, y, result = 1000000000, MAX = 1000000000;
int distance(pair<int, int>a, pair<int, int>b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
pair<int, int> reverse(pair<int, int>a) {
	return { a.second,a.first };
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		V.push_back({ x,y });
	}
	sort(V.begin(), V.end());
	S.insert(reverse(V[0]));
	S.insert(reverse(V[1]));
	result = distance(V[0], V[1]);
	int index = 0;
	for (int i = 2; i < N; i++) {
		while (index < i) {
			if (pow(V[i].first - V[index].first, 2) <= result)
				break;
			else
				S.erase(reverse(V[index])), index++;
		}
		int T = sqrt(result);
		auto end = S.upper_bound({ V[i].second + T,MAX });
		for (auto start = S.lower_bound({ V[i].second - T,-MAX }); start != end; start++)
			result = min(result, distance(*start, reverse(V[i])));
		S.insert(reverse(V[i]));
	}
	cout << result << endl;
	return 0;
}
