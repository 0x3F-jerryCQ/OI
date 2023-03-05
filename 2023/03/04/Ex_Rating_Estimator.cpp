#include <bits/stdc++.h>
using namespace std;
const int _ = 5e5 + 10;
const int __ = 2e6 + 10;
int n, b, q, c, x;
int a[_];
long long num[_], s;
#define ls (p<<1)
#define rs ((p<<1)|1)
#define M ((L+R)>>1)
long long mx[__], tg[__];
void build(int p, int L, int R) {
	if (L == R) {
		mx[p] = num[L];
	} else {
		build(ls, L, M);
		build(rs, M+1, R);
		mx[p] = max(mx[ls], mx[rs]);
	}
}
inline void pushdown(int p) {
	mx[ls] += tg[p];
	tg[ls] += tg[p];
	mx[rs] += tg[p];
	tg[rs] += tg[p];
	tg[p] = 0;
}
inline void pushup(int p) {
	mx[p] = max(mx[ls], mx[rs]);
}
void change(int p, long long k, int l, int r, int L, int R) {
	if (l == L && r == R) {
		mx[p] += k;
		tg[p] += k;
	} else {
		pushdown(p);
		if (r <= M) change(ls, k, l, r, L, M);
		else if (l > M) change(rs, k, l, r, M+1, R);
		else {
			change(ls, k, l, M, L, M);
			change(rs, k, M+1, r, M+1, R);
		}
		pushup(p);
	}
}
int fnat(int p, int L, int R, long long& v) {
	if (mx[p] < 0) {
		v = 0;
		return 0;
	} else if (L == R) {
		v = mx[p];
		return L;
	} else {
		pushdown(p);
		int ans = fnat(ls, L, M, v);
		if (ans) return ans;
		else return fnat(rs, M+1, R, v);
	}
}
#undef M
#undef rs
#undef ls
int main() {
	scanf("%d%d%d", &n, &b, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		num[i] = num[i-1] + a[i] - b;
	}
	s = num[n];
	build(1, 1, n);
	while (q--) {
		scanf("%d%d", &c, &x);
		change(1, x - a[c], c, n, 1, n);
		s += x - a[c];
		a[c] = x;
		int A;
		long long B;
		A = fnat(1, 1, n, B);
		if (A) {
			printf("%.20Lf\n", b + (long double) B / A);
		} else {
			printf("%.20Lf\n", b + (long double) s / n);
		}
	}
	return 0;
}