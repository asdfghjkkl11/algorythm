#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	vector<string> v[51];
	cin >> t;
	for (int i = 0; i < t;i++) {
		string str;
		cin >> str;
		if(find(v[str.length()].begin(), v[str.length()].end(),str)== v[str.length()].end())
			v[str.length()].push_back(str);
	}
	for (int i = 0; i < 51;i++) {
		if (v[i].size() > 1)
			sort(v[i].begin(),v[i].end());
		if (v[i].size() > 0)
			for (int j = 0; j < v[i].size();j++) {
				cout << v[i][j]<<'\n';
			}
	}
}
