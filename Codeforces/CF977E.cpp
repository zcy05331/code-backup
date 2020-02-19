#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int to, next;
};

edge e[MaxN << 1];
std::vector<int> v;
int n, m, cnt, ans;
int head[MaxN], vis[MaxN], deg[MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    ++deg[u];
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dfs(int u)
{
    v.push_back(u), vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v])
            continue;
        dfs(v);
    }
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
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            v.clear();
            dfs(i);
            int tmp = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (deg[v[j]] != 2)
                    tmp = 1;
            }
            if (!tmp)
                ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
