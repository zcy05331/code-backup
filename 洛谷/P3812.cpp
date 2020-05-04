#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll n, x;

struct LinearBasis
{
    ll d[70];
    void add(ll x)
    {
        for (int i = 60; ~i; i--)
        {
            if (x & (1ll << i))
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
    ll query()
    {
        ll ans = 0;
        for(int i = 60; ~i; i--)
            if((d[i] ^ ans) > ans)
                ans ^= d[i];
        return ans;
    }
} L;

ll read()
{
    ll x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i++)
        L.add((x = read()));
    printf("%lld\n", L.query());
    return 0;
}
