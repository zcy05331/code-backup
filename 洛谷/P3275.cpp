#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;

struct edge
{
    ll next, from, to, dis;
};

std::stack<ll> st;
std::queue<ll> q;
edge e[MaxN << 1], e2[MaxN << 1];
ll n, m, cnt, Cnt, dfscnt, colcnt;
ll head[MaxN], dfn[MaxN], low[MaxN];
ll col[MaxN], ins[MaxN], dis[MaxN], ind[MaxN];

void add_edge2(ll u, ll v, ll d)
{
    ++Cnt;
    e2[Cnt].to = v;
    e2[Cnt].dis = d;
    e2[Cnt].next = head[u];
    head[u] = Cnt, ind[v]++;
}

void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].from = u;
    e[cnt].dis = d;
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

void tarjan(ll u)
{
    dfn[u] = low[u] = ++dfscnt;
    ins[u] = 1, st.push(u);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++colcnt;
        ll v;
        do
        {
            v = st.top(), st.pop();
            ins[v] = 0, col[v] = colcnt;
        } while (v != u);
    }
}

int main()
{
    n = read(), m = read();
    for (ll i = 1; i <= n; i++)
        add_edge(i, 0, 1);
    for (ll i = 1; i <= m; i++)
    {
        ll x = read(), u = read(), v = read();
        if (x == 1)
            add_edge(u, v, 0), add_edge(v, u, 0);
        else if (x == 2)
            add_edge(v, u, 1);
        else if (x == 3)
            add_edge(u, v, 0);
        else if (x == 4)
            add_edge(u, v, 1);
        else if (x == 5)
            add_edge(v, u, 0);
    }
    for (ll i = 0; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    memset(head, 0, sizeof(head));
    for (ll i = 1; i <= cnt; i++)
    {
        ll u = e[i].from, v = e[i].to;
        if (col[u] == col[v])
        {
            if (e[i].dis)
                return 0 * printf("-1");
        }
        else if (col[u] != col[v])
            add_edge2(col[v], col[u], e[i].dis);
    }
    for (ll i = 1; i <= colcnt; i++)
        if (!ind[i])
            q.push(i);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = head[u]; i; i = e2[i].next)
        {
            ll v = e2[i].to;
            dis[v] = std::max(dis[v], dis[u] + e2[i].dis);
            if (--ind[v] == 0)
                q.push(v);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += dis[col[i]];
    printf("%lld\n", ans);
    return 0;
}
