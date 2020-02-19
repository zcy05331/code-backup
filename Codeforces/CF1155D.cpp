#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e5 + 10;

ll n, x;
ll a[MaxN], f[MaxN][3][3];

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
    n = read(), x = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                f[i][j][k] = -0x7f7f7f7f;
    f[0][0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j < 2)
                    f[i][j + 1][k] = cmax(f[i][j][k], f[i][j + 1][k]);
                if (k < 2)
                    f[i][j][k + 1] = cmax(f[i][j][k], f[i][j][k + 1]);
                if (i < n)
                    f[i + 1][j][k] = cmax(f[i + 1][j][k], f[i][j][k] + (j == 1 ? a[i + 1] : 0) * (ll)(k == 1 ? x : 1));
            }
        }
    }
    printf("%I64d\n", f[n][2][2]);
    return 0;
}
