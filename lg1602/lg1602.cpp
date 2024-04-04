#include <iostream>
using namespace std;

const int N = 120000;
int a[N], b[N], c[N];
int la, lb, lc;

bool checkSwap(int a[], int b[]) {
	if (la != lb) return la < lb;
	for (int i = la - 1; ~i; i--) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

void sub() {
	for (int i = 0; i < lc; i++) {
		if (a[i] < b[i]) {
			a[i + 1]--;
			a[i] += 10;
		}
		c[i] = a[i] - b[i];
	}
	while (lc > 1 && !c[lc - 1]) lc--;
}

int main() {
	string sa, sb;
	cin >> sa >> sb;
	la = sa.size();
	lb = sb.size();
	lc = max(la, lb);
	for (int i = la - 1; ~i; i--)a[la - 1 - i] = sa[i] - '0';
	for (int i = lb - 1; ~i; i--)b[lb - 1 - i] = sb[i] - '0';
	if (checkSwap(a, b)) {
		swap(a, b);
		printf("-");
	}
	sub();
	for (int i = lc - 1; ~i; i--)printf("%d", c[i]);
	return 0;
}
