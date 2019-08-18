#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> V[201];
int N, num;
string str;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num >> str;
		V[num].push_back(str);
	}
	for (int i = 0; i < 201; i++)
		for (int j = 0; j < V[i].size(); j++)
			cout << i << ' ' << V[i][j] << '\n';
	return 0;
}
