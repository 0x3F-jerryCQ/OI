#include <cstring>
#include <cstdio>
const int mod = 998244353;
int n, m;
char str[50];
int arr[50][50];
int dp[50][50][50];
int tmp[50][50][50][10];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		for (int j = 1; j <= m; j++) {
			if (str[j-1] == '?') arr[i][j] = -1;
			else arr[i][j] = str[j-1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[m+1][i][i] = 1;
	}
	for (int i = m; i >= 1; i--) {
		memset(tmp, 0, sizeof(tmp));
		for (int l = 1; l <= n; l++) {
			int L = 0, R = 0;
			if (arr[l][i] == -1) {
				L = 0;
				R = 9;
			} else {
				L = arr[l][i];
				R = arr[l][i];
			}
			for (int k = L; k <= R; k++) {
				tmp[l][l][l][k] = 1;
			}
			for (int r = l+1; r <= n; r++) {
				int L = 0, R = 0;
				if (arr[r][i] == -1) {
					L = 0;
					R = 9;
				} else {
					L = arr[r][i];
					R = arr[r][i];
				}
				for (int k = L; k <= R; k++) {
					for (int d = l; d < r; d++) {
						tmp[l][d][r][k] = (tmp[l][d][r][k] + tmp[l][d][r-1][k]) % mod;
					}
					for (int d = l; d < r; d++) {
						for (int e = 0; e < k; e++) {
							tmp[l][r][r][k] = (tmp[l][r][r][k] + (long long) tmp[l][d][r-1][e] * dp[i+1][d][r-1]) % mod;
						}
					}
				}
			}
		}
		for (int l = 1; l <= n; l++) {
			for (int d = l; d <= n; d++) {
				for (int r = d; r <= n; r++) {
					for (int e = 0; e <= 9; e++) {
						dp[i][l][r] = (dp[i][l][r] + (long long) tmp[l][d][r][e] * dp[i+1][d][r]) % mod;
					}
				}
			}
		}
	}
	printf("%d\n", dp[1][1][n]);
}