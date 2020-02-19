#include <bits/stdc++.h>
using std::min;
using std::queue;
const int MaxN = 1e4 + 10;
const int MaxM = 1e5 + 10;
const int inf = (1 << 30);
struct edge
{
    int next, to, cap;
};
edge e[MaxM << 1];
int n, m, s, t, ans, cnt = 1;
int head[MaxN], dep[MaxN];
inline void add_edge(int u, int v, int cap)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cap = cap;
    e[cnt].next = head[u];
    head[u] = cnt;
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
        int k = dinic(v, min(c, rest));
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
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int u, v, cap;
        scanf("%d%d%d", &u, &v, &cap);
        add_edge(u, v, cap);
        add_edge(v, u, 0);
    }
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    printf("%d\n", ans);
    return 0;
}
