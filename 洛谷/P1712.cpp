#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct node
{
    int l, r;
    int max, tag;
};

pir a[MaxN], b[MaxN];
int n, m, k, ans, c[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max); }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return (void)1;
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

int cmp(pir a, pir b) { return a.second - a.first < b.second - b.first; }

void init()
{
    std::sort(c + 1, c + 2 * n + 1);
    k = std::unique(c + 1, c + 2 * n + 1) - c - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i].first = std::lower_bound(c + 1, c + k + 1, a[i].first) - c;
        a[i].second = std::lower_bound(c + 1, c + k + 1, a[i].second) - c;
    }
    T.build(1, 1, k);
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
    n = read(), m = read(), ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        a[i].first = read(), a[i].second = read();
        c[i] = a[i].first, c[i + n] = a[i].second;
        b[i].first = a[i].first, b[i].second = a[i].second;
    }
    std::sort(a + 1, a + n + 1, cmp);
    std::sort(b + 1, b + n + 1, cmp), init();
    for (int l = 1, r = 1; r <= n; r++)
    {
        T.modify(1, a[r].first, a[r].second, 1);
        while (l <= r && T.query(1, 1, k) >= m)
        {
            if (T.query(1, 1, k) >= m)
                ans = std::min(ans, b[r].second + b[l].first - b[r].first - b[l].second);
            T.modify(1, a[l].first, a[l].second, -1), ++l;
        }
    }
    printf("%d\n", ((ans == 0x3f3f3f3f) ? -1 : ans));
    return 0;
}
