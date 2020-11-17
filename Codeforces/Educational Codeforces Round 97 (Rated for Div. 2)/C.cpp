#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e2 + 10;

int n, a[MaxN], f[MaxN][MaxN];

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

signed main()
{
    int T = read();
    while (T--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        memset(f, 0x3f, sizeof(f));
        std::sort(a + 1, a + n + 1), f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2 * n; j++)
                for (int k = j + 1; k <= 2 * n; k++)
                    f[i][k] = std::min(f[i][k], f[i - 1][j] + abs(k - a[i]));
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i <= 2 * n; i++)
            ans = std::min(ans, f[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
