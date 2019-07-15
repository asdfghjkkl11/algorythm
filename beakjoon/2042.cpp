#include <iostream>
#include <algorithm>
using namespace std;
struct tree {
	long long val;
	tree* left;
	tree* right;
};
int N, A, B, M, X;
tree* makeTree(int a, int b) {
	tree* node = new tree;
	node->val = 0;
	if (b - a == 1) {
		node->left = NULL;
		node->right = NULL;
	}
	else {
		int mid = (a + b) / 2;
		node->left = makeTree(a, mid);
		node->right = makeTree(mid, b);
	}
	return node;
}
void insert(tree* T, int n, int x, int a, int b) {
	T->val += x;
	if (b - a != 1) {
		int mid = (a + b) / 2;
		if (n < mid)
			insert(T->left, n, x, a, mid);
		else
			insert(T->right, n, x, mid, b);
	}
}
int change(tree* T, int n, int x, int a, int b) {
	int mid = (a + b) / 2;
	int res;
	if (b - a != 1)
		if (n < mid)
			res = change(T->left, n, x, a, mid);
		else
			res = change(T->right, n, x, mid, b);
	else
		res = T->val;
	T->val -= res;
	T->val += x;
	return res;
}
long long calculate(tree* T, int n, int m, int a, int b) {
	if (n >= b || m <= a)
		return 0;
	if (a >= n&&b <= m)
		return T->val;
	int mid = (a + b) / 2;
	return calculate(T->left, n, m, a, mid) + calculate(T->right, n, m, mid, b);
}
int main() {
	tree* stree;
	cin >> N >> A >> B;
	stree = makeTree(0, N);
	M = A + B;
	for (int i = 0; i < N; i++) {
		cin >> X;
		insert(stree, i, X, 0, N);
	}
	for (int i = 0; i < M; i++) {
		cin >> X >> A >> B;
		A--;
		if (X == 1)
			change(stree, A, B, 0, N);
		else {
			long long res = calculate(stree, A, B, 0, N);
			cout << res << endl;
		}
	}
	return 0;
}
