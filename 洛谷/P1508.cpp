#include <bits/stdc++.h>
const int MaxN = 210;
int n, m;
int a[MaxN][MaxN];
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
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read() + std::max(a[i - 1][j], std::max(a[i - 1][j - 1], a[i - 1][j + 1]));
    printf("%d\n", std::max(a[n][m / 2], std::max(a[n][m / 2 + 1], a[n][m / 2 + 2])));
    return 0;
}
