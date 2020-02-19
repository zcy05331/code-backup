#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

ll n, m, cnt1[200];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d%I64d", &n, &m);
        memset(cnt1, 0, sizeof(cnt1));
        if (m > n)
        {
            printf("0\n");
            continue;
        }
        ll k = 1, lim = (n / m), l, tot = 0;
        while (!cnt1[(ll)((ll)(k * m) % 100)] && (k <= lim))
            cnt1[(ll)((ll)(k * m) % 100)] = 1, k++;
        --k;
        for (ll i = 0; i < 100; i++)
            tot += (i % 10) * cnt1[i];
        l = (lim / k);
        if (k > lim)
            l = 1;
        tot *= l;
        for (ll i = k * l + 1; i <= lim; i++)
            tot += ((ll)(i * 1ll * m) % 10ll)/*, printf("%lld\n", i)*/;
        printf("%I64d\n", tot);
    }
    return 0;
}
