#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int n;
int a[50][50];

inline void solve()
{
    std::bitset<1000> tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp.reset();
        for (int j = 1; j <= n; j++)
            tmp[a[i][j]] = 1;
        if (tmp.count() != n)
            return (void)printf("no\n");
    }
    for (int i = 1; i <= n; i++)
    {
        tmp.reset();
        for (int j = 1; j <= n; j++)
            tmp[a[j][i]] = 1;
        if (tmp.count() != n)
            return (void)printf("no\n");
    }
    int x = sqrt(n) + 0.5;
    for (int i = 1; i <= n; i++)
    {
        tmp.reset();
        int v = (i - 1) % x, u = (i - 1) / x;
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= x; k++)
                tmp[a[j + u * x][k + v * x]] = 1;
        }
        if (tmp.count() != n)
            return (void)printf("no\n");
    }
    printf("yes\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        solve();
    }
    return 0;
}
