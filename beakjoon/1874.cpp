#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> v1;
vector<char> v2;
int c = 1;
void push() {
	v1.push_back(c);
	v2.push_back('+');
	c++;
}
bool pop(int n) {
	if (v1[v1.size() - 1] != n)
		return false;
	v1.pop_back();
	v2.push_back('-');
	return true;
}
int main()
{	
	int t;
	bool result=true;
	cin >> t;
	for (int i = 0; i < t;i++) {
		int n;
		cin >> n;
		while (c<=n)
			push();
		if (pop(n) == false)
			result = false;
	}
	if (result == false) {
		cout << "NO\n";
		return 0;
	}
	else
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << '\n';
	return 0;
}
