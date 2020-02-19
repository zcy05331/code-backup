#include <bits/stdc++.h>

#define R register
#define ll long long
#define id(i, j) ((i - 1) * m + j)
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define check(i, j) (i > 0 && i <= n && j > 0 && j <= m)

const int MaxN = 2e4 + 10;
const int MaxM = 5e5 + 10;
const int inf = (1 << 30);
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
int n, m, s = 10001, t = 10002, cnt = 1, ans;
int head[MaxN], dep[MaxN], cur[MaxN], a[200][200];

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

inline void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
           a[i][j] = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
                add_edge(s, id(i, j), inf);
            else if (a[i][j] == 2)
                add_edge(id(i, j), t, inf);
            for (int k = 0; k <= 3; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (check(nx, ny))
                    add_edge(id(i, j), id(nx, ny), 1);
            }
        }
    }
    solve();
    printf("%d\n", ans);
    return 0;
}