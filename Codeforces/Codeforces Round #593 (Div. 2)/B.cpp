#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int mod = 1e9 + 7;

ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld", fast_pow(fast_pow(2, m) - 1, n) % mod);
    return 0;
}
