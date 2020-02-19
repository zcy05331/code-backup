#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

ll ans;
edge e[MaxN << 1];
std::vector<std::pair<int, int>> vec;
int n, st, ed, cnt;
int head[MaxN], fa[MaxN], dep[MaxN], vis[MaxN], on[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!vis[v])
        {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}

void dfs2(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (dep[v] > dep[u])
        {
            fa[v] = u;
            dfs2(v);
            on[u] = on[u] | on[v];
        }
    }
}

inline void dfs3(int u, int root)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (dep[v] > dep[u])
            dfs3(v, on[v] ? v : root);
    }
    if (!on[u])
    {
        if (dep[u] > dep[u] + dep[ed] - (dep[root] * 2))
        {
            ans += dep[u];
            vec.push_back(std::make_pair(st, u));
        }
        else
        {
            ans += dep[u] + dep[ed] - (dep[root] * 2);
            vec.push_back(std::make_pair(ed, u));
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (dep[i] > dep[st])
            st = i;
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    dfs(st);
    for (int i = 1; i <= n; i++)
        if (dep[i] > dep[ed])
            ed = i;
    on[ed] = 1;
    dfs2(st), dfs3(st, st);
    for (; st != ed; ed = fa[ed])
        ans += dep[ed], vec.push_back(std::make_pair(st, ed));
    printf("%I64d\n", ans);
    for (auto i : vec)
        printf("%d %d %d\n", i.first, i.second, i.second);
    return 0;
}