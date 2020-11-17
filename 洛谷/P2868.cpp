#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e4 + 10;
const int MaxM = 2e4 + 10;

struct edge
{
    int next, to;
    double dis;
};

edge e[MaxM];
double dis[MaxN];
int n, m, cnt, vis[MaxN], u[MaxN], v[MaxN];
int head[MaxN], f[MaxN], t[MaxM], inq[MaxN];

void add_edge(int u, int v, double d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(inq, 0, sizeof(inq));
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= n; i++)
        dis[i] = 2e9;
}

void build(double mid)
{
    for (int i = 1; i <= m; i++)
        add_edge(u[i], v[i], mid * t[i] - f[u[i]]);
}

int spfa()
{
    std::queue<int> q;
    q.push(1), dis[1] = 0, inq[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop(), inq[x] = 0;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].dis)
            {
                vis[y] = vis[x] + 1;
                dis[y] = dis[x] + e[i].dis;
                if (vis[y] >= n) return 0;
                if (!inq[y]) inq[y] = 1, q.push(y);
            }
        }
    }
    return 1;
}

int check(double mid)
{
    init(), build(mid);
    return !spfa();
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &u[i], &v[i], &t[i]);
    double l = 0, r = 1e4;
    for(int i = 1; i <= 30; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.2lf\n", l);
    return 0;
}
