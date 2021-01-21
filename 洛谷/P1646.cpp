#include <bits/stdc++.h>

#define R register
#define ll long long
#define id(i, j) (((i)-1) * m + (j))
#define meow(cat...) fprintf(stderr, cat)
#define sum(A, B, Mod) (((A) + (B)) % (Mod))
#define check(i, j) (i > 0 && j > 0 && i <= n && j <= m)

const int Max = 2e2 + 10;
const int MaxN = 2e5 + 10;
const int MaxM = 5e5 + 10;
const int inf = 998244353;
const int dx[] = {1, 0, -1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

struct edge
{
    int next, to, flow;
};

edge e[MaxM];
int n, m, ans, cnt = 1, s = 50001, t = 50002;
int head[MaxN], cur[MaxN], dep[MaxN];
int art[Max][Max], sci[Max][Max], sart[Max][Max], ssci[Max][Max];

void add(int u, int v, int f)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(int u, int v, int f) { add(u, v, f), add(v, u, 0); }

int bfs()
{
    std::queue<int> q;
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    dep[s] = 1, q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, c = e[i].flow;
            if (dep[v] || !c) continue;
            dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[t];
}

int dinic(int u, int flow)
{
    if (u == t) return flow;
    int rest = flow;
    for (int i = cur[u]; i && (rest > 0); i = e[i].next)
    {
        int v = e[i].to, c = e[i].flow, k;
        if (dep[v] != dep[u] + 1 || !c) continue;
        cur[u] = i, k = dinic(v, std::min(rest, c));
        if (!k)
            dep[v] = -1;
        else
        {
            e[i ^ 1].flow += k;
            rest -= k, e[i].flow -= k;
        }
    }
    if (rest > 0) dep[u] = -1;
    return flow - rest;
}

int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while ('0' <= ch && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans -= now;
}

int main()
{
    n = read(), m = read(), cnt = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            art[i][j] = read(), ans += art[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sci[i][j] = read(), ans += sci[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            add_edge(s, id(i, j), art[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            add_edge(id(i, j), t, sci[i][j]);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++)
            sart[i][j] = read(), ans += sart[i][j];
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++)
            ssci[i][j] = read(), ans += ssci[i][j];
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++)
        {
            int now = id(i, j) + n * m;
            add_edge(s, now, sart[i][j]);
            add_edge(now, id(i, j), inf);
            add_edge(now, id(i + 1, j), inf);
        }
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++)
        {
            int now = id(i, j) + 2 * n * m;
            add_edge(now, t, ssci[i][j]);
            add_edge(id(i, j), now, inf);
            add_edge(id(i + 1, j), now, inf);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++)
            sart[i][j] = read(), ans += sart[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++)
            ssci[i][j] = read(), ans += ssci[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++)
        {
            int now = id(i, j) + 3 * n * m;
            add_edge(s, now, sart[i][j]);
            add_edge(now, id(i, j), inf);
            add_edge(now, id(i, j + 1), inf);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m - 1; j++)
        {
            int now = id(i, j) + 4 * n * m;
            add_edge(now, t, ssci[i][j]);
            add_edge(id(i, j), now, inf);
            add_edge(id(i, j + 1), now, inf);
        }
    solve(), printf("%d\n", ans);
    return 0;
}