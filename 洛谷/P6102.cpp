#include <bits/stdc++.h>

#define R register
#define int unsigned
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

int n, ans, a[MaxN], cnt[100][2];

int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        for (int j = 0; j <= 31; j++)
            cnt[j][(a[i] >> j) & 1]++;
    }
    for (int i = 0; i <= 31; i++)
    {
        ll num = 0, x = 0, y = 0;
        x = (2 * cnt[i][0] * cnt[i][1] + cnt[i][1] * cnt[i][1]);
        y = (2 * cnt[i][0] * cnt[i][1] + cnt[i][0] * cnt[i][0]), num += x * y;
        x = (cnt[i][0] * cnt[i][0]), y = (cnt[i][1] * cnt[i][1]), num += x * y, ans += num * (1 << i);
    }
    printf("%u\n", ans);
    return 0;
}
