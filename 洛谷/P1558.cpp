#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int l, r;
    int sum, tag;
};

int n, m, q;

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(int id, int l, int r, int p)
    {
        t[id].l = l, t[id].r = r, t[id].tag = -1;
        if (l == r)
        {
            if (p == 1)
                t[id].sum = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, p), build(id << 1 | 1, mid + 1, r, p), pushup(id);
    }
    void pushdown(int id)
    {
        if (~t[id].tag)
        {
            int tag = t[id].tag;
            t[id].tag = -1, t[id << 1].tag = tag, t[id << 1 | 1].tag = tag;
            t[id << 1].sum = tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum = tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
        }
    }
    void modify(int id, int l, int r, int v)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum = v * (t[id].r - t[id].l + 1);
            return (void)(t[id].tag = v);
        }
        pushdown(id), modify(id << 1, l, r, v);
        modify(id << 1 | 1, l, r, v), pushup(id);
    }
    int query(int id, int l, int r)
    {
        if (t[id].l > r || l > t[id].r) return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T[31];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
        T[i].build(1, 1, n, i);
    while (q--)
    {
        char op[2];
        int l, r, x;
        scanf("%s%d%d", op + 1, &l, &r);
        if (l > r) std::swap(l, r);
        if (op[1] == 'C')
        {
            x = read();
            for (int i = 1; i <= m; i++)
                T[i].modify(1, l, r, 0);
            T[x].modify(1, l, r, 1);
        }
        else
        {
            ll ans = 0;
            for (int i = 1; i <= m; i++)
                if (T[i].query(1, l, r))
                    ++ans;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
