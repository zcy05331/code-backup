#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
const int MaxN = 500010;
struct edge
{
    int to, next;
};
edge e[MaxN];
int n, m, cnt;
int head[MaxN], col[MaxN], u[MaxN], v[MaxN];
inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
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
inline void dfs(int u, int c)
{
    col[u] = c;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (col[v])
            continue;
        dfs(v, (c == 1) ? 2 : 1);
    }
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        u[i] = read(), v[i] = read();
        add_edge(u[i], v[i]);
        add_edge(v[i], u[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!col[i])
            dfs(i, 1);
    for (int i = 1; i <= m; i++)
    {
        if (col[u[i]] == col[v[i]])
            return 0 * printf("NO");
    }
    printf("YES\n");
    for (int i = 1; i <= m; i++)
    {
        if (col[u[i]] == 1)
            printf("1");
        else
            printf("0");
    }
    return 0;
}
