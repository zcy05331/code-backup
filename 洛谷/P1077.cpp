# include <bits/stdc++.h>

const int Max = 1005;
const int mod = 1000007;

int n, m;
int a[Max];
int f[Max][Max];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= a[i]; k++)
            {
                f[i][j] = (f[i - 1][j - k] + f[i][j]) % mod;
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}