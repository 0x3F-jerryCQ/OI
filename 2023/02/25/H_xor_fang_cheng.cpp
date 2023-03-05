#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
class mat {
	private:
	long long data[2][2];
	public:
	inline mat(void) {
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				data[i][j] = 0LL;
			}
		}
	}
	inline long long* operator [] (size_t x) {
		return data[x];
	}
};
inline mat operator * (mat lhs, mat rhs) {
	mat ans;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 1; k++) {
				ans[i][j] += lhs[i][k] * rhs[k][j];
			}
			ans[i][j] %= mod;
		}
	}
	return ans;
}
inline mat operator ^ (mat lhs, long long rhs) {
	mat ans;
	ans[0][0] = ans[1][1] = 1LL;
	while (rhs) {
		if (rhs & 1) ans = ans * lhs;
		lhs = lhs * lhs;
		rhs >>= 1;
	}
	return ans;
}
int T, n, temp[100], d[100];
long long N, M, dp[100][2][2], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> N;
		M = N;
		n = 0;
		while (N) {
			temp[n] = (N & 1LL);
			N >>= 1LL;
			n++;
		}
		for (int i = 1; i <= n; i++) {
			d[i] = temp[n - i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 1; j++) {
				for (int k = 0; k <= 1; k++) {
					dp[i][j][k] = 0LL;
				}
			}
		}
		dp[0][0][0] = 1LL;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 1; j++) {
				for (int k = 0; k <= 1; k++) {
					if (!(j && k)) {
						dp[i][k][1] += dp[i-1][j][1];
					}
				}
				for (int k = 0; k < d[i]; k++) {
					if (!(j && k)) {
						dp[i][k][1] += dp[i-1][j][0];
					}
				}
				int k = d[i];
				if (!(j && k)) {
					dp[i][k][0] += dp[i-1][j][0];
				}
			}
		}
		ans = 0LL;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				ans += dp[n][i][j];
			}
		}
		ans--;
		cout << ans << endl;
		mat Mat;
		Mat[0][0] = Mat[0][1] = Mat[1][0] = 1LL;
		mat Ans = (Mat ^ (M + 1));
		cout << Ans[0][0] << endl;
	}
	return 0;
}