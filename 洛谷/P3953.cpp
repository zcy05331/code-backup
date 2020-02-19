#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

struct edge
{
    int next, to, dis;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const { return dis > x.dis; }
};

edge e[MaxN << 1];
int n, m, k, p, cnt, flag;
int head[MaxN], dis[MaxN], vis[MaxN], u[MaxN], v[MaxN], d[MaxN], f[MaxN][100], ins[MaxN][100];

inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra(int s)
{
    std::priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis));
    q.push((node){s, 0}), dis[s] = 0;
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
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
                if (!vis[v])
                    q.push((node){v, dis[v]});
            }
        }
    }
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

int dfs(int u, int val)
{
    // printf("debug: %d %d %d\n", u, val, f[u][val]);
    if (val < 0)
        return 0;
    if (ins[u][val])
    {
        flag = 1;
        return 0;
    }
    if (~f[u][val])
        return f[u][val];
    ins[u][val] = 1;
    int ans = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        ans = (ans + dfs(v, dis[u] - dis[v] + val - e[i].dis)) % p;
        if (flag == 1)
            return 0;
    }
    ins[u][val] = 0, (u == 1 && val == 0) ? ++ans : 0;
    return (f[u][val] = ans);
}

int main()
{
    int T = read();
    while (T--)
    {
        memset(f, -1, sizeof(f)), memset(ins, 0, sizeof(ins));
        cnt = 0, flag = 0, memset(head, 0, sizeof(head));
        n = read(), m = read(), k = read(), p = read();
        for (int i = 1; i <= m; i++)
        {
            u[i] = read(), v[i] = read(), d[i] = read();
            add_edge(u[i], v[i], d[i]);
        }
        dijkstra(1);
        cnt = 0, memset(head, 0, sizeof(head));
        for (int i = m; i; i--)
            add_edge(v[i], u[i], d[i]);
        ll ans = 0;
        for (int i = 0; i <= k; i++)
            ans = (dfs(n, i) + ans) % p;
        printf("%lld\n", flag ? -1ll : ans);
    }
    return 0;
}