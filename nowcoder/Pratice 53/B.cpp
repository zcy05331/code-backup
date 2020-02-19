#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 7e6 + 10;
const int mod = 1e9 + 7;

ll n, ans, s[MaxN];

inline ll fast_pow(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        ll x = 1;
        for (int j = 1; j * i <= n; j++)
        {
            x = (i * x) % mod;
            s[i * j] = (s[i * j] + x) % mod, s[(i + 1) * j] = (s[(i + 1ll) * j] - x + mod) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
        s[i] = (s[i - 1] + s[i]) % mod;
    for (int i = 1; i <= n; i++)
        ans = (ans + (1ll * i * s[i]) % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
