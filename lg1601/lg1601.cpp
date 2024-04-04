#include <iostream>
using namespace std;

const int N = 550;
int a[N], b[N], c[N];
int la, lb, lc;

void add(int a[], int b[], int c[]) {
	for (int i = 0; i < lc; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] = c[i] / 10;
		c[i] %= 10;
	}
	if (c[lc]) lc++;
}

int main() {
	string sa, sb;
	cin >> sa >> sb;
	la = sa.size();
	lb = sb.size();
	lc = max(la, lb);
	for (int i = 0; i < la; i++)a[i] = sa[la - 1 - i] - '0';
	for (int i = 0; i < lb; i++)b[i] = sb[lb - 1 - i] - '0';
	add(a, b, c);
	for (int i = lc; i; i--)printf("%d", c[i - 1]);
	return 0;
}
