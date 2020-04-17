#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to, dis;
};

struct node
{
    int l, r;
    int max, add, set;
};

edge e[MaxN];
int n, cnt, dfscnt;
int head[MaxN], u[MaxN], v[MaxN], d[MaxN], fa[MaxN], val[MaxN];
int dfn[MaxN], pre[MaxN], top[MaxN], size[MaxN], son[MaxN], dep[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max); }
    void build(int id, int l, int r)
    {
        t[id].set = -1;
        t[id].l = l, t[id].r = r;
        if (l == r)
            return (void)(t[id].max = pre[l]);
        int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r), pushup(id);
    }
    void pushdown(int id)
    {
        if (~t[id].set)
        {
            int tag = t[id].set;
            t[id << 1].max = tag, t[id << 1 | 1].max = tag;
            t[id << 1].set = tag, t[id << 1 | 1].set = tag;
            t[id << 1].add = 0, t[id << 1 | 1].add = 0, t[id].set = -1;
        }
        if (t[id].add)
        {
            int add = t[id].add;
            t[id << 1].max += add, t[id << 1 | 1].max += add;
            t[id << 1].add += add, t[id << 1 | 1].add += add, t[id].add = 0;
        }
    }
    void set(int id, int l, int r, int val)
    {
        if (l > t[id].r || t[id].l > r) return;
        if (l <= t[id].l && t[id].r <= r)
            return (void)(t[id].set = t[id].max = val, t[id].add = 0);
        pushdown(id), set(id << 1, l, r, val);
        set(id << 1 | 1, l, r, val), pushup(id);
    }
    void add(int id, int l, int r, int val)
    {
        if (l > t[id].r || t[id].l > r) return;
        if (l <= t[id].l && t[id].r <= r)
            return (void)(t[id].add += val, t[id].max += val);
        pushdown(id), add(id << 1, l, r, val);
        add(id << 1 | 1, l, r, val), pushup(id);
    }
    int query_max(int id, int l, int r)
    {
        if (l > t[id].r || t[id].l > r) return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].max;
        pushdown(id);
        return std::max(query_max(id << 1, l, r), query_max(id << 1 | 1, l, r));
    }
} T;

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    size[u] = 1, ::fa[u] = fa;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v], val[v] = e[i].dis;
        if (size[son[u]] < size[v]) son[u] = v;
    }
}

void dfs2(int u, int top)
{
    ::top[u] = top;
    dfn[u] = ++dfscnt, pre[dfscnt] = val[u];
    if (son[u]) dfs2(son[u], top);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

void set(int u, int v, int val)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        T.set(1, dfn[top[u]], dfn[u], val), u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    T.set(1, dfn[v] + 1, dfn[u], val);
}

void add(int u, int v, int val)
{
    while(top[u] != top[v])
    {
        if(dep[top[u]] < dep[top[v]]) std::swap(u, v);
        T.add(1, dfn[top[u]], dfn[u], val), u = fa[top[u]];
    }
    if(dep[u] < dep[v]) std::swap(u, v);
    T.add(1, dfn[v] + 1, dfn[u], val);
}

int query_max(int u, int v)
{
    int ans = 0;
    while(top[u] != top[v])
    {
        if(dep[top[u]] < dep[top[v]]) std::swap(u, v);
        ans = std::max(ans, T.query_max(1, dfn[top[u]], dfn[u])), u = fa[top[u]];
    }
    if(dep[u] < dep[v]) std::swap(u, v);
    ans = std::max(ans, T.query_max(1, dfn[v] + 1, dfn[u]));
    return ans;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    char op[10];
    n = read();
    for(int i = 1; i < n; i++)
    {
        u[i] = read(), v[i] = read(), d[i] = read();
        add_edge(u[i], v[i], d[i]), add_edge(v[i], u[i], d[i]);
    }
    dfs1(1, 0), dfs2(1, 1), T.build(1, 1, n);
    while(scanf("%s", op + 1) && op[1] != 'S')
    {
        if(op[1] == 'M')
        {
            int u = read(), v = read();
            printf("%d\n", query_max(u, v));
        }
        else if(op[1] == 'A')
        {
            int u = read(), v = read(), val = read();
            add(u, v, val);
        }
        else if(op[2] == 'o')
        {
            int u = read(), v = read(), val = read();
            set(u, v, val);
        }
        else if(op[2] == 'h')
        {
            int num = read(), val = read();
            if(dep[u[num]] < dep[v[num]])
                T.set(1, dfn[v[num]], dfn[v[num]], val);
            else T.set(1, dfn[u[num]], dfn[u[num]], val);
        }
    }
    return 0;
}
