#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, m, k, cnt;
int fa[MaxN][21], sum[MaxN][21];
int head[MaxN], f[MaxN], c[MaxN], dep[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int jump(int x, int y)
{
    for (int i = 20; ~i; i--)
        if (y & (1 << i))
            x = fa[x][i];
    return x;
}

void dfs1(int u, int fa)
{
    if (dep[fa] <= k) f[1] += c[u];
    dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u);
        for (int j = 1; j <= k; j++)
            sum[u][j] += sum[v][j - 1];
    }
}

void dfs2(int u, int fa)
{
    if (u != 1)
    {
        int now = fa, last = u;
        f[u] = f[fa] + sum[u][k];
        for(int i = 1; i <= k; i++)
        {
            if(!now) break;
            f[u] -= sum[now][k - i + 1] - sum[last][k - i];
            last = now, now = ::fa[now][0];
        }
        f[u] -= c[now];
    }
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
    n = read(), k = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        sum[i][0] = c[i] = read();
    dfs1(1, 0), dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", f[i]);
        // for (int j = 1; j <= k; j++)
        //     printf("%d%c", sum[i][j], " \n"[j == k]);
    }
    return 0;
}
