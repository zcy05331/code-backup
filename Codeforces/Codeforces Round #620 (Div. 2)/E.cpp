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
int n, q, cnt;
int head[MaxN], dep[MaxN], f[MaxN][21];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
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

int dis(int a, int b)
{
    int lca_ = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[lca_];
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    q = read(), dfs(1, 0);
    while(q--)
    {
        int x = read(), y = read(), a = read(), b = read(), k = read(), d = dis(a, b);
        if(d <= k && (d - k) % 2 == 0)
        {
            printf("YES\n");
            continue;
        }
        d = dis(x, a) + dis(y, b) + 1;
        if (d <= k && (d - k) % 2 == 0)
        {
            printf("YES\n");
            continue;
        }
        d = dis(x, b) + dis(y, a) + 1;
        if (d <= k && (d - k) % 2 == 0)
        {
            printf("YES\n");
            continue;
        }
        int dx = dis(x, y) + 1;
        d = dis(x, a) + dis(y, b) + 1;
        if(dx % 2 && dx + d <= k)
        {
            printf("YES\n");
            continue;
        }
        d = dis(x, b) + dis(y, a) + 1;
        if (dx % 2 && dx + d <= k)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}
