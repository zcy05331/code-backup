#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll n, a[50];

ll f(ll l, ll r, ll x, ll y)
{
    ll ans = 1e18;
    if(r - l <= 1) return 0;
    for(int i = l + 1; i <= r - 1; i++)
        ans = std::min((f(l, i, x, x + y) + f(i, r, x + y, y) + a[i] * (x + y)), ans);
    return ans;
}

int main()
{   
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    printf("%lld\n", f(1, n, 1, 1) + a[1] + a[n]);
    return 0;
}
