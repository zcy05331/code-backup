#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll next, to;
};

char type[3];
edge e[MaxN << 1];
ll n, q, cnt, a, x, b, y;
ll p[MaxN], head[MaxN], dep[MaxN], fa[MaxN], f[MaxN][2];

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

void dfs(ll u, ll f)
{
    dep[u] = dep[f] + 1, fa[u] = f;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == f)
            continue;
        dfs(v, u);
    }
}

void dp(ll u, ll fa)
{
    f[u][1] = p[u];
    if (((u == a && x == 0) || (u == b && y == 0)))
        f[u][1] = inf;
    if (((u == a && x == 1) || (u == b && y == 1)))
        f[u][0] = inf;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa)
            continue;
        dp(v, u);
        if (f[u][0] != inf)
        {
            if (f[v][1] != inf)
                f[u][0] += f[v][1];
            else
                f[u][0] = inf;
        }
        if (f[u][1] != inf)
            f[u][1] += std::min(f[v][1], f[v][0]);
    }
}

int main()
{
    n = read(), q = read(), scanf("%s", type + 1);
    for (ll i = 1; i <= n; i++)
        p[i] = read();
    for (ll i = 1; i < n; i++)
    {
        ll u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    while (q--)
    {
        a = read(), x = read(), b = read(), y = read();
        if ((fa[a] == b || fa[b] == a) && ((x + y) == 0))
        {
            printf("%lld\n", -1ll);
            continue;
        }
        memset(f, 0, sizeof(f)), dp(1, 0);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        ans = std::min(ans, f[1][1]), ans = std::min(ans, f[1][0]);
        // for (int i = 1; i <= n; i++)
        //     printf("%lld\t", f[i][0]);
        // puts("");
        // for (int i = 1; i <= n; i++)
        //     printf("%lld\t", f[i][1]);
        // puts("");
        ans = std::min(ans, std::min(f[1][1], f[1][0]));
        printf("%lld\n", ans);
    }
    return 0;
}
