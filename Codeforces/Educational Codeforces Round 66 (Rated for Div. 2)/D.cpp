#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e5 + 10;

ll n, k, ans, sum;
ll a[MaxN], s[MaxN];

int main()
{
    scanf("%I64d%I64d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]), sum += a[i];
    for (int i = n; i; i--)
        s[i] = s[i + 1] + a[i];
    std::sort(s + 2, s + n + 1);
    for (int i = 1; i < k; i++)
        ans += s[n - i + 1];
    printf("%I64d\n", ans + sum);
    return 0;
}
