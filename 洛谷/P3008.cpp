#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10, MaxM = 2e5 + 10;

struct edge
{
    int next, to, dis;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const
    {
        return dis > x.dis;
    }
};

edge e[MaxM];
std::queue<int> q;
std::vector<int> v[MaxN];
int n, m1, m2, cnt, s, tot;
int head[MaxN], c[MaxN], dis[MaxN], deg[MaxN], vis[MaxN];

inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

void dfs(int u)
{
    c[u] = tot, v[tot].push_back(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (c[v])
            continue;
        dfs(v);
    }
}

inline void dijkstra(int cur)
{
    std::priority_queue<node> pq;
    for (int i = 0; i < v[cur].size(); i++)
        pq.push((node){v[cur][i], dis[v[cur][i]]});
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.pos;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].dis)
            {
                dis[v] = dis[u] + e[i].dis;
                if (c[v] == c[u])
                    pq.push((node){v, dis[v]});
            }
            if (c[u] != c[v])
            {
                deg[c[v]]--;
                if (deg[c[v]] == 0)
                    q.push(c[v]);
            }
        }
    }
}

inline void solve()
{
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= tot; i++)
    {
        if (!deg[i] || (c[s] == i))
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        dijkstra(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > 0x3f3f3f3f)
            printf("NO PATH\n");
        else
            printf("%d\n", dis[i]);
    }
}

int main()
{
    n = read(), m1 = read(), m2 = read(), s = read();
    for (int i = 1; i <= m1; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
            ++tot, dfs(i);
    }
    for (int i = 1; i <= m2; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        deg[c[v]]++;
    }
    solve();
    return 0;
}
