#include <iostream>
#include <cmath>
using namespace std;
double a, b, c, d;

double f(double x) {
	return a * pow(x, 3) + b * pow(x, 2) + c * pow(x, 1) + d;
}

double find(double r, double l) {
	while (r - l > 0.0001) {
		double m = (r + l) / 2;
		if (f(m)*f(r) < 0) l = m;
		else r = m;
	}
	return r;
}

int main() {
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	for (int i = -100; i < 100; i++) {
		if (!f(i)) printf("%.2lf ", 1.0 * i);
		if (f(i)*f(i + 1) < 0) printf("%.2lf ", find(i + 1, i));
	}
	return 0;
}
