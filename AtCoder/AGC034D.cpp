#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 4e3 + 10;
const ll MaxM = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    ll next, to, flow, cost;
};

edge e[MaxM << 1];
ll n, m, s = 3001, t = 3002, cnt, mincost, maxflow;
ll head[MaxN], x[MaxN], y[MaxN], c[MaxN], dis[MaxN], cur[MaxN], vis[MaxN];

void add(ll u, ll v, ll f, ll c)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].cost = c;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(ll u, ll v, ll f, ll c) { add(u, v, f, -c), add(v, u, 0, c); }

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

ll spfa()
{
    std::queue<ll> q;
    memset(dis, 0x3f, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    dis[s] = 0, vis[s] = 1, q.push(s);
    while (!q.empty())
    {
        ll u = q.front();
        vis[u] = 0, q.pop();
        for (ll i = head[u]; i; i = e[i].next)
        {
            ll v = e[i].to, c = e[i].flow;
            if ((dis[v] > dis[u] + e[i].cost) && c)
            {
                dis[v] = dis[u] + e[i].cost;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return (dis[t] != inf);
}

ll dinic(ll u, ll flow)
{
    if (u == t)
    {
        maxflow += flow;
        return flow;
    }
    vis[u] = 1;
    ll rest = flow;
    for (ll i = cur[u]; i && rest; i = e[i].next)
    {
        ll v = e[i].to, c = e[i].flow;
        if (!vis[v] && (dis[v] == dis[u] + e[i].cost) && c)
        {
            cur[u] = i;
            ll k = dinic(v, std::min(e[i].flow, rest));
            rest -= k, e[i].flow -= k, e[i ^ 1].flow += k, mincost += k * e[i].cost;
        }
    }
    vis[u] = 0;
    return flow - rest;
}

void mcmf()
{
    while (spfa())
        memset(vis, 0, sizeof(vis)), dinic(s, inf);
}

signed main()
{
    n = read(), cnt = 1;
    for (ll i = 1; i <= n; i++)
    {
        x[i] = read(), y[i] = read(), c[i] = read(), add_edge(s, i, c[i], 0);
        add_edge(i, 2 * n + 1, inf, x[i] + y[i]), add_edge(i, 2 * n + 2, inf, x[i] - y[i]);
        add_edge(i, 2 * n + 3, inf, -x[i] + y[i]), add_edge(i, 2 * n + 4, inf, -x[i] - y[i]);
    }
    for (ll i = 1; i <= n; i++)
    {
        x[i] = read(), y[i] = read(), c[i] = read(), add_edge(i + n, t, c[i], 0);
        add_edge(2 * n + 1, i + n, inf, -x[i] - y[i]), add_edge(2 * n + 2, i + n, inf, -x[i] + y[i]);
        add_edge(2 * n + 3, i + n, inf, x[i] - y[i]), add_edge(2 * n + 4, i + n, inf, x[i] + y[i]);
    }
    mcmf(), printf("%lld\n", -mincost);
    return 0;
}
