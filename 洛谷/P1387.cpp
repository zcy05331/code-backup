#include <bits/stdc++.h>
int n, m, ans;
int a[101][101], f[101][101];
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
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = read();
            if (a[i][j] == 1)
                f[i][j] = std::min(std::min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
            ans = std::max(ans, f[i][j]);
        }
    printf("%d", ans);
    return 0;
}