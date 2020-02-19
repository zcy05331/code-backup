#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e5 + 10;

struct edge
{
    int nxt, to, dis;
};

edge e[MaxN << 1];
int n, m, cnt;
int head[MaxN], x[MaxN], y[MaxN], f[MaxN], wf[MaxN], dep[MaxN];

inline void add_(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

inline void add_edge(int u, int v, int d) { add_(u, v, d), add_(v, u, d); }

inline void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1, f[u] = fa;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u), wf[v] = e[i].dis;
    }
}

inline void update1(int u, int v, int c)
{
    if (dep[u] < dep[v])
        std::swap(u, v);
    while (dep[u] ^ dep[v])
        wf[u] = c, u = f[u];
    while (u ^ v)
        wf[u] = c, wf[v] = c, u = f[u], v = f[v];
}

inline void update2(int u, int v)
{
    if (dep[u] < dep[v])
        std::swap(u, v);
    while (dep[u] ^ dep[v])
        wf[u] *= -1, u = f[u];
    while (u ^ v)
        wf[u] *= -1, wf[v] *= -1, u = f[u], v = f[v];
}

int query_sum(int u, int v)
{
    int ret = 0;
    if (dep[u] < dep[v])
        std::swap(u, v);
    while (dep[u] ^ dep[v])
        ret += wf[u], u = f[u];
    while (u ^ v)
        ret += wf[u], ret += wf[v], u = f[u], v = f[v];
    return ret;
}

inline int query_max(int u, int v)
{
    int ret = -1e9;
    if (dep[u] < dep[v])
        std::swap(u, v);
    while (dep[u] ^ dep[v])
        ret = std::max(ret, wf[u]), u = f[u];
    while (u ^ v)
        ret = std::max(ret, std::max(wf[u], wf[v])), u = f[u], v = f[v];
    return ret;
}

inline int query_min(int u, int v)
{
    int ret = 1e9;
    if (dep[u] < dep[v])
        std::swap(u, v);
    while (dep[u] ^ dep[v])
        ret = std::min(ret, wf[u]), u = f[u];
    while (u ^ v)
        ret = std::min(ret, std::min(wf[u], wf[v])), u = f[u], v = f[v];
    return ret;
}

int main()
{
    int u, v, d;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        scanf("%d%d%d", &x[i], &y[i], &d), ++x[i], ++y[i], add_edge(x[i], y[i], d);
    dfs(1, 0);
    scanf("%d", &m);
    char op[5];
    while (m--)
    {
        scanf("%s %d %d", op, &u, &v);
        if (op[0] == 'C')
            update1(x[u], y[u], v);
        else if (op[0] == 'N')
            update2(u + 1, v + 1);
        else if (op[0] == 'S')
            printf("%d\n", query_sum(u + 1, v + 1));
        else
        {
            if (op[1] == 'A')
                printf("%d\n", query_max(u + 1, v + 1));
            else
                printf("%d\n", query_min(u + 1, v + 1));
        }
    }
    return 0;
}
