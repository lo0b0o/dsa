#include <iostream>
#include <vector>
using namespace std;

const int N = 10005;
typedef vector<int> vi;
vi a, c;
int b;
typedef long long ll;


int main() {
	string sa;
	cin >> sa >> b;
	for (int i = sa.size() - 1; ~i; i--) a.push_back(sa[i] - '0');
	ll r = 0;
	for (int i = a.size() - 1; ~i; i--) {
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}
	int init = 0;
	while ((init < (c.size() - 1)) && !c[init]) {
		init++;
	};
	for (int i = init; i < c.size(); i++)printf("%d", c[i]);
	return 0;
}

