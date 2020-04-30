#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 6e5 + 10;
const int mod = 998244353;

struct edge
{
    int next, to;
};

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

edge e[MaxN];
int n, m, cnt;
int head[MaxN], dep[MaxN], fa[MaxN][21];
mod_t val[MaxN][51], num[MaxN][51];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    dep[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        num[i][0] = 1;
        for(int j = 1; j <= 50; j++)
            num[i][j] = num[i][j - 1] * mod_t(i);
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

int lca(int u, int v)
{
    if(dep[u] < dep[v])
        std::swap(u, v);
    for(int i = 20; ~i; i--)
        if(dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if(u == v) return u;
    for(int i = 20; ~i; i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void dfs(int u, int fa)
{
    ::fa[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = 1; i <= 20; i++)
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    for(int i = 0; i <= 50; i++)
        val[u][i] = val[fa][i] + num[dep[u]][i];
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u);
    }
}

int main()
{   
    n = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    m = read(), init(), dfs(1, 0);
    while(m--)
    {
        mod_t ans = 0;
        int u = read(), v = read();
        int k = read(), l = lca(u, v), fl = fa[l][0];
        ans = val[u][k] + val[v][k] - val[l][k] - val[fl][k];
        printf("%d\n", ans.x);
    }
    return 0;
}
