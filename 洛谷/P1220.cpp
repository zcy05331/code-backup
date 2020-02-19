#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int MaxN = 100;
int n, c;
int a[MaxN], b[MaxN], sum[MaxN], f[MaxN][MaxN][2];
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
    n = read(), c = read();
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(), sum[i] = sum[i - 1] + b[i];
    f[c][c][0] = f[c][c][1] = 0;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            f[i][j][0] = cmin(f[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j]), f[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j]));
            f[i][j][1] = cmin(f[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1]), f[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    }
    int ans = cmin(f[1][n][0], f[1][n][1]);
    printf("%d\n", ans);
    return 0;
}
