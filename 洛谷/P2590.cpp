#include <bits/stdc++.h>
#define int long long
const int MaxN = 200010;

struct edge
{
    int next, to, from;
};

struct node
{
    int l, r;
    long long sum, max;
};

edge e[MaxN];
int n, q, cnt, dfsnum;
int w[MaxN], head[MaxN], top[MaxN];
int size[MaxN], hson[MaxN], fa[MaxN], dep[MaxN], tpos[MaxN], pre[MaxN];

struct SegmentTree
{
    int n, x[MaxN];
    node t[MaxN << 2];
    inline void pushup(int id)
    {
        t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
        t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max);
    }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].sum = t[id].max = x[pre[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    void modify(int id, int l, int r, int delta)
    {
        if (r < t[id].l || l > t[id].r)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum = t[id].max = delta;
            return;
        }
        if (t[id].l == t[id].r)
            return;
        modify(id << 1, l, r, delta);
        modify(id << 1 | 1, l, r, delta);
        pushup(id);
    }
    int QuerySum(int id, int l, int r)
    {
        if (r < t[id].l || l > t[id].r)
            return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        if (t[id].l == t[id].r)
            return 0;
        return QuerySum(id << 1, l, r) + QuerySum(id << 1 | 1, l, r);
    }
    int QueryMax(int id, int l, int r)
    {
        if (r < t[id].l || l > t[id].r)
            return -100000000;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].max;
        if (t[id].l == t[id].r)
            return -100000000;
        return std::max(QueryMax(id << 1, l, r), QueryMax(id << 1 | 1, l, r));
    }
} T;

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].from = u;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int f)
{
    size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f)
            continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v, u);
        size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}

void dfs2(int u, int Top)
{
    ++dfsnum;
    tpos[u] = dfsnum;
    pre[dfsnum] = u;
    top[u] = Top;
    if (hson[u])
        dfs2(hson[u], Top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u] || v == hson[u])
            continue;
        dfs2(v, v);
    }
}

int query_sum(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        ans += T.QuerySum(1, tpos[top[u]], tpos[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    ans += T.QuerySum(1, tpos[v], tpos[u]);
    return ans;
}

int query_max(int u, int v)
{
    int ans = -1000000000;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        ans = std::max(ans, T.QueryMax(1, tpos[top[u]], tpos[u]));
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    ans = std::max(ans, T.QueryMax(1, tpos[v], tpos[u]));
    return ans;
}

inline long long read()
{
    long long x;
    scanf("%lld", &x);
    return x;
}

signed main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        T.x[i] = read();
    dep[1] = 1;
    fa[1] = 0;
    dfs1(1, 0), dfs2(1, 1);
    T.build(1, 1, n);
    q = read();
    while (q--)
    {
        int u, v;
        std::string op;
        std::cin >> op;
        u = read(), v = read();
        if (op == "CHANGE")
            T.modify(1, tpos[u], tpos[u], v);
        else if (op == "QSUM")
            printf("%lld\n", query_sum(u, v));
        else
            printf("%lld\n", query_max(u, v));
    }
    return 0;
}
