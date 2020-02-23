#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 5e5 + 10;

    ll now = 0, ans1 = 0, ans2 = 0, ans3 = 0;
ll n, a[MaxN], b[MaxN], c[MaxN], d[MaxN], e[MaxN], ans[MaxN];

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    now = a[1];
    for (ll i = 1; i <= n; i++)
        ans1 += std::min(now, a[i]), b[i] = std::min(now, a[i]), now = std::min(now, a[i]);
    now = a[n];
    for (ll i = n; i; i--)
        ans2 += std::min(now, a[i]), c[i] = std::min(now, a[i]), now = std::min(now, a[i]);
    ll ansx = 0;
    for (ll i = 2; i <= n - 1; i++)
    {
        now = a[i], ansx = a[i];
        for (ll j = i + 1; j <= n; j++)
            ansx += std::min(now, a[j]), d[j] = std::min(now, a[j]), now = std::min(now, a[j]);
        now = a[i], d[i] = a[i];
        for (ll j = i - 1; j; j--)
            ansx += std::min(now, a[j]), d[j] = std::min(now, a[j]), now = std::min(now, a[j]);
        if (ans3 < ansx)
            ans3 = std::max(ans3, ansx), memcpy(e, d, n * 8 + 100);
    }
    ll maxx = 0;
    if (ans1 > maxx)
        maxx = ans1, memcpy(ans, b, n * 8 + 100);
    if (ans2 > maxx)
        maxx = ans2, memcpy(ans, c, n * 8 + 100);
    if (ans3 > maxx)
        maxx = ans3, memcpy(ans, e, n * 8 + 100);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
