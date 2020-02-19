#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n;
long double ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        ans += (1.0 / (i * 1.0));
    printf("%.8Lf", ans);
    return 0;
}
