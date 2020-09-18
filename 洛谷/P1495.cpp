#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll n, M, a[20], b[20], Mi[20];

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    return (void)(x = 1, y = 0);
    exgcd(b, a % b, x, y);
    int z = x;
    x = y, y = z - y * (a / b);
}

int main()
{   
    ll ans = 0;
    scanf("%lld", &n), M = 1;
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld", &b[i], &a[i]), M *= b[i];
    for(int i = 1; i <= n; i++)
    {
        ll x, y;
        Mi[i] = M / b[i];
        exgcd(Mi[i], b[i], x, y);
        ans += a[i] * Mi[i] * ((x < 0) ? (x + b[i]) : x);
    }
    printf("%lld\n", ans % M);
    return 0;
}
