#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 2e4 + 10;

struct edge
{
    int to, next;
};

edge e[2000010];
int n, m, cnt, ans;
int f[2000010], vis[MaxN], head[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int dfs(int u)
{
    if (vis[u])
        return 0;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!f[v] || dfs(f[v]))
        {
            f[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, i);
        add_edge(v, i);
    }
    for (int i = 1; i <= 10000; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ++ans;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}
