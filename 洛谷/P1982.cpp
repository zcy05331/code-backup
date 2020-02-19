#include <bits/stdc++.h>

const int MaxN = 1000010;
int a[MaxN];
int f[MaxN], g[MaxN];
int n, p;
int ans = -0x7fffffff, maxn = -0x7fffffff;

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    g[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        g[i] = (std::max(g[i - 1], 0) + a[i]);
        //printf("%d ", g[i]);
    }
    for(int i = 2; i <= n; i++)
    {
        g[i] = std::max(g[i - 1], g[i]);
    }
    int flag = 0;
    f[1] = g[1];
    f[2] = g[1] + f[1];
    if (f[2] > f[1])
        flag = 1;
    for (int i = 3; i <= n; ++i)
    {
        f[i] = f[i - 1];
        if (g[i - 1] > 0)
            f[i] += g[i - 1];
        if (f[i] > f[1])
            flag = 1;
        if (flag)
            f[i] %= p;
    }
    if (flag)
        printf("%lld", f[n]);
    else
        printf("%lld", f[1]);
    return 0;
}