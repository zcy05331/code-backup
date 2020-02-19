#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n = 0, m = 0, g = 0, ans = m;
        scanf("%lld%lld", &n, &m);
        g = std::__gcd(n, m), m /= g, ans = m;
        for (ll i = 2; i * i <= m; i++)
        {
            if (m % i == 0)
            {
                ans = (ans * 1ll * (i - 1ll)) / i;
                while (m % i == 0)
                    m /= i;
            }
        }
        if (m != 1)
            ans = (ans / m) * (m - 1);
        printf(" %lld\n", ans);
    }
    return 0;
}