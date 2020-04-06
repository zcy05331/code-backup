#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll n, m;
ll a[MaxN], ans[MaxN], sum[MaxN];

int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] + i > n + 1)
            return 0 * printf("-1");
    }
    for (int i = m; i; i--)
        sum[i] = sum[i + 1] + a[i];
    if (sum[1] < n) return 0 * printf("-1");
    for (int i = 1; i <= m; i++)
    {
        ans[i] = std::max(i * 1ll, n - sum[i] + 1);
        printf("%lld ", ans[i]);
    }
    return 0;
}
