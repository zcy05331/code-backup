#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

struct edge
{
    int next, to;
};

char s[MaxN];
edge e[MaxN << 1];
int n, m, cnt, curson;
int w[MaxN], head[MaxN], num[MaxN], dep[MaxN];
int size[MaxN], hson[MaxN], ans[MaxN], p[1 << 23], f[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs1(int u, int fa)
{
    size[u] = 1, dep[u] = dep[fa] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        w[v] = w[u] ^ (1 << (s[v] - 'a')), dfs1(v, u), size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}

void calc(int root, int x)
{
    ans[root] = std::max(ans[root], p[w[x]] + dep[x] - 2 * dep[root]);
    for (int i = 0; i <= 21; i++)
        ans[root] = std::max(ans[root], p[w[x] ^ (1 << i)] + dep[x] - 2 * dep[root]);
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != f[x])
            calc(root, v);
    }
}

void query(int u)
{
    p[w[u]] = std::max(p[w[u]], dep[u]);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != f[u])
            query(v);
    }
}

void del(int u)
{
    p[w[u]] = -0x3f3f3f3f;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != f[u])
            del(v);
    }
}

void dfs2(int u, int fa, int op)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != hson[u] && v != fa)
            dfs2(v, u, 0), ans[u] = std::max(ans[u], ans[v]);
    }
    if (hson[u])
        dfs2(hson[u], u, 1), ans[u] = std::max(ans[u], ans[hson[u]]);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == hson[u] || v == fa)
            continue;
        calc(u, v), query(v);
    }
    ans[u] = std::max(ans[u], p[w[u]] - dep[u]);
    for (int i = 0; i <= 21; i++)
        ans[u] = std::max(ans[u], p[w[u] ^ (1 << i)] - dep[u]);
    p[w[u]] = std::max(p[w[u]], dep[u]);
    if (!op)
        del(u);
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d %c", &f[i], &s[i]), add_edge(f[i], i), add_edge(i, f[i]);
    for (int i = 0; i <= (1 << 22) - 1; i++)
        p[i] = -0x3f3f3f3f;
    dfs1(1, 0), dfs2(1, 0, 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
