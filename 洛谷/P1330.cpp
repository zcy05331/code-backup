#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e4 + 10, MaxM = 5e5 + 10;

struct edge
{
    int to, next;
};

edge e[MaxN];
int head[MaxN], vis[MaxN];
int n, m, w, b, ans, cnt, impossible;

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs(int u, int col)
{
    vis[u] = col;
    if (col == 1)
        ++b;
    else
        ++w;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v] == col)
            impossible = 1;
        if (!vis[v])
            dfs(v, (col == 1) ? 2 : 1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
            ans += cmin(b, w);
            b = w = 0;
        }
    }
    if (impossible == 1)
        return 0 * printf("Impossible\n");
    else
        printf("%d\n", ans);
    return 0;
}
