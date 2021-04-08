#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e3 + 10;
const int mod = 1e9 + 7;

ll n, k, a[MaxN], inv[MaxN], C[MaxN];

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
    n = read(), k = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    if(!k) 
    {
        for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        return 0;
    }
    inv[0] = inv[1] = 1, C[0] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 1; i <= n; i++) 
        C[i] = C[i - 1] * inv[i] % mod * (k + i - 1) % mod;
    for(int i = 1; i <= n; i++)
    {
        ll now = 0;
        for(int j = 1; j <= i; j++)
            now = sum(now, a[j] * C[i - j] % mod, mod);
        printf("%lld ", now);
    }
    return 0;
}
