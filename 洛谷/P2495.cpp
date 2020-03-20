#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int next, to, dis;
};

int n, m;

struct tree
{
    edge e[MaxN << 1];
    int cnt, dfscnt, head[MaxN], dep[MaxN], dfn[MaxN], f[MaxN][21], min[MaxN][21];
    void add_edge(int u, int v, int d)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].dis = d;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dfs(int u, int fa)
    {
        dfn[u] = ++dfscnt;
        dep[u] = dep[fa] + 1, f[u][0] = fa;
        for (int i = 1; i <= 20; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
            min[u][i] = std::min(min[u][i - 1], min[f[u][i - 1]][i - 1]);
        }
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (v == fa) continue;
            min[v][0] = e[i].dis, dfs(v, u);
        }
    }
#define pir std::pair<int, int>
    pir lca(int u, int v)
    {
        int ans = 0x3f3f3f3f;
        if (dep[u] < dep[v]) std::swap(u, v);
        for (int i = 20; ~i; i--)
            if (dep[f[u][i]] >= dep[v])
                ans = std::min(ans, min[u][i]), u = f[u][i];
        if (u == v)
            return {u, ans};
        for (int i = 20; ~i; i--)
        {
            if (f[u][i] != f[v][i])
            {
                ans = std::min(min[u][i], ans), u = f[u][i];
                ans = std::min(min[v][i], ans), v = f[v][i];
            }
        }
        return {f[u][0], ans};
    }
} t;

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

int cmp(int a, int b) { return t.dfn[a] < t.dfn[b]; }

struct VirtualTree
{
    edge e[MaxN << 1];
    ll f[MaxN];
    int k, cnt, top, head[MaxN], h[MaxN], st[MaxN], is[MaxN];
    void add_edge(int u, int v, int d)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].dis = d;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dp(int u)
    {
        f[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dp(v);
            if (!is[v])
                f[u] += std::min(f[v], e[i].dis * 1ll);
            else
                f[u] += e[i].dis;
        }
    }
    void build()
    {
        cnt = head[1] = 0;
        k = read(), st[top = 1] = 1;
        for (int i = 1; i <= k; i++)
            h[i] = read(), is[h[i]] = 1;
        std::sort(h + 1, h + k + 1, cmp);
        for (int i = 1; i <= k; i++)
        {
            if (h[i] != 1)
            {
                int l = t.lca(h[i], st[top]).first;
                if (l != st[top])
                {
                    while (t.dfn[l] < t.dfn[st[top - 1]])
                    {
                        int minn = t.lca(st[top - 1], st[top]).second;
                        add_edge(st[top - 1], st[top], minn), --top;
                    }
                    if (t.dfn[l] != t.dfn[st[top - 1]])
                    {
                        int minn = t.lca(l, st[top]).second;
                        head[l] = 0, add_edge(l, st[top], minn), st[top] = l;
                    }
                    else
                    {
                        int minn = t.lca(l, st[top]).second;
                        add_edge(l, st[top], minn), top--;
                    }
                }
                head[h[i]] = 0, st[++top] = h[i];
            }
        }
        for (int i = 1; i < top; i++)
        {
            int minn = t.lca(st[i], st[i + 1]).second;
            add_edge(st[i], st[i + 1], minn);
        }
    }
    void solve()
    {
        build(), dp(1), printf("%lld\n", f[1]);
        for (int i = 1; i <= k; i++)
            is[h[i]] = 0;
    }
} vt;

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        t.add_edge(u, v, d), t.add_edge(v, u, d);
    }
    t.dfs(1, 0), m = read();
    while (m--)
        vt.solve();
    return 0;
}
