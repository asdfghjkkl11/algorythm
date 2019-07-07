#include <iostream>
#include <algorithm>
using namespace std;
int x, y, w, h, result;
int main() {
	cin >> x >> y >> w >> h;
	result = min(min(x,w-x),min(y,h-y));
	cout << result << endl;
	return 0;
}
