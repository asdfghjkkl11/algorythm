#include <iostream>
#include <vector>
using namespace std;
int cnt[8001] = { 0 };
int main()
{
	int t;
	int max = -4001;
	int min = 4001;
	int mid = -1;
	vector<int> maxi;
	double sum = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int j;
		cin >> j;
		cnt[j + 4000]++;
		if (j < min)
			min = j;
		if (j > max)
			max = j;
	}
	for (int i = 0; i < 8001; i++) {
		sum += cnt[i] * (i - 4000);
		if (i == 0)
			maxi.push_back(i);
		else {
			if (maxi[0] != 0) {
				if (cnt[i] > cnt[maxi[0]] - cnt[maxi[0] - 1]) {
					maxi.clear();
					maxi.push_back(i);
				}
				else if (cnt[i] == cnt[maxi[0]] - cnt[maxi[0] - 1])
					maxi.push_back(i);
			}
			else {
				if (cnt[i] > cnt[maxi[0]]) {
					maxi.clear();
					maxi.push_back(i);
				}
				else if (cnt[i] == cnt[maxi[0]])
					maxi.push_back(i);
			}
			cnt[i] += cnt[i - 1];
			if (cnt[i] > t / 2 && mid == -1)
				mid = i;
		}
	}
	int r[4];
	sum /= t;
	
	int mod = (int)(sum * 10) % 10;
	if (mod > 4)
		r[0] = (int)sum + 1;
	else if(mod<-4){
		r[0] = (int)sum - 1;
	else
		r[0] = (int)sum;
	r[1] = mid - 4000;
	if (maxi.size() > 1)
		r[2] = maxi[1]-4000;
	else
		r[2] = maxi[0]-4000;
	r[3] = max - min;
	for (int i = 0; i < 4;i++)
		cout <<r[i] <<'\n';
}
