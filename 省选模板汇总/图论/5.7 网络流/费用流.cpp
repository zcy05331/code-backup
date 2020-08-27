#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll next, to, flow, cost;
};

edge e[MaxN << 1];
ll n, m, s = 20001, t = 20002, cnt = 1, mincost, maxflow;
ll head[MaxN], dis[MaxN], vis[MaxN], cur[MaxN];

void add(ll u, ll v, ll f, ll c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].cost = c;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(ll u, ll v, ll f, ll c) { add(u, v, f, c), add(v, u, 0, -c); }

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

ll spfa()
{
    std::queue<ll> q;
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    dis[s] = 0, vis[s] = 1, q.push(s);
    while(!q.empty())
    {
        ll u = q.front();
        q.pop(), vis[u] = 0;
        for(ll i = head[u]; i; i = e[i].next)
        {
            ll v = e[i].to, c = e[i].flow;
            if(dis[v] > dis[u] + e[i].cost && c)
            {
                dis[v] = dis[u] + e[i].cost;
                if(!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    return (dis[t] != inf);
}

ll dinic(ll u, ll flow)
{
    if(u == t) 
    {
        maxflow += flow;
        return flow;
    }
    ll rest = flow; 
    vis[u] = 1;
    for(ll i = cur[u]; i && rest; i = e[i].next)
    {
        ll v = e[i].to, c = e[i].flow;
        if(!vis[v] && (dis[v] == dis[u] + e[i].cost) && c)
        {
            cur[u] = i;
            ll k = dinic(v, std::min(rest, e[i].flow));
            rest -= k, e[i].flow -= k, e[i ^ 1].flow += k, mincost += k * e[i].cost;
        }
    }
    vis[u] = 0;
    return flow - rest;
}

void mcmf()
{
    while(spfa())
    {
        memset(vis, 0, sizeof(vis));
        dinic(s, inf);
    }
}

signed main()
{   
    n = read(), m = read(), s = read(), t = read();
    for(ll i = 1; i <= m; i++)
    {
        ll u = read(), v = read(), f = read(), c = read();
        add_edge(u, v, f, c);
    }
    mcmf(), printf("%lld %lld\n", maxflow, mincost);
    return 0;
}
