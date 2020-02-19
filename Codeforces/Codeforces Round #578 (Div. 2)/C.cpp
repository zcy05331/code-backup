#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main()
{
    ll n, m, q, g;
    scanf("%I64d%I64d%I64d", &n, &m, &q);
    g = gcd(n, m);
    ll x = n / g, y = m / g;
    while (q--)
    {
        std::pair<ll, ll> s, t;
        scanf("%I64d%I64d%I64d%I64d", &s.first, &s.second, &t.first, &t.second);
        if (s.first == 2)
            std::swap(s, t);
        ll a = (s.second - 1) / x, b = (t.second - 1) / y;
        if (s.first == 2)
            a = (s.second - 1) / y;
        if (t.first == 1)
            b = (t.second - 1) / x;
        //printf("%I64d %I64d\n", a, b);
        if (a != b)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
