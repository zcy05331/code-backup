#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) ((x) & (-(x)))
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

ll n, m, ans, v[MaxN];
std::pair<ll, ll> a[MaxN];

int cmp(std::pair<ll, ll> a, std::pair<ll, ll> b) 
{
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

struct BIT
{
    ll c[MaxN];
    void add(ll x, ll val)
    {
        while (x <= n)
            c[x] += val, x += lowbit(x);
    }
    ll query(ll x)
    {
        ll ans = 0;
        while (x)
            ans += c[x], x -= lowbit(x);
        return ans;
    }
} T1, T2;

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

signed main()
{
    n = read();
    for (ll i = 1; i <= n; i++)
        a[i].second = read();
    for (ll i = 1; i <= n; i++)
        a[i].first = v[i] = read();
    std::sort(v + 1, v + n + 1);
    std::sort(a + 1, a + n + 1, cmp);
    for (ll i = 1; i <= n; i++)
    {
        ll val = std::lower_bound(v + 1, v + n + 1, a[i].first) - v;
        ll x = T1.query(val), y = T2.query(val);
        ans += x * a[i].second - y, T1.add(val, 1), T2.add(val, a[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}
