#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 3e3 + 10;

struct edge
{
    ll next, to;
};

edge e[MaxN << 1];
ll n, cnt, f[MaxN][MaxN], dep[MaxN][MaxN];
ll head[MaxN], fa[MaxN][MaxN], size[MaxN][MaxN];

inline void add_edge(ll u, ll v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
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

void dfs(ll root, ll u, ll f)
{
    fa[root][u] = f, size[root][u] = 1;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == f)
            continue;
        dfs(root, v, u), size[root][u] += size[root][v];
    }
}

ll dp(ll u, ll v)
{
    if (u == v)
        return 0;
    if (~f[u][v])
        return f[u][v];
    ll ans = size[u][v] * size[v][u] + std::max(dp(fa[v][u], v), dp(u, fa[u][v]));
    return (f[u][v] = ans);
}

int main()
{
    n = read();
    for (ll i = 1; i < n; i++)
    {
        ll u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        dfs(i, i, i);
    memset(f, -1, sizeof(f));
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            ans = std::max(dp(i, j), ans);
    printf("%lld\n", ans);
    return 0;
}
