#include <iostream>
#include <vector>
using namespace std;
int cnt[10001] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int j;
		cin >> j;
		cnt[j]++;
	}
	for (int i = 0; i < 10001;i++) {
		while (cnt[i]!=0) {
			cout << i<<'\n';
			cnt[i]--;
		}
	}
}
