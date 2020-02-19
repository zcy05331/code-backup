#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 3e5 + 10;
int n;
std::vector<int> g[MaxN];
int a[MaxN], col[MaxN], deg[MaxN], f[MaxN], dp[MaxN];
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
inline void dfs(int u)
{
    if (col[u])
        dp[u] = 1;
    if (a[u] == 0)
    {
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            dfs(v);
            dp[u] += dp[v];
        }
    }
    else if (!col[u])
    {
        int tmp = 2e9;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            dfs(v);
            tmp = cmin(tmp, dp[v]);
        }
        dp[u] = tmp;
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 2; i <= n; i++)
    {
        f[i] = read();
        g[f[i]].push_back(i);
        deg[i]++;
        deg[f[i]]++;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (deg[i] == 1)
            col[i] = 1, ans++;
    dfs(1);
    printf("%d\n", ans - dp[1] + 1);
    return 0;
}
