#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool visited[3000];
vector<int>x, y, r;
int m;
void DFS(int a) {
	for (int i = 0; i < m;i++) {
		if(i==a){}
		else {
			if (!visited[i]) {
				int X = x[i] - x[a];
				int Y = y[i] - y[a];
				int R = r[a] + r[i];
				X *= X;
				Y *= Y;
				R *= R;
				if (X+Y <= R) {
					visited[i] = true;
					DFS(i);
				}
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t;i++) {
		cin >> m;
		int answer = 0;
		x.clear();
		y.clear();
		r.clear();
		for (int j = 0; j < m;j++) {
			int a, b, c;
			cin >> a >> b >> c;
			x.push_back(a);
			y.push_back(b);
			r.push_back(c);
			visited[j] = false;
		}
		for (int j = 0; j < m; j++) {
			if (!visited[j]) {
				visited[j] = true;
				DFS(j);
				answer++;
			}
		}
		cout << answer << '\n';
	}
}
