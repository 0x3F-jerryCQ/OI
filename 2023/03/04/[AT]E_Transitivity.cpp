#include <cstdio>
const int _ = 2010;
const int __ = 4010;
int n, m, c, u, v, hd[_], nx[__], to[__];
bool vis[_];
inline void dfs(int x) {
	if (vis[x]) return;
	vis[x] = true;
	for (int i = hd[x]; i; i = nx[i]) {
		int y = to[i];
		dfs(y);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		nx[i] = hd[u];
		to[i] = v;
		hd[u] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = false;
		}
		dfs(i);
		for (int j = 1; j <= n; j++) {
			if (vis[j]) c++;
		}
	}
	printf("%d\n", c-n-m);
	return 0;
}