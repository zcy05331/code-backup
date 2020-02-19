#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;
const int mod = 998244353;

struct edge
{
    int to, next;
};

edge e[MaxN << 1];
int head[MaxN], cnt;
int n, size[MaxN], fa[MaxN], fac[MaxN], f[MaxN], sizson[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs1(int u)
{
    size[u] = 1;
    if (u != 1)
        sizson[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
        ++sizson[u];
    }
}
inline void dfs2(int u)
{
    f[u] = fac[sizson[u]];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa[u])
            continue;
            dfs2(v);
        f[u] = 1ll * f[v] * f[u] % mod;
    }
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i < MaxN; i++)
        fac[i] = 1ll * i * fac[i - 1] % mod;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1);
    dfs2(1);
    printf("%d\n", 1ll * f[1] * n % mod);
    return 0;
}
