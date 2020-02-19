#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e3 + 10, MaxM = 2e4 + 10, MaxF = 1e2 + 10;

struct edge
{
    int to, next, dis;
};

struct node
{
    int city, fuel, cost;
    bool operator<(node x) const
    {
        return cost > x.cost;
    }
};

edge e[MaxM];
int n, m, cnt, c, s, t;
int a[MaxN], head[MaxN], f[MaxN][MaxF];

inline void add_edge(int u, int v, int dis)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = dis;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void bfs()
{
    std::priority_queue<node> q;
    q.push((node){s, 0, 0});
    f[s][0] = 0;
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int u = tmp.city;
        f[u][tmp.fuel] = tmp.cost;
        if (u == t)
            return (void)printf("%d\n", tmp.cost);
        if (tmp.fuel < c)
            q.push((node){tmp.city, tmp.fuel + 1, tmp.cost + a[tmp.city]});
        if (tmp.fuel == 0)
            continue;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, d = e[i].dis;
            if (d <= tmp.fuel && f[v][tmp.fuel - d] == 0x3f3f3f3f)
                q.push((node){v, tmp.fuel - d, tmp.cost});
        }
    }
    printf("impossible\n");
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        ++u, ++v;
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    int q = 0;
    scanf("%d", &q);
    while (q--)
    {
        memset(f, 0x3f, sizeof(f));
        scanf("%d%d%d", &c, &s, &t);
        ++s, ++t;
        bfs();
    }
    return 0;
}
