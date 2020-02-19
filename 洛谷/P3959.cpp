#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 13;
int n, m;
int g[MaxN][MaxN], st[1 << MaxN][MaxN], f[1 << MaxN];

int dp(int s)
{
    memset(st, 0x3f, sizeof(st)), memset(f, 0x3f, sizeof(f));
    int lim = (1 << n);
    f[1 << s] = 0, st[1 << s][s] = 0;
    for (int i = 1; i < lim; i++)
    {
        if (f[i] < 0x3f3f3f3f)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (!(i & (1 << k)))
                        {
                            if ((g[j][k] != 0x3f3f3f3f) && (f[i | (1 << k)] > f[i] + (g[j][k] * (st[i][j] + 1))))
                            {
                                f[i | (1 << k)] = f[i] + (g[j][k] * (st[i][j] + 1));
                                memcpy(st[i | (1 << k)], st[i], sizeof(st[i | (1 << k)]));
                                st[i | (1 << k)][k] = st[i][j] + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return f[lim - 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d), --u, --v;
        g[u][v] = std::min(g[u][v], d), g[v][u] = std::min(g[v][u], d);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        ans = std::min(ans, dp(i));
    printf("%d\n", ans);
    return 0;
}
