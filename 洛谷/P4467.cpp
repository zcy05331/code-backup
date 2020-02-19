#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10, MaxM = 5e5 + 10;

struct edge
{
    int to, next, dis;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const
    {
        return dis > x.dis;
    }
};

edge e[MaxM << 1];
int n, m, s, t, k, cnt;
int head[MaxN], dist[MaxN], u[MaxN], v[MaxN], d[MaxN], vis[MaxN];

inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
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

inline void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    std::priority_queue<node> q;
    q.push((node){s, 0});
    while (!q.empty())
    {
        node tmp = q.top();
        int u = tmp.pos;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dist[v] > dist[u] + e[i].dis)
            {
                dist[v] = dist[u] + e[i].dis;
                if (!vis[v])
                    q.push((node){v, dist[v]});
            }
        }
    }
}

inline void Astar()
{
    if (s == t)
        k++;
    memset(vis, 0, sizeof(vis));
    std::priority_queue<node> q;
    q.push((node){s, dist[s]});
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int u = tmp.pos, dis = tmp.dis - dist[u];
        ++vis[u];
        if (vis[t] == k)
            return (void)printf("%d\n", dis - dist[t]);
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (vis[v] < k)
                q.push((node){v, dis + dist[v] + e[i].dis});
        }
    }
    printf("-1");
}

int main()
{
    freopen("date.in", "r", stdin);
    freopen("date.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read(), d[i] = read();
        add_edge(v[i], u[i], d[i]);
    }
    s = read(), t = read(), k = read();
    dijkstra(t);
    cnt = 0;
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= m; i++)
        add_edge(u[i], v[i], d[i]);
    Astar();
    return 0;
}