#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n;
double f[MaxN], s[MaxN];

signed main()
{
    scanf("%d", &n);
    if (n > 1000000)
        return 0 * printf("%.5lf\n", log(n) + 1.5772151649);
    for (int i = 2; i <= n; i++)
        f[i] = (i + s[i - 1]) / (double)(i - 1), s[i] = s[i - 1] + f[i];
    printf("%.5lf", f[n]);
    return 0;
}
