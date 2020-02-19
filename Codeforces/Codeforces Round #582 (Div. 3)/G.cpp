#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

struct edge
{
    int u, v, w;
    bool operator<(const edge x) const { return w < x.w; }
} e[MaxN << 1];

struct query
{
    int q, id;
    bool operator<(const query x) const { return q < x.q; }
} query[MaxN];

ll ans[MaxN], now;
int n, q, pos = 0, u, v, f[MaxN], size[MaxN];

ll getsize(ll x)
{
    return 1ll * (x - 1ll) * x / 2;
}

int getf(int x)
{
    if (f[x] != x)
        f[x] = getf(f[x]);
    return f[x];
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        f[i] = i, size[i] = 1;
    for (int i = 1; i < n; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    std::sort(e + 1, e + n);
    for (int i = 1; i <= q; i++)
        scanf("%d", &query[i].q), query[i].id = i;
    std::sort(query + 1, query + 1 + q);
    for (int i = 1; i <= q; i++)
    {
        while (pos < n - 1 && e[pos + 1].w <= query[i].q)
        {
            ++pos;
            u = getf(e[pos].u), v = getf(e[pos].v);
            if (u == v)
                continue;
            now = now - getsize(size[u]) - getsize(size[v]) + getsize(size[u] + size[v]);
            size[u] += size[v], f[v] = u;
        }
        ans[query[i].id] = now;
    }
    for (int i = 1; i <= q; i++)
        printf("%I64d ", ans[i]);
    return 0;
}
