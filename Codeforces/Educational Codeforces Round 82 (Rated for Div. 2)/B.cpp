#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, m, g, b, x, y, ans;
        scanf("%I64d%I64d%I64d", &n, &g, &b);
        m = (n + 1) / 2;
        x = m / g, y = m % g;
        ans = x * (g + b) + y;
        if(!y) ans -= b;
        printf("%lld\n", std::max(ans, n));
    }
    return 0;
}
