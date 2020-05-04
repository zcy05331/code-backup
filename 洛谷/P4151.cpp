#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;

struct edge
{
    ll next, to, dis;
};

edge e[MaxN];
ll n, m, cnt;
ll head[MaxN], vis[MaxN], dis[MaxN];

struct LinearBasis
{
    ll d[70];
    void insert(ll x)
    {
        for(ll i = 63; ~i; i--)
        {
            if(x & (1ll << i))
            {
                if(d[i]) x ^= d[i];
                else
                {
                    d[i] = x;
                    break;
                }
            }
        }
    }
    ll query(ll x)
    {
        ll ans = x;
        for(ll i = 63; ~i; i--)
            if((ans ^ d[i]) > ans)
                ans ^= d[i];
        return ans;
    }
} L;

void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(ll u, ll val)
{
    dis[u] = val, vis[u] = 1;
    for(ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if(!vis[v]) dfs(v, val ^ e[i].dis);
        else L.insert(dis[u] ^ e[i].dis ^ dis[v]);
    }
}

signed main()
{   
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= m; i++)
    {
        ll u, v, d;
        scanf("%lld%lld%lld", &u, &v, &d);
        add_edge(u, v, d), add_edge(v, u, d);
    }
    dfs(1, 0), printf("%lld\n", L.query(dis[n]));
    return 0;
}
