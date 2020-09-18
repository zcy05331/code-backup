#include <bits/stdc++.h>

#define R register
#define ll long long
#define int unsigned
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e2 + 10;

struct matrix
{
    int n, m;
    int a[MaxN][MaxN];
    matrix(int x = 0, int y = 0)
    {
        n = x, m = y;
        memset(a, 0, sizeof(a));
    }
};

int n, m, q;
matrix f, g, a[40];

matrix I(int n)
{
    matrix I(n, n);
    for(int i = 1; i <= n; i++)
        I.a[i][i] = 1;
    return I;
}

matrix mul(matrix a, matrix b)
{
    matrix c(a.n, b.m);
    for(int i = 1; i <= a.n; i++)
        for(int j = 1; j <= b.m; j++)
             for(int k = 1; k <= a.m; k++)
                c.a[i][j] ^= a.a[i][k] * b.a[k][j];
    return c;
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

void solve(int x)
{
    matrix g = f;
    for (int i = 0; i <= 31; i++)
        if (x & (1u << i))
            g = mul(g, a[i]);
    printf("%u\n", g.a[1][1]);
}

signed main()
{   
    n = read(), m = read(), q = read();
    f = matrix(1, n), g = matrix(n, n);
    for(int i = 1; i <= n; i++)
        f.a[1][i] = read();
    for(int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        g.a[u][v] = g.a[v][u] = 1;
    }
    a[0] = g;
    for(int i = 1; i <= 31; i++)
        a[i] = mul(a[i - 1], a[i - 1]);
    while(q--)
    {
        int x = read();
        solve(x);
    }
    return 0;
}
