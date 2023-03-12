#include <cstdio>
long long dp[200010], ans;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			dp[i * j]++;
		}
	}
	for (int i = 1; i < n; i++) {
		ans += dp[i] * dp[n-i];
	}
	printf("%lld\n", ans);
	return 0;
}