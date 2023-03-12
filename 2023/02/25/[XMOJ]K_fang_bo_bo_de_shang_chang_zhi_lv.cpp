#include <bits/stdc++.h>
using namespace std;
int tempd[100], d[100];
long long cnt[100][2];
long long sum[100][2];
long long dp[100][300][2];
inline long long solve1(int n, int k) {
	memset(cnt, 0, sizeof(cnt));
	cnt[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			cnt[i][1] += cnt[i-1][1];
		}
		for (int j = 0; j < d[i]; j++) {
			cnt[i][1] += cnt[i-1][0];
		}
		cnt[i][0] += cnt[i-1][0];
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			sum[i][1] += sum[i-1][1] + cnt[i-1][1] * (n-i) * j;
		}
		for (int j = 0; j < d[i]; j++) {
			sum[i][1] += sum[i-1][0] + cnt[i-1][0] * (n-i) * j;
		}
		int j = d[i];
		sum[i][0] += sum[i-1][0] + cnt[i-1][0] * (n-i) * j;
	}
	return sum[n][1];
}
inline long long solve2(int n, int m, int k) {
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int s = 0; s <= 290; s++) {
			for (int j = 0; j < k; j++) {
				int t = s;
				if (i > m) t += j;
				else t -= j;
				if (t >= 0 && t <= 290) {
					dp[i][s][1] += dp[i-1][t][1];
				}
			}
			for (int j = 0; j < d[i]; j++) {
				int t = s;
				if (i > m) t += j;
				else t -= j;
				if (t >= 0 && t <= 290) {
					dp[i][s][1] += dp[i-1][t][0];
				}
			}
			int j = d[i];
			int t = s;
			if (i > m) t += j;
			else t -= j;
			if (t >= 0 && t <= 290) {
				dp[i][s][0] += dp[i-1][t][0];
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= 290; i++) {
		sum += i * dp[n][i][1];
	}
	return sum;
}
inline long long solve(long long x, int k) {
	int n = 0;
	while (x) {
		tempd[n] = (x % k);
		x /= k;
		n++;
	}
	for (int i = 1; i <= n; i++) {
		d[i] = tempd[n - i];
	}
	long long ans = solve1(n, k);
	for (int i = 1; i < n; i++) {
		ans -= solve2(n, i, k);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long l, r;
	int k;
	cin >> l >> r >> k;
	cout << solve(r+1, k) - solve(l, k) << endl;
	return 0;
}