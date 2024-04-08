#include <iostream>
#include <cmath>
using namespace std;

int n, m;
const int N = pow(10, 9), M = 100000;
int *a = new int[N], *b = new int[M];
int find(int q) {
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (a[m] >= q)r = m;
		else l = m;
	}
	return a[r] == q ? r : -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) printf("%d ", find(b[i]));
	return 0;
}
