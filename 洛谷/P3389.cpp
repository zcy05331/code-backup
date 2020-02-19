#include <bits/stdc++.h>

int n;

double a[200][200], b[200];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];
        std::cin >> b[i];
    } 
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (fabs(a[j][i]) > 1e-8)
            {
                for (int k = 1; k <= n; k++)
                    std::swap(a[i][k], a[j][k]);
                std::swap(b[i], b[j]);
            }
        }
        if(fabs(a[i][i]) < 1e-8)
        {
            puts("No Solution");
            return 0;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            double rate = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
                a[j][k] -= a[i][k] * rate;
            b[j] -= b[i] * rate;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%.2f\n", b[i] / a[i][i]);
    return 0;
}
