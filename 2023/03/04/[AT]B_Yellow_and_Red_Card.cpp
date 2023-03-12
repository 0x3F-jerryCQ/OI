#include <cstdio>
int c[110];
int n, q, o, x;
int main() {
	scanf("%d%d", &n, &q);
	while (q--) {
		scanf("%d%d", &o, &x);
		switch (o) {
			case 1: {
				c[x] += 1;
				break;
			}
			case 2: {
				c[x] += 2;
				break;
			}
			case 3: {
				if (c[x] >= 2) printf("Yes\n");
				else printf("No\n");
				break;
			}
		}
	}
	return 0;
}