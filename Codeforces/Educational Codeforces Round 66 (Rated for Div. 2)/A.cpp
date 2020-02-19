#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, k, ans = 0;
        scanf("%I64d%I64d", &n, &k);
        while (n)
        {
            ans += (n % k);
            n -= (n % k);
            if(n == 0)
                break;
            n /= k;
            ++ans;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
