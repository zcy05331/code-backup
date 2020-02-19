#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 998244353;
const int MaxN = 50, MaxM = 5e2 + 10;

int n, m, cnt = 1;
int a[MaxN][MaxM], sum[MaxN];
int g[MaxN][MaxN][MaxN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), sum[i] = sum(sum[i], a[i][j], mod);
        cnt = (cnt * 1ll * (sum[i] + 1)) % mod;
    }
    cnt = sum(cnt, mod - 1, mod);
    for (int i = 1; i <= m; i++)
    {
        g[0][0][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                for (int l = 0; l <= k; l++)

                {
                    g[j][k][l] = g[j - 1][k][l];
                    if (k)
                    {
                        g[j][k][l] = sum(g[j][k][l], g[j - 1][k - 1][l] * 1ll * ((sum[j] + mod - a[j][i]) % mod), mod);
                        if (l)
                            g[j][k][l] = sum(g[j][k][l], g[j - 1][k - 1][l - 1] * 1ll * a[j][i], mod);
                    }
                }
            }
        }
        for (int j = 1; j <= n; j++)
            for (int k = (j / 2) + 1; k <= j; k++)
                cnt = sum(cnt, mod - (g[n][j][k] % mod), mod);
    }

    printf("%d\n", cnt);
    return 0;
}
