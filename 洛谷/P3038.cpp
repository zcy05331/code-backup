#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;

struct edge
{
    ll next, to;
};

struct node
{
    ll l, r;
    ll sum, tag;
};

edge e[MaxN];
ll n, m, cnt, dfscnt;
ll dfn[MaxN], top[MaxN], son[MaxN];
ll head[MaxN], fa[MaxN], dep[MaxN], size[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void pushup(ll id) { t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum; }
    void build(ll id, ll l, ll r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    }
    void pushdown(ll id)
    {
        if (t[id].tag)
        {
            ll tag = t[id].tag;
            t[id << 1].tag += tag, t[id << 1 | 1].tag += tag;
            t[id << 1 | 1].sum += tag * (t[id << 1 | 1].r - t[id << 1 | 1].l + 1);
            t[id << 1].sum += tag * (t[id << 1].r - t[id << 1].l + 1), t[id].tag = 0;
        }
    }
    void modify(ll id, ll l, ll r)
    {
        if (l > t[id].r || t[id].l > r) return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].tag++;
            t[id].sum += t[id].r - t[id].l + 1;
            return;
        }
        pushdown(id), modify(id << 1, l, r);
        modify(id << 1 | 1, l, r), pushup(id);
    }
    ll query(ll id, ll l, ll r)
    {
        if (l > t[id].r || t[id].l > r) return 0;
        if (l <= t[id].l && t[id].r <= r) return t[id].sum;
        pushdown(id);
        return query(id << 1, l, r) + query(id << 1 | 1, l, r);
    }
} T;

void add_edge(ll u, ll v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(ll u, ll fa)
{
    dep[u] = dep[fa] + 1;
    ::fa[u] = fa, size[u] = 1;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), size[u] += size[v];
        if (size[v] > size[son[u]]) son[u] = v;
    }
}

void dfs2(ll u, ll top)
{
    ::top[u] = top;
    dfn[u] = ++dfscnt;
    if (son[u]) dfs2(son[u], top);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

void modify(ll u, ll v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        T.modify(1, dfn[top[u]], dfn[u]), u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    if (u != v) T.modify(1, dfn[v] + 1, dfn[u]);
}

ll query(ll u, ll v)
{
    ll ans = 0;
    if (dep[u] < dep[v]) std::swap(u, v);
    ans += T.query(1, dfn[u], dfn[u]);
    return ans;
}

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
    n = read(), m = read();
    for (ll i = 1; i < n; i++)
    {
        ll u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 1), T.build(1, 1, n);
    while (m--)
    {
        char op = get();
        if (op == 'P')
        {
            ll u = read(), v = read();
            modify(u, v);
        }
        else if (op == 'Q')
        {
            ll u = read(), v = read();
            printf("%lld\n", query(u, v));
        }
    }
    return 0;
}