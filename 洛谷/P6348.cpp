#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int Max = MaxN << 5;

struct edge
{
    int next, to, dis;
};

struct st_node
{
    int l, r;
    int lc, rc;
};

struct node
{
    int pos, dis;
    bool operator<(const node &x) const { return x.dis < dis; }
};

edge e[Max << 1];
int n, m, s, cnt, root[2];
int head[Max], dis[Max], vis[Max];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
    // printf("road: %d %d %d\n", u, v, d);
}

struct SegmentTree
{
    int cnt;
    st_node t[Max];
    void build(int &rt, int l, int r)
    {
        if (l == r)
            return (void)(rt = l, t[rt].l = t[rt].r = l);
        int mid = (l + r) >> 1;
        rt = ++cnt, t[rt].l = l, t[rt].r = r;
        build(t[rt].lc, l, mid), add_edge(rt, t[rt].lc, 0);
        build(t[rt].rc, mid + 1, r), add_edge(rt, t[rt].rc, 0);
    }
    void build1(int &rt, int l, int r)
    {
        if (l == r)
            return (void)(rt = l, t[rt].l = t[rt].r = l);
        int mid = (l + r) >> 1;
        rt = ++cnt, t[rt].l = l, t[rt].r = r;
        build1(t[rt].lc, l, mid), add_edge(t[rt].lc, rt, 0);
        build1(t[rt].rc, mid + 1, r), add_edge(t[rt].rc, rt, 0);
    }
    void modify(int rt, int l, int r, int p, int d)
    {
        if (t[rt].l > r || l > t[rt].r) return;
        if (l <= t[rt].l && t[rt].r <= r)
            return (void)add_edge(p, rt, d);
        modify(t[rt].lc, l, r, p, d), modify(t[rt].rc, l, r, p, d);
    }
    void modify1(int rt, int l, int r, int p, int d)
    {
        if (t[rt].l > r || l > t[rt].r) return;
        if (l <= t[rt].l && t[rt].r <= r)
            return (void)add_edge(rt, p, d);
        modify1(t[rt].lc, l, r, p, d), modify1(t[rt].rc, l, r, p, d);
    }
} T;

void dijkstra(int s)
{
    std::priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, q.push((node){s, 0});
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
                if (!vis[v]) q.push((node){v, dis[v]});
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

int main()
{
    n = read(), m = read(), s = read(), T.cnt = n;
    T.build(root[0], 1, n), T.build1(root[1], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), p;
        int c = read(), d = read(), q;
        p = ++T.cnt, T.modify(root[0], a, b, p, 1), T.modify1(root[1], c, d, p, 0);
        q = ++T.cnt, T.modify(root[0], c, d, q, 1), T.modify1(root[1], a, b, q, 0);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        printf("%d\n", dis[i]);
    return 0;
}
