#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<int, int>
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e2 + 10;
const int MaxK = 5e3 + 10;
const int MaxM = 12500010;

struct edge
{
    int next, to;
};

pir a[MaxK];
edge e[MaxM];
int n, m, k, s, cnt;
int head[MaxK], dis[MaxK], f[MaxN][MaxN];

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dp(int u)
{
    if (dis[u]) return dis[u];
    for (R int i = head[u]; i; i = e[i].next)
        dis[u] = std::max(dis[u], dp(e[i].to) + 1);
    return dis[u];
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

int main()
{
    n = read(), m = read(), k = read();
    memset(f, 0x3f, sizeof(f));
    for(R int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (R int i = 1; i <= m; ++i)
    {
        int u = read(), v = read(), d = read();
        f[u][v] = d, f[v][u] = d;
    }
    for (R int k = 1; k <= n; ++k)
        for (R int i = 1; i <= n; ++i)
            for (R int j = 1; j <= n; ++j)
                if (f[i][j] > f[i][k] + f[k][j])
                    f[i][j] = f[i][k] + f[k][j];
    for (R int i = 1; i <= k; ++i)
        a[i].first = read(), a[i].second = read();
    std::sort(a + 1, a + k + 1), s = k + 1;
    for (R int i = 1; i <= k; ++i)
        if (a[i].first >= f[1][a[i].second])
            add_edge(s, i);
    for (R int i = 1; i <= k; ++i)
        for (R int j = i + 1; j <= k; j++)
            if ((a[j].first - a[i].first) >= f[a[i].second][a[j].second])
                add_edge(i, j);
    printf("%d\n", dp(s));
    return 0;
}
