// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define int long long

const int MaxN = 100010;

struct edge
{
    int next, to;
};

struct node
{
    int l, r;
    int sum, tag;
};

edge e[MaxN << 1];
int n, m, cnt, dfscnt;
int a[MaxN], head[MaxN], dfn[MaxN], pre[MaxN];
int top[MaxN], dep[MaxN], hson[MaxN], fa[MaxN], size[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    inline void pushup(int id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].sum = a[pre[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    inline void pushdown(int id)
    {
        if (t[id].tag)
        {
            t[id << 1].sum += t[id].tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum += t[id].tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);

            t[id << 1].tag += t[id].tag, t[id << 1 | 1].tag += t[id].tag;

            t[id].tag = 0;
        }
    }
    void modify(int id, int l, int r, int delta)
    {
        if (l > t[id].r || r < t[id].l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum += delta * (t[id].r - t[id].l + 1);
            t[id].tag += delta;
            return;
        }
        if (t[id].l == t[id].r)
            return;
        pushdown(id);
        modify(id << 1, l, r, delta);
        modify(id << 1 | 1, l, r, delta);
        pushup(id);
    }
    int query(int id, int l, int r)
    {
        if (l > t[id].r || r < t[id].l)
            return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        if (t[id].l == t[id].r)
            return 0;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T;

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
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
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v, u);
        size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}

void dfs2(int u, int Top)
{
    ++dfscnt;
    dfn[u] = dfscnt;
    pre[dfscnt] = u;
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

inline int query(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[u] < dep[v])
            std::swap(u, v);
        ans += T.query(1, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    ans += T.query(1, dfn[v], dfn[u]);
    return ans;
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dep[1] = 1, fa[1] = 0;
    dfs1(1, 0), dfs2(1, 1);
    T.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op = read();
        if (op == 1)
        {
            int u = read(), x = read();
            T.modify(1, dfn[u], dfn[u], x);
        }
        if (op == 2)
        {
            int u = read(), x = read();
            T.modify(1, dfn[u], dfn[u] + size[u] - 1, x);
        }
        if (op == 3)
        {
            int u = read();
            printf("%lld\n", query(u, 1));
        }
    }
    return 0;
}
