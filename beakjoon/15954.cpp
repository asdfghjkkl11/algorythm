#include<iostream>
#include<cmath>
using namespace std; \
long long num[501], sum[501], ssum[501];
int n, k;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[i] = a;
	}
	sum[0] = 0;
	ssum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + num[i - 1];
		ssum[i] = ssum[i - 1] + pow(num[i - 1], 2);
	}
	long double M = (long double)(sum[k] - sum[0]) / k;
	long double V = (long double)(ssum[k] - ssum[0]) / k - pow(M, 2);
	V = sqrt(V);
	for (int i = 1; i <= n - k;i++) {
		for (int j = i + k; j <= n; j++) {
			long double m= (long double)(sum[j] - sum[i]) / (j-i);
			long double v = (long double)(ssum[j] - ssum[i]) / (j-i) - pow(m, 2);
			v = sqrt(v);
			if (v < V)
				V = v;
		}
	}
	printf("%.11Lf\n", V);
	return 0;
}
