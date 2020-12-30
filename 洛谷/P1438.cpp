#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;

struct node
{
    ll l, r, len;
    ll k, d, sum;
};

ll n, m, a[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    ll calc(ll k, ll d, ll len) { return (k * 2 + d * (len - 1)) * len / 2; }
    void pushup(ll id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r, t[id].len = r - l + 1;
        if (l == r) return (void)(t[id].sum = a[l]);
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(ll id)
    {
        if (t[id].k || t[id].d)
        {
            ll k = t[id].k, d = t[id].d;
            t[id << 1].sum += calc(k, d, t[id << 1].len);
            t[id << 1].d += d, t[id << 1 | 1].d += d, t[id].d = 0;
            t[id << 1].k += k, t[id << 1 | 1].k += k + d * t[id << 1].len, t[id].k = 0;
            t[id << 1 | 1].sum += calc(k + d * t[id << 1].len, d, t[id << 1 | 1].len);
        }
    }
    void modify(ll id, ll l, ll r, ll k, ll d)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].k += k, t[id].d += d;
            return (void)(t[id].sum += calc(k, d, t[id].len));
        }
        pushdown(id), modify(id << 1, l, r, k, d);
        modify(id << 1 | 1, l, r, k + d * t[id << 1].len, d), pushup(id);
    }
    ll query(ll id, ll l, ll r)
    {
        if (t[id].l > r || l > t[id].r) return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
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
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while (m--)
    {
        ll op = read(), l, r, k, d, p;
        if (op == 1)
        {
            l = read(), r = read(), k = read();
            d = read(), T.modify(1, l, r, k - (l - 1) * d, d);
        }
        else
            p = read(), printf("%lld\n", T.query(1, p, p));
    }
    return 0;
}
