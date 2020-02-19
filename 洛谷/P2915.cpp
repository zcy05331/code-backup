#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 18;

int n, k;
int a[MaxN], f[1 << MaxN][MaxN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        f[1 << i][i] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (int l = 0; l < n; l++)
                    if ((i & (1 << l)) == 0 && abs(a[j + 1] - a[l + 1]) > k)
                        f[i | (1 << l)][l] += f[i][j];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += f[(1 << n) - 1][i];
    printf("%lld\n", ans);
    return 0;
}
