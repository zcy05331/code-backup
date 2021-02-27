#include <bits/stdc++.h>

#define R register
#define ll long long
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

struct node
{
    int l, r;
    int sum, tag;
};

pair a[MaxN];
int n, m, ans[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
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
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag, t[id].tag = 0;
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
        }
    }
    void modify(int id, int l, int r, int val)
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
    int query(int id, int pos)
    {
        if (t[id].l > pos || pos > t[id].r)
            return 0;
        if (pos == t[id].l && t[id].r == pos)
            return t[id].sum;
        pushdown(id);
        return query(id << 1, pos) + query(id << 1 | 1, pos);
    }
} T;

int cmp(pair a, pair b)
{
    if (a.second - a.first != b.second - b.first)
        return a.second - a.first < b.second - b.first;
    return a.first < b.first;
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
    int now = 1;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i].first = read(), a[i].second = read();
    std::sort(a + 1, a + n + 1, cmp), T.build(1, 1, m);
    for (int i = 1; i <= m; i++)
    {
        while (now <= n && i > a[now].second - a[now].first + 1)
            T.modify(1, a[now].first, a[now].second, 1), ++now;
        for (int j = i; j <= m; j += i)
            ans[i] = ans[i] + T.query(1, j);
        ans[i] += n - now + 1;
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
