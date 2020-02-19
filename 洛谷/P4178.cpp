#include <bits/stdc++.h>
#define ll long long
const int MaxN = 50010;
struct edge
{
    int to, next, dis;
};
edge e[MaxN << 1];
int n, cnt, root;
ll k, ans, l, r;
ll dis[MaxN], q[MaxN];
int head[MaxN], size[MaxN], vis[MaxN], max, siz;
inline void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

void getroot(int u, int fa)
{
    size[u] = 1;
    int num = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        getroot(v, u);
        size[u] += size[v];
        num = std::max(num, size[v]);
    }
    num = std::max(num, siz - size[u]);
    if (num < max)
    {
        max = num;
        root = u;
    }
}
void getdis(int u, int fa)
{
    q[++r] = dis[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa || vis[v])
            continue;
        dis[v] = dis[u] + e[i].dis;
        getdis(v, u);
    }
}
int calc(int u, int val)
{
    r = 0;
    dis[u] = val;
    getdis(u, 0);
    ll sum = 0;
    l = 1;
    std::sort(q + 1, q + r + 1);
    while (l < r)
    {
        if (q[l] + q[r] <= k)
            sum += r - l, ++l;
        else
            r--;
    }
    return sum;
}
void dfs(int u)
{
    ans += calc(u, 0);
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v])
            continue;
        ans -= calc(v, e[i].dis);
        siz = size[v];
        max = 0x3f3f3f3f;
        getroot(v, 0);
        dfs(root);
    }
}
int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d);
        add_edge(v, u, d);
    }
    k = read();
    siz = n;
    max = 0x3f3f3f3f;
    getroot(1, 0);
    dfs(root);
    printf("%lld", ans);
    return 0;
}
