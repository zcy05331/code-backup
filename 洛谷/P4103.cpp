#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;
const int inf = 998244853;

int n, q;

struct edge
{
    int next, to;
};
edge e[MaxN << 1];

struct tree
{
    int cnt, dfscnt, head[MaxN], dep[MaxN], dfn[MaxN], f[MaxN][21];
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dfs(int u, int fa)
    {
        dfn[u] = ++dfscnt;
        dep[u] = dep[fa] + 1, f[u][0] = fa;
        for (int i = 1; i <= 20; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (v == fa) continue;
            dfs(v, u);
        }
    }
    int lca(int u, int v)
    {
        if (dep[u] < dep[v]) std::swap(u, v);
        for (int i = 20; ~i; i--)
            if (dep[f[u][i]] >= dep[v])
                u = f[u][i];
        if (u == v) return u;
        for (int i = 20; ~i; i--)
            if (f[u][i] != f[v][i])
                u = f[u][i], v = f[v][i];
        return f[u][0];
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
    ll sum, ans1, ans2;
    int siz[MaxN], maxd[MaxN], mind[MaxN], st[MaxN];
    int cnt, top, k, h[MaxN], is[MaxN], head[MaxN];
    void clear()
    {
        for (int i = 1; i <= k; i++)
            is[h[i]] = 0;
    }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void dp(int u)
    {
        siz[u] = is[u];
        if (is[u])
            maxd[u] = mind[u] = 0;
        else
            maxd[u] = -inf, mind[u] = inf;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, a;
            ll l = t.dep[v] - t.dep[u];
            dp(v), siz[u] += siz[v];
            sum += siz[v] * l * (k - siz[v]);
            a = maxd[v] + l;
            ans1 = std::max(ans1, maxd[u] + a * 1ll), maxd[u] = std::max(a, maxd[u]);
            a = mind[v] + l;
            ans2 = std::min(ans2, mind[u] + a * 1ll), mind[u] = std::min(a, mind[u]);
        }
    }
    void build()
    {
        k = read();
        sum = 0, ans1 = -inf, ans2 = inf;
        for (int i = 1; i <= k; i++)
            h[i] = read(), is[h[i]] = 1;
        std::sort(h + 1, h + k + 1, cmp);
        st[top = 1] = 1, head[1] = 0;
        for (int i = 1; i <= k; i++)
        {
            if (h[i] != 1)
            {
                int l = t.lca(h[i], st[top]);
                if (l != st[top])
                {
                    while (t.dfn[l] < t.dfn[st[top - 1]])
                        add_edge(st[top - 1], st[top]), top--;
                    if (t.dfn[l] != t.dfn[st[top - 1]])
                        head[l] = 0, add_edge(l, st[top]), st[top] = l;
                    else
                        add_edge(l, st[top--]);
                }
                head[h[i]] = 0, st[++top] = h[i];
            }
        }
        for (int i = 1; i < top; i++)
            add_edge(st[i], st[i + 1]);
    }
} vt;

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        t.add_edge(u, v), t.add_edge(v, u);
    }
    t.dfs(1, 0);
    q = read();
    while (q--)
    {
        vt.build(), vt.dp(1), vt.clear();
        printf("%lld %lld %lld\n", vt.sum, vt.ans2, vt.ans1);
    }
    return 0;
}
