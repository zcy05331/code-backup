#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to, dis;
};

edge e[MaxN];
int n, cnt, ans, sum, root;
int head[MaxN], size[MaxN], maxp[MaxN], dis[MaxN], vis[MaxN], buc[3];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void getroot(int u, int fa)
{
    size[u] = 1, maxp[u] = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        getroot(v, u), size[u] += size[v];
        maxp[u] = std::max(maxp[u], size[v]);
    }
    maxp[u] = std::max(maxp[u], sum - size[u]);
    (maxp[u] < maxp[root]) ? (root = u) : 0;
}

void getdis(int u, int fa)
{
    buc[dis[u]]++;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        dis[v] = sum(dis[u], e[i].dis, 3), getdis(v, u);
    }
}

ll calc(int u, int d)
{
    ll Ans = 0;
    dis[u] = d, memset(buc, 0, sizeof(buc));
    getdis(u, 0), Ans = buc[0] * buc[0] + 2ll * buc[1] * buc[2];
    return Ans;
}

void solve(int u)
{
    vis[u] = 1, ans += calc(u, 0);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v])
            continue;
        ans -= calc(v, e[i].dis % 3);
        sum = size[v], maxp[root = 0] = 0x3f3f3f3f, getroot(v, 0), solve(root);
    }
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d), add_edge(v, u, d);
    }
    maxp[root] = n, getroot(1, 0), solve(root);
    ll a = ans, b = (n * 1ll * n), g = std::__gcd(a, b);
    a /= g, b /= g;
    printf("%lld/%lld\n", a, b);
    return 0;
}
