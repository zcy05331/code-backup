# include <bits/stdc++.h>

int n;

double a[20][20], b[20], c[20][20];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lf", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]);
            b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(fabs(c[j][i]) > 1e-8)
            {
                for(int k = 1; k <= n; k++)
                    std::swap(c[i][k], c[j][k]);
                std::swap(b[i], b[j]);
            }
        }
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            double rate = c[j][i] / c[i][i];
            for (int k = i; k <= n; k++)
                c[j][k] -= c[i][k] * rate;
            b[j] -= b[i] * rate;
        }
    }
    for (int i = 1; i < n; i++)
        printf("%.3f ", b[i] / c[i][i]);
    printf("%.3f\n", b[n] / c[n][n]);
    return 0;
}

