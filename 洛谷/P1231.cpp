#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e4 + 10;
const int MaxM = 1e6 + 10;
const int inf = 1e9;

int n1, n2, n3, m1, m2, s, t, ans, cnt = 1;
int head[MaxN], dep[MaxN], to[MaxM], cap[MaxM], next[MaxM], cur[MaxN];

inline void add_edge(int u, int v, int c)
{
    ++cnt;
    to[cnt] = v;
    cap[cnt] = c;
    next[cnt] = head[u];
    head[u] = cnt;
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
        for (int i = head[u]; i; i = next[i])
        {
            int v = to[i];
            if (dep[v] || !cap[i])
                continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
    return dep[t];
}

int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = cur[u]; i && (flow - rest < flow); i = next[i])
    {
        cur[u] = i;
        int v = to[i];
        if (dep[v] != dep[u] + 1 || !cap[i])
            continue;
        int k = dinic(v, cmin(rest, cap[i]));
        if (!k)
            dep[v] = 0;
        else
        {
            cap[i] -= k;
            cap[i ^ 1] += k;
            rest -= k;
        }
    }
    if (flow - rest < flow)
        dep[u] = -1;
    return flow - rest;
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

int main()
{
    n1 = read(), n2 = read(), n3 = read();
    m1 = read();
    s = 2 * n1 + n2 + n3 + 1, t = s + 1;
    int tmp1 = n2 + n3, tmp2 = n1 + n2 + n3;
    for (int i = 1; i <= n1; ++i)
    {
        add_edge(tmp1 + i, tmp2 + i, 1);
        add_edge(tmp2 + i, tmp1 + i, 0);
    }
    for (int i = 1; i <= n2; ++i)
    {
        add_edge(s, i, 1);
        add_edge(i, s, 0);
    }
    for (int i = 1; i <= n3; ++i)
    {
        add_edge(i + n2, t, 1);
        add_edge(t, i + n2, 0);
    }
    for (int i = 1; i <= m1; ++i)
    {
        int u = read(), v = read();
        add_edge(v, tmp1 + u, 1);
        add_edge(tmp1 + u, v, 0);
    }
    m2 = read();
    for (int i = 1; i <= m2; ++i)
    {
        int u = read(), v = read();
        add_edge(tmp2 + u, v + n2, 1);
        add_edge(v + n2, tmp2 + u, 0);
    }
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans += now;
    printf("%d\n", ans);
    return 0;
}
