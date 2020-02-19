#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

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
int n, m, s, t, S, D, cnt;
int head[MaxN], vis[MaxN], dis[MaxN];

inline void init()
{
    n = cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
}

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
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    std::priority_queue<node> q;
    q.push((node){s, 0}), dis[s] = 0;
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        int u = x.pos;
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

int main()
{
    while (scanf("%d%d%d", &m, &S, &D) == 3)
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            add_edge(u, v, d), add_edge(v, u, d), n = std::max(n, u), n = std::max(n, v);
        }
        s = n + 1, t = n + 2;
        for (int i = 1; i <= S; i++)
        {
            int st;
            scanf("%d", &st);
            add_edge(s, st, 0);
        }
        for (int i = 1; i <= D; i++)
        {
            int ed;
            scanf("%d", &ed);
            add_edge(ed, t, 0);
        }
        dijkstra(s), printf("%d\n", dis[t]);
    }
    return 0;
}
