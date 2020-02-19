#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int MaxN = 2e5 + 10;
typedef std::pair<int, int> pa;
ll h, n;
ll d[MaxN], sum[MaxN];
int main()
{
    scanf("%lld%lld", &h, &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &d[i]), sum[i] = sum[i - 1] + d[i];
    for (int i = 1; i <= n; i++)
        if (h + sum[i] <= 0)
            return 0 * printf("%d\n", i);
    if (sum[n] >= 0)
        return 0 * printf("-1");
    ll min = *std::min_element(sum + 1, sum + n + 1);
    ll cnt = (h + min - 1) / (-sum[n]) + 1;
    h += cnt * sum[n];
    for (int i = 1; i <= n; i++)
        if (h + sum[i] <= 0)
            return 0 * printf("%lld\n", i + cnt * n);
    return 0;
}
