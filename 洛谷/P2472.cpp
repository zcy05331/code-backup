#include <bits/stdc++.h>

#define R register
#define ll long long
#define id(i, j) ((i - 1) * m + j)
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define dis(x, y, x1, y1) (((x - x1) * (x - x1)) + ((y - y1) * (y - y1)))

const int MaxN = 2e4 + 10;
const int MaxM = 5e5 + 10;
const int inf = 1e8;

struct edge
{
    int to, next, cap;
};

edge e[MaxM];
std::string str[50];
int n, m, d, s = 5000, t = 5001, cnt = 1, ans;
int head[MaxN], dep[MaxN], cur[MaxN], a[50][50], b[50][50];
std::vector<std::pair<int, int>> vec;

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
    int tot = 0;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> str[i];
        for (int j = 0; j < m; j++)
            a[i][j + 1] = str[i][j] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> str[i];
        for (int j = 0; j < m; j++)
            b[i][j + 1] = ((str[i][j] == 'L') ? 1 : 0);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
                add_edge(id(i, j), id(i, j) + n * m, a[i][j]), vec.push_back(std::make_pair(i, j));
            if (b[i][j])
                add_edge(s, id(i, j), 1), ++tot;
            if (a[i][j] && (i <= d || ((i + d) > n) || j <= d || ((j + d) > m)))
                add_edge(n * m + id(i, j), t, inf);
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (i == j)
                continue;
            if (dis(vec[i].first, vec[i].second, vec[j].first, vec[j].second) <= d * d)
                add_edge(id(vec[i].first, vec[i].second) + n * m, id(vec[j].first, vec[j].second), inf);
        }
    }
    solve();
    printf("%d\n", tot - ans);
    return 0;
}