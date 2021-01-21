#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprllf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 3e5 + 10;

struct edge
{
    ll next, to, dis;
};

edge e[MaxN << 1];
ll w, ans, d[MaxN];
int n, q, cnt, dfscnt, u[MaxN], v[MaxN], f[MaxN], pre[MaxN], ed[MaxN];
int head[MaxN], dep[MaxN], siz[MaxN], son[MaxN], top[MaxN], dfn[MaxN];

struct BIT
{
    ll c[MaxN];
    int lowbit(int x) { return x & (-x); }
    void add(int x, ll v)
    {
        while (x <= n)
            c[x] += v, x += lowbit(x);
    }
    ll query(int x)
    {
        ll ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
    ll Query(int l, int r) { return query(r) - query(l - 1); }
} T1;

void add_edge(int u, int v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    siz[u] = 1, f[u] = fa, dep[u] = dep[fa] + 1;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), d[v] = e[i].dis, siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int top)
{
    dfn[u] = ++dfscnt;
    pre[dfscnt] = u, ::top[u] = top;
    if (son[u] != 0) dfs2(son[u], top);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == f[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
    ed[u] = dfscnt;
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        u = f[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    return v;
}

ll query_chain(int u, int v)
{
    ll ret = 0, l = lca(u, v);
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        ret += T1.Query(dfn[top[u]], dfn[u]), u = f[top[u]];
    }
    if (dep[u] < dep[v])
        std::swap(u, v);
    ret += T1.Query(dfn[v] + 1, dfn[u]);
    return ret;
}

struct pair
{
    ll d;
    int u, v;
    pair() {}
    pair(int U, int V)
    {
        u = U, v = V;
        d = query_chain(u, v);
    }
};

ll cmp(pair a, pair b) { return a.d > b.d; }

pair operator+(pair a, pair b)
{
    pair c[10];
    c[1] = pair(a.u, a.v), c[2] = pair(b.u, b.v), c[3] = pair(a.u, b.u);
    c[4] = pair(a.u, b.v), c[5] = pair(a.v, b.u), c[6] = pair(a.v, b.v);
    std::sort(c + 1, c + 6 + 1, cmp);
    return c[1];
}

struct node
{
    pair d;
    ll l, r;
};

struct SegmentTree
{
    node t[MaxN << 2];
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r)
        {
            ll u = pre[l];
            t[id].d = pair(u, u);
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
        t[id].d = t[id << 1].d + t[id << 1 | 1].d;
    }
    void modify(int id, int l, int r)
    {
        if (t[id].l > r || l > t[id].r) return;
        if (l <= t[id].l && t[id].r <= r) return;
        modify(id << 1, l, r), modify(id << 1 | 1, l, r);
        t[id].d = t[id << 1].d + t[id << 1 | 1].d;
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

signed main()
{
    n = read(), q = read(), w = read(), cnt = 1;
    for (int i = 1; i < n; i++)
    {
        ll u = read(), v = read(), d = read();
        add_edge(u, v, d), add_edge(v, u, d);
    }
    dfs1(1, 0), dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        T1.add(dfn[i], d[i]);
    T.build(1, 1, n);
    while (q--)
    {
        ll d = read(), e = read(), u, v, dis;
        d = (d + ans) % (n - 1) + 1, e = (e + ans) % w;
        u = ::e[d * 2].to, v = ::e[d * 2 + 1].to, dis = ::e[d * 2].dis;
        ((f[v] == u) ? std::swap(u, v) : (void)1);
        T1.add(dfn[u], e - dis), ::e[d * 2].dis = ::e[d * 2 + 1].dis = e;
        T.modify(1, dfn[u], ed[u]), printf("%lld\n", (ans = T.t[1].d.d));
    }
    return 0;
}
