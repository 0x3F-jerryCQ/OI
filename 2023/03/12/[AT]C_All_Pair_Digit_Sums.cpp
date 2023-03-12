#include <bits/stdc++.h>
using namespace std;
const int _ = 2e5 + 10;
long long pw[20], a[_], b[_], num[15], ans;
int n, cnt[15];
int main() {
	pw[0] = 1;
	for (int i = 1; i <= 16; i++) {
		pw[i] = pw[i-1] * 10LL;
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 0; k <= 15; k++) {
		for (int i = 1; i <= n; i++) {
			b[i] = a[i] % pw[k+1];
		}
		sort(b+1, b+n+1);
		for (int i = 1; i <= n; i++) {
			for (int d = 0; d <= 9; d++) {
				num[d] = (pw[k] * d - b[i] + pw[k+1]) % pw[k+1];
				cnt[d] = lower_bound(b+1, b+n+1, num[d]) - b - 1;
			}
			for (int d = 1; d <= 9; d++) {
				int e = (d + 1) % 10;
				if (num[d] > num[e]) ans += d * (n + cnt[e] - cnt[d]);
				else ans += d * (cnt[e] - cnt[d]);
			}
		}
	}
	cout << ans << endl;
}