#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e4 + 10;
const int MaxM = 5e5 + 10;
const int inf = (1 << 30);

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
int n, m, s = 5000, t = 6000, cnt = 1, ans;
int head[MaxN], dep[MaxN], cur[MaxN], a[MaxN];

inline void add(int u, int v, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].cap = c;
    head[u] = cnt;
}

inline void add_edge(int u, int v, int c) { add(u, v, c), add(v, u, 0); }

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

inline int bfs()
{
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    std::queue<int> q;
    dep[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].cap;
            if (dep[v] || !c)
                continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
    return dep[t];
}

inline int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = cur[u]; i && (flow - rest < flow); i = e[i].next)
    {
        int v = e[i].to, c = e[i].cap;
        if (dep[v] != dep[u] + 1 || !c)
            continue;
        int k = dinic(v, cmin(rest, c));
        if (!k)
            dep[v] = dep[u] + 1;
        else
        {
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    if (flow - rest < flow)
        dep[u] = -1;
    return flow - rest;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (a[i])
            add_edge(s, i, 1);
        else
            add_edge(i, t, 1);
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        if (a[u] != a[v])
            add_edge(u, v, 1), add_edge(v, u, 1);
    }
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    printf("%d\n", ans);
    return 0;
}
