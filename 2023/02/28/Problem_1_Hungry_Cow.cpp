#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
long long q, b, l, d, a;
map<long long, long long> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> q;
	while (q--) {
		cin >> d >> b;
		m[d] = b;
		l = (long long)(0xC0C0C0C0C0C0C0C0ULL);
		a = 0LL;
		for (auto p: m) {
			d = p.first;
			b = p.second;
			if (l < d) l = d;
			a = (a + b * (l % mod) % mod) % mod;
			a = (a + ((b * (b - 1LL)) >> 1LL) % mod) % mod;
			l += b;
		}
		cout << a << endl;
	}
	return 0;
}