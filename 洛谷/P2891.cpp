#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2010;
const int MaxM = 1e5 + 10;
const int inf = (1 << 30);

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
int head[MaxN], dep[MaxN];
int n, p, q, s = 999, t = 1000, cnt = 1, ans;

inline void add_edge(int u, int v, int cap)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cap = cap;
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

inline bool bfs()
{
    memset(dep, 0, sizeof(dep));
    std::queue<int> q;
    q.push(s);
    dep[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].cap;
            if (dep[v] || !c)
                continue;
            q.push(v);
            dep[v] = dep[u] + 1;
            if (v == t)
                return 1;
        }
    }
    return 0;
}

int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to, c = e[i].cap;
        if (dep[v] != dep[u] + 1 || !c)
            continue;
        int k = dinic(v, cmin(rest, c));
        if (!k)
            dep[v] = 0;
        else
        {
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int main()
{
    n = read(), p = read(), q = read();
    for (int i = 1; i <= p; i++)
    {
        add_edge(s, i, 1);
        add_edge(i, s, 0);
    }
    for (int i = 1; i <= q; i++)
    {
        add_edge(i + p, t, 1);
        add_edge(t, i + p, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        int f = read(), d = read();
        for (int j = 1; j <= f; j++)
        {
            int x = read();;
            add_edge(x, p + q + i, 1);
            add_edge(p + q + i, x, 0);
        }
        for (int j = 1; j <= d; j++)
        {
            int x = read();
            add_edge(p + q + n + i, x + p, 1);
            add_edge(x + p, p + q + n + i, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        add_edge(p + q + i, p + q + n + i, 1);
        add_edge(p + q + n + i, p + q + i, 0);
    }
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    printf("%d\n", ans);
    return 0;
}
