#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

struct edge
{
    ll next, to, dis;
};

edge e[MaxN << 1];
std::pair<ll, ll> h[MaxN];
ll n, m, cnt, acnt, bcnt, ccnt;
ll ok[MaxN], tim[MaxN], need[MaxN], used[MaxN];
ll dep[MaxN], head[MaxN], f[MaxN][21], dis[MaxN][21], q[MaxN];

inline void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(ll u, ll fa)
{
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (ll i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1], dis[u][i] = dis[u][i - 1] + dis[f[u][i - 1]][i - 1];
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa)
            continue;
        dis[v][0] = e[i].dis, dfs1(v, u);
    }
}

bool dfs2(ll u, ll fa)
{
    bool son = 0;
    if (ok[u])
        return 1;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa)
            continue;
        son = 1;
        if (!dfs2(v, u))
            return 0;
    }
    if (!son)
        return 0;
    return 1;
}

void init()
{
    acnt = bcnt = ccnt = cnt = 0;
    memset(ok, 0, sizeof(ok));
    memset(tim, 0, sizeof(tim));
    memset(need, 0, sizeof(need));
    memset(h, 0, sizeof(h));
    memset(used, 0, sizeof(used));
}

bool check(ll lim)
{
    init();
    for (ll i = 1; i <= m; i++)
    {
        ll x = q[i], cnt = 0;
        for (ll j = 20; ~j; j--)
        {
            if (f[x][j] > 1 && (cnt + dis[x][j] <= lim))
                cnt += dis[x][j], x = f[x][j];
        }
        if (f[x][0] == 1 && cnt + dis[x][0] <= lim)
            h[++ccnt] = std::make_pair(lim - cnt - dis[x][0], x);
        else
            ok[x] = 1;
    }
    for (ll i = head[1]; i; i = e[i].next)
        if (!dfs2(e[i].to, 1))
            need[e[i].to] = 1;
    std::sort(h + 1, h + ccnt + 1);
    for (ll i = 1; i <= ccnt; i++)
    {
        if (need[h[i].second] && h[i].first < dis[h[i].second][0])
            need[h[i].second] = 0;
        else
            tim[++acnt] = h[i].first;
    }
    for (ll i = head[1]; i; i = e[i].next)
    {
        if (need[e[i].to])
            used[++bcnt] = dis[e[i].to][0];
    }
    if (acnt < bcnt)
        return 0;
    std::sort(tim + 1, tim + acnt + 1), std::sort(used + 1, used + bcnt + 1);
    ll l = 1, r = 1;
    while (l <= acnt && r <= bcnt)
    {
        if (tim[l] >= used[r])
            ++l, ++r;
        else
            ++l;
    }
    if (r > bcnt)
        return 1;
    return 0;
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

int main()
{
    n = read();
    ll l = 0, r = 0, sum;
    for (ll i = 1; i < n; i++)
    {
        ll u = read(), v = read(), d = read();
        add_edge(u, v, d), add_edge(v, u, d), r += d;
    }
    sum = r;
    dfs1(1, 0);
    m = read();
    for (ll i = 1; i <= m; i++)
        q[i] = read();
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l >= sum)
        printf("-1\n");
    else
        printf("%lld\n", l);
    return 0;
}
