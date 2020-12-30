#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1e9 + 7;
const int MaxN = 6e2 + 10;

ll n, k, ans, g[MaxN], nxt[MaxN], f[MaxN][MaxN];

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
    n = read() * 2, k = read(), g[0] = 1;
    for (int i = 2; i <= n; i += 2)
        g[i] = g[i - 2] * 1ll * (i - 1) % mod;
    for (int i = 1; i <= k; i++)
    {
        int x = read(), y = read();
        nxt[x] = y, nxt[y] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j += 2)
        {
            ll flag = 1, cnt = j - i + 1, c = 0;
            for (int l = i; l <= j; l++)
            {
                if (nxt[l])
                {
                    --cnt;
                    if (nxt[l] < i || nxt[l] > j)
                        flag = 0;
                }
            }
            if (!flag) continue; f[i][j] = g[cnt];
            for(int l = i; l < j; l++)
                c += !nxt[l], f[i][j] = sum(f[i][j], mod - (f[i][l] * g[cnt - c] % mod), mod);
            ans = sum(ans, f[i][j] * g[n - 2 * k - cnt], mod);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
