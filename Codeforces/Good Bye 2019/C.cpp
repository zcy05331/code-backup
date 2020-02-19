#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
ll n, a[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &n);
        ll sum = 0, xorsum = 0;
        for (int i = 1; i <= n; i++)
            scanf("%I64d", &a[i]), sum += a[i], xorsum ^= a[i];
        printf("%d\n", 2);
        printf("%I64d %I64d\n", xorsum, sum + xorsum);
    }
    return 0;
}
