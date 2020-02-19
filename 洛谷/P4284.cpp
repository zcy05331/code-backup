#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    double d;
    int next, to;
};

edge e[MaxN << 1];
int n, cnt;
int head[MaxN];
double p[MaxN], f[MaxN], g[MaxN];

inline void add_edge(int u, int v, double d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].d = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs(int u, int fa)
{
    f[u] = 1 - p[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u), f[u] *= (1 - e[i].d + (e[i].d * f[v]));
    }
}

inline void dfs1(int u, int fa, int id)
{
    if (u == 1)
        g[u] = f[u];
    else
    {
        double posibility = g[fa] / (1 - e[id].d + e[id].d * f[u]);
        g[u] = f[u] * (1 - e[id].d + e[id].d * posibility);
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u, i);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        double d;
        scanf("%d%d%lf", &u, &v, &d), d *= 0.01;
        add_edge(u, v, d), add_edge(v, u, d);
    }
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]), p[i] *= 0.01;
    dfs(1, 0), dfs1(1, 0, 0);
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1.00 - g[i];
    printf("%.6lf", ans);
    return 0;
}
