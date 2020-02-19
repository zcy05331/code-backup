// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

const int MaxN = 150010;

struct edge
{
    int to, next;
};

struct node
{
    int l, r;
    int sum, tag;
};

struct SegmentTree
{
    node t[MaxN << 1];
    inline void pushup(int id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r, t[id].tag = -1;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    inline void pushdown(int id)
    {
        if (t[id].tag != -1)
        {
            t[id << 1].sum = t[id].tag * (t[id << 1].r - t[id << 1].l + 1);
            t[id << 1 | 1].sum = t[id].tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);

            t[id << 1].tag = t[id].tag;
            t[id << 1 | 1].tag = t[id].tag;

            t[id].tag = -1;
        }
    }
    inline void modify(int id, int l, int r, int delta)
    {
        if (l > t[id].r || t[id].l > r)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum = delta * (t[id].r - t[id].l + 1);
            t[id].tag = delta;
            return;
        }
        if (t[id].l == t[id].r)
            return;
        pushdown(id);
        modify(id << 1, l, r, delta);
        modify(id << 1 | 1, l, r, delta);
        pushup(id);
        return;
    }
    inline int query(int id, int l, int r)
    {
        if (l > t[id].r || t[id].l > r)
            return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].sum;
        if (t[id].l == t[id].r)
            return 0;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T;

edge e[MaxN << 1];
int n, m, cnt, dfsnum, size[MaxN], hson[MaxN];
int head[MaxN], top[MaxN], dfn[MaxN], fa[MaxN], dep[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs1(int u, int f)
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

inline void dfs2(int u, int Top)
{
    ++dfsnum;
    dfn[u] = dfsnum;
    top[u] = Top;
    if (hson[u])
        dfs2(hson[u], Top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == hson[u] || v == fa[u])
            continue;
        dfs2(v, v);
    }
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

inline void update_tree(int u)
{
    T.modify(1, dfn[u], dfn[u] + size[u] - 1, 0);
}

inline void update_chain(int u, int v, int delta)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        T.modify(1, dfn[top[u]], dfn[u], delta);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    T.modify(1, dfn[v], dfn[u], delta);
}

signed main()
{
    n = read();
    for (int i = 2; i <= n; ++i)
    {
        int u = read() + 1;
        add_edge(i, u);
        add_edge(u, i);
    }
    dep[1] = 1, fa[1] = 0;
    dfs1(1, 0), dfs2(1, 1);
    T.build(1, 1, n);
    m = read();
    for (int i = 1; i <= m; i++)
    {
        string op;
        cin >> op;
        int before = T.t[1].sum;
        if (op == "install")
        {
            int u = read() + 1;
            update_chain(u, 1, 1);
            int after = T.t[1].sum;
            printf("%d\n", after - before);
        }
        else
        {
            int u = read() + 1;
            update_tree(u);
            int after = T.t[1].sum;
            printf("%d\n", before - after);
        }
    }
    return 0;
}
