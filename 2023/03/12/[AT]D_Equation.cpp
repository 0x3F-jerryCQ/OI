#include <bits/stdc++.h>
using namespace std;
inline int qpow(int a, int b, int p) {
	int s = 1;
	while (b) {
		if (b & 1) s = (long long) s * a % p;
		a = (long long) a * a % p;
		b >>= 1;
	}
	return s;
}
int T, n, p, a[6];
int main() {
	mt19937 eng(114514);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n >> p;
		uniform_int_distribution<int> rnd(1, p - 1);
		while (1) {
			for (int i = 1; i <= 3; i++) {
				a[i] = rnd(eng);
			}
			if (a[1] == a[2] || a[1] == a[3] || a[2] == a[3]) continue;
			int s = 0;
			for (int i = 1; i <= 3; i++) {
				s = (s + a[i]) % p;
			}
			if (!s) continue;
			int s1 = 0;
			for (int i = 1; i <= 3; i++) {
				s1 = (s1 + qpow(a[i], n % (p - 1), p)) % p;
			}
			if (!s1) continue;
			int s2 = 0;
			for (int i = 1; i <= 3; i++) {
				s2 = (s2 + qpow(a[i], (n * 2LL) % (p - 1), p)) % p;
			}
			if (!s2) continue;
			int s3 = 0;
			for (int i = 1; i <= 3; i++) {
				s3 = (s3 + qpow(a[i], (n * 3LL) % (p - 1), p)) % p;
			}
			if (!s3) continue;
			int k = (long long) s3 * qpow((long long) s * s1 % p * s2 % p, p - 2, p) % p;
			for (int i = 1; i <= 3; i++) {
				a[i] = (long long) a[i] * k % p;
			}
			sort(a+1, a+4);
			cout << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
			break;
		}
	}
}