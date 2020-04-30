#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
int n, m, a, b, c, cnt;
ll ans, p[MaxN], pre[MaxN];
int head[MaxN], vis[MaxN], dis[3][MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    cnt = 0, ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
        head[i] = dis[0][i] = dis[1][i] = dis[2][i] = 0;
}

void bfs(int s, int d[])
{
    std::queue<int> q;
    memset(vis, 0, 4 * (n + 10));
    memset(d, 0x3f, 4 * (n + 10));
    d[s] = 0, vis[s] = 1, q.push(s);
    while (!q.empty())
    {
        s = q.front(), q.pop();
        for (int i = head[s]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (!vis[v])
            {
                d[v] = d[s] + 1;
                vis[v] = 1, q.push(v);
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    //     printf("%d%c", d[i], " \n"[i == n]);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init(), scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &p[i]);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        std::sort(p + 1, p + m + 1);
        for (int i = 1; i <= m; i++)
            pre[i] = pre[i - 1] + p[i];
        bfs(a, dis[0]), bfs(b, dis[1]), bfs(c, dis[2]);
        for (int i = 1; i <= n; i++)
        {
            ll x = dis[0][i] + dis[1][i] + dis[2][i];
            ll num = pre[x] + pre[dis[1][i]];
            if (x <= m) ans = std::min(ans, num);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
