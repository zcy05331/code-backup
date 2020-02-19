#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int MaxN = 810;
const int mod = 1e9 + 7;
int n, m, k;
int a[MaxN][MaxN], f[MaxN][MaxN][20][2];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
int main()
{
    n = read(), m = read(), k = read() + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), f[i][j][a[i][j] % k][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int l = 0; l <= k; l++)
            {
                f[i][j][l][0] = (f[i][j][l][0] + f[i][j - 1][(l - a[i][j] + k) % k][1]) % mod;
                f[i][j][l][0] = (f[i][j][l][0] + f[i - 1][j][(l - a[i][j] + k) % k][1]) % mod;
                f[i][j][l][1] = (f[i][j][l][1] + f[i][j - 1][(l + a[i][j]) % k][0]) % mod;
                f[i][j][l][1] = (f[i][j][l][1] + f[i - 1][j][(l + a[i][j]) % k][0]) % mod;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = (ans + f[i][j][0][1]) % mod;
    printf("%d\n", ans);
    return 0;
}
