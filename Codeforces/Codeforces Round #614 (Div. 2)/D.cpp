#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 100;

ll lim = 0x7fffffffffffffff;
ll x[MaxN], y[MaxN], vis[MaxN];
ll n, xs, ys, t, ax, ay, bx, by;

ll abs(ll x) { return (x > 0) ? x : (-x); }
ll dis(ll x1, ll y1, ll x2, ll y2) { return abs(x1 - x2) + abs(y1 - y2); }

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1ll) + (x << 3ll) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    ll ans = 0;
    x[0] = read(), y[0] = read(), ax = read(), ay = read(), bx = read(), by = read(), xs = read(), ys = read(), t = read();
    for (ll i = 1;; i++)
    {
        x[i] = ax * x[i - 1] + bx, y[i] = ay * y[i - 1] + by;
        if (x[n] > 1e16 || y[n] > 1e16)
            break;
        n = i;
    }
    for (int i = 0; i <= n; i++)
    {
        ll X = xs, Y = ys, cnt = 0, tim = t;
        for (int j = i; j >= 0; j--)
        {
            if ((tim -= dis(X, Y, x[j], y[j])) >= 0)
                ++cnt, X = x[j], Y = y[j];
            else
                goto as;
        }
        for (int j = i + 1; j <= n; j++)
        {
            if ((tim -= dis(X, Y, x[j], y[j])) >= 0)
                ++cnt, X = x[j], Y = y[j];
            else
                goto as;
        }
    as:
        ans = std::max(ans, cnt);
    }
    printf("%lld\n", ans);
    return 0;
}
