#include <bits/stdc++.h>

#define R register
#define ll long long

const int mod = 20101009;
const int MaxN = 1e7 + 10;

bool flag[MaxN];
ll n, m, mu[MaxN], p[MaxN], sum[MaxN];

void init()
{
    mu[1] = 1;
    ll cnt = 0, k = std::min(n, m);
    for (ll i = 2; i <= k; i++)
    {
        if (!flag[i])
            p[++cnt] = i, mu[i] = -1;
        for (ll j = 1; j <= cnt && i * p[j] <= k; j++)
        {
            flag[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
    for (ll i = 1; i <= k; i++)
        sum[i] = (sum[i - 1] + i * i % mod * (mu[i] + mod)) % mod;
}

ll g(ll x, ll y) { return (x * (x + 1) / 2 % mod) * (y * (y + 1) / 2 % mod) % mod; }

ll Sum(ll x, ll y)
{
    ll ret = 0;
    for (ll l = 1, r; l <= std::min(x, y); l = r + 1)
    {
        r = std::min(x / (x / l), y / (y / l));
        ret = (ret + (sum[r] - sum[l - 1] + mod) * g(x / l, y / l) % mod) % mod;
    }
    return ret;
}

ll solve(ll x, ll y)
{
    ll ret = 0;
    for (ll l = 1, r; l <= std::min(x, y); l = r + 1)
    {
        r = std::min(x / (x / l), y / (y / l));
        ret = (ret + (r - l + 1) * (l + r) / 2 % mod * Sum(x / l, y / l) % mod) % mod;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld", &n, &m), init();
    printf("%lld\n", solve(n, m));
    return 0;
}