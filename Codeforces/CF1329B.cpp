#include <bits/stdc++.h>

#define R register
#define ll long long
#define int long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int g[50];

int maxbit(int x)
{
    int cnt = 0;
    while (x)
        ++cnt, x >>= 1;
    return cnt;
}

int solve(int n, int m)
{
    g[0] = 1 % m;
    for (int i = 1; i <= 30; i++)
        g[i] = g[i - 1] * 1 * ((1 << (i - 1)) + 1) % m;
    // for(int i = 0; i <= 4; i++)
    //     printf("%lld %lld\n", i, g[i]);
    ll k = n, ans = 0, cnt = maxbit(n);
    for (int i = 0; i <= cnt; i++)
    {
        if (k >= (1 << i))
            ans = sum(ans, g[i] * 1ll * (1 << i), m);
        else
        {
            ans = sum(ans, g[i] * 1ll * k, m);
            return ans;
        }
        k -= (1 << i);
        // printf("%lld %lld\n", i, ans);
    }
}

signed main()
{
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        int n, m;
        scanf("%lld%lld", &n, &m);
        memset(g, 0, sizeof(g));
        printf("%lld\n", solve(n, m));
    }
    return 0;
}
