#include <bits/stdc++.h>
using namespace std;
const int _ = 1e5 + 10;
const int __ = 1.1e6 + 10;
const int mod = 1e9 + 7;
int f[_];
int n, m, num[_];
int cnt[__];
int dp[__], sum[__];
string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = (long long) (f[i-1] + 1) * i % mod;
	}
	for (int i = 1; i <= m; i++) {
		cin >> str;
		for (int j = 1; j <= n; j++) {
			if (str[j-1] == 'H') {
				num[j] |= (1 << (i - 1));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[num[i]]++;
	}
	for (int i = 0; i < (1 << m); i++) {
		sum[i] = 1;
		for (int j = i; j;) {
			j = (j-1) & i;
			sum[i] = ((long long) sum[i] + dp[j]) % mod;
		}
		dp[i] = (long long) f[cnt[i]] * sum[i] % mod;
		sum[i] = (sum[i] + dp[i]) % mod;
	}
	cout << (sum[(1<<m)-1]+mod-1)%mod << endl;
	return 0;
}