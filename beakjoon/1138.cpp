#include <iostream>
#include <vector>
using namespace std;
vector<int> V;
int N, arr[10];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = N - 1; i >= 0; i--)
		V.insert(V.begin()+arr[i],i+1);
	for (int i = 0; i < N; i++)
		cout << V[i] << ' ';
	return 0;
}
