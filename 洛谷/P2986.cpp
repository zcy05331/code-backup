#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to, dis;
};


edge e[MaxN];
ll n, m, cnt, ans;
ll head[MaxN], c[MaxN], f[MaxN], fa[MaxN], dep[MaxN], size[MaxN];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    size[u] = c[u];
    ::fa[u] = fa, f[1] += dep[u] * c[u];
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dep[v] = dep[u] + e[i].dis;
        dfs1(v, u), size[u] += size[v];
    }
}

void dfs2(int u, int fa, ll l)
{
    if(u != 1)
    {
        ll in = size[u], out = size[1] - size[u];
        f[u] = f[fa] + l * (out - in);
    }
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs2(v, u, e[i].dis);
    }
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read();
    for(int i = 1; i <= n; i++)
        c[i] = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d), add_edge(v, u, d);
    }
    ans = 0x3f3f3f3f3f3f3f3f;
    dfs1(1, 0), dfs2(1, 0, 0);
    for(int i = 1; i <= n; i++)
        ans = std::min(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}
