#include <bits/stdc++.h>
#define ll long long
const int MaxN = 10000010;
ll a, b, n, an, bn, nn, f[MaxN], g[MaxN], h[MaxN], ans, m;
int main()
{
    scanf("%I64d%I64d", &a, &b);
    n = a + b;
    ans = 4 * n;
    m = sqrt(n);
    for(ll i = 1; i <= m; i++)
    {
        if(n % i == 0)
        {
            nn++;
            h[nn] = i;
        }
    }
    m = sqrt(a);
    for(ll i = 1; i <= m; i++)
    {
        if(a % i == 0)
        {
            an++;
            f[an] = i;
        }
    }
    m = sqrt(b);
    for(ll i = 1; i <= m; i++)
    {
        if(b % i == 0)
        {
            bn++;
            g[bn] = i;
        }
    }
    ll l = 0;
    ll r = 0;
    for(int i = 1; i <= nn; i++)
    {
        while(l < an && f[l + 1] <= h[i])
            l++;
        while(r < bn && g[r + 1] <= h[i])
            r++;
        if((f[l] > h[i] || a / f[l] > n / h[i]) && (g[r] > h[i] || b / g[r] > n / h[i]))
            continue;
        ans = std::min(ans, 2 * h[i] + 2 * n / h[i]);
    }
    printf("%I64d", ans);
    return 0;
}