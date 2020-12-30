#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

ll n, l, t;
ll a[MaxN], b[MaxN], c[MaxN];

signed main()
{
    ll pos = 1;
    scanf("%lld%lld%lld", &n, &l, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i], &c[i]);
        if (c[i] == 2) c[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
            b[i] = (a[i] + t) % l;
        else
            b[i] = ((a[i] - t) % l + l) % l;
    }
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
            if (l - a[i] <= t)
                pos += ((t - l + a[i]) / l + 1) % n;
        }
        else
        {
            if (a[i] + 1 <= t)
                pos -= ((t - a[i] - 1) / l + 1) % n;
        }
    }
    pos = (pos % n + n) % n;
    if (pos == 0) pos = n;
    fprintf(stderr, "pos = %lld\n", pos);
    for (int i = 1; i <= n; i++)
        printf("%lld\n", b[pos]), pos = (pos % n) + 1;
    return 0;
}