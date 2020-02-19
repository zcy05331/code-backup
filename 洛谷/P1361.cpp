#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;
const int MaxM = 5e6 + 10;
const int inf = (1 << 30);

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
int head[MaxN], dep[MaxN], cur[MaxN];
int n, m, s = 50000, t = 50001, cnt = 1, ans;

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
        cur[u] = i;
        int v = e[i].to, c = e[i].cap;
        if (dep[v] != dep[u] + 1 || !c)
            continue;
        int k = dinic(v, cmin(rest, c));
        if (!k)
            dep[v] = -1;
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

inline void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans -= now;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int tmp = read();
        ans += tmp;
        add_edge(s, i, tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = read();
        ans += tmp;
        add_edge(i, t, tmp);
    }
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int k = read(), c1 = read(), c2 = read();
        ans += (c1 + c2);
        add_edge(s, n + i, c1), add_edge(n + m + i, t, c2);
        for (int j = 1; j <= k; j++)
        {
            int pos = read();
            add_edge(n + i, pos, inf);
            add_edge(pos, n + m + i, inf);
        }
    }
    solve();
    printf("%d\n", ans);
    return 0;
}