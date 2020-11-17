#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int l, r;
    int max, tag;
};

struct line
{
    int x, y1, y2, c;
} l[MaxN];

int n, m, w, h, cnt;
int x[MaxN], y[MaxN], b[MaxN], c[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max); }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    void pushdown(int id)
    {
        if (t[id].tag)
        {
            int tag = t[id].tag;
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag;
            t[id << 1].max += tag, t[id << 1 | 1].max += tag, t[id].tag = 0;
        }
    }
    void modify(int id, int l, int r, int v)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r)
            return (void)(t[id].max += v, t[id].tag += v);
        pushdown(id), modify(id << 1, l, r, v);
        modify(id << 1 | 1, l, r, v), pushup(id);
    }
    int query(int id, int l, int r)
    {
        if (t[id].l > r || l > t[id].r) return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].max;
        pushdown(id);
        return std::max(query(id << 1, l, r), query(id << 1 | 1, l, r));
    }
} T;

int cmp(line a, line b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.c > b.c;
}

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
    int T = read();
    while (T--)
    {
        int ans = 0;
        n = read(), w = read(), h = read(), cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            x[i] = read(), y[i] = read(), c[i] = read();
            b[i] = y[i], b[i + n] = y[i] + h - 1;
        }
        std::sort(b + 1, b + 2 * n + 1);
        m = std::unique(b + 1, b + 2 * n + 1) - b - 1;
        for (int i = 1; i <= n; i++)
        {
            int y1 = std::lower_bound(b + 1, b + m + 1, y[i]) - b;
            int y2 = std::lower_bound(b + 1, b + m + 1, y[i] + h - 1) - b;
            l[++cnt] = (line){x[i], y1, y2, c[i]};
            l[++cnt] = (line){x[i] + w - 1, y1, y2, -c[i]};
        }
        std::sort(l, l + cnt + 1, cmp), ::T.build(1, 1, m);
        for (int i = 1; i <= cnt; i++)
        {
            ans = std::max(ans, ::T.query(1, 1, m));
            ::T.modify(1, l[i].y1, l[i].y2, l[i].c);
        }
        printf("%d\n", ans);
    }
    return 0;
}
