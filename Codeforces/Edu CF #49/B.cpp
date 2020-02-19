#include <bits/stdc++.h>
const int MaxN = 100010;   
long long  n, q;
long long x[MaxN], y[MaxN];
long long calc(long long x, long long y)
{
    long long ans = 0;
    if(x % 2 == 0 && y % 2 == 0)
    {
        ans = (long long)(x - 2) / 2 * 1ll * n + (n % 2 == 0 ? n / 2 : (n + 1) / 2) + (y / 2);
    }
    else if(x % 2 == 1 && y % 2 == 0)
    {
        ans = (long long)(long long)(x - 1) / 2 * 1ll * n + (y) / 2;
    }
    else if (x % 2 == 0 && y % 2 == 1)
    {
        ans = (long long)(x - 2) / 2 * 1ll * n + (long long)(n % 2 == 0 ? n / 2 : (n + 1) / 2 - 1) + ((y + 1) / 2);
    }
    else if (x % 2 == 1 && y % 2 == 1)
    {
        ans = (long long)(x - 1) / 2 * 1ll * n + (long long)((y + 1) / 2);
    }
    return ans;
}
int main()
{
    scanf("%I64d%I64d", &n, &q);
    for(int i = 1; i <= q; i++)
    {
        scanf("%I64d%I64d", &x[i], &y[i]);
        long long ans = 0;
        if((x[i] + y[i]) % 2 == 1)
            ans += (long long)((n * n) / 2) + bool(n % 2 != 0);
        //printf("%I64d\n", ans);
        ans += calc(x[i], y[i]);
        printf("%I64d\n", ans);
    }
    return 0;
}