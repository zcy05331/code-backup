#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll mod = 20100403;
const ll MaxN = 2e6 + 10;

ll n, m;
ll fac[MaxN], inv[MaxN];

ll C(ll n, ll m)
{
    if (n > m) return 0;
    return (fac[m] * inv[n]) % mod * inv[m - n];
}

void init(ll n = 2e6)
{
    fac[0] = inv[0] = inv[1] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (ll i = 2; i <= n; i++)
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    for (ll i = 1; i <= n; i++)
        inv[i] = (ll)(inv[i] * inv[i - 1]) % mod;
}

signed main()
{
    scanf("%lld%lld", &n, &m), init();
    printf("%lld", (((C(m, n + m) - C(m - 1, n + m)) % mod + mod)) % mod);
    return 0;
}
