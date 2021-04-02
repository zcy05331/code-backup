#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stdout, cat)

const ll MaxN = 2e5 + 10;

struct node
{
    ll l, r;
    ll sum, tag;
};

struct query
{
    ll op, l, r, k, id;
} q[MaxN], Ql[MaxN], Qr[MaxN];

ll n, m, cnt, ans[MaxN];

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-') f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(ll id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    void pushdown(ll id)
    {
        if (t[id].tag != 0)
        {
            ll tag = t[id].tag;
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag, t[id].tag = 0;
        }
    }
    void modify(ll id, ll l, ll r, ll val)
    {
        if (t[id].l > r || l > t[id].r)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum += val * (t[id].r - t[id].l + 1);
            return (void)(t[id].tag += val);
        }
        pushdown(id), modify(id << 1, l, r, val);
        modify(id << 1 | 1, l, r, val), pushup(id);
    }
    ll query(ll id, ll l, ll r)
    {
        if (t[id].l > r || l > t[id].r) return 0;
        if (l <= t[id].l && t[id].r <= r) return t[id].sum;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T;

void solve(ll l, ll r, ll ql, ll qr)
{
    if (l > r || ql > qr) return;
    if (l == r)
    {
        for (ll i = ql; i <= qr; i++)
            if (q[i].op == 2) ans[q[i].id] = l;
        return;
    }
    ll cntl = 0, cntr = 0, mid = (l + r) >> 1;
    for (ll i = ql; i <= qr; i++)
    {
        if (q[i].op == 1)
        {
            if (q[i].k > mid)
                T.modify(1, q[i].l, q[i].r, 1), Qr[++cntr] = q[i];
            else
                Ql[++cntl] = q[i];
        }
        else
        {
            ll t = T.query(1, q[i].l, q[i].r);
            if (q[i].k <= t)
                Qr[++cntr] = q[i];
            else
                q[i].k -= t, Ql[++cntl] = q[i];
        }
    }
    for (ll i = ql; i <= qr; i++)
        if (q[i].op == 1 && q[i].k > mid)
            T.modify(1, q[i].l, q[i].r, -1);
    for (ll i = 1; i <= cntl; i++)
        q[ql + i - 1] = Ql[i];
    for (ll i = 1; i <= cntr; i++)
        q[ql + cntl + i - 1] = Qr[i];
    solve(l, mid, ql, ql + cntl - 1), solve(mid + 1, r, ql + cntl, qr);
}

signed main()
{
    n = read(), m = read(), T.build(1, 1, n);
    for (ll i = 1; i <= m; i++)
        q[i].op = read(), q[i].l = read(), q[i].r = read(),
        q[i].k = read(), q[i].id = i, ans[i] = -1;
    solve(0, n, 1, m);
    for (ll i = 1; i <= m; i++)
        if (~ans[i]) printf("%lld\n", ans[i]);
    return 0;
}