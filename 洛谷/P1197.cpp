#include <bits/stdc++.h>
const int MaxN = 500010;
struct edge
{
    int next, to, from;
};
edge e[MaxN];
int n, m, k, cnt;
int u[MaxN], v[MaxN], vis[MaxN];
int head[MaxN], ans[MaxN], f[MaxN], tim[MaxN];
inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].from = u;
    head[u] = cnt;
}
inline int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}
inline void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv)
        f[fv] = fu;
}
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
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        u[i] = read() + 1, v[i] = read() + 1, add_edge(u[i], v[i]), add_edge(v[i], u[i]);
    k = read();
    for (int i = 1; i <= k; i++)
        tim[i] = read() + 1, vis[tim[i]] = 1;
    int now = n - k;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[e[i * 2].from] && !vis[e[i * 2].to])
        {
            int fu = getf(e[i * 2].from), fv = getf(e[i * 2].to);
            if (fu != fv)
            {
                --now;
                merge(fu, fv);
            }
        }
    }
    ans[k + 1] = now;
    int x, y;
    for (int i = k; i; i--)
    {
        ++now;
        x = tim[i];
        vis[x] = 0;
        for (int j = head[tim[i]]; j; j = e[j].next)
        {
            y = e[j].to;
            if (!vis[y])
            {
                int fx = getf(x), fy = getf(y);
                if (fx != fy)
                    merge(x, y), --now;
            }
        }
        ans[i] = now;
    }
    for (int i = 1; i <= k + 1; i++)
        printf("%d\n", ans[i]);
    return 0;
}