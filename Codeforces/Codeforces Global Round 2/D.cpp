#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 100010;

ll n, q;
ll a[MaxN], b[MaxN], c[MaxN];

int main()
{
    scanf("%I64d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    std::sort(b + 2, b + n + 1);
    for (int i = 2; i <= n; i++)
        c[i] = c[i - 1] + b[i];
    scanf("%I64d", &q);
    for (int i = 1; i <= q; i++)
    {
        ll l, r;
        scanf("%I64d%I64d", &l, &r);
        ll g = (r - l + 1);
        for (l = 2, r = n + 1; l < r;)
        {
            ll mid = (l + r) >> 1;
            b[mid] > g ? r = mid : l = mid + 1;
        }
        printf("%I64d ", a[n] + g - a[1] - (c[n] - c[l - 1] - (n - l + 1) * g));
    }
    return 0;
}
