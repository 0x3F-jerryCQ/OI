#include <bits/stdc++.h>
using namespace std;
const int _ = 2e5 + 10;
const int __ = 4e5 + 10;
int n, m, e, u, v, hd[_], nx[__], to[__], arr[_];
string str;
bool vis[_];
inline void add(int u, int v) {
	e++;
	nx[e] = hd[u];
	to[e] = v;
	hd[u] = e;
}
int dp[_][2];
inline void dfs(int x, int f, int k) {
	dp[x][1] = k + 1;
	if (!vis[x]) dp[x][0] = 0;
	else dp[x][0] = 1000000007;
	for (int i = hd[x]; i; i = nx[i]) {
		int y = to[i];
		if (y != f) {
			dfs(y, x, k);
			dp[x][1] += min(dp[y][0], dp[y][1] - k);
			if (!vis[x]) dp[x][0] += min(dp[y][0], dp[y][1]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> str;
	for (int i = 1; i <= n; i++) {
		vis[i] = (str[i-1] == '1');
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			dfs(1, 0, i);
			cout << min(dp[1][0], dp[1][1]) << endl;
		}
	} else {
		int l = 0;
		long long c = 0LL;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				c++;
				if (l) {
					m++;
					arr[m] = i-l-1;
				}
				l = i;
			}
		}
		sort(arr+1, arr+m+1);
		for (int i = 0, j = 0; i <= n-1; i++) {
			while (j != m && arr[j+1] <= i) j++;
			c += m - j + 1;
			cout << c << endl;
		}
	}
}