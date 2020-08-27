#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e4 + 10;
const int MaxM = 5e5 + 10;
const int inf = 2147483647;

struct edge
{
    int next, to, cap;
};

edge e[MaxM << 2];
int head[MaxN], cur[MaxN], dep[MaxN], g[510][510];
int n, m, num, s = 20001, t = 20002, cnt = 1, ans;

inline void add(int u, int v, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cap = c;
    e[cnt].next = head[u];
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
    q.push(s), dep[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].cap;
            if (dep[v] || !c) continue;
            dep[v] = dep[x] + 1, q.push(v);
        }
    }
    return dep[t];
}

inline int dinic(int u, int flow)
{
    if (u == t) return flow;
    int rest = flow;
    for (int i = cur[u]; i && (rest > 0); i = e[i].next)
    {
        cur[u] = i;
        int v = e[i].to, c = e[i].cap;
        if (dep[v] != dep[u] + 1 || !c) continue;
        int k = dinic(v, std::min(c, rest));
        if (!k)
            dep[v] = -1;
        else
        {
            e[i].cap -= k;
            e[i ^ 1].cap += k;
            rest -= k;
        }
    }
    if (rest < 0) dep[u] = -1;
    return flow - rest;
}

inline void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
}

int main()
{
    n = read(), m = read(), num = read();
    for (int i = 1; i <= n; i++)
        add_edge(s, i, 1);
    for (int i = 1; i <= m; i++)
        add_edge(i + n, t, 1);
    for (int i = 1; i <= num; i++)
    {
        int u = read(), v = read();
        if (u > n || v > m || g[u][v]) continue;
        add_edge(u, v + n, 1), g[u][v] = 1;
    }
    solve(), printf("%d\n", ans);
    return 0;
}
