#include <bits/stdc++.h>
const int MaxN = 150;
#define int long long
int n, m;
int a[MaxN], f[MaxN][MaxN][20], g[MaxN][MaxN][20];
int mod(int x) { return ((x % 10) + 10) % 10; }
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}
signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), a[i + n] = a[i];
    for (int i = 1; i <= n * 2; i++)
        a[i] += a[i - 1];
    memset(g, 10, sizeof(g));
    for (int i = 1; i <= n * 2; i++)
        for (int j = i; j <= n * 2; j++)
            f[i][j][1] = g[i][j][1] = mod(a[j] - a[i - 1]);
    int tmp = 0;
    for (int l = 2; l <= m; l++)
        for (int i = 1; i <= 2 * n - l + 1; i++)
            for (int j = i + l - 1; j <= n * 2; j++)
                for (int k = i + l - 1; k < j; k++)
                    tmp = mod(a[j] - a[k - 1]), f[i][j][l] = std::max(f[i][j][l], f[i][k - 1][l - 1] * tmp), g[i][j][l] = std::min(g[i][j][l], g[i][k - 1][l - 1] * tmp);
    int max = 0, min = 1 << 30;
    for (int i = 1; i <= n; i++)
    {
        max = std::max(max, f[i][i + n - 1][m]);
        min = std::min(min, g[i][i + n - 1][m]);
    }
    printf("%lld\n%lld", min, max);
    return 0;
}
