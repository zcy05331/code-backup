#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int Max = MaxN * 45;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, cnt;
int ans[MaxN], head[MaxN], root[MaxN], dep[MaxN], f[MaxN][21];

struct SegmentTree
{
    int lc[Max], rc[Max];
    std::pair<int, int> max[Max];
    void pushup(int x)
    {
        if (max[lc[x]].first >= max[rc[x]].first)
            max[x] = max[lc[x]];
        else
            max[x] = max[rc[x]];
    }
    void insert(int &rt, int l, int r, int pos, int val)
    {
        if (!rt)
            rt = ++cnt;
        if (l == r)
        {
            max[rt].first += val;
            max[rt].second = l;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(lc[rt], l, mid, pos, val);
        else
            insert(rc[rt], mid + 1, r, pos, val);
        pushup(rt);
    }
    int merge(int x, int y, int l, int r)
    {
        if (!x || !y)
            return x + y;
        if (l == r)
        {
            max[x].first += max[y].first;
            max[x].second = l;
            return x;
        }
        int mid = (l + r) >> 1;
        lc[x] = merge(lc[x], lc[y], l, mid);
        rc[x] = merge(rc[x], rc[y], mid + 1, r), pushup(x);
        return x;
    }
} T;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        std::swap(u, v);
    for (int i = 20; ~i; i--)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 20; ~i; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
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

void solve(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        solve(v, u);
        root[u] = T.merge(root[u], root[v], 1, 100000);
    }
    ans[u] = ((T.max[root[u]].first > 0) ? (T.max[root[u]].second) : 0);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0), cnt = 0;
    while (m--)
    {
        int x = read(), y = read(), z = read(), lca_ = lca(x, y);
        T.insert(root[x], 1, 100000, z, 1), T.insert(root[y], 1, 100000, z, 1);
        T.insert(root[lca_], 1, 100000, z, -1), T.insert(root[f[lca_][0]], 1, 100000, z, -1);
    }
    solve(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
