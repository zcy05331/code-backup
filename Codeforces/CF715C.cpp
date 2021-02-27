#include <bits/stdc++.h>

#define R register
#define ll long long
#define mp(i, j) std::make_pair(i, j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e5 + 10;

struct edge
{
    ll next, to, dis;
} e[MaxN << 1];

std::map<ll, ll> s;
std::pair<ll, ll> d[MaxN << 1];
ll n, m, cnt, sum, ans, num, root, p[MaxN];
ll head[MaxN], f[MaxN], dep[MaxN], vis[MaxN], siz[MaxN];

void add_edge(ll u, ll v, ll d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll z = x; x = y, y = z - a / b * y;
    return d;
}

ll Inv(ll a, ll m)
{
    ll x, y, d = exgcd(a, m, x, y);
    return (d == 1) ? (x % m + m) % m : -1;
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

void getdigit(ll u, ll fa, ll d1, ll d2, ll dep)
{
    if (dep >= 0) ++s[d1], d[++num] = mp(d2, dep);
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to, w = e[i].dis;
        if (v == fa || vis[v]) continue;
        ll d3 = (d1 + w * p[dep + 1]) % m;
        ll d4 = (d2 * 10 + w) % m;
        getdigit(v, u, d3, d4, dep + 1);
    }
}

void getroot(ll u, ll fa)
{
    siz[u] = 1, f[u] = 0;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (vis[v] || v == fa) continue;
        getroot(v, u), siz[u] += siz[v];
        f[u] = std::max(f[u], siz[v]);
    }
    f[u] = std::max(f[u], sum - f[u]);
    if (f[u] < f[root]) root = u;
}

ll calc(ll u, ll dig)
{
    s.clear(); ll ret = 0; num = 0;
    if(dig) 
        getdigit(u, 0, dig % m, dig % m, 0);
    else getdigit(u, 0, 0, 0, -1);
    for(ll i = 1; i <= num; i++)
    {
        ll tmp = (-d[i].first * Inv(p[d[i].second + 1], m) % m + m) % m;
        if(s.find(tmp) != s.end()) ret += s[tmp];
        if(!dig) ret += !d[i].first;
    }
    if(!dig) ret += s[0];
    return ret;
}

void solve(ll u)
{
    ans += calc(u, 0), vis[u] = 1;
    for(ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to, w = e[i].dis;
        if(vis[v]) continue;
        ans -= calc(v, w), sum = siz[v];
        f[0] = n, root = 0, getroot(v, u), solve(root);
    }
}

signed main()
{
    n = read(), m = read();
    for(ll i = 1, u, v, d; i < n; i++)
    {
        u = read() + 1, v = read() + 1, d = read();
        add_edge(u, v, d), add_edge(v, u, d);
    }
    p[0] = 1;
    for(ll i = 1; i <= n; i++)
        p[i] = p[i - 1] * 10 % m;
    f[0] = sum = n, getroot(1, 0), solve(root);
    printf("%lld\n", ans);
    return 0;
}
