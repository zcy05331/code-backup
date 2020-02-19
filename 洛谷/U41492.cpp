#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, cnt, tot, cur;
int son[MaxN], size[MaxN], ans[MaxN];
int cnt_[MaxN], col[MaxN], head[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa)
{
    size[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u), size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
}

void calc(int u, int fa, int val)
{
    if (!cnt_[col[u]])
        ++tot;
    cnt_[col[u]] += val;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || v == cur)
            continue;
        calc(v, u, val);
    }
}

void dsu(int u, int fa, bool op)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || v == son[u])
            continue;
        dsu(v, u, 0);
    }
    if (son[u])
        dsu(son[u], u, 1), cur = son[u];
    calc(u, fa, 1), cur = 0, ans[u] = tot;
    if (!op)
        calc(u, fa, -1), tot = 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &col[i]);
    dfs1(1, 0), dsu(1, 0, 1);
    scanf("%d", &m);
    while (m--)
    {
        int u;
        scanf("%d", &u);
        printf("%d\n", ans[u]);
    }
    return 0;
}
