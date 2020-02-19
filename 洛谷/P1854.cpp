#include <bits/stdc++.h>
const int Max = 101;
int a[Max][Max];
int f[Max][Max];
void print(int i, int j)
{
    if(j == 0)
        return;
    for(int k = 0; k <= i - j; k++)
        if(f[i][j] == f[j + k - 1][j - 1] + a[j][j + k])
        {
            print(j + k - 1, j - 1);
            printf("%d ", j + k);
            return;
        }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
        f[i][i] = f[i - 1][i - 1] + a[i][i];
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = -0x3f3f3f3f;
            for(int k = 0; k <= i - j; k++)
            {
               f[i][j] = std::max(f[i][j], f[j + k - 1][j - 1] + a[j][j + k]);
            }
        }
    }
    printf("%d\n", f[m][n]);
    print(m, n);
    return 0;
}