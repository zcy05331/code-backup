#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll n, m;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll ans = 0;
        scanf("%lld%lld", &n, &m);
        if (2 * m >= n)
            ans = (n * (n + 1) / 2ll) + (m - n);
        else
        {
            ll a = (n - m) / (m + 1), b = (n - m) % (m + 1);
            ans = (((a + 1) * (a + 2) * b) / 2) + (((m - b + 1) * a * (a + 1)) / 2);
            ans = (n * (n + 1) / 2ll) - ans;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
