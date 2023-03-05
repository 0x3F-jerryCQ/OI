#include <cstdio>
const int _ = 2e5 + 10;
int n, m, u, v;
int fa[_], c[_];
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	while (m--) {
		scanf("%d%d", &u, &v);
		u = find(u);
		v = find(v);
		if (c[u]) {
			printf("No\n");
			return 0;
		}
		if (c[v]) {
			printf("No\n");
			return 0;
		}
		if (u == v) c[u]++;
		else fa[u] = v;
	}
	for (int i = 1; i <= n; i++) {
		if (fa[i] == i && c[i] != 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}