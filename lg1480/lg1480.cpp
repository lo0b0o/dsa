#include <iostream>
using namespace std;

const int N = 10005;
int a[N], c[N], b;
int l;
typedef long long ll;

void div() {
	ll r = 0;
	for (int i = l - 1; ~i; i--) {
		r = r * 10 + a[i];
		c[i] = r / b;
		r %= b;
	}
	while (!c[l - 1] && l > 1)l--;
}

int main() {
	string sa;
	cin >> sa >> b;
	l = sa.size();
	for (int i = l - 1; ~i; i--)a[l - 1 - i] = sa[i] - '0';
	div();
	for (int i = l - 1; ~i; i--)printf("%d", c[i]);
	return 0;
}

