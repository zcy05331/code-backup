#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int Max = 2e5;
const int mod = 1e9 + 7;
const int MaxN = 2e5 + 10;

ll n, m, k;
std::pair<ll, ll> a[MaxN];
ll f[MaxN], fac[MaxN], inv[MaxN];

inline void prework()
{
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i <= Max; i++)
        fac[i] = fac[i - 1] * 1ll * i % mod;
    for (int i = 2; i <= Max; i++)
        inv[i] = (((mod - (mod / i)) % mod) * 1ll * inv[mod % i]) % mod;
    for (int i = 1; i <= Max; i++)
        inv[i] = (inv[i - 1] * 1ll * inv[i]) % mod;
}

ll C(ll n, ll m) { return ((fac[m] * inv[n]) % mod * inv[m - n]) % mod; }

int main()
{
    prework();
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= k; i++)
        scanf("%lld%lld", &a[i].first, &a[i].second);
    std::sort(a + 1, a + k + 1);
    f[0] = 1, a[k + 1].first = n, a[k + 1].second = m;
    for (int i = 1; i <= k + 1; i++)
    {
        f[i] = C(a[i].first - 1, (a[i].first + a[i].second) - 2);
        for (int j = 1; j < i; j++)
            if ((a[i].first >= a[j].first) && (a[i].second >= a[j].second))
                f[i] = (f[i] - ((f[j] * C(a[i].first - a[j].first, (a[i].first + a[i].second) - (a[j].first + a[j].second))) % mod) + mod) % mod;
    }
    printf("%lld\n", (f[k + 1] + mod) % mod);
    return 0;
}
