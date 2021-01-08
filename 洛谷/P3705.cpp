#include <bits/stdc++.h>

#define R register
#define id(i, j) ((i)*n + (j))
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int inf = 1e9;
const double eps = 1e-8;
const int Max = 2e2 + 10;
const int MaxN = 5e5 + 10;
const int MaxM = 5e5 + 10;

struct edge
{
    double cost;
    int next, to, flow;
};

edge e[MaxM << 1];
int n, m, cnt, s, t;
int maxflow, head[MaxN], cur[MaxN], vis[MaxN];
double mincost, dis[MaxN], a[Max][Max], b[Max][Max];

void add(int u, int v, int f, double c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(int u, int v, int f, double c) { add(u, v, f, c), add(v, u, 0, -c);  }

int bfs()
{
    std::queue<int> q;
    memcpy(cur, head, 8 * (n + 10));
    for(int i = 0; i <= 2 * (n + 10); i++)
        dis[i] = inf;
    dis[s] = 0, q.push(s), vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].flow;
            if (dis[v] > dis[u] + e[i].cost && c)
            {
                dis[v] = dis[u] + e[i].cost;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return (dis[t] < inf);
}

int dinic(int u, int flow)
{
    if (u == t)
    {
        maxflow += flow;
        return flow;
    }
    int rest = flow;
    vis[u] = 1;
    for (int i = cur[u]; i && rest; i = e[i].next)
    {
        int v = e[i].to, c = e[i].flow, k;
        if (!vis[v] && (dis[v] == dis[u] + e[i].cost) && c)
        {
            cur[u] = i,  k = dinic(v, std::min(rest, e[i].flow));
            e[i].flow -= k, e[i ^ 1].flow += k, rest -= k, mincost += k * e[i].cost;
        }
    }
    vis[u] = 0;
    return flow - rest;
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

void mcmf()
{
    while (bfs())
        memset(vis, 0, 8 * (n + 10)), dinic(s, inf);
}

int check(double mid)
{
    // meow("%lf\n", mid);
    cnt = 1, mincost = maxflow = 0;
    memset(head, 0, 8 * (n + 10));
    for (int i = 1; i <= n; i++)
    {
        add_edge(s, i, 1, 0);
        add_edge(i + n, t, 1, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            add_edge(i, j + n, 1, -a[i][j] + mid * b[i][j]);
    mcmf();
    return mincost < 0;
}

signed main()
{
    n = read(), s = 2 * n + 1, t = 2 * n + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lf", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lf", &b[i][j]);
    double l = 0, r = 1e4;
    for (int i = 1; i <= 100; i++)
    {
        double mid = (l + r) / 2.0;
        if (check(mid)) l = mid;
        else r = mid;
        if(fabs(r - l) <= eps) break;
    }
    printf("%lf\n", l);
    return 0;
}
