#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

ll n, m, k;
ll a[MaxN];

int main()
{
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        scanf("%I64d", &a[i]);
    ll tmp = 0, div = 0, ans = 0, id = 0, num = 1;
    for (ll i = 1; i <= m; i++)
    {
        tmp = (a[i] - id) % k;
        div = (a[i] - id) / k;
        if (tmp == 0)
            --div;
        num = 1;
        while (i + 1 <= m && a[i + 1] - id <= (div + 1) * k)
            ++i, ++num;
        ++ans;
        id += num;
    }
    printf("%I64d", ans);
    return 0;
}
