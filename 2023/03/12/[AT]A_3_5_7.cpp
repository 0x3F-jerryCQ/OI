#include <bits/stdc++.h>
using namespace std;
int T, a[5], x, y, z;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		x = a[1] - a[0];
		y = a[2] - a[1];
		if ((x & 1) || (y & 1) || (((x - y) % 3))) {
			cout << -1 << endl;
		} else {
			x >>= 1;
			y >>= 1;
			z = (y - x) / 3;
			cout << (abs(x + z) + abs(z) + abs(y - z)) / 2 << endl;
		}
	}
	return 0;
}