#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll inf = 1e16;
const ll MaxN = 1e3 + 10;

ll n, m, a[MaxN][MaxN], f[MaxN][MaxN];

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

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    memset(f, -0x3f, sizeof(f)), f[1][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        ll max = -inf;
        for (int j = 1; j <= n; j++)
        {
            max = std::max(max, f[j][i - 1]) + a[j][i];
            f[j][i] = std::max(max, f[j][i]);
        }
        max = -inf;
        for (int j = n; j; j--)
        {
            max = std::max(max, f[j][i - 1]) + a[j][i];
            f[j][i] = std::max(max, f[j][i]);
        }
    }
    printf("%lld\n", f[n][m]);
    return 0;
}
