#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

struct edge
{
    ll next, to;
};

unsigned s;
edge e[MaxN];
std::vector<ll> u[MaxN], v[MaxN];
ll n, q, rt, cnt, ans, g[MaxN];
ll f[MaxN][21], dep[MaxN], maxd[MaxN], son[MaxN], top[MaxN], head[MaxN];

inline unsigned get(unsigned x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}

void add_edge(ll u, ll v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(ll u, ll fa)
{
    maxd[u] = dep[u] = dep[fa] + 1;
    for (ll i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
        if (maxd[v] > maxd[u]) maxd[u] = maxd[v], son[u] = v;
    }
}

void dfs1(ll u, ll top)
{
    ::top[u] = top;
    if (u == top)
    {
        ll x = u;
        for (ll i = 0; i <= maxd[u] - dep[u]; i++)
            ::u[u].push_back(x), x = f[x][0];
        x = u;
        for (ll i = 0; i <= maxd[u] - dep[u]; i++)
            ::v[u].push_back(x), x = son[x];
    }
    if (son[u]) dfs1(son[u], top);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v != son[u]) dfs1(v, v);
    }
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

ll query(ll u, ll k)
{
    if (!k) return u;
    u = f[u][g[k]], k -= (1 << g[k]);
    k -= (dep[u] - dep[top[u]]), u = top[u];
    return ((k >= 0) ? ::u[u][k] : ::v[u][-k]);
}

int main()
{
    ll lastans = 0;
    n = read(), q = read(), s = read(), g[0] = -1;
    for (ll i = 1; i <= n; i++)
    {
        f[i][0] = read(), rt = (f[i][0] ? rt : i);
        add_edge(f[i][0], i), g[i] = g[i >> 1] + 1;
    }
    dfs(rt, 0), dfs1(rt, rt);
    for (ll i = 1; i <= q; i++)
    {
        ll u = (get(s) ^ lastans) % n + 1;
        ll k = (get(s) ^ lastans) % dep[u];
        lastans = query(u, k), ans ^= 1ll * i * lastans;
    }
    printf("%lld\n", ans);
    return 0;
}
