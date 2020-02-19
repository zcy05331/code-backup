#include <bits/stdc++.h>
#define ll long long
#define maxn 10000010
using namespace std;

inline ll read()
{
    ll x = 0, f = 1;
    char cc = getchar();
    while (cc < '0' || cc > '9')
    {
        if (cc == '-')
            f = -1;
        cc = getchar();
    }
    while (cc >= '0' && cc <= '9')
    {
        x = x * 10 + cc - '0';
        cc = getchar();
    }
    return x * f;
}

ll a, b, n, an, bn, nn, f[maxn], g[maxn], h[maxn], ans, m;

int main()
{
    a = read();
    b = read();
    n = a + b;
    ans = 4 * n;
    m = sqrt(n);
    for (ll i = 1; i <= m; i++)
    {
        if (n % i == 0)
        {
            nn++;
            h[nn] = i;
        }
    }
    m = sqrt(a);
    for (ll i = 1; i <= m; i++)
    {
        if (a % i == 0)
        {
            an++;
            f[an] = i;
        }
    }
    m = sqrt(b);
    for (ll i = 1; i <= m; i++)
    {
        if (b % i == 0)
        {
            bn++;
            g[bn] = i;
        }
    }
    ll l = 0;
    ll r = 0;
    for (ll i = 1; i <= nn; i++)
    {
        while (l < an && f[l + 1] <= h[i])
            l++;
        while (r < bn && g[r + 1] <= h[i])
            r++;
        if ((f[l] > h[i] || a / f[l] > n / h[i]) && (g[r] > h[i] || b / g[r] > n / h[i]))
            continue;
        ans = min(ans, 2 * h[i] + 2 * n / h[i]);
    }
    printf("%I64d", ans);
}