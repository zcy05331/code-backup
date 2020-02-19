#include <bits/stdc++.h>
#define ll long long
const int MaxN = 1e3 + 10;
const int MaxM = 2e4 + 10;
const int inf = (1 << 30);
struct edge
{
    ll to, next, cap;
};
edge e[MaxM];
ll n, m, s, t, cnt = 1, ans;
ll head[MaxN], dep[MaxN];
inline void add_edge(int u, int v, int cap)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cap = cap;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline ll read()
{
    ll x = 0;
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
        int k = dinic(v, std::min(c, rest));
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
    n = read(), m = read(), s = read(), t = read();
    for (int i = 1; i <= m; i++)
    {
        ll u = read(), v = read(), cap = read();
        add_edge(u, v, cap);
        add_edge(v, u, 0);
    }
    ll now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    printf("%lld\n", ans);
    return 0;
}