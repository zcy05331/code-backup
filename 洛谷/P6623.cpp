#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 6e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

int n, m, cnt, siz[MaxN], a[MaxN], son[MaxN], ans[MaxN];
int head[MaxN], f[MaxN], b[MaxN << 1][22], dep[MaxN];

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u)
{
    siz[u] = 1, dep[u] = dep[f[u]] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs1(v), siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}

void calc(int u, int op)
{
    for (int i = 0; i <= 21; i++)
        b[a[u] & ((1 << i) - 1)][i] += op;
    for (int i = head[u]; i; i = e[i].next)
        calc(e[i].to, op);
}

void getans(int u)
{
    for (int i = head[u]; i; i = e[i].next)
        ans[u] ^= ans[e[i].to];
    for (int i = 0; i <= 21; i++)
        ans[u] ^= ((b[dep[u] & ((1 << i) - 1)][i] & 1) << i);
    ans[u] ^= (a[u] - dep[u]);
}

void dfs(int u, int tp)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (son[u] != v)
            dfs(v, 0);
    }
    if (son[u]) dfs(son[u], 1);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (son[u] != v)
            calc(v, 1);
    }
    getans(u);
    if (!tp)
    {
        for (int i = head[u]; i; i = e[i].next)
            calc(e[i].to, -1);
    }
    else
    {
        for (int i = 0; i <= 21; i++)
            b[a[u] & ((1 << i) - 1)][i]++;
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

signed main()
{
    ll Ans = 0;
    n = read(), dep[0] = -1;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 2; i <= n; i++)
        f[i] = read(), add_edge(f[i], i);
    dfs1(1);
    for (int i = 1; i <= n; i++)
        a[i] += dep[i];
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        Ans += ans[i];
    printf("%lld\n", Ans);
    return 0;
}
