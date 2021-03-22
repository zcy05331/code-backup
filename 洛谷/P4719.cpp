#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

struct matrix
{
    int a[2][2];
    matrix() { memset(a, -0x3f, sizeof a); }
} val[MaxN];

struct node
{
    int l, r;
    matrix m;
};

int n, m, cnt, dfscnt, f[MaxN][2], fa[MaxN], dep[MaxN], siz[MaxN];
int head[MaxN], a[MaxN], pos[MaxN], top[MaxN], son[MaxN], dfn[MaxN], end[MaxN];

matrix mul(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c.a[i][j] = std::max(c.a[i][j], a.a[i][k] + b.a[k][j]);
    return c;
};

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(int id) { t[id].m = mul(t[id << 1].m, t[id << 1 | 1].m); }
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return (void)(t[id].m = val[pos[l]]);
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    void modify(int id, int pos)
    {
        if(t[id].l == t[id].r)
            return (void) (t[id].m = val[::pos[pos]]);
        int mid = (t[id].l + t[id].r) >> 1;
        if(pos <= mid) modify(id << 1, pos);
        else modify(id << 1 | 1, pos);
        pushup(id);
    }
    matrix query(int id, int l, int r)
    {
        if(l <= t[id].l && t[id].r <= r)
            return t[id].m;
        int mid = (t[id].l + t[id].r) >> 1;
        if(r <= mid) return query(id << 1, l, r);
        else if(l > mid) return query(id << 1 | 1, l, r);
        else return mul(query(id << 1, l, r), query(id << 1 | 1, l, r));
    }
} T;

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

void dfs1(int u, int fa)
{
    siz[u] = 1, dep[u] = dep[fa] + 1, ::fa[u] = fa;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int top)
{
    ++dfscnt, pos[dfscnt] = u, end[top] = std::max(end[top], dfscnt);
    dfn[u] = dfscnt, ::top[u] = top, f[u][0] = 0, f[u][1] = a[u], val[u].a[1][0] = a[u];
    val[u].a[0][0] = val[u].a[0][1] = 0;
    if (son[u])
    {
        dfs2(son[u], top), f[u][1] += f[son[u]][0];
        f[u][0] += std::max(f[son[u]][0], f[son[u]][1]);
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v), f[u][1] += f[v][0];
        f[u][0] += std::max(f[v][0], f[v][1]);
        val[u].a[0][0] += std::max(f[v][0], f[v][1]);
        val[u].a[0][1] += std::max(f[v][0], f[v][1]);
        val[u].a[1][0] += f[v][0];
    }
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 1), T.build(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int u = read(), val = read();
        
    }
    return 0;
}
