#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
int n, m;
int a[510][510], b[510][510];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &b[i][j]), a[i][j] ^= b[i][j];
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= m; j++)
            cnt += a[i][j];
        if (cnt % 2)
            return 0 * printf("No");
    }
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            cnt += a[j][i];
        if (cnt % 2)
            return 0 * printf("No");
    }
    printf("Yes");
    return 0;
}
