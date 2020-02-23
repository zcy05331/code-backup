#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    int u, v, dis;
};

node t[MaxN];
edge e[MaxN << 1];
int n, m, q, cnt, Cnt;
int head[MaxN], val[MaxN], f[MaxN], dep[MaxN], fa[MaxN][21];

int cmp(node a, node b) { return a.dis < b.dis; }

void add_edge(int u, int v)
{
    ++Cnt;
    e[Cnt].to = v;
    e[Cnt].next = head[u];
    head[u] = Cnt;
}

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

void kruskal()
{
    cnt = n;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    std::sort(t + 1, t + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fu = getf(t[i].u), fv = getf(t[i].v);
        if (fu != fv)
        {
            val[++cnt] = t[i].dis;
            f[cnt] = f[fu] = f[fv] = cnt;
            add_edge(fu, cnt), add_edge(fv, cnt);
            add_edge(cnt, fu), add_edge(cnt, fv);
        }
    }
    dfs(cnt, 0);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        std::swap(u, v);
    for (int i = 20; ~i; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = 20; ~i; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
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
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
        t[i].u = read(), t[i].v = read(), t[i].dis = read();
    kruskal();
    while (q--)
    {
        int u = read(), v = read();
        printf("%d\n", val[lca(u, v)]);
    }
    return 0;
}
