#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e6 + 10;

ll n, l, r;
ll c[MaxN], p[MaxN], f[MaxN], q[MaxN], d[MaxN], s[MaxN], sum[MaxN];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll K(ll num) { return d[num]; }
ll X(ll num) { return s[num]; }
ll Y(ll num) { return f[num] + sum[num]; }

inline double slope(ll x, ll y)
{
    return (1.0 * (Y(x) - Y(y))) / (1.0 * (X(x) - X(y)));
}

int main()
{
    n = read();
    for (ll i = 1; i <= n; i++)
        d[i] = read(), p[i] = read(), c[i] = read(),
        s[i] = s[i - 1] + p[i], sum[i] = sum[i - 1] + d[i] * p[i];
    l = 0, r = 0;
    for (ll i = 1; i <= n; i++)
    {
        while (l < r && slope(q[l + 1], q[l]) < K(i))
            ++l;
        f[i] = f[q[l]] + d[i] * (s[i] - s[q[l]]) - (sum[i] - sum[q[l]]) + c[i];
        while (l < r && slope(q[r], q[r - 1]) > slope(i, q[r]))
            --r;
        q[++r] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}
