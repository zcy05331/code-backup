#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = -f;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}
inline void chkmin(int &a, int b)
{
    if (a > b)
        a = b;
}
inline void chkmax(int &a, int b)
{
    if (a < b)
        a = b;
}
#define _ read()
const int N = 3e5 + 5;
int col[N], dp[N], a[N], f[N], deg[N];
vector<int> G[N];
inline void dfs(int u)
{
    if (col[u])
        dp[u] = 1;
    if (a[u] == 0)
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            dfs(v);
            dp[u] += dp[v];
        }
    else if (!col[u])
    {
        int tmp = 2e9;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            dfs(v);
            chkmin(tmp, dp[v]);
        }
        dp[u] = tmp;
    }
}
int main()
{
    int n = _;
    for (int i = 1; i <= n; i++)
        a[i] = _;
    for (int i = 2; i <= n; i++)
    {
        f[i] = _;
        G[f[i]].push_back(i);
        deg[i]++;
        deg[f[i]]++;
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        if (deg[i] == 1)
            col[i] = 1, ans++;
    dfs(1);
    cout << ans - dp[1] + 1;
    return 0;
}