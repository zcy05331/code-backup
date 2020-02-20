#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 40;

struct node
{
    int sum, id, lc, rc;
};

int n, m, q, a[MaxN], f[MaxN], root[MaxN];

struct SegmentTree
{
    int cnt;
    node t[Max];
    void pushup(int rt) { t[rt].sum = t[t[rt].lc].sum + t[t[rt].rc].sum; }
    void insert(int &rt, int l, int r, int pos, int index)
    {
        if (!rt)
            rt = ++cnt;
        if (l == r)
        {
            t[rt].id = index, t[rt].sum++;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(t[rt].lc, l, mid, pos, index);
        else
            insert(t[rt].rc, mid + 1, r, pos, index);
        pushup(rt);
    }
    int merge(int x, int y, int l, int r)
    {
        if (!x || !y)
            return x + y;
        if (l == r)
        {
            t[x].sum += t[y].sum;
            if (t[y].id)
                t[x].id = t[y].id;
            return x;
        }
        int mid = (l + r) >> 1;
        t[x].lc = merge(t[x].lc, t[y].lc, l, mid);
        t[x].rc = merge(t[x].rc, t[y].rc, mid + 1, r), pushup(x);
        return x;
    }
    int query(int rt, int l, int r, int rk)
    {
        if ((t[rt].sum < rk) || (!rt))
            return 0;
        if (l == r)
            return t[rt].id;
        int mid = (l + r) >> 1;
        if (rk <= t[t[rt].lc].sum)
            return query(t[rt].lc, l, mid, rk);
        else
            return query(t[rt].rc, mid + 1, r, rk - t[t[rt].lc].sum);
    }
} T;

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
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

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), f[i] = i;
        T.insert(root[i], 1, n, a[i], i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        u = getf(u), v = getf(v);
        if (u == v)
            continue;
        root[u] = T.merge(root[u], root[v], 1, n), f[v] = u;
    }
    q = read();
    while (q--)
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            int x = read(), k = read(), ans;
            x = getf(x), ans = T.query(root[x], 1, n, k);
            printf("%d\n", (!ans) ? (-1) : ans);
        }
        else
        {
            int u = read(), v = read();
            u = getf(u), v = getf(v);
            if (u == v)
                continue;
            root[u] = T.merge(root[u], root[v], 1, n), f[v] = u;
        }
    }
    return 0;
}
