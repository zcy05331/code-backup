#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const ll inf = 1e18 + 3;
const ll MaxN = 1e4 + 10;

struct edge
{
    ll next, to, flow;
} e[MaxN << 1];

ll n, m, s, t, cnt, ans;
ll head[MaxN], cur[MaxN], dep[MaxN];

void add(ll u, ll v, ll f)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void add_edge(ll u, ll v, ll f) { add(u, v, f), add(v, u, 0); }

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll bfs()
{
    std::queue<ll> q;
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    dep[s] = 1, q.push(s);
    while(!q.empty())
    {
        ll u = q.front(); q.pop();
        for(ll i = head[u]; i; i = e[i].next)
        {
            ll v = e[i].to, c = e[i].flow;
            if(dep[v] || !c) continue;
            dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[t];
}

ll dinic(ll u, ll flow)
{
    if(u == t) return flow;
    ll rest = flow;
    for(ll i = cur[u]; i && rest; i = e[i].next)
    {
        ll v = e[i].to, c = e[i].flow, k;
        if(dep[v] == dep[u] + 1 && c)
        {
            cur[u] = i, k = dinic(v, std::min(c, rest));
            if(k) rest -= k, e[i].flow -= k, e[i ^ 1].flow += k;
            else dep[v] = -1;
        }
    }
    if(rest) dep[u] = -1;
    return flow - rest;
}

void solve()
{
    ll now = 0;
    while(bfs())
        while((now = dinic(s, inf)))
            ans -= now;
}

signed main()
{   
    n = read(), m = read(), cnt = 1;
    s = n + m + 1, t = n + m + 2;
    for(ll i = 1, x; i <= n; i++)
        x = read(), add_edge(s, i, x);
    for(ll i = 1, u, v, w; i <= m; i++)
    {
        u = read(), v = read(), w = read(), add_edge(u, i + n, inf);
        add_edge(v, i + n, inf), ans += w, add_edge(i + n, t, w);
    }
    solve(), printf("%lld\n", ans);
    return 0;
}
