#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 60;
ll n, m;
ll dis[MaxN][MaxN], g[MaxN][MaxN][MaxN << 1];

int main()
{
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        dis[u][v] = 1, g[u][v][0] = 1;
    }
    for (int l = 1; l <= 64; l++)
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (g[i][k][l - 1] && g[k][j][l - 1])
                        g[i][j][l] = 1, dis[i][j] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    printf("%lld\n", dis[1][n]);
    return 0;
}
