// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define tp int
#define ll long long
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
inline tp read()
{
    bool f = 0;
    tp x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = true;
        ch = getchar();
    }1
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return (!f) ? x : -x;
}
const int MaxN = 1000005;
struct node
{
    int l, r, val;
};
struct Persistable_Segment_Tree
{
    int cnt, a[MaxN];
    node t[MaxN << 5];
    inline void build(int &id, int l, int r)
    {
        id = ++cnt;
        if (l == r)
            return (void)(t[id].val = a[l]);
        int mid = (l + r) >> 1;
        build(t[id].l, l, mid);
        build(t[id].r, mid + 1, r);
    }
    inline void insert(int &id, int pre, int l, int r, int q, int v)
    {
        id = ++cnt;
        t[id].l = t[pre].l, t[id].r = t[pre].r, t[id].val = t[pre].val;
        if (l == r)
            return (void)(t[id].val = v);
        int mid = (l + r) >> 1;
        if (q <= mid)
            insert(t[id].l, t[pre].l, l, mid, q, v);
        else
            insert(t[id].r, t[pre].r, mid + 1, r, q, v);
    }
    inline int query(int id, int l, int r, int q)
    {
        if (l == r)
            return t[id].val;
        int mid = (l + r) >> 1;
        if (q <= mid)
            return query(t[id].l, l, mid, q);
        else
            return query(t[id].r, mid + 1, r, q);
    }
} t;
int rt[MaxN << 5];
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        t.a[i] = read();
    t.build(rt[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int pre = read(), op = read(), x = read();
        if (op == 1)
        {
            int v = read();
            t.insert(rt[i], rt[pre], 1, n, x, v);
        }
        else
        {
            printf("%d\n", t.query(rt[pre], 1, n, x));
            rt[i] = rt[pre];
        }
    }
    return 0;
}