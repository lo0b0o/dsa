#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi a, b;
int la, lb;

void mul(vi &a, vi &b, vi &c) {
	for (int i = 0; i < la; i++)
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	while (c.size() > 1 && !c.back()) c.pop_back();
}

int main() {
	string sa, sb;
	cin >> sa >> sb;
	la = sa.size();
	lb = sb.size();
	for (int i = la - 1; ~i; i--)a.push_back(sa[i] - '0');
	for (int i = lb - 1; ~i; i--)b.push_back(sb[i] - '0');
	vi c(la + lb);
	mul(a, b, c);
	for (int i = c.size() - 1; ~i; i--)printf("%d", c[i]);
	return 0;
}
