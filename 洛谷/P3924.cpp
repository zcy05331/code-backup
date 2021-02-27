#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct node
{
    ll l, r;
    ll sum, tag;
};

ll s[MaxN], dep[MaxN];
ll n, m, k, maxd, a[MaxN];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct SegmentTree
{
    node t[MaxN << 2];
    void build(ll id, ll l, ll r, ll d)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].sum = a[l], dep[l] = d;
            maxd = std::max(maxd, d);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, d + 1);
        build(id << 1 | 1, mid + 1, r, d + 1);
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
    }
    ll query(ll id, ll a, ll b)
    {
        if (t[id].l == t[id].r) return (1 << a) * (b + t[id].sum);
        return query(id << 1, a - 1, (b + t[id].sum)) + query(id << 1 | 1, a - 1, (b + t[id].sum));
    }
} T;

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
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n, 1);
    ll ans = T.query(1, maxd - 1, 0), y = 1 << (maxd - 1);
    ll g = gcd(y, k);
    y /= g, k /= g;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (((1 << dep[i]) - 1) << (maxd - dep[i]));
    while (m--)
    {
        ll l = read(), r = read(), x = read();
        ans += (s[r] - s[l - 1]) * x;
        printf("%lld\n", ans / y * k);
    }
    return 0;
}
