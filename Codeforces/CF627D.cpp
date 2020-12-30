#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
};

edge e[MaxN << 1];
int n, m, cnt, ans, root;
int head[MaxN], a[MaxN], f[MaxN], size[MaxN];

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

void dfs(int u, int fa, int x)
{
    f[u] = size[u] = 1;
    int max1 = 0, max2 = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u, x), size[u] += size[v];
        if (f[v] == size[v])
            f[u] += f[v];
        else
        {
            if (f[v] > max1) std::swap(f[v], max1);
            if (f[v] > max2) std::swap(f[v], max2);
        }
    }
    f[u] = ((a[u] < x) ? 0 : (f[u] + max1));
    ans = std::max(ans, f[u] + max2);
}

int check(int x)
{
    ans = 0, dfs(root, 0, x);
    return ((ans >= m) ? 1 : 0);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    root = std::min_element(a + 1, a + n + 1) - a;
    int l = *std::min_element(a + 1, a + n + 1);
    int r = *std::max_element(a + 1, a + n + 1);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}