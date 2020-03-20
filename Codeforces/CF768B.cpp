#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    int next, to, dis;
};

struct node
{
    ll pos, dis;
    bool operator<(node x) const { return dis > x.dis; }
};

struct st_node
{
    int l, r;
    int lc, rc;
};

edge e[MaxN << 4];
int n, m, s, cnt, root[2];
ll head[MaxN], dis[MaxN], vis[MaxN], idx[MaxN];

void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct SegmentTree
{
    int cnt;
    st_node t[MaxN << 2];
    void build(int &rt, int l, int r)
    {
        if(l == r) 
            return (void) (rt = l, t[rt].l = t[rt].r = l);
        int mid = (l + r) >> 1;
        rt = ++cnt, t[rt].l = l, t[rt].r = r;
        build(t[rt].lc, l, mid), build(t[rt].rc, mid + 1, r);
        add_edge(rt, t[rt].lc, 0), add_edge(rt, t[rt].rc, 0);
    }
    void build1(int &rt, int l, int r)
    {
        if(l == r)
            return (void) (rt = l, t[rt].l = t[rt].r = l);
        int mid = (l + r) >> 1;
        rt = ++cnt, t[rt].l = l, t[rt].r = r;
        build1(t[rt].lc, l, mid), build1(t[rt].rc, mid + 1, r);
        add_edge(t[rt].lc, rt, 0), add_edge(t[rt].rc, rt, 0);
    }
    void insert(int rt, int l, int r, int u, int d)
    {
        if(t[rt].l > r || l > t[rt].r) return;
        if(l <= t[rt].l && t[rt].r <= r)
            return add_edge(u, rt, d);
        insert(t[rt].lc, l, r, u, d), insert(t[rt].rc, l, r, u, d);
    }
    void insert1(int rt, int l, int r, int u, int d)
    {
        if (t[rt].l > r || l > t[rt].r) return;
        if (l <= t[rt].l && t[rt].r <= r)
            return add_edge(rt, u, d);
        insert1(t[rt].lc, l, r, u, d), insert1(t[rt].rc, l, r, u, d);
    }
} T;

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void dijkstra(int s)
{
    std::priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = dis[0] = 0, q.push({s, 0});
    while (!q.empty())
    {
        s = q.top().pos, q.pop();
        if (vis[s]) continue; 
        vis[s] = 1;
        for (int i = head[s]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[s] + e[i].dis)
            {
                dis[v] = dis[s] + e[i].dis;
                if (!vis[v])
                    q.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    n = read(), m = read(), s = read(), T.cnt = n;
    T.build(root[0], 1, n), T.build1(root[1], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op = read();
        if (op == 1)
        {
            int u = read(), v = read(), w = read();
            add_edge(u, v, w);
        }
        else if (op == 2)
        {
            int u = read(), l = read(), r = read(), w = read();
            T.insert(root[0], l, r, u, w);
        }
        else
        {
            int u = read(), l = read(), r = read(), w = read();
            T.insert1(root[1], l, r, u, w);
        }
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        printf("%lld ", (dis[i] == inf) ? -1 : dis[i]);
    return 0;
}
