#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
ll pos, ans, f[MaxN];
int n, cnt, head[MaxN], dep[MaxN], size[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[1] += dep[u], size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v];
    }
}

void dfs2(int u, int fa)
{
    if (u != 1)
        f[u] = f[fa] + n - (2 * size[u]);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs2(v, u);
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

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 0);
    for(int i = 1; i <= n; i++)
        if(ans < f[i])
            ans = f[i], pos = i; 
    printf("%lld\n", pos);
    return 0;
}
