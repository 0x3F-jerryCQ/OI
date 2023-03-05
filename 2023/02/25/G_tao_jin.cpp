#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long N, K, arr[10000], pref[10000], L, M, R, C, ans;
int n, m, k, temp[20], d[20];
unordered_map<long long, long long> dp[20][2];
inline void add(unordered_map<long long, long long>& tmp, long long x, long long y) {
	if (tmp.find(x) == tmp.end()) {
		tmp.insert(make_pair(x, y));
	} else {
		tmp.at(x) += y;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	N++;
	while (N) {
		temp[m] = N % 10;
		N /= 10;
		m++;
	}
	for (int i = 1; i <= m; i++) {
		d[i] = temp[m-i];
	}
	add(dp[0][0], 1LL, 1LL);
	for (int i = 1; i <= m; i++) {
		if (i != 1) {
			for (int j = 0; j <= 9; j++) {
				add(dp[i][1], j, 1LL);
			}
		}
		for (int j = 0; j <= 9; j++) {
			for (auto V: dp[i-1][1]) {
				long long x = V.first;
				long long y = V.second;
				add(dp[i][1], x*j, y);
			}
		}
		for (int j = 0; j < d[i]; j++) {
			for (auto V: dp[i-1][0]) {
				long long x = V.first;
				long long y = V.second;
				add(dp[i][1], x*j, y);
			}
		}
		for (auto V: dp[i-1][0]) {
			long long x = V.first;
			long long y = V.second;
			add(dp[i][0], x*d[i], y);
		}
	}
	for (auto V: dp[m][1]) {
		long long x = V.first;
		long long y = V.second;
		if (x) {
			n++;
			arr[n] = y;
		}
	}
	if (K >= n * n) {
		C = 0LL;
		for (int i = 1; i <= n; i++) {
			C += arr[i];
		}
		C %= mod;
		ans = C * C % mod;
	} else {
		sort(arr+1, arr+n+1);
		L = 1LL;
		R = arr[n] * arr[n];
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i-1] + arr[i];
		}
		while (L < R) {
			M = ((L + R + 1) >> 1);
			C = 0LL;
			for (int i = 1; i <= n; i++) {
				int x = lower_bound(arr+1, arr+n+1, (M - 1) / arr[i] + 1) - arr;
				C += n - x + 1;
			}
			if (C < K) R = M - 1;
			else L = M;
		}
		C = 0LL;
		for (int i = 1; i <= n; i++) {
			int x = upper_bound(arr+1, arr+n+1, L / arr[i]) - arr;
			C += n - x + 1;
			ans = (ans + (arr[i] % mod) * ((pref[n] - pref[x-1]) % mod)) % mod;
		}
		ans = (ans + (L % mod) * ((K - C) % mod)) % mod;
	}
	cout << ans << endl;
	return 0;
}