#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

ll max = 0, sum = 0, ans[MaxN];
int n, m, cnt, cur, son[MaxN], num[MaxN];
int head[MaxN], c[MaxN], siz[MaxN], dep[MaxN];

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

void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1, siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
            son[u] = v;
    }
}

void calc(int u, int fa, int val)
{
    num[c[u]] += val;
    if (num[c[u]] > max)
        max = num[c[u]], sum = c[u];
    else if (num[c[u]] == max)
        sum += c[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || v == cur)
            continue;
        calc(v, u, val);
    }
}

void dfs2(int u, int fa, int op)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u])
        dfs2(son[u], u, 1), cur = son[u];
    calc(u, fa, 1), cur = 0, ans[u] = sum;
    if (!op) calc(u, fa, -1), sum = max = 0;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs1(1, 0), dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}
