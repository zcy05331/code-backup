#include <bits/stdc++.h>
#define ll long long
const int MaxN = 100010;
ll n;
ll a[MaxN], b[MaxN];
inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
inline ll fast_mul(ll a, ll b, ll p)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return gcd;
}
ll excrt()
{
    ll x, y;
    ll m = b[1], ans = a[1];
    for (int i = 1; i <= n; i++)
    {
        ll ax = m, bx = b[i], c = (a[i] - ans % bx + bx) % bx;
        ll gcd = exgcd(ax, bx, x, y), bg = bx / gcd;
        if (c % gcd != 0)
            return -1;
        x = fast_mul(x, c / gcd, bg);
        ans += x * m;
        m *= bg;
        ans = (ans % m + m) % m;
    }
    return (ans % m + m) % m;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        b[i] = read(), a[i] = read();
    printf("%lld", excrt());
    return 0;
}
