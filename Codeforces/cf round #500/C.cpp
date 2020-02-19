#include <bits/stdc++.h>

const int MaxN = 100010 * 2;
long long a[MaxN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++)
    {
        scanf("%I64d", &a[i]);
    }
    std::sort(a + 1, a + 2 * n + 1);
    long long d = 0x7fffffff;
    for(int i = n + 1; i < 2 * n; i++)
    {
        d = std::min(d, a[i] - a[i - n + 1]);
    }
    printf("%I64d", std::min(1ll * d * (a[n + n] - a[1]), 1ll * (a[n] - a[1]) * (a[n + n] - a[n + 1])));
    return 0;
}