#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxM = 1e3 + 10;
const int MaxN = 1e4 + 10;

int n, m, k;
int x[MaxN], y[MaxN], up[MaxN], cnt[MaxN], down[MaxN], f[MaxN][MaxM];

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
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read(), up[i] = m + 1, down[i] = 0;
    for (int i = 1; i <= k; i++)
    {
        int p = read(), l = read(), r = read();
        cnt[p] = i, up[p] = r, down[p] = l;
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x[i]; j <= m; j++)
            f[i][j] = std::min(f[i][j], f[i - 1][j - x[i]] + 1), f[i][j] = std::min(f[i][j], f[i][j - x[i]] + 1);
        for (int j = m - x[i]; j <= m; j++)
            f[i][m] = std::min(f[i][m], f[i - 1][j] + 1), f[i][m] = std::min(f[i][m], f[i][j] + 1);
        for (int j = down[i] + 1; j <= up[i]; j++)
            if (j + y[i] <= m)
                f[i][j] = std::min(f[i][j], f[i - 1][j + y[i]]);
        for (int j = 1; j <= down[i]; j++)
            f[i][j] = 0x3f3f3f3f;
        for (int j = up[i]; j <= m; j++)
            f[i][j] = 0x3f3f3f3f;
    }
    int num = k, ans = 0x3f3f3f3f;
    for (int i = n; i; i--)
    {
        for (int j = up[i] - 1; j >= down[i] + 1; j--)
            ans = std::min(ans, f[i][j]);
        if (ans != 0x3f3f3f3f)
            break;
        if (up[i] != m + 1)
            --num;
    }
    if (num == k)
        printf("1\n%d", ans);
    else
        printf("0\n%d", num);
    return 0;
}
