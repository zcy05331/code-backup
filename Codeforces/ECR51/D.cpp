#include <bits/stdc++.h>

const int mod = 998244353;
const int MaxN = 1010;

int f[MaxN][MaxN << 1];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j > i * 2)
                f[i][j] = 0;
            else
            {
                f[i][j] = 2;
                for(int l = 1; l <= j;l++)
                    f[i][j] += f[i - 1][l];
            }
        }
    }
    printf("%d", f[n][k]);
    return 0;
}