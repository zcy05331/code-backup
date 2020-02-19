// luogu-judger-enable-o2
#include <bits/stdc++.h>

struct edge
{
    int to, next;
} e[1000010];

int head[700010];
int f[700010][50];
int dep[700010];
int cnt;

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
    return x;
}

inline void add_edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init(int s, int fa)
{
    dep[s] = dep[fa] + 1;
    f[s][0] = fa;
    for (int i = 0; i <= 29; i++)
    {
        f[s][i + 1] = f[f[s][i]][i];
    }
    for (int i = head[s]; i; i = e[i].next)
    {
        int g = e[i].to;
        if (g == fa)
            continue;
        init(g, s);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        std::swap(x, y);
    for (int i = 30; i >= 0; i--)
    {
        if (dep[f[x][i]] >= dep[y])
            x = f[x][i];
        if (x == y)
            return x;
    }
    for (int i = 30; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int main()
{
    int n, m, s;
    n = read(), m = read();
    for (int i = 1; i <= n - 1; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    init(1, 0);
    for (int i = 0; i < m; i++)
    {
        int x = read(), y = read(), z = read();
        int a, b, c;
        a = lca(x, y);
        b = lca(x, z);
        c = lca(y, z);
        int ans, dist;
        dist = dep[x] + dep[y] + dep[z] - dep[a] - dep[b] - dep[c];
        if (a == b)
            ans = c;
        else if (a == c)
            ans = b;
        else
            ans = a;
        printf("%d %d\n", ans, dist);
    }
    return 0;
}
