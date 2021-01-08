#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct node
{
    int sum;
    int lc, rc;
};

node t[MaxN << 5];
int n, m, cnt, ans, a[MaxN], b[MaxN], rt[MaxN];

struct SegmentTree
{
    void insert(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].sum = t[pre].sum + 1;
        t[rt].lc = t[pre].lc, t[rt].rc = t[pre].rc;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(t[rt].lc, t[pre].lc, l, mid, pos);
        else
            insert(t[rt].rc, t[pre].rc, mid + 1, r, pos);
    }
    int query(int u, int v, int l, int r, int ql, int qr)
    {
        if (l > qr || ql > r) return 0;
        if (ql <= l && r <= qr) return t[v].sum - t[u].sum;
        int mid = (l + r) >> 1;
        return query(t[u].lc, t[v].lc, l, mid, ql, qr) +
               query(t[u].rc, t[v].rc, mid + 1, r, ql, qr);
    }
} T;

int f(int z) { return (z + ans + n) % n + 1; }
int cmp(int a, int b) { return ::a[a] < ::a[b]; }

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
    n = read(), ans = -1;
    for (int i = 1; i <= n; i++) a[read()] = i;
    for (int i = 1; i <= n; i++) b[i] = a[read()];
    for (int i = 1; i <= n; i++)
        T.insert(rt[i], rt[i - 1], 1, n, b[i]);
    m = read();
    while (m--)
    {
        int a = read(), b = read(), c = read(), d = read();
        int l = std::min(f(a), f(b)), r = std::max(f(a), f(b));
        int u = std::min(f(c), f(d)), v = std::max(f(c), f(d));
        printf("%d\n", (ans = T.query(rt[u - 1], rt[v], 1, n, l, r)));
    }
    return 0;
}
