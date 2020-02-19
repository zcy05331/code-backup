#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

struct edge
{
    int next, to;
};

edge e[3][MaxN << 1];
int n, m, cnt[3];
int s[MaxN], t[MaxN], l[MaxN], calc[MaxN];
int b1[MaxN << 1], b2[MaxN << 1], dis[MaxN], ans[MaxN];
int head[3][MaxN], f[MaxN][21], w[MaxN], dep[MaxN];

inline void add_edge(int u, int v, int op)
{
    ++cnt[op];
    e[op][cnt[op]].to = v;
    e[op][cnt[op]].next = head[op][u];
    head[op][u] = cnt[op];
}

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[0][u]; i; i = e[0][i].next)
    {
        int v = e[0][i].to;
        if (v == f[u][0])
            continue;
        dfs1(v, u);
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

void dfs2(int u)
{
    int t1 = b1[w[u] + dep[u]], t2 = b2[w[u] - dep[u] + MaxN];
    for (int i = head[0][u]; i; i = e[0][i].next)
    {
        int v = e[0][i].to;
        if (v == f[u][0])
            continue;
        dfs2(v);
    }
    b1[dep[u]] += calc[u];
    for (int i = head[1][u]; i; i = e[1][i].next)
    {
        int v = e[1][i].to;
        b2[dis[v] - dep[t[v]] + MaxN]++;
    }
    ans[u] += b1[w[u] + dep[u]] - t1 + b2[w[u] + MaxN - dep[u]] - t2;
    for (int i = head[2][u]; i; i = e[2][i].next)
    {
        int v = e[2][i].to;
        b1[dep[s[v]]]--, b2[dis[v] - dep[t[v]] + MaxN]--;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v, 0), add_edge(v, u, 0);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i], &t[i]);
        int lca_ = lca(s[i], t[i]);
        dis[i] = dep[s[i]] + dep[t[i]] - 2 * dep[lca_], calc[s[i]]++;
        add_edge(t[i], i, 1), add_edge(lca_, i, 2);
        if (dep[lca_] + w[lca_] == dep[s[i]])
            --ans[lca_];
    }
    dfs2(1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
