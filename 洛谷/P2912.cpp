#include <bits/stdc++.h>
const int MaxN = 100010;
struct edge
{
    int next, to, dis;
};
edge e[MaxN];
int cnt, n;
int dis[MaxN];
int dep[MaxN];
int head[MaxN];
int f[MaxN][50];
inline void add_edge(int u, int v, int d)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void init(int s, int fa, int d)
{
    f[s][0] = fa;
    dep[s] = dep[fa] + 1;
    dis[s] = dis[fa] + d;
    for (int i = 0; i <= 29; i++)
        f[s][i + 1] = f[f[s][i]][i];
    for (int i = head[s]; i; i = e[i].next)
    {
        int g = e[i].to;
        if (g == fa)
            continue;
        init(g, s, e[i].dis);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        std::swap(x, y);
    for(int i = 30; i >= 0; i--)
    {
        if(dep[f[x][i]] >= dep[y])x = f[x][i];
        if(x == y)return x;
    }
    for(int i = 30; i >= 0; i--)
    {
        if(f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    init(1, 0, 0);
    for(int i = 1; i <= q; i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        printf("%d\n", dis[u] + dis[v] - 2 * dis[lca(u, v)]);
    }
    return 0;
}