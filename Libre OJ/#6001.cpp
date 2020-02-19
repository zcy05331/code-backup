#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e3 + 10;
const int MaxM = 5e5 + 10;
const int inf = (1 << 30);

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
int n, m, s = 2000, t = 2001, cnt = 1, ans, enter;
int head[MaxN], dep[MaxN], cur[MaxN], c[MaxN], p[MaxN];
std::vector<int> r[MaxN];

inline void add(int u, int v, int c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].cap = c;
    head[u] = cnt;
}

inline void add_edge(int u, int v, int c) { add(u, v, c), add(v, u, 0); }

inline int bfs()
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
        }
    }
    return dep[t];
}

inline int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    int rest = flow;
    for (int i = head[u]; i && (flow - rest < flow); i = e[i].next)
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

inline void solve()
{
    int now = 0;
    while (bfs())
        while ((now = dinic(s, inf)))
            ans -= now;
}

int main()
{
    //freopen("6001.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]), ans += p[i];
        char ch;
        int now = 0;
        add_edge(s, i, p[i]);
        while ((ch = getchar()) != '\n')
        {
            if (ch >= '0' && ch <= '9')
                now = now * 10 + (ch - '0');
            else if(now)
                add_edge(i, now + m, inf), now = 0;
        }
        if (now)
            add_edge(i, now + m, inf);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]), add_edge(i + m, t, c[i]);
    solve();
    bool space = 0;
    for (int i = 1; i <= m; i++)
    {
        if (dep[i])
        {
            if (!space)
                printf("%d", i), space = 1;
            else
                printf(" %d", i);
        }
    }
    puts("");
    space = 0;
    for (int i = m + 1; i <= n + m; i++)
    {
        if (dep[i])
        {
            if (!space)
                printf("%d", i - m), space = 1;
            else
                printf(" %d", i - m);
        }
    }
    puts("");
    printf("%d\n", ans);
    return 0;
}