#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const double inf = 1e9;
const int MaxN = 2e3 + 10;

int n, m, v, e;
double k[MaxN], dp[MaxN][MaxN][2];
int c[MaxN], d[MaxN], f[MaxN][MaxN];

int main()
{
    scanf("%d%d%d%d", &n, &m, &v, &e);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++)
        std::cin >> k[i];
    memset(f, 31, sizeof(f));
    for (int i = 1; i <= v; i++)
        f[i][i] = f[i][0] = f[0][i] = 0;
    for (int i = 1; i <= e; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        f[u][v] = f[v][u] = std::min(f[u][v], d);
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= 2000; j++)
            dp[i][j][0] = dp[i][j][1] = inf;
    }
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + f[c[i - 1]][c[i]];
        for (int j = 1; j <= std::min(i, m); j++)
        {
            dp[i][j][0] = std::min(dp[i][j][0], dp[i - 1][j][0] + f[c[i - 1]][c[i]]);
            dp[i][j][0] = std::min(dp[i][j][0], dp[i - 1][j][1] + k[i - 1] * f[d[i - 1]][c[i]] + (1.0 - k[i - 1]) * f[c[i - 1]][c[i]]);
            dp[i][j][1] = std::min(dp[i][j][1], dp[i - 1][j - 1][0] + k[i] * f[c[i - 1]][d[i]] + (1.0 - k[i]) * f[c[i - 1]][c[i]]);
            dp[i][j][1] = std::min(dp[i][j][1], dp[i - 1][j - 1][1] + k[i] * k[i - 1] * f[d[i - 1]][d[i]] + k[i] * (1.0 - k[i - 1]) * f[c[i - 1]][d[i]] + (1.0 - k[i]) * k[i - 1] * f[d[i - 1]][c[i]] + (1.0 - k[i - 1]) * (1.0 - k[i]) * f[c[i - 1]][c[i]]);
            // printf("debug: %d %d %0.2lf %0.2lf\n", i, j, dp[i][j][0], dp[i][j][1]);
        }
    }
    double ans = inf;
    for (int i = 0; i <= m; i++)
        ans = std::min(ans, std::min(dp[n][i][0], dp[n][i][1]));
    printf("%0.2lf", ans);
    return 0;
}
