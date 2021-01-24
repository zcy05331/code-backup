#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

ll n, x, p, m, ans, down;
ll a[MaxN], b[MaxN], f[MaxN][MaxN];

ll fast_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p, b >>= 1;
    }
    return ret;
}

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read(), x = read(), ans = 0;
    p = read(), m = read(), f[0][0] = 1;
    for (int i = 0; i <= m; i++)
        a[i] = read() % p;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
            f[i][j] = (j * f[i - 1][j] + f[i - 1][j - 1]) % p;
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
            b[i] = sum(b[i], f[j][i] * a[j], p);
    }
    down = 1, ans = a[0] * fast_pow(x + 1, n) % p;
    for (int i = 1; i <= m; i++)
    {
        down = down * (n - i + 1) % p;
        ll A = fast_pow(x, i), B = fast_pow(x + 1, n - i);
        ans = sum(ans, (b[i] * down % p) * (A * B % p) % p, p);
    }
    printf("%lld\n", ans);
    return 0;
}
