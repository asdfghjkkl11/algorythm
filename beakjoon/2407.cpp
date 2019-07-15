#include <iostream>
#include <cmath>
#define mod 1000000000000000
using namespace std;
long long int cathe1[101][101] = { 0 };
long long int cathe2[101][101] = { 0 };
int n, k;
pair<long long int, long long int> bin(int a, int b) {
	if (cathe1[a][b] != 0 || cathe2[a][b] != 0)
		return make_pair(cathe1[a][b], cathe2[a][b]);
	if (b == 0 || b == a)
		return make_pair(0,1);
	pair<long long int, long long int> c = bin(a - 1, b - 1), d = bin(a - 1, b);
	cathe1[a][b] = c.first + d.first;
	cathe2[a][b] = c.second + d.second;
	if (cathe2[a][b] > mod) {
		cathe2[a][b] %= mod;
		cathe1[a][b]++;
	}
	return make_pair(cathe1[a][b], cathe2[a][b]);
}
int main()
{
	cin >> n >> k;
	pair<long long int, long long int> result = bin(n,k);
	int t = log10(cathe2[n][k]);
	if (cathe1[n][k] != 0)
		cout << cathe1[n][k];
	if(cathe1[n][k] != 0)
		for (int i = 0; i < 14 - t;i++)
			cout << 0;
	cout << cathe2[n][k] << endl;
	return 0;
}
