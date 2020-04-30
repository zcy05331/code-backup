#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

std::vector<int> g[MaxN];
int n, m, d[MaxN], vis[MaxN];
std::vector<std::pair<int, int>> ans;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v), ++d[u];
        g[v].push_back(u), ++d[v];
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
        std::sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; i++)
        if (d[i] == 1) vis[i] = 1, q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (!vis[v] && --d[v] == 1)
                vis[v] = 1, q.push(v);
    }
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    for (int i = 1; i <= n; i++)
        if (d[i] > 1) vis[i] = 1, q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (!vis[v])
                vis[v] = 1, q.push(v);
    }
    for (int u = 1; u <= n; u++)
    {
        for (auto v : g[u])
        {
            if (!vis[u] && g[u].size() == 1)
                ans.push_back(std::make_pair(u, v));
            if(vis[u] && d[u] > 1 && d[v] == 1)
                ans.push_back(std::make_pair(u, v));
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans)
        printf("%d %d\n", x.first, x.second);
    return 0;
}
