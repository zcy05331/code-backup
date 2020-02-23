#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 8e5 + 10;
const int MaxM = 1e6 + 10;

struct edge
{
    int next, to, dis;
};

struct Edge
{
    int u, v, ht;
};

struct node
{
    int pos, dis;
    bool operator<(node x) const { return dis > x.dis; }
};

edge e[MaxM];
Edge t[MaxN];
int n, m, q, k, s, cnt, num;
int head[MaxM], dep[MaxM], f[MaxM], val[MaxM], mind[MaxN];
int u[MaxN], v[MaxN], l[MaxN], a[MaxN], dis[MaxN], vis[MaxN], fa[MaxN][21];

int cmp(Edge a, Edge b) { return a.ht > b.ht; }

void link(int u, int v, int a) { ++cnt, t[cnt].u = u, t[cnt].v = v, t[cnt].ht = a; }

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void rebuild()
{
    cnt = 0;
    for (int i = 1; i <= m; i++)
        link(u[i], v[i], a[i]);
}

int jump(int u, int k)
{
    for (int i = 20; ~i; i--)
        if (val[fa[u][i]] > k)
            u = fa[u][i];
    return u;
}

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    n = m = cnt = num = 0;
    memset(f, 0, sizeof(fa));
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));
    memset(vis, 0, sizeof(vis));
    memset(val, 0, sizeof(val));
    memset(head, 0, sizeof(head));
    memset(mind, 0x3f, sizeof(mind));
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

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, ::fa[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u), mind[u] = std::min(mind[u], mind[v]);
    }
}

void kruskal()
{
    num = n, cnt = 0;
    memset(head, 0, sizeof(head));
    std::sort(t + 1, t + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int fu = getf(t[i].u), fv = getf(t[i].v);
        if (fu != fv)
        {
            val[++num] = t[i].ht;
            f[num] = f[fu] = f[fv] = num;
            add_edge(fu, num, 0), add_edge(num, fu, 0);
            add_edge(fv, num, 0), add_edge(num, fv, 0);
        }
    }
    dfs(num, 0);
}

void dijkstra(int u)
{
    std::priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0, q.push((node){u, 0});
    while (!q.empty())
    {
        node x = q.top();
        q.pop(), u = x.pos;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[u] + e[i].dis < dis[v])
            {
                dis[v] = dis[u] + e[i].dis;
                if (!vis[v])
                    q.push((node){v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        mind[i] = dis[i];
}

int main()
{
    int T = read();
    while (T--)
    {
        int lastans = 0;
        init(), n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            u[i] = read(), v[i] = read(), l[i] = read(), a[i] = read();
            add_edge(u[i], v[i], l[i]), add_edge(v[i], u[i], l[i]);
        }
        dijkstra(1), rebuild(), kruskal();
        q = read(), k = read(), s = read();
        while (q--)
        {
            int v = (read() + k * lastans - 1) % n + 1, p = (read() + k * lastans) % (s + 1);
            lastans = mind[jump(v, p)], printf("%d\n", lastans);
        }
    }
    return 0;
}
