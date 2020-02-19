#include <bits/stdc++.h>
const int MaxN = 500010;
struct edge
{
    int next, to, dis;
};
struct node
{
    int max;
    int l, r;
};
edge e[MaxN << 1];
int n, cnt, dfsnum;
int a[MaxN], head[MaxN], dep[MaxN], fa[MaxN], size[MaxN];
int hson[MaxN], dfn[MaxN], top[MaxN], from[MaxN], to[MaxN], pre[MaxN];
struct SegmentTree
{
    node t[MaxN << 2];
    inline void pushup(int id) { t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max); }
    inline void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            t[id].max = a[pre[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    inline void modify(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].max = val;
            return;
        }
        modify(id << 1, l, r, val);
        modify(id << 1 | 1, l, r, val);
        pushup(id);
    }
    inline int query(int id, int l, int r)
    {
        if (l > t[id].r || r < t[id].l)
            return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].max;
        return std::max(query(id << 1, l, r), query(id << 1 | 1, l, r));
    }
} T;
inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
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
inline void dfs1(int u, int f)
{
    size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == f)
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        a[v] = e[i].dis;
        dfs1(v, u);
        size[u] += size[v];
        if (size[hson[u]] < size[v])
            hson[u] = v;
    }
}
inline void dfs2(int u, int Top)
{
    ++dfsnum;
    dfn[u] = dfsnum;
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
inline void modify(int pos, int val) { T.modify(1, dfn[pos], dfn[pos], val); }
inline int query_chain(int u, int v)
{
    int ans = 0;
    if (dfn[u] < dfn[v])
        std::swap(u, v);
    while (top[u] != top[v])
    {
        if (dfn[u] < dfn[v])
            std::swap(u, v);
        ans = std::max(ans, T.query(1, dfn[top[u]], dfn[u]));
        u = fa[top[u]];
    }
    if (dfn[u] < dfn[v])
        std::swap(u, v);
    ans = std::max(ans, T.query(1, dfn[v] + 1, dfn[u]));
    return ans;
}
int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        from[i] = u;
        to[i] = v;
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    dep[1] = 1, fa[1] = 0;
    dfs1(1, 0), dfs2(1, 1);
    T.build(1, 1, n);
    std::string op;
    std::cin >> op;
    while (op != "DONE")
    {
        if (op == "CHANGE")
        {
            int x = read(), val = read();
            int u = from[x], v = to[x];
            if (fa[v] == u)
                std::swap(u, v);
            modify(u, val);
        }
        else
        {
            int a = read(), b = read();
            printf("%d\n", query_chain(a, b));
        }
        std::cin >> op;
    }
    return 0;
}
