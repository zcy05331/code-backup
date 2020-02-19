#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, cnt;
int head[MaxN], dep[MaxN], vis[MaxN];

inline void add_edge(int u, int v)
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

inline void dfs1(int u, int d)
{
    dep[u] = d;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v])
            continue;
        dfs1(v, d + 1);
    }
}

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0);
    memset(vis, 0, sizeof(vis));
    int pos = 0, maxdep = 0;
    for (int i = 1; i <= n; i++)
        if (dep[i] > maxdep)
            maxdep = dep[i], pos = i;
    memset(dep, 0, sizeof(dep));
    dfs1(pos, 0);
    maxdep = 0;
    for (int i = 1; i <= n; i++)
        if (dep[i] > maxdep)
            maxdep = dep[i];
    printf("%d\n", maxdep);
    return 0;
}
