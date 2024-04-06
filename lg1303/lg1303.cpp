#include <iostream>
using namespace std;

const int N = 5000;
int a[N], b[N], c[N];
int la, lb, lc;

void mul() {
	for (int i = 0; i < la; i++)
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	while (lc > 1 && !c[lc - 1]) lc--;
}

int main() {
	string sa, sb;
	cin >> sa >> sb;
	la = sa.size();
	lb = sb.size();
	lc = la + lb;
	for (int i = la - 1; ~i; i--)a[la - 1 - i] = sa[i] - '0';
	for (int i = lb - 1; ~i; i--)b[lb - 1 - i] = sb[i] - '0';
	mul();
	for (int i = lc - 1; ~i; i--) printf("%d", c[i]);
	return 0;
}
