#include <bits/stdc++.h>
#define ll long long
const int MaxN = 50;
const double delta = 0.993;
ll n, a[MaxN], ans;
ll abs(ll x){ return (x > 0) ? x : (-x);}
inline ll calc()
{
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i <= (n + 1) / 2)
            sum1 += a[i];
        else sum2 += a[i];
    }
    return abs(sum1 - sum2);
}
inline void sa()
{
    double t = 10000000;
    while (t > 1e-14)
    {
        int x = rand() % ((n + 1) / 2) + 1, y = rand() % ((n + 1) / 2) + ((n + 1) / 2);
        std::swap(a[x], a[y]);
        int now = calc();
        int de = now - ans;
        if (de < 0)
            ans = now;
        else if (exp(-de / t) * RAND_MAX <= rand())
            std::swap(a[x], a[y]);
        t *= delta;
    }
}
int main()
{
    int T;
    srand(time(NULL));
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ans = 1e9;
        for (int i = 1; i <= 50; i++)
            sa();
        printf("%lld\n", ans);
    }
    return 0;
}
