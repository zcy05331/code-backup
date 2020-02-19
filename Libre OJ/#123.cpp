#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;
const int MaxM = 1e6 + 10;

struct edge
{
    int u, v, dis;
};

edge e[MaxM];
int n, m;
int f[MaxN];

inline int cmp(edge a, edge b) { return a.dis < b.dis; }

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

int getf(int u)
{
    if (f[u] != u)
        f[u] = getf(f[u]);
    return f[u];
}

inline void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv)
        f[fu] = fv;
}

int main()
{
    ll ans = 0;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        e[i].u = read(), e[i].v = read(), e[i].dis = read();
    std::sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v;
        int fu = getf(u), fv = getf(v);
        if (fu != fv)
            ans += e[i].dis, merge(fu, fv);
    }
    printf("%lld\n", ans);
    return 0;
}
