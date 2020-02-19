#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

ll a[MaxN], b[MaxN];
ll n, m, ta, tb, k, ans, x;
std::vector<int> vec;

int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d", &n, &m, &ta, &tb, &k);
    if (k >= cmin(n, m))
        return 0 * printf("-1");
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%I64d", &x), vec.push_back(x);
    if (k + 1 <= n)
        n = k + 1;
    for (int i = 1; i <= n; i++)
    {
        ll x = a[i] + ta;
        int id = std::lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
        if (id + k - i >= m)
            return 0 * printf("-1");
        else
            ans = cmax(ans, vec[id + k - i]);
    }
    printf("%d\n", ans + tb);
    return 0;
}
