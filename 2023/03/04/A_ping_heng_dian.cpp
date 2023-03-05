#include <bits/stdc++.h>
using namespace std;
const int _ = 1e4 + 10;
const long double eps = 1e-6L;
const long double dwn = 0.99L;
const long double K = 0.03L;
const long double Q = 3.0L;
long double X[_], Y[_], W[_];
int n;
inline long double f(long double x, long double y) {
	long double fx = 0.0L;
	long double fy = 0.0L;
	for (int i = 1; i <= n; i++) {
		long double dx = X[i] - x;
		long double dy = Y[i] - y;
		long double d = hypotl(dx, dy);
		if (d > eps) {
			fx += (dx / d) * W[i];
			fy += (dy / d) * W[i];
		}
	}
	return hypotl(fx, fy);
}
int main() {
	long double sx = 0.0L, sy = 0.0L, sw = 0.0L, dis = 0.0L;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i] >> W[i];
		sx += X[i] * W[i];
		sy += Y[i] * W[i];
		sw += W[i];
	}
}