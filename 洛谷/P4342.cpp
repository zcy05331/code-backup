#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 200;
const int inf = 998244353;

char c[MaxN];
int n, ans = -inf;
int a[MaxN], f[MaxN][MaxN], g[MaxN][MaxN];

char get()
{
    char ch = getchar();
    while(!isalpha(ch))
        ch = getchar();
    return ch;
}

int main()
{   
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        c[i] = get(), scanf("%d", &a[i]);
        a[n + i] = a[i], c[n + i] = c[i];
    }
    for(int i = 1; i <= n * 2; i++)
        for(int j = 1; j <= n * 2; j++)
            f[i][j] = -inf, g[i][j] = inf;
    for(int i = 1; i <= 2 * n; i++)
        f[i][i] = g[i][i] = a[i];
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            for(int k = i; k < j; k++)
            {
                if(c[k + 1] == 'x')
                {
                    f[i][j] = std::max(f[i][j], std::max(f[i][k] * f[k + 1][j], std::max(f[i][k] * g[k + 1][j], std::max(g[i][k] * f[k + 1][j], g[i][k] * g[k + 1][j]))));
                    g[i][j] = std::min(g[i][j], std::min(f[i][k] * f[k + 1][j], std::min(f[i][k] * g[k + 1][j], std::min(g[i][k] * f[k + 1][j], g[i][k] * g[k + 1][j]))));
                }
                else
                {
                    f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j]);
                    g[i][j] = std::min(g[i][j], g[i][k] + g[k + 1][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = std::max(ans, f[i][i + n - 1]);
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        if(f[i][i + n - 1] == ans)
            printf("%d ", i);
    return 0;
}
