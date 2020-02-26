#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 50;

struct node
{
    int sum, lc, rc;
};

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, q, cnt, dfn;
int a[MaxN], b[MaxN], vis[MaxN], dep[MaxN], head[MaxN], root[MaxN], f[MaxN][21];

struct SegmentTree
{
    int cnt = 0;
    node t[Max];
    void build(int &rt, int l, int r)
    {
        rt = ++cnt;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(t[rt].lc, l, mid);
        build(t[rt].rc, mid + 1, r);
    }
    void modify(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].lc = t[pre].lc;
        t[rt].rc = t[pre].rc, t[rt].sum = t[pre].sum + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            modify(t[rt].lc, t[pre].lc, l, mid, pos);
        else
            modify(t[rt].rc, t[pre].rc, mid + 1, r, pos);
        t[rt].sum = t[t[rt].lc].sum + t[t[rt].rc].sum;
    }
    int query(int u, int v, int x, int y, int l, int r, int k)
    {
        if (l == r) return l;
        int mid = (l + r) >> 1, num = t[t[u].lc].sum + t[t[v].lc].sum - t[t[x].lc].sum - t[t[y].lc].sum;
        if (k <= num)
            return query(t[u].lc, t[v].lc, t[x].lc, t[y].lc, l, mid, k);
        else
            return query(t[u].rc, t[v].rc, t[x].rc, t[y].rc, mid + 1, r, k - num);
    }
} T;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void prework()
{
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
}

void Dfs(int u, int fa)
{
    T.modify(root[u], root[fa], 1, m, a[u]);
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        Dfs(v, u);
    }
}

void dfs(int u, int fa)
{
    // std::cerr << u << " " << T.cnt << " " << ++dfn << "\n";
    dep[u] = dep[fa] + 1, f[u][0] = fa, vis[u] = 1;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
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
    if (u == v) return u;
    for (int i = 20; ~i; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

inline int read()
{
    int x = 0, f = 1;
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
    int lastans = 0;
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    prework(), T.build(root[0], 1, m), dfs(1, 0), Dfs(1, 0);
    while (q--)
    {
        int u = read() ^ lastans, v = read(), k = read();
        int lca_ = lca(u, v), flca = f[lca_][0], pos = T.query(root[u], root[v], root[lca_], root[flca], 1, m, k);
        lastans = b[pos], printf("%d\n", lastans);
    }
    return 0;
}
