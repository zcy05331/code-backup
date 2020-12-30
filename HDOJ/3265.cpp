#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

struct line
{
    ll x, y1, y2, c;
};

struct node
{
    ll l, r;
    ll sum, tag;
};

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(ll id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r;
        t[id].sum = t[id].tag = 0;
        if (l == r) return (void)1;
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    void pushdown(ll id)
    {
        if (t[id].tag)
        {
            ll tag = t[id].tag;
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag, t[id].tag = 0;
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
        }
    }
    void modify(ll id, ll l, ll r, ll v)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum += v * (t[id].r - t[id].l + 1);
            return (void)(t[id].tag += v);
        }
        pushdown(id), modify(id << 1, l, r, v);
        modify(id << 1 | 1, l, r, v), pushup(id);
    }
} T;

ll n, cnt, ans;
line l[MaxN << 1];

ll cmp(line a, line b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.c > b.c;
}

void insert(ll x1, ll y1, ll x2, ll y2)
{
    if (x1 == x2 || y1 == y2) return;
    l[++cnt] = (line){x1, y1, y2, 1};
    l[++cnt] = (line){x2, y1, y2, -1};
}

signed main()
{
    while (scanf("%lld", &n) != EOF && n)
    {
        cnt = ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll x[5] = {}, y[5] = {};
            for (ll j = 1; j <= 4; j++)
                scanf("%lld%lld", &x[j], &y[j]);
            insert(x[1], y[1], x[2], y[3]);
            insert(x[1], y[3], x[3], y[4]);
            insert(x[4], y[3], x[2], y[4]);
            insert(x[1], y[4], x[2], y[2]);
        }
        T.build(1, 0, 50000);
        std::sort(l + 1, l + cnt + 1, cmp);
        for (ll i = 1; i <= cnt; i++)
        {
            T.modify(1, l[i].y1, l[i].y2 - 1, l[i].c);
            if (i < cnt) ans += T.t[1].sum * (l[i + 1].x - l[i].x);
            // prllf("%lld %lld %lld %lld %lld\n", l[i].x, l[i].y1, l[i].y2, l[i].c, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
