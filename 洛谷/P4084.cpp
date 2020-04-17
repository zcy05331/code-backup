#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1e9 + 7;
const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN];
ll ans, f[MaxN][3];
int n, m, cnt, head[MaxN], col[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
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

void dp(int u, int fa)
{
    if (~col[u])
        f[u][col[u]] = 1;
    else
        f[u][0] = f[u][1] = f[u][2] = 1;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dp(v, u);
        f[u][0] = f[u][0] * (f[v][1] + f[v][2]) % mod;
        f[u][1] = f[u][1] * (f[v][0] + f[v][2]) % mod; 
        f[u][2] = f[u][2] * (f[v][0] + f[v][1]) % mod;
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    memset(col, -1, sizeof(col));
    for (int i = 1, u; i <= m; i++)
        u = read(), col[u] = read() - 1;
    dp(1, 0), ans = (f[1][0] + f[1][1] + f[1][2]) % mod;
    printf("%lld\n", ans);
    return 0;
}
