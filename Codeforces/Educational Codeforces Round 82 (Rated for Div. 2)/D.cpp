#include <bits/stdc++.h>

#define R register
#define ll long long
#define lowbit(x) ((x) & (-(x)))
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll n, m, sum, cnt[MaxN], a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll ans = 0;
        scanf("%I64d%I64d", &m, &n), sum = 0;
        for (int i = 1; i <= n; i++)
            scanf("%I64d", &a[i]);
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            int t = m & (a[i] - 1);
            if (t)
            {
                ans += __builtin_ffs(a[i]) - __builtin_ffs(t);
                m -= t;
            }
            sum += a[i] - t;
            while (m && sum >= lowbit(m))
                sum -= lowbit(m), m -= lowbit(m);
        }
        if (m > sum)
            printf("-1\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
