#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, m;
ll a[MaxN];

struct node
{
    ll l, r;
    ll sum, tag;
};

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(int id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
            return (void)(t[id].sum = a[l]);
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    };
    void pushdown(int id)
    {
        if (t[id].tag)
        {
            ll tag = t[id].tag;
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag;
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1), t[id].tag = 0;
        }
    }
    void modify(int id, int l, int r, ll val)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].tag += val;
            t[id].sum += val * (t[id].r - t[id].l + 1);
            return;
        }
        pushdown(id), modify(id << 1, l, r, val);
        modify(id << 1 | 1, l, r, val), pushup(id);
    }
    ll query(int id, int l, int r)
    {
        if (t[id].l > r || l > t[id].r) return 0;
        if (l <= t[id].l && t[id].r <= r) return t[id].sum;
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

int main()
{
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while(m--)
    {
        int op = read();
        if(op == 1)
        {
            ll l = read(), r = read(), val = read();
            T.modify(1, l, r, val);
        }
        else 
        {
            ll l = read(), r = read();
            printf("%lld\n", T.query(1, l, r));
        }
    }
    return 0;
}
