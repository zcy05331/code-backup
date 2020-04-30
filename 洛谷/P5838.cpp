#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int Max = MaxN << 5;

struct edge
{
    int next, to;
};

struct node
{
    int lc, rc, sum;
};

edge e[MaxN];
int n, m, cnt;
int head[MaxN], root[MaxN];
int a[MaxN], dep[MaxN], fa[MaxN][21];

struct SegmentTree
{
    int cnt;
    node t[Max];
    int calc(int u, int v, int x, int y) { return t[u].sum + t[v].sum - t[x].sum - t[y].sum; }
    void build(int &rt, int l, int r)
    {
        rt = ++cnt;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(t[rt].lc, l, mid);
        build(t[rt].rc, mid + 1, r);
    }
    void insert(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].lc = t[pre].lc;
        t[rt].rc = t[pre].rc, t[rt].sum = t[pre].sum + 1;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid)
            insert(t[rt].lc, t[pre].lc, l, mid, pos);
        else insert(t[rt].rc, t[pre].rc, mid + 1, r, pos);
        t[rt].sum = t[t[rt].lc].sum + t[t[rt].rc].sum;
    }
    int query(int u, int v, int x, int y, int l, int r, int pos)
    {
        if(l == r) return calc(u, v, x, y);
        int mid = (l + r) >> 1;
        if(pos <= mid)
            return query(t[u].lc, t[v].lc, t[x].lc, t[y].lc, l, mid, pos);
        else return query(t[u].rc, t[v].rc, t[x].rc, t[y].rc, mid + 1, r, pos);
    }
}T;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
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

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    T.insert(root[u], root[fa], 1, n, a[u]);
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v]) 
        std::swap(u, v);
    for(int i = 20; ~i; i--)
        if(dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if(u == v) return u;
    for(int i = 20; ~i; i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int main()
{   
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    T.build(root[0], 1, n), dfs(1, 0);
    while(m--)
    {
        int u = read(), v = read(), flag;
        int c = read(), l = lca(u, v), fl = fa[l][0];
        flag = T.query(root[u], root[v], root[l], root[fl], 1, n, c);
        printf("%d", !!flag);
    }
    return 0;
}
