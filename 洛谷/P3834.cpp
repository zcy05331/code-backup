#include <bits/stdc++.h>
const int MaxN = 200010;

struct node
{
    int val, l, r;
};

node t[MaxN];
int n, q, m, cnt;
int a[MaxN << 4], b[MaxN << 4], T[MaxN << 4];

inline int build(int l, int r)
{
    int id = ++cnt;
    t[id].val = 0;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        t[id].l = build(l, mid);
        t[id].r = build(mid + 1, r);
    }
    return id;
}

inline int update(int pre, int l, int r, int x)
{
    int id = ++cnt;
    t[id].l = t[pre].l;
    t[id].r = t[pre].r;
    t[id].val = t[pre].val + 1;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        if (x <= mid)
            t[id].l = update(t[pre].l, l, mid, x);
        else
            t[id].r = update(t[pre].r, mid + 1, r, x);
    }
    return id;
}

inline int query(int u, int v, int l, int r, int k)
{
    if (l >= r)
        return l;
    int mid = (l + r) >> 1, x = t[t[v].l].val - t[t[u].l].val;
    if (x >= k)
        return query(t[u].l, t[v].l, l, mid, k);
    else
        return query(t[u].r, t[v].r, mid + 1, r, k - x);
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    T[0] = build(1, m);
    for (int i = 1; i <= n; i++)
    {
        int tmp = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
        T[i] = update(T[i - 1], 1, m, tmp);
    }
    while (q--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int tmp = query(T[x - 1], T[y], 1, m, z);
        printf("%d\n", b[tmp]);
    }
    return 0;
}