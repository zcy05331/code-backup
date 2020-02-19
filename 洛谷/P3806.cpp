#include <bits/stdc++.h>

const int MaxN = 100010;
const int lim = 10000010;

struct edge
{
    int to, next, dis;
};

edge e[MaxN << 1];
int query[1010], sum, root, ans, n, m;
int cnt, head[MaxN], vis[MaxN], test[lim], ok[lim];
int maxp[MaxN], size[MaxN], dis[MaxN], rem[MaxN], q[MaxN];

inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void getroot(int u, int fa)
{
    size[u] = 1, maxp[u] = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        getroot(v, u);
        size[u] += size[v];
        maxp[u] = std::max(maxp[u], size[v]);
    }
    maxp[u] = std::max(maxp[u], sum - size[u]);
    if (maxp[u] < maxp[root])
        root = u;
}

void getdis(int u, int fa)
{
    rem[++rem[0]] = dis[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        dis[v] = dis[u] + e[i].dis;
        getdis(v, u);
    }
}

void calc(int u)
{
    int p = 0;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(vis[v])
            continue;
        rem[0] = 0;
        dis[v] = e[i].dis;
        getdis(v, u);
        for(int j = rem[0]; j; --j)
            for(int k = 1; k <= m; ++k)
                if(query[k] >= rem[j])
                    test[k] |= ok[query[k] - rem[j]];
        for(int j = rem[0]; j; --j)
            q[++p] = rem[j], ok[rem[j]] = 1;
    }
    for(int i = 1; i <= p; ++i)
        ok[q[i]] = 0;
}
void solve(int u)
{
    vis[u] = ok[0] = 1;
    calc(u);
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(vis[v])
            continue;
        sum = size[v];
        maxp[root = 0] = lim;
        getroot(v, 0);
        solve(root);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    for(int i = 1; i <= m; i++)
        scanf("%d", &query[i]);
    maxp[root] = sum = n;
    getroot(1, 0);
    solve(root);
    for(int i = 1; i <= m; i++)
    {
        if(test[i])
            printf("AYE\n");
        else 
            printf("NAY\n");
    }
    return 0;
}