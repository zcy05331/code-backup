#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<ll, ll>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int inf = 1e9 + 7;
const int MaxN = 2e5 + 10;

pir a[MaxN];
ll pmin[MaxN], pmax[MaxN];
ll n, ans, rmax, rmin, bmax, bmin;

int cmp(pir a, pir b) { return a.first < b.first; }

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

signed main()
{
    n = read(), rmin = bmin = inf;
    for (int i = 1; i <= n; i++)
    {
        ll x = read(), y = read(); if (x > y) std::swap(x, y);
        bmin = std::min(bmin, x), bmax = std::max(bmax, x);
        rmin = std::min(rmin, y), rmax = std::max(rmax, y), a[i] = mp(x, y);
    }
    ans = (rmax - rmin) * (bmax - bmin), pmax[0] = 0, pmin[0] = inf;
    std::sort(a + 1, a + n + 1, cmp), rmin = a[1].first;
    for (int i = 1; i <= n; i++)
        pmax[i] = std::max(pmax[i - 1], a[i].second), pmin[i] = std::min(pmin[i - 1], a[i].second);
    for(int i = 2; i <= n; i++)
        ans = std::min(ans, (rmax - rmin) * (std::max(pmax[i - 1], a[n].first) - std::min(pmin[i - 1], a[i].first)));
    printf("%lld\n", ans);
    return 0;
}
