#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e3 + 10;

int n;
int a[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll ans = 0x3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ll tot = 0;
        for (int j = 1; j <= n; j++)
            tot += (abs(a[i] - a[j]) % 2);
        ans = std::min(ans, tot);
    }
    printf("%I64d\n", ans);
    return 0;
}
