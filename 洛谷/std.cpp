#include <bits/stdc++.h>
#define fp(i, a, b) for (register int i = a, I = b + 1; i < I; ++i)
#define fd(i, a, b) for (register int i = a, I = b - 1; i > I; --i)
#define go(u) for (register int i = fi[u], v = e[i].to; i; v = e[i = e[i].nx].to)
#define file(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
template <class T>
inline bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
inline bool cmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
using namespace std;
char ss[1 << 17], *A = ss, *B = ss;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++; }
template <class T>
inline void sd(T &x)
{
	char c;
	T y = 1;
	while (c = gc(), (c < 48 || 57 < c) && c != -1)
		if (c == 45)
			y = -1;
	x = c - 48;
	while (c = gc(), 47 < c && c < 58)
		x = x * 10 + c - 48;
	x *= y;
}
char sr[1 << 21], z[20];
int C = -1, Z;
inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
template <class T>
inline void we(T x)
{
	if (C > 1 << 20)
		Ot();
	if (x < 0)
		sr[++C] = 45, x = -x;
	while (z[++Z] = x % 10 + 48, x /= 10)
		;
	while (sr[++C] = z[Z], --Z)
		;
	sr[++C] = '\n';
}
const int N = 1e5 + 5, inf = 2e9;
typedef int arr[N];
typedef long long ll;
struct Q
{
	int l, r, x, id;
	inline bool operator<(const Q b) const { return x == b.x ? x & 1 ? r < b.r : r > b.r : x < b.x; }
} q[N];
int n, m, Sz, Top, Mi[17], f[N][17];
arr a, pre, suf, S, Log;
ll Now, fl[N], fr[N], ans[N];
inline int cmp(const int x, const int y) { return a[x] < a[y] ? x : y; }
inline int qry(int L, int R)
{
	int t = Log[R - L + 1];
	return cmp(f[L][t], f[R - Mi[t] + 1][t]);
}
inline ll left(int L, int R)
{
	int p = qry(L - 1, R);
	return (ll)a[p] * (R - p + 1) + fl[L - 1] - fl[p];
}
inline ll right(int L, int R)
{
	int p = qry(L, R + 1);
	return (ll)a[p] * (p - L + 1) + fr[R + 1] - fr[p];
}
int main()
{

	sd(n);
	sd(m);
	Sz = sqrt(n);
	a[n + 1] = a[0] = inf;
	Mi[0] = 1;
	fp(i, 1, 16) Mi[i] = Mi[i - 1] << 1;
	fp(i, 2, n) Log[i] = Log[i >> 1] + 1;
	fp(i, 1, n) sd(a[i]), f[i][0] = i;
	fp(j, 1, Log[n]) fp(i, 1, n - Mi[j - 1] + 1)
		f[i][j] = cmp(f[i][j - 1], f[i + Mi[j - 1]][j - 1]);
	fp(i, 1, n)
	{
		while (Top && a[S[Top]] > a[i])
			suf[S[Top--]] = i;
		pre[i] = S[Top];
		S[++Top] = i;
	}
	while (Top)
		pre[S[Top]] = S[Top - 1], suf[S[Top--]] = n + 1;
	fp(i, 1, n) fr[i] = (ll)a[i] * (i - pre[i]) + fr[pre[i]];
	fd(i, n, 1) fl[i] = (ll)a[i] * (suf[i] - i) + fl[suf[i]];
	int x, y, L, R;
	fp(i, 1, m) sd(x), sd(y), q[i] = {x, y, x / Sz, i};
	sort(q + 1, q + m + 1);
	L = q[1].l, R = L - 1;
	fp(i, 1, m)
	{
		x = q[i].l, y = q[i].r;
		while (L > x)
			Now += left(L, R), L--;
		while (R < y)
			Now += right(L, R), R++;
		while (L < x)
			Now -= left(L + 1, R), ++L;
		while (R > y)
			Now -= right(L, R - 1), --R;
		ans[q[i].id] = Now;
	}
	fp(i, 1, m) we(ans[i]);
	return Ot(), 0;
}