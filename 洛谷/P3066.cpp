#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

struct edge
{
    ll next, to, dis;
};

edge e[MaxN];
ll n, t, cnt;
std::vector<ll> up[MaxN], down[MaxN];
ll head[MaxN], lg2[MaxN], dep[MaxN], maxd[MaxN], ans[MaxN];
ll dis[MaxN], val[MaxN], son[MaxN], top[MaxN], fa[MaxN][21];

void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

ll query_kth(ll u, ll k)
{
    if (!k) return u;
    if(k >= dep[u]) return 0;
    u = fa[u][lg2[k]], k -= (1 << lg2[k]);
    k -= (dep[u] - dep[top[u]]), u = top[u];
    return ((k >= 0) ? up[u][k] : down[u][-k]);
}

void dfs(ll u, ll fa)
{
    maxd[u] = dep[u] = dep[fa] + 1;
    for (ll i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        dis[v] = dis[u] + e[i].dis, dfs(v, u);
        if (maxd[u] < maxd[v])
            maxd[u] = maxd[v], son[u] = v;
    }
}

void dfs1(ll u, ll top)
{
    ::top[u] = top;
    if (u == top)
    {
        ll x = u;
        for (ll i = 0; i <= maxd[u] - dep[u]; i++)
            up[u].push_back(x), x = fa[x][0];
        x = u;
        for (ll i = 0; i <= maxd[u] - dep[u]; i++)
            down[u].push_back(x), x = son[x];
    }
    if (son[u]) dfs1(son[u], top);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v != son[u]) dfs1(v, v);
    }
}

void dfs2(ll u, ll fa)
{
    ll l = 0, r = dep[u] - 1;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        ll x = query_kth(u, mid);
        if (dis[u] - dis[x] <= t)
            l = mid;
        else
            r = mid - 1;
    }
    ll x = query_kth(u, l + 1);
    val[u]++, val[x]--;
    for (ll i = head[u]; i; i = e[i].next)
        dfs2(e[i].to, u);
}

void dfs3(ll u, ll fa)
{
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        dfs3(v, u), ans[u] += ans[v];
    }
    ans[u] += val[u];
}

inline ll read()
{
    ll x = 0, f = 1;
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

signed main()
{
    n = read(), t = read(), lg2[0] = -1;
    for (ll i = 1; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;
    for (ll i = 2, d; i <= n; i++)
    {
        fa[i][0] = read(), d = read();
        add_edge(fa[i][0], i, d);
    }
    dfs(1, 0), dfs1(1, 1), dfs2(1, 0), dfs3(1, 0);
    for (ll i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
