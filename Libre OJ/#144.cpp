#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
const int MaxN = 1e6 + 10;
struct edge
{
    int next, to;
};
struct node
{
    int dfn, val, r;
};
node a[MaxN];
edge e[MaxN << 1];
int n, m, r, dfsnum, cnt;
int head[MaxN], vis[MaxN], c[MaxN];
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
        x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
    return f ? x : (-x);
}
inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline void dfs(int u)
{
    vis[u] = true, a[u].dfn = ++dfsnum;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!vis[v])
            dfs(v);
    }
    a[u].r = dfsnum;
}
inline void modify(int pos, int x)
{
    while (pos <= n)
    {
        c[pos] += x;
        pos += lowbit(pos);
    }
}
inline int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += c[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
signed main()
{
    n = read(), m = read(), r = read();
    for (int i = 1; i <= n; i++)
        a[i].val = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(r);
    for (int i = 1; i <= n; i++)
        modify(a[i].dfn, a[i].val);
    for (int i = 1; i <= m; i++)
    {
        int op = read();
        if (op == 1)
        {
            int pos = read(), x = read();
            modify(a[pos].dfn, x);
        }
        else
        {
            int pos = read();
            printf("%lld\n", query(a[pos].r) - query(a[pos].dfn - 1));
        }
    }
    return 0;
}