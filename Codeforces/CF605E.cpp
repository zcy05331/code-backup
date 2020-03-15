#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n, vis[MaxN], a[MaxN];
double p[MaxN][MaxN], d[MaxN], sum[MaxN], pr[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int now = 0;
        sum[i] = pr[i] = 1.0;
        for (int j = 1; j <= n; j++)
            scanf("%d", &now), p[i][j] = now * 0.01L;
    }
    vis[n] = 1, a[1] = n, d[0] = 1e18;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[j]) continue;
            sum[j] += d[a[i - 1]] * p[j][a[i - 1]] * pr[j];
            pr[j] *= (1 - p[j][a[i - 1]]), d[j] = sum[j] / (1 - pr[j]);
        }
        int pos = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[pos] > d[j])
                pos = j;
        vis[pos] = 1, a[i] = pos;
    }
    printf("%.10lf\n", d[1]);
    std::cerr << "tiger0132 /qq";
    return 0;
}
