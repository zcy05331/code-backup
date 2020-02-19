#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 3e5 + 10;

struct edge
{
    ll next, to;
};

edge e[MaxN];
ll n, m, cnt;
ll a[MaxN], f[MaxN], c[MaxN], size[MaxN], head[MaxN];

ll get(ll x) { return ((x == -1) ? -1 : (x ^ 1)); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void add_edge(ll u, ll v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

ll getf(ll x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void dfs(ll u, ll fa, ll val)
{
    c[u] = val;
    for (ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u, get(val));
    }
}

void merge(ll a, ll b)
{
    ll u = getf(a), v = getf(b);
    if (u == v)
    {
        if (c[a] == c[b] && c[a] != -1)
            dfs(a, 0, -1);
        return;
    }
    if (size[u] < size[v])
        std::swap(a, b), std::swap(u, v);
    size[u] += size[v], f[v] = u;
    dfs(b, 0, get(c[a])), add_edge(a, b), add_edge(b, a);
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
    n = read(), m = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read(), size[i] = 1, f[i] = i;
    while (m--)
    {
        ll op = read(), x = read(), y = read();
        if (op == 1)
            a[x] = y;
        else if (op == 2)
            merge(x, y);
        else
        {
            ll v = read();
            if(getf(x) != getf(y) || c[y] == -1)
                printf("0\n");
            else
            {
                ll h = v * 1ll * a[x], l = a[y], g = gcd(h, l);
                if (c[x] != c[y])
                    putchar('-');
                printf("%lld/%lld\n", h / g, l / g);
            }
        }
    }
    return 0;
}
