#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e4 + 10;
const int inf = 0x3f3f3f3f;

struct edge
{
    int next, to;
};

char s[MaxN];
edge e[MaxN];
int n, ans, cnt;
int a[MaxN], head[MaxN], dis[MaxN], size[MaxN], f[MaxN];

void init()
{
    for (int i = 1; i <= n; i++)
        dis[i] = size[i] = f[i] = 0;
}

void add_edge(int u, int v)
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

void dfs(int u, int fa)
{
    size[u] = a[u];
    int maxp = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u), size[u] += size[v], dis[v] += size[v];
        dis[u] += dis[v], maxp = ((dis[maxp] > dis[v]) ? maxp : v);
    }    
    if(!maxp) return (void) (f[u] = 0);
    if(dis[u] >= 2 * (dis[maxp])) f[u] = (dis[u] / 2);
    else f[u] = dis[u] - dis[maxp] + std::min(f[maxp], (2 * dis[maxp] - dis[u]) / 2);
}

int main()
{
    ans = inf;
    n = read(), scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        init(), dfs(i, 0);
        if(dis[i] & 1) continue;
        if (f[i] * 2 >= dis[i]) ans = std::min(ans, dis[i] / 2);
    }
    printf("%d\n", (ans == inf) ? -1 : ans);
    return 0;
}
