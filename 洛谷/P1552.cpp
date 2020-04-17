#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

struct node
{
    ll val, sum;
    int ch[2], dep, cnt;
};

ll ans;
node t[MaxN];
edge e[MaxN];
int n, m, cnt;
int head[MaxN], f[MaxN], l[MaxN], fa[MaxN];

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int merge(int x, int y)
{
    if (!x || !y) return x + y;
    if (t[x].val < t[y].val) std::swap(x, y);
    t[x].ch[1] = merge(t[x].ch[1], y);
    if (t[t[x].ch[0]].dep < t[t[x].ch[1]].dep)
        std::swap(t[x].ch[0], t[x].ch[1]);
    t[x].dep = t[t[x].ch[1]].dep + 1;
    return x;
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

void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v), t[u].cnt += t[v].cnt;
        t[u].sum += t[v].sum, f[u] = merge(f[u], f[v]);
    }
    while (t[u].sum > m && t[u].cnt)
    {
        t[u].sum -= t[f[u]].val, t[u].cnt--;
        f[u] = merge(t[f[u]].ch[0], t[f[u]].ch[1]);
    }
    ans = std::max(ans, l[u] * 1ll * t[u].cnt);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        fa[i] = read(), t[i].val = read(), l[i] = read();
        t[i].sum = t[i].val, t[i].cnt = 1, f[i] = i, add_edge(fa[i], i);
    }
    dfs(1), printf("%lld\n", ans);
    return 0;
}