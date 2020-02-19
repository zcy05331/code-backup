#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 300010;
ll n;
ll a[MaxN];
int main()
{
    ll ans = 0, sum = 0;
    scanf("%I64d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (sum == 0)
            ans += a[i] / 3, sum += a[i] % 3;
        else
        {
            if (sum >= (a[i] / 2))
                ans += a[i] / 2, sum -= a[i] / 2, sum += a[i] % 2;
            else
            {
                ans += sum;
                a[i] -= sum * 2;
                ans += a[i] / 3;
                sum = a[i] % 3;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
