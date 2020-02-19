#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 510;
const ll mod = 1e9 + 7;

ll n, p, m;
ll a[MaxN][MaxN], b[MaxN][MaxN], c[MaxN][MaxN];

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read(), p = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
            a[i][j] = read();
    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= p; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])) % mod;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%lld ", (c[i][j] % mod + mod) % mod);
        puts("");
    }
    return 0;
}
