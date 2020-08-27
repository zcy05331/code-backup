#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll mod = 1e9 + 7;
const ll MaxN = 2e5 + 10;

struct edge
{
    ll next, to;
};

edge e[MaxN];
ll n, m, cnt;
std::vector<ll> p, q;
ll head[MaxN], val[MaxN], size[MaxN];

void add_edge(ll u, ll v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    n = m = cnt = 0;
    p.clear(), q.clear();
    memset(val, 0, sizeof(val));
    memset(head, 0, sizeof(head));
    memset(size, 0, sizeof(size));
}

void dfs(ll u, ll fa)
{
    size[u] = 1;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa) continue;
        dfs(v, u), size[u] += size[v];
        val[v] = (size[v] * 1ll * (n - size[v]));
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

signed main()
{
    ll T = read();
    while (T--)
    {
        init(), n = read();
        for (ll i = 1; i < n; i++)
        {
            ll u = read(), v = read();
            add_edge(u, v), add_edge(v, u);
        }
        dfs(1, 0), m = read();
        for(ll i = 2; i <= n; i++)
            q.push_back(val[i]);
        for (ll i = 1, u; i <= m; i++)
            p.push_back((u = read()));
        if (m <= n - 1)
        {
            for (ll i = m + 1; i < n; i++)
                p.push_back(1);
            std::sort(p.begin(), p.end());
        }
        else
        {
            ll x = 1;
            std::sort(p.begin(), p.end());
            for(ll i = n - 1; i <= m; i++)
                x = (x * p[i - 1]) % mod;
            p[n - 2] = x, p.erase(p.begin() + n - 1, p.end());
            // for(auto x : p) printf("%d ", x); puts("");
        }
        ll ans = 0;
        std::sort(p.begin(), p.end());
        std::sort(q.begin(), q.end());
        for(int i = 0; i < n - 1; i++)
            ans = sum(ans, (q[i] % mod) * p[i] % mod, mod);
        printf("%lld\n", ans);
    }
    return 0;
}
