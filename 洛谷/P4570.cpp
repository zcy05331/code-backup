#include <bits/stdc++.h>

#define R register
#define ll long long
#define pir std::pair<ll, ll>
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

ll n, ans;
pir a[MaxN];

struct LinearBasis
{
    ll d[70];
    bool insert(ll x)
    {
        for(ll i = 63; ~i; i--)
        {
            if(x & (1ll << i))
            {
                if(d[i]) x ^= d[i];
                else 
                {
                    d[i] = x;
                    return 1;
                }
            }
        }
        return 0;
    }
}L;

int main()
{   
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].second, &a[i].first), a[i].first = -a[i].first;
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        if(L.insert(a[i].second))
            ans -= a[i].first;
    printf("%lld\n", ans);
    return 0;
}
