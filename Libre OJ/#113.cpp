#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 1e2 + 10;

ll n, x;

struct LinearBasis
{
    ll d[70];
    void insert(ll x)
    {
        for (ll i = 60; ~i; i--)
        {
            if (x & (1 << i))
            {
                if (d[i])
                    x ^= d[i];
                else
                {
                    d[i] = x;
                    break;
                }
            }
        }
    }
    ll query(ll x)
    {
        for(int i = 60; ~i; i--)
            if((x ^ d[i]) > x) x ^= d[i];
        return x;
    }
} L;

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read();
    for(int i = 1; i <= n; i++)
        x = read(), L.insert(x);
    printf("%lld\n", L.query(0));
    return 0;
}
