#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int inf = 1e9;
const int MaxN = 5e4 + 10;
const int MaxM = 5e5 + 10;

struct edge
{
    int next, to, flow, cost;
};

edge e[MaxM];
int n, m, s = 6000, t = 6001, ans, cnt = 1, mincost, maxflow;
int head[MaxN], flow[MaxN], dis[MaxN], pre[MaxN], last[MaxN], vis[MaxN];

inline void add(int u, int v, int f, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void add_edge(int u, int v, int f, int c)
{
    add(u, v, f, c);
    add(v, u, 0, -c);
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(flow, 0x3f, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    std::queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    pre[t] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            if (e[i].flow && dis[e[i].to] > dis[u] + e[i].cost)
            {
                int v = e[i].to;
                dis[v] = dis[u] + e[i].cost;
                pre[v] = u;
                last[v] = i;
                flow[v] = cmin(flow[u], e[i].flow);
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return pre[t] != -1;
}

void MCMF()
{
    while (spfa())
    {
        int u = t;
        maxflow += flow[t];
        mincost += flow[t] * dis[t];
        while (u != s)
        {
            e[last[u]].flow -= flow[t];
            e[last[u] ^ 1].flow += flow[t];
            u = pre[u];
        }
    }
}

int main()
{
    n = read(), m = read();

    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), c = read();
        add_edge(a + n, b, 1, c);
    }
    s = 1 + n, t = n;
    for (int i = 1; i <= n; i++)
        add_edge(i, i + n, 1, 0);
    MCMF();
    printf("%d %d\n", maxflow, mincost);
    return 0;
}