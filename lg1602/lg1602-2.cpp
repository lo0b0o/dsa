#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi a, b, c;

bool checkSwap(vi a, vi b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size() - 1; ~i; i--) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

void sub() {
	for (int i = 0; i < a.size(); i++) {
		int t = a[i];
		if (i < b.size()) t -= b[i];
		if (t < 0) {
			a[i + 1]--;
			t += 10;
		}
		c.push_back(t);
	}
	while (c.size() > 1 && !c.back() )c.pop_back();
}

int main() {
	string sa, sb;
	cin >> sa >> sb;
	for (int i = 0; i < sa.size(); i++) a.push_back(sa[sa.size() - 1 - i] - '0');
	for (int i = 0; i < sb.size(); i++) b.push_back(sb[sb.size() - 1 - i] - '0');
	if (checkSwap(a, b)) {
		swap(a, b);
		printf("-");
	}
	sub();
	for (int i = c.size() - 1; ~i; i--)printf("%d", c[i]);
	return 0;
}
