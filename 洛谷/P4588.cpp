#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e5 + 10;

struct node
{
    ll l, r, sum;
};

ll n, mod;

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(ll id) { t[id].sum = t[id << 1].sum * t[id << 1 | 1].sum % mod; }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r, t[id].sum = 1;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    }
    void modify(ll id, ll pos, ll v)
    {
        if (t[id].l > pos || t[id].r < pos) return;
        if (t[id].l == t[id].r) return (void)(t[id].sum = v);
        modify(id << 1, pos, v), modify(id << 1 | 1, pos, v), pushup(id);
    }
} T;

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
    ll T = read();
    while (T--)
    {
        n = read(), mod = read(), ::T.build(1, 1, n);
        for (ll i = 1; i <= n; i++)
        {
            ll op = read(), x = read();
            if (op == 1)
                ::T.modify(1, i, x);
            else
                ::T.modify(1, x, 1);
            printf("%lld\n", ::T.t[1].sum);
        }
    }
    return 0;
}
