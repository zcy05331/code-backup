#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const ll mod = 20101009;
const ll MaxN = 1e7 + 10;

ll n, m, cnt;
ll mu[MaxN], p[MaxN], s[MaxN], prime[MaxN];

void init()
{
    mu[1] = 1;
    for (ll i = 2; i < MaxN; i++)
    {
        if (!p[i])
            prime[++cnt] = i, mu[i] = -1;
        for (ll j = 1; j <= cnt && i * prime[j] < MaxN; j++)
        {
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (ll i = 1; i < MaxN; i++)
        s[i] = sum(s[i - 1], i * i % mod * (mu[i] + mod) % mod, mod);
}

ll g(ll n, ll m) { return (n * (n + 1) / 2 % mod) * (m * (m + 1) / 2 % mod) % mod; }

ll Sum(ll n, ll m)
{
    ll res = 0;
    for (ll l = 1, r; l <= std::min(n, m); l = r + 1)
    {
        r = std::min(n / (n / l), m / (m / l));
        res = sum(res, (s[r] - s[l - 1] + mod) * g(n / l, m / l) % mod, mod);
    }
    return res;
}

ll solve(ll n, ll m)
{
    ll ans = 0;
    for (ll l = 1, r; l <= std::min(n, m); l = r + 1)
    {
        r = std::min(n / (n / l), m / (m / l));
        ans = sum(ans, (r - l + 1) * (l + r) / 2 % mod * Sum(n / l, m / l) % mod, mod);
    }
    return ans;
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
    init(), n = read(), m = read();
    printf("%lld\n", solve(n, m));
    return 0;
}