#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll ans, f[25][MaxN];
int n, m, L, R, cur, a[MaxN], cnt[MaxN];

void update(int x, int y) { ans += y * 1ll * cnt[x] * (cnt[x] - 1) / 2ll; }

ll calc(int l, int r)
{
    while (L < l)
        update(a[L], -1), cnt[a[L]]--, update(a[L], 1), L++;
    while (L > l)
        L--, update(a[L], -1), cnt[a[L]]++, update(a[L], 1);
    while (R < r)
        R++, update(a[R], -1), cnt[a[R]]++, update(a[R], 1);
    while (R > r)
        update(a[R], -1), cnt[a[R]]--, update(a[R], 1), --R;
    return ans;
}

void solve(int l, int r, int lb, int rb)
{
    if (lb > rb || l > r)
        return;
    ll res = 1e18;
    int mid = (l + r) >> 1, d = 0;
    for (int i = lb; i <= rb; i++)
    {
        ll tmp = calc(i + 1, mid);
        if (res > f[cur - 1][i] + tmp)
            res = f[cur - 1][i] + tmp, d = i;
    }
    f[cur][mid] = res;
    solve(l, mid - 1, lb, d), solve(mid + 1, r, d, rb);
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read(), m = read();
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    cnt[a[1]] = L = R = 1;
    for (cur = 1; cur <= m; cur++)
        solve(1, n, 0, n - 1);
    printf("%lld\n", f[m][n]);
    return 0;
}
