#include <bits/stdc++.h>
using namespace std;
const int _ = 2e5 + 10;
int n, a[_], m, b[_];
int n1, n2;
pair<int, int> a1[_], a2[_];
long double mmax, mmin, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			n1++;
			a1[n1] = make_pair(a[i], i);
		} else {
			n2++;
			a2[n2] = make_pair(a[i], i);
		}
	}
	sort(a1+1, a1+n1+1);
	for (int i = 1; i <= n1; i++) {
		if (i <= 3 || i >= n1 - 2) {
			m++;
			b[m] = a1[i].second;
		}
	}
	sort(a2+1, a2+n2+1);
	for (int i = 1; i <= n2; i++) {
		if (i <= 3 || i >= n2 - 2) {
			m++;
			b[m] = a2[i].second;
		}
	}
	mmax = -1.0L / 0.0L;
	mmin = 1.0L / 0.0L;
	for (int i = 1; i <= n; i++) {
		for (int i1 = 1; i1 < m; i1++) {
			for (int i2 = i1 + 1; i2 <= m; i2++) {
				if (i != b[i1] && i != b[i2]) {
					int x = a[i];
					int y = a[b[i1]];
					int z = a[b[i2]];
					tmp = 1.0L / x / y + 1.0L / x / z + 1.0L / y / z;
					mmax = max(mmax, tmp);
					mmin = min(mmin, tmp);
				}
			}
		}
	}
	cout << fixed << setprecision(20) << mmin << ' ' << mmax << endl;
}