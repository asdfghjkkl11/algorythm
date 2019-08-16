#include <iostream>
#include <vector>
using namespace std;
int N, a;
long long result = 0;
vector<int>v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 0)
			v.pop_back();
		else
			v.push_back(a);
	}
	for (int i = 0; i < v.size(); i++)
		result += v[i];
	cout << result << endl;
	return 0;
}
