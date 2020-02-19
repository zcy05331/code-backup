#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e3 + 10;

int n, maxp, w, l, r;
int ap[MaxN], bp[MaxN], as[MaxN], bs[MaxN], q[MaxN << 2], f[MaxN][MaxN];

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
    n = read(), maxp = read(), w = read();
    for (int i = 1; i <= n; i++)
        ap[i] = read(), bp[i] = read(), as[i] = read(), bs[i] = read();
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0, l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= as[i]; j++)
            f[i][j] = std::max(f[i][j], -ap[i] * j);
        for (int j = 0; j <= maxp; j++)
            f[i][j] = std::max(f[i][j], f[i - 1][j]);
        if (i >= w + 1)
        {
            l = 1, r = 0;
            for (int j = 0; j <= maxp; j++)
            {
                while (l <= r && q[l] < j - as[i])
                    l++;
                while (l <= r && f[i - w - 1][q[r]] + q[r] * ap[i] <= f[i - w - 1][j] + j * ap[i])
                    r--;
                q[++r] = j;
                if (l <= r)
                    f[i][j] = std::max(f[i][j], f[i - w - 1][q[l]] - (j - q[l]) * ap[i]);
            }
            l = 1, r = 0;
            for (int j = maxp; j >= 0; j--)
            {
                while (l <= r && q[l] > j + bs[i])
                    l++;
                while (l <= r && f[i - w - 1][q[r]] + q[r] * bp[i] <= f[i - w - 1][j] + j * bp[i])
                    --r;
                q[++r] = j;
                if (l <= r)
                    f[i][j] = std::max(f[i][j], f[i - w - 1][q[l]] + (q[l] - j) * bp[i]);
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <= maxp; i++)
        ans = std::max(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}
