#include <iostream>
#include <iomanip>
#include <cmath>
const long double d30 = asin(0.5L);
using namespace std;
int main() {
	long double a, b, c;
	cin >> a >> b;
	if (4 * a * a <= 3 * b * b) {
		c = a * 2 / sqrtl(3);
	} else if (4 * b * b <= 3 * a * a) {
		c = b * 2 / sqrtl(3);
	} else {
		long double L = max(a, b);
		long double R = hypotl(a, b);
		while (R - L > 1e-12) {
			long double M = ((L + R) / 2);
			long double t = acosl(a/M) + acosl(b/M);
			if (t > d30) R = M;
			else L = M;
		}
		c = ((L + R) / 2);
	}
	cout << setprecision(100) << c << endl;
}