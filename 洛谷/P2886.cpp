#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e2 + 10;

struct matrix
{
    int n, m;
    int a[MaxN][MaxN];
    matrix(int x, int y) { n = x, m = y; }
};

int n, m, p, s, t;
int u[MaxN], v[MaxN], d[MaxN], b[MaxN];

matrix mul(const matrix &a, const matrix &b)
{
    matrix c(a.n, b.m);
    memset(c.a, 0x3f, sizeof(c.a));
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.m; j++)
            for (int k = 1; k <= a.m; k++)
                c.a[i][j] = std::min(c.a[i][j], a.a[i][k] + b.a[k][j]);
    return c;
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

matrix fast_pow(matrix a, int b)
{
    matrix ret = a;
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a), b >>= 1;
    }
    return ret;
}

int main()
{
    n = read(), m = read();
    s = read(), t = read();
    for (int i = 1; i <= m; i++)
    {
        d[i] = read(), u[i] = read(), v[i] = read();
        b[i * 2 - 1] = u[i], b[i * 2] = v[i];
    }
    std::sort(b + 1, b + 2 * m + 1);
    p = std::unique(b + 1, b + 2 * m + 1) - b - 1;
    matrix g(p, p);
    memset(g.a, 0x3f, sizeof(g.a));
    for (int i = 1; i <= m; i++)
    {
        u[i] = std::lower_bound(b + 1, b + p + 1, u[i]) - b;
        v[i] = std::lower_bound(b + 1, b + p + 1, v[i]) - b;
        g.a[u[i]][v[i]] = g.a[v[i]][u[i]] = d[i];
    }
    s = std::lower_bound(b + 1, b + p + 1, s) - b;
    t = std::lower_bound(b + 1, b + p + 1, t) - b;
    printf("%d\n", fast_pow(g, n - 1).a[s][t]);
    return 0;
}
