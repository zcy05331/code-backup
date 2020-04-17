#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e2 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, m, cnt, ans = 0x3f3f3f3f;
int head[MaxN], size[MaxN], f[MaxN][MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v];
    }
    f[u][size[u]] = 1, f[u][0] = 0;
}

void dfs2(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs2(v, u);
        for (int j = size[u] - 1; j; j--)
            for (int k = 0; k <= j; k++)
                f[u][j] = std::min(f[u][j], f[u][j - k] + f[v][k]);
    }
    if (size[u] >= m)
        ans = std::min(ans, f[u][size[u] - m] + f[u][size[u]]);
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
    n = read(), m = read();
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), f[1][n] = 0, dfs2(1, 0);
    printf("%d\n", ans);
    return 0;
}
