#include <bits/stdc++.h>

const int MaxN = 300010;

struct edge
{
    int to, next, dis;
};

struct query
{
    int u, v, dis, lca;
};

query q[MaxN];
edge e[MaxN << 1];
int n, m, cnt, dfscnt, l, r;
int head[MaxN], dep[MaxN], val[MaxN];
int f[MaxN][40], dfn[MaxN], num[MaxN], dis[MaxN];

inline void add_edge(int u, int v, int dis)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = dis;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

inline void dfs(int u, int fa)
{
    f[u][0] = fa;
    dfn[u] = ++dfscnt;
    num[dfscnt] = u;
    dep[u] = dep[fa] + 1;
    for(int i = 1; i <= 30; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(dfn[v])
            continue;
        dis[v] = dis[u] + e[i].dis;
        dfs(v, u);
    }
}

inline int lca(int u, int v)
{
    if(dep[u] < dep[v])
        std::swap(u, v);
    for(int i = 30; i >= 0; i--)
    {
        if(dep[f[u][i]] >= dep[v])
            u = f[u][i];
        if(u == v)
            return u;
    }
    for(int i = 30; i >= 0; i--)
    {
        if(f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}

inline bool check(int x)
{
    int cnt = 0, ans = 0;
    memset(val, 0, sizeof(val));
    for(int i = 1; i <= m; i++)
    {
        if(q[i].dis > x)
        {
            ++val[q[i].u], ++val[q[i].v];
            val[q[i].lca] -= 2;
            ans = std::max(ans, q[i].dis - x);
            ++cnt;
        }
    }
    if(cnt == 0)
        return true;
    for(int i = n; i >= 1; i--)
        val[f[num[i]][0]] += val[num[i]];
    for(int i = 2; i <= n; i++)
        if(val[i] == cnt && dis[i] - dis[f[i][0]] >= ans)
            return true;
    return false;
}

int main()
{   
    n = read(), m = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        add_edge(v, u, d);
        r += d;
    }
    dfs(1, 0);
    for(int i = 1; i <= m; i++)
    {
        q[i].u = read(), q[i].v = read();
        q[i].lca = lca(q[i].u, q[i].v);
        q[i].dis = dis[q[i].u] + dis[q[i].v] - 2 * dis[q[i].lca];
    }
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
