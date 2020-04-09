#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

ll n, m, ans = 0x3f3f3f3f3f3f3f3f;
ll a[MaxN], s[MaxN], sum[MaxN], lg[MaxN], max[MaxN][21];

ll query_max(int l, int r)
{
    int k = lg[r - l + 1];
    return std::max(max[l][k], max[r - (1 << k) + 1][k]);
}

void prework()
{
    lg[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        max[i][0] = s[i], lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
    }
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i], &s[i]);
    prework();
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if ((sum[i] - sum[mid - 1]) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        if ((sum[i] - sum[l - 1]) < m) continue;
        ans = std::min(ans, query_max(l, i));
    }
    printf("%lld\n", ans);
    return 0;
}
