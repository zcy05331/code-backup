#include <bits/stdc++.h>

#define R register
#define ll long long
#define abs(x) (((x) > 0) ? (x) : (-(x)))
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 15e4 + 10;

ll n, m, d, l, r, sum;
ll a[MaxN], t[MaxN], b[MaxN], q[MaxN], f[2][MaxN];

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

int main()
{
    n = read(), m = read(), d = read();
    for (int i = 1; i <= m; i++)
        a[i] = read(), b[i] = read(), t[i] = read(), sum += b[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[1][i] = abs(a[1] - i);
    for (ll i = 2; i <= m; i++)
    {
        l = 1, r = 0;
        ll D = (t[i] - t[i - 1]) * d;
        memset(f[i & 1], 0x3f, sizeof(f[i & 1]));
        for (ll j = 1; j <= n; j++)
        {
            while (l <= r && q[l] < j - D)
                ++l;
            while (l <= r && f[(i - 1) & 1][q[r]] > f[(i - 1) & 1][j])
                --r;
            q[++r] = j;
            f[i & 1][j] = std::min(f[i & 1][j], f[(i - 1) & 1][q[l]] + abs(a[i] - j));
        }
        l = 1,r = 0;
        for (ll j = n; j; j--)
        {
            while (l <= r && q[l] > j + D)
                ++l;
            while (l <= r && f[(i - 1) & 1][q[r]] > f[(i - 1) & 1][j])
                --r;
            q[++r] = j;
            f[i & 1][j] = std::min(f[i & 1][j], f[(i - 1) & 1][q[l]] + abs(a[i] - j));
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
        ans = std::min(ans, f[m & 1][i]);
    printf("%lld\n", sum - ans);
    return 0;
}